#include "Estacion.h"
#include <iostream>
using namespace std;

// Constructor
Estacion::Estacion(int _id, const string& _nombre,
                   double _lat, double _lon, int _cap, int _zona)
{
    id = _id;
    nombre = _nombre;
    latitud = _lat;
    longitud = _lon;
    zona = _zona;

    if (_cap == 10 || _cap == 20 || _cap == 30)
        capacidad = _cap;
    else
        capacidad = 10;

    // Llenar la mitad de la capacidad con bicis
    int mitad = capacidad / 2;
    for (int i = 0; i < mitad; i++) {
        if (i % 2 == 0)
            bicicletas.push_back(new BiMecanica("MEC" + to_string(id * 100 + i), 3));
        else
            bicicletas.push_back(new BiElectrica("ELE" + to_string(id * 100 + i), 12.0f));
    }
}

/* ===== GETTERS ===== */

int Estacion::getID() { return id; }
string Estacion::getNombre() { return nombre; }
double Estacion::getLatitud() { return latitud; }
double Estacion::getLongitud() { return longitud; }
int Estacion::getCapacidad() { return capacidad; }
int Estacion::getOcupadas() { return bicicletas.size(); }
int Estacion::getZona() { return zona;}

/* ===== CANTIDADES POR TIPO ===== */

int Estacion::getCantElectricas() {
    int c = 0;
    for (auto b : bicicletas)
        if (b->isElectrico()) c++;
    return c;
}

int Estacion::getCantMecanicas() {
    int c = 0;
    for (auto b : bicicletas)
        if (!b->isElectrico()) c++;
    return c;
}

/* ===== GESTIÓN DE BICICLETAS ===== */

bool Estacion::agregarBicicleta(Bicicleta* b) {
    if (bicicletas.size() >= capacidad) return false;
    bicicletas.push_back(b);
    return true;
}

Bicicleta* Estacion::retirarBicicleta(int idx) {
    if (idx < 0 || idx >= (int)bicicletas.size()) return nullptr;
    Bicicleta* b = bicicletas[idx];
    bicicletas.erase(bicicletas.begin() + idx);
    return b;
}

/* ===== MOSTRAR ===== */

void Estacion::mostrar() {
    cout << "ESTACION" << endl;
    cout << "  | ID        : " << id << endl;
    cout << "  | Nombre    : " << nombre << endl;
    cout << "  | Latitud   : " << latitud << endl;
    cout << "  | Longitud  : " << longitud << endl;
    cout << "  | Capacidad : " << capacidad << endl;
    cout << "  | Ocupadas  : " << bicicletas.size() << endl;
    cout << "  | Electricas: " << getCantElectricas() << endl;
    cout << "  | Mecanicas : " << getCantMecanicas() << endl;
    cout << "  | Zona      : " << zona <<endl;
    cout << "-----------------------------------------\n";
}
