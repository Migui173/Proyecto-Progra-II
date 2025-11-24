#include "Supervisor.h"
#include <iostream>
using namespace std;

// Constructor
Supervisor::Supervisor(string _ID, string _Nombre, string _Apellido,
                       string _DNI, string _NumContacto)
{
    ID = _ID;
    Nombre = _Nombre;
    Apellido = _Apellido;
    DNI = _DNI;
    NumContacto = _NumContacto;
}

/* ======== GETTERS ======== */

string Supervisor::getID() { return ID; }
string Supervisor::getNombre() { return Nombre; }
string Supervisor::getApellido() { return Apellido; }
string Supervisor::getDNI() { return DNI; }
string Supervisor::getContacto() { return NumContacto; }

/* ======== SETTERS ======== */

void Supervisor::setID(string _ID) { ID = _ID; }
void Supervisor::setNombre(string _Nombre) { Nombre = _Nombre; }
void Supervisor::setApellido(string _Apellido) { Apellido = _Apellido; }
void Supervisor::setDNI(string _DNI) { DNI = _DNI; }
void Supervisor::setContacto(string _NumContacto) { NumContacto = _NumContacto; }

/* ======== MOSTRAR ======== */

void Supervisor::mostrar() {
    cout << "SUPERVISOR" << endl;
    cout << "  | ID: " << ID << endl;
    cout << "  | Nombre: " << Nombre << endl;
    cout << "  | Apellido: " << Apellido << endl;
    cout << "  | DNI: " << DNI << endl;
    cout << "  | Contacto: " << NumContacto << endl;
}
