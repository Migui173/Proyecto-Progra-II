#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Sistema.h"
#include <ctime>
#include "colors.h"
using namespace std;

Sistema::Sistema() {

}
Sistema::~Sistema() {
    for (int i=0; i<usuarios.size(); i++) {
        delete usuarios[i];
    }
    for (int i=0; i<zonas.size(); i++) {
        delete zonas[i];
    }
    for (int i=0;i<transacciones.size();i++) {
        delete transacciones[i];
    }
}
void Sistema::inicializarZonas() {

    vector<string> nombre = {
        "Santiago", "Valentin", "Matias", "Diego", "Marcos",
        "Julian", "Ricardo", "Rodrigo"};
    vector<string> apellido = {
        "Herron", "Castro" , "Vargas" , "Mendoza" ,"Silva", "Rojas",
        "Torres", "Guzman"};
    for (int i=1; i<=8; i++) {
        // CREANDO SUPERVISOR
        Supervisor*sup = new Supervisor(
            "SUP0"+ to_string(i),
            nombre[i-1],
            apellido[i-1],
            CrearDNI(),
            "99999999" + to_string(i)
            );
        Zona *z = new Zona(i, sup);
        zonas.push_back(z);
        //zonas[i-1]->mostrar();
    }
    cout<<VERDE<<"[OK] Zonas inicializadas correctamente.\n"<<RESET;
}

void Sistema::inicializarEstaciones() {
    cout<<VERDE<<"[OK] Iniciando creación de estaciones...\n"<<RESET;
    for (Zona* z : zonas) {
        int zonaID = z->getId();
        int cant = rand() % 3 + 2; //cant. de estac. (2-4)
        for (int j=1; j<=cant; j++) {
            int idEstacion = zonaID *100 +  j; // id unico
            string nombre = "Estacion " + to_string(zonaID)+ "-" + to_string(j); //nombre
            double lat = -12.0 + (rand() % 1000) / 1000.0; //latitud
            double lon = -77 + (rand() % 1000) / 1000.0; //longitud

            int capacidad = (rand() % 3 + 1) *10;

            Estacion * e = new Estacion(idEstacion, nombre, lat, lon, capacidad, zonaID);

            z->agregarEstacion(e);
        }
    }
    cout<<VERDE<<"Todas las estaciones fueron creadas correctamente.\n"<< RESET;
}

void Sistema::inicializarUsuarios(int cantidad) {
    cout<<AMARILLO<<"[OK] Creando usuarios..."<<endl<<RESET;
    for (int i=1; i<=cantidad; i++) {
        string nombre = "Usuario-" + to_string(i);
        string apellido = "Ape_" + to_string(i);
        Usuario *u = new Usuario(nombre, apellido);

        usuarios.push_back(u);
    }
    cout<<VERDE<<"[OK] " <<cantidad<< " usuarios correctamente.\n"<<RESET;

}

void Sistema::simularDia(int cantViajes) {
    cout << "\n[SIMULACION] Iniciando simulación del día...\n";

    ofstream archivo("transacciones.txt", ios::app);
    if (!archivo.is_open()) {
        cerr << "[ERROR] No se pudo abrir transacciones.txt para escritura.\n";
        return;
    }

    for (int v=1; v<=cantViajes; v++) {
        Usuario* user = eligirUsuario();

        Estacion* origen = eligirEstacionOrigen(user);

        Estacion* destino = eligirEstacionDestino(origen, user);

        Bicicleta* bici = elegirBicicleta(origen);

        int tiempo = generarTiempo();

        float distacia = generarDistancia(tiempo);

        Transaccion* t = new Transaccion(user, bici, origen, destino, tiempo, distacia);

        t->calcularTarifa();
        transacciones.push_back(t);

        moverBicicleta(origen,destino,bici);
        t->mostrar();

        t->guardarEnArchivo(archivo);
        //cout << "Viaje #" << v << " completado. Monto: S/" << t->getMonto() << endl;
    }
    archivo.close();
    cout << VERDE <<"[SIMULACION] Día completado exitosamente.\n"<<RESET;
}

Usuario *Sistema::eligirUsuario() {
    if (usuarios.empty()) return nullptr;

    int r = rand() % 100;

    // 70% probabilidad → usuarios frecuentes (primeros 20 o todos si hay menos)
    if (r<70 && usuarios.size() >=20) {
        int idx = rand() % 20;
        return usuarios[idx];
    }

    int idx = rand() % usuarios.size();
    return usuarios[idx];
}

