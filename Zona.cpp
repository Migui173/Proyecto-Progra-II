#include "Zona.h"
#include <iostream>
using namespace std;

// Constructor vacío
Zona::Zona() {
    id = -1;
    nombre = "SIN_NOMBRE";
}

// Constructor completo
Zona::Zona(int _id, string _nombre) {
    id = _id;
    nombre = _nombre;
}

/* ===== GETTERS ===== */

int Zona::getId() { return id; }
string Zona::getNombre() { return nombre; }

/* ===== SETTERS ===== */

void Zona::setId(int _id) { id = _id; }
void Zona::setNombre(string _nombre) { nombre = _nombre; }

/* ===== MOSTRAR ===== */

void Zona::mostrar() {
    cout << "ZONA" << endl;
    cout << "  | ID     : " << id << endl;
    cout << "  | Nombre : " << nombre << endl;
    cout << "-----------------------------\n";
}
