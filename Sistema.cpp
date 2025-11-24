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