Estacion *Sistema::eligirEstacionOrigen(Usuario *u) {
    if (zonas.empty()) return nullptr;
    int zonaUsuario = u->getZona();

    int r = rand() % 100;
    int zonaElegida = zonaUsuario;

    if (r<40) // 40% MISMA ZONA
        zonaElegida = zonaUsuario;
    else if (r<70) { // 30% ZONA VECINA
        int dir = (rand() % 2 == 0 ? -1 : 1);
        zonaElegida = zonaUsuario + dir;

        // Limitar a 1-8
        if (zonaElegida < 1) zonaElegida = 2;
        if (zonaElegida > 8) zonaElegida = 7;
    }
    else { // 30 % ZONA ALEATORIA
        zonaElegida = (rand() % 8) + 1;
    }

    // Buscar la zona
    Zona* z = nullptr;
    for (Zona* zona : zonas) {
        if (zona->getId() == zonaElegida) {
            z = zona;
            break;
        }
    }

    if (z == nullptr) return nullptr;
    vector<Estacion*>& ests = z->getEstaciones();

    if (ests.empty()) return nullptr;

    // ELegir una estacion aleatoria

    int idx = rand() % ests.size();

    return ests[idx];
}

Estacion *Sistema::eligirEstacionDestino(Estacion *origen, Usuario *u) {
    if (!origen) return nullptr;
    if (zonas.empty()) return nullptr;

    int zonaOrigen = origen->getZona();
    int zonaElegida = zonaOrigen;

    int r = rand() % 100;  // 0..99

    // 60% destino en misma zona
    if (r < 60) {
        zonaElegida = zonaOrigen;
    }
    // 30% destino en zona vecina
    else if (r < 90) {
        int dir = (rand() % 2 == 0 ? -1 : 1);
        zonaElegida = zonaOrigen + dir;

        if (zonaElegida < 1) zonaElegida = 2;
        if (zonaElegida > 8) zonaElegida = 7;
    }
    // 10% destino en cualquier zona
    else {
        zonaElegida = (rand() % 8) + 1; // 1–8
    }

    // Buscar la zona elegida
    Zona* z = nullptr;
    for (Zona* zona : zonas) {
        if (zona->getId() == zonaElegida) {
            z = zona;
            break;
        }
    }

    if (!z) return nullptr;

    vector<Estacion*>& ests = z->getEstaciones();
    if (ests.empty()) return nullptr;

    // Elegir estación destino aleatoria
    int idx = rand() % ests.size();
    return ests[idx];
}

Bicicleta *Sistema::elegirBicicleta(Estacion *origen) {
    if (!origen) return nullptr;

    int cantE = origen->getCantElectricas();
    int cantM = origen->getCantMecanicas();

    if (cantE + cantM == 0) return nullptr;

    // Preferencia realista:
    int r = rand() % 100;  // 0..99
    bool quiereMecanica = (r < 60);  // 60%

    // 1. Intentar con tipo preferido
    if (quiereMecanica && cantM > 0) {
        // Buscar una mecánica
        // retiramos por índice
        // buscamos la mecánica en el vector interno de estación
        // Estacion ya tiene retirarBicicleta(int idx)

        // buscar bicicleta mecánica
        for (int i = 0; i < origen->getOcupadas(); i++) {
            Bicicleta* b = origen->retirarBicicleta(i);
            if (b) {
                if (!b->isElectrico()) {
                    return b; // listo
                }
                else {
                    // no era mecánica → regresarla y seguir
                    origen->agregarBicicleta(b);
                }
            }
        }
    }
    else if (!quiereMecanica && cantE > 0) {
        // Buscar eléctrica
        for (int i = 0; i < origen->getOcupadas(); i++) {
            Bicicleta* b = origen->retirarBicicleta(i);
            if (b) {
                if (b->isElectrico()) {
                    return b; // encontrado
                }
                else {
                    origen->agregarBicicleta(b);
                }
            }
        }
    }

    // 2. Fallback: si no se encontró del tipo deseado, tomar cualquiera disponible
    for (int i = 0; i < origen->getOcupadas(); i++) {
        Bicicleta* b = origen->retirarBicicleta(i);
        if (b) return b;
    }

    return nullptr;
}

int Sistema::generarTiempo() {
    int r = rand() % 100;

    if (r<55) // Viaje Corto
        return 300 + (rand() % 901);
    if (r<90) // Viaje mediano
        return 1200 + (rand() % 1201);
    return 2400 + (rand() % 1201); //Viaje largo
}

