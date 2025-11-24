#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Sistema.h"
#include <ctime>
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
    for (int i=0; i<=8; i++) {
        // CREANDO SUPERVISOR
        Supervisor*sup = new Supervisor(
            "SUP0"+ to_string(i),
            "Nombre" + to_string(i),
            "Apellido" + to_string(i),
            CrearDNI(),
            "99999999" + to_string(i)
            );
        Zona *z = new Zona(i, sup);
        zonas.push_back(z);
    }
    cout<<"[OK] Zonas inicializadas correctamente.\n";
}

void Sistema::inicializarEstaciones() {
    cout<<"[OK] Iniciando creación de estaciones...\n";
    for (Zona* z : zonas) {
        int zonaID = z->getId();
        int cant = rand() % 3 + 2; //cant. de estac. (2-4)
        for (int j=1; j<=cant; j++) {
            int idEstacion = zonaID *100 +  j; // id unico
            string nombre = "Estacion " + to_string(zonaID)+ "-" + to_string(j); //nombre
            double lat = -12.0 + (rand() % 1000) / 1000.0;
            double lon = -77 + (rand() % 1000) / 1000.0;

            int capacidad = (rand() % 3 + 1) *10;

            Estacion * e = new Estacion(idEstacion, nombre, lat, lon, capacidad, zonaID);

            z->agregarEstacion(e);
        }
    }
    cout<<"Todas las estaciones fueron creadas correctamente.\n";
}

void Sistema::inicializarUsuarios(int cantidad) {
    cout<<"[OK] Creando usuarios..."<<endl;
    for (int i=0; i<=cantidad; i++) {
        string nombre = "Usuario-" + to_string(cantidad);
        string apellido = "Ape_" + to_string(cantidad);
        Usuario *u = new Usuario(nombre, apellido);

        usuarios.push_back(u);
    }
    cout<<"[OK] " <<cantidad<< " usuarios correctamente.\n";
}


