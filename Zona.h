#ifndef PROYECTOPROGRA_ZONA_H
#define PROYECTOPROGRA_ZONA_H

#include <string>
#include <vector>
using namespace std;

class Zona {
private:
    int id;
    string nombre;

public:
    Zona();
    Zona(int _id, string _nombre);

    int getId();
    string getNombre();

    void setId(int _id);
    void setNombre(string _nombre);

    void mostrar();
};

#endif //PROYECTOPROGRA_ZONA_H
