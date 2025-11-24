#ifndef PROYECTOPROGRA_SUPERVISOR_H
#define PROYECTOPROGRA_SUPERVISOR_H

#include <string>
using namespace std;

class Supervisor {
private:
    string ID;
    string Nombre;
    string Apellido;
    string DNI;
    string NumContacto;

public:
    // Constructor
    Supervisor(string _ID, string _Nombre, string _Apellido,
               string _DNI, string _NumContacto);

    // Getters
    string getID();
    string getNombre();
    string getApellido();
    string getDNI();
    string getContacto();

    // Setters
    void setID(string _ID);
    void setNombre(string _Nombre);
    void setApellido(string _Apellido);
    void setDNI(string _DNI);
    void setContacto(string _NumContacto);

    // Mostrar
    void mostrar();
};

#endif //PROYECTOPROGRA_SUPERVISOR_H
