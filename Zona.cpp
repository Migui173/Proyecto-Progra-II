#include "Zona.h"
#include <iostream>
using namespace std;

// Constructor completo
Zona::Zona(int _id, Supervisor * sup) {
    id = _id;
    supervisor = sup;
}

/* ===== GETTERS ===== */

int Zona::getId() { return id; }
Supervisor *Zona::getSupervisor() {return supervisor;}
vector<Estacion *>& Zona::getEstaciones() {
    return estaciones;
}

/* ===== SETTERS ===== */

void Zona::setId(int _id) { id = _id; }

/* ===== MOSTRAR ===== */

void Zona::mostrar() {
    cout << "ZONA" << endl;
    cout << "  | ID         : " << id << endl;
    cout << "  | Supervisor : " << supervisor->getNombre() << endl;
    cout << "  | Estaciones : " << estaciones.size()<<endl;
    cout << "-----------------------------\n";
}

void Zona::agregarEstacion(Estacion *e) {
    estaciones.push_back(e);
}

