#include "usuario.h"
#include "utils.h"
#include "colors.h"
#include <iostream>
using namespace std;

//CONSTRUCTORES
Usuario::Usuario(string _name, string _ape){
    Nombre = _name;
    Apellido = _ape;
    ID = CrearID();
    DNI = CrearDNI();
    TarjetaPago = ElegirTarjeta();
    EsVecino = Vecinidad();
    Zona = elegirzona();
}

Usuario::Usuario(string _Nombre, string _ID, string _Apellido,
    string _DNI, string _TarjetaPago, bool _EsVecino, int _zona){
        Nombre = _Nombre;
        ID = _ID;
        Apellido = _Apellido;
        DNI = _DNI;
        TarjetaPago = _TarjetaPago;
        EsVecino = _EsVecino;
        Zona = _zona;
    }

// GETTERS
string Usuario::getNombre(){
    return Nombre;
}

string Usuario::getID(){
    return ID;
}

string Usuario::getApellido(){
    return Apellido;
}

string Usuario::getDNI(){
    return DNI;

}
string Usuario::getTarjetaPago(){
    return TarjetaPago;
}

bool Usuario::getEsVecino(){
    return EsVecino;
}

int Usuario::getZona(){
    return Zona;
}

// SETTERS

void Usuario::setNombre(string nombre){
    Nombre = nombre;
}

void Usuario::setID(string id){
    ID = id;
}

void Usuario::setApellido(string apellido){
    Apellido = apellido;
}

void Usuario::setDNI(string dni){
    DNI = dni;
}

void Usuario::setTarjetaPago(string _TarjetaPago){
    TarjetaPago = _TarjetaPago;
}

void Usuario::setEsVecino(bool esvecino){
    EsVecino = esvecino;
}

void Usuario::setZona(int zona){
    Zona = zona;
}

// Imprimir

void Usuario::imp(){
    cout << CYAN<<"USUARIO " << ID << " : \n"<<RESET;
    cout << AMARILLO<<"\t| Nombre : " << Nombre << endl;
    cout << "\t| Apellido : " << Apellido << endl;
    cout << "\t| DNI : " << DNI << endl;
    cout << "\t| Tarjeta : " << TarjetaPago << endl;
    cout << "\t| Es Vecino : " << (EsVecino ? "Si" : "No") << endl;
    cout << "\t| Zona : " << Zona << endl<<RESET;
}