#include <iostream>
#include "utils.h"
#include "usuario.h"
#include "Supervisor.h"
#include "Zona.h"
#include "Bicicleta.h"
#include "BiElectrica.h"
#include "BiMecanica.h"
#include "Estacion.h"
#include "Transaccion.h"

using namespace std;

int main() {
    srand(time(NULL));
    cout << "=== PRUEBA DE SISTEMA DE BICICLETAS ===\n\n";

    // Crear usuarios
    Usuario u1("Bryhan", "Gonzales");
    Usuario u2("Miguel", "Villena");

    cout << ">> Usuarios generados:\n";
    u1.imp();
    cout << endl;
    u2.imp();
    cout << "\n----------------------------------------\n\n";

    // Crear supervisor
    Supervisor* s1 = new Supervisor("SUP01", "Carlos", "Lopez", "70223311", "987654321");
    cout << ">> Supervisor creado:\n";
    s1->mostrar();
    cout << "\n----------------------------------------\n\n";

    // Crear bicicletas
    Bicicleta* b1 = new BiMecanica("BIKE01", 5);
    Bicicleta* b2 = new BiElectrica("BIKE02", 12);

    cout << ">> Bicicletas creadas:\n";
    b1->mostrar();
    cout << endl;
    b2->mostrar();
    cout << "\n----------------------------------------\n\n";

    // Crear estación
    Estacion * e1 = new Estacion(1, "Estacion Central", 12.35, 23.9, 10,2);
    Estacion * e2 = new Estacion(2, "Estacion Central 1 ", 15.86, 25.9, 10,7);
    cout << ">> Datos de estación:\n";
    e1->mostrar();
    cout << "\n----------------------------------------\n\n";

    // Crear transacción
    cout << ">> Creando transacción...\n";
    Transaccion t1(&u1, b2, e1, e2, 1500, 4.0f);

    t1.calcularTarifa();
    t1.mostrar();

    cout << "\nGuardando transacción en archivo...\n";
    ofstream archivo("transacciones.txt", ios::app);
    if (archivo.is_open()) {
        t1.guardarEnArchivo(archivo);
        archivo.close();
    }

    cout << "Transacción guardada correctamente.\n";

    // Liberar memoria dinámica
    delete b1;
    delete b2;

    cout << "\n=== FIN DE PRUEBAS ===\n";

    Zona z1(1, s1);
    z1.mostrar();
    return 0;

    //REVISANDO SI ESTA TODO BIEN
}