float Sistema::generarDistancia(int tiempo) {
    if (tiempo <=1200) // Viaje Corto
        return 0.5f + (rand() % 1501) / 1000.0f;
    if (tiempo <=2400) // Viaje Mediano
        return 2.0f + (rand() % 2001) / 1000.0f;
    // Viaje largo
    return 4.0f + (rand()% 2001) / 1000.0f;
}

void Sistema::moverBicicleta(Estacion *origen, Estacion *destino, Bicicleta *bici) {
    if (!origen || !destino || !bici) return;
    bool pudoAgregar = destino->agregarBicicleta(bici);

    if (!pudoAgregar) {
        origen->agregarBicicleta(bici);
        cout<<ROJO<<"[ADVERTENCIA] La estación destino (" << destino->getID()
             << ") está llena. Bici devuelta a estación origen." << endl<<RESET;
    }
}

void Sistema::menu() {
    int opcion;
    do {
        cout <<AZUL<< "\n======= MENU DEL SISTEMA DE BICICLETAS =======" << endl;
        cout << "1. Lista de Zonas" << endl;
        cout << "2. Lista de Estaciones por Zona" << endl;
        cout << "3. Lista de Usuarios" << endl;
        cout << "4. Registrar Usuario" << endl;
        cout << "5. Simular un Dia Completo" << endl;
        cout << "6. Mostrar Todas las Transacciones" << endl;
        cout << "7. Guardar Transacciones del Dia" << endl;
        cout << "8. Salir" << endl;
        cout<< string(46, '=')<<endl<<RESET;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {

            case 1: {
                cout << MAGENTA<<"\n------------------- ZONAS --------------------\n";
                cout<<"N°ZONA\tID - Supervisor\t\t\tN° Estaciones\n"<<RESET;
                for (Zona* z : zonas) {
                    z->mostrarfila();
                }
                cout<<MAGENTA<<"----------------------------------------------\n"<<RESET;
                break;
            }

            case 2: {
                int idz;
                cout << "Ingrese ID de zona (1-8): ";
                cin >> idz;

                for (Zona* z : zonas) {
                    if (z->getId() == idz) {
                        cout << MAGENTA<<"\n--- ESTACIONES DE ZONA " << idz << " ---\n"<<RESET;
                        for (Estacion* e : z->getEstaciones()) {
                            e->mostrar();
                        }
                    }
                }
                break;
            }

            case 3: {
                cout << MAGENTA<<"\n--- USUARIOS ---\n"<<RESET;
                for (Usuario* u : usuarios) {
                    u->imp(); // Tu método imprime todo
                    cout << endl;
                }
                break;
            }

            case 4: {
                string nom, ape;
                cout << "Ingrese nombre: ";
                cin >> nom;
                cout << "Ingrese apellido: ";
                cin >> ape;

                Usuario* u = new Usuario(nom, ape);
                usuarios.push_back(u);

                cout <<VERDE<< "[OK] Usuario "<<u->getID()<<" registrado correctamente.\n"<<RESET;
                break;
            }

            case 5: {
                int cantidad;
                cout << "¿Cuantos viajes desea simular hoy?: ";
                cin >> cantidad;

                simularDia(cantidad);
                break;
            }

            case 6: {
                cout <<MAGENTA<< "\n--- TRANSACCIONES ---\n"<<RESET;
                if (transacciones.empty()) {
                    cout<<AMARILLO<<"[AVISO] NO SE ENCONTRARON TRANSACCIONES"<<endl<<RESET;
                    break;
                }
                else {
                    for (Transaccion* t : transacciones) {
                        t->mostrar();
                    }
                    break;
                }

            }

            case 7: {
                ofstream archivo("transacciones.txt", ios::app);
                if (!archivo.is_open()) {
                    cout <<ROJO<<"[ERROR] No se pudo abrir el archivo." << endl<<RESET;
                } else {
                    for (Transaccion* t : transacciones) {
                        t->guardarEnArchivo(archivo);
                    }
                    cout <<VERDE<<"[OK] Transacciones guardadas en transacciones.txt\n"<<RESET;
                    archivo.close();
                }
                break;
            }

            case 8:
                cout<<ROJO<< "Saliendo del sistema..." << endl<<RESET;
                break;

            default:
                cout<<ROJO<<"Opcion invalida." << endl<<RESET;
        }

    } while (opcion != 8);
};

