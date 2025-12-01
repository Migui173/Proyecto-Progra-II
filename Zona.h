#ifndef PROYECTOPROGRA_ZONA_H
#define PROYECTOPROGRA_ZONA_H

#include <string>
#include <vector>

#include "Estacion.h"
#include "Supervisor.h"
using namespace std;

class Zona {
private:
    int id;
    Supervisor* supervisor;
    vector<Estacion*> estaciones;

public:
    Zona(int _id, Supervisor * sup);

    int getId();
    vector<Estacion*>& getEstaciones();
    void setId(int _id);

    Supervisor* getSupervisor();

    void agregarEstacion(Estacion* e);

    void mostrar();
    void mostrarfila();
};

#endif //PROYECTOPROGRA_ZONA_H
