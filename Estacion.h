#ifndef PROYECTOPROGRA_ESTACION_H
#define PROYECTOPROGRA_ESTACION_H

#include <string>
#include <vector>
#include "Bicicleta.h"
#include "BiMecanica.h"
#include "BiElectrica.h"

using namespace std;

class Estacion {
private:
    int id;
    string nombre;
    double latitud;
    double longitud;
    int capacidad;
    vector<Bicicleta*> bicicletas;

public:
    // Constructor
    Estacion(int _id, const string& _nombre,
             double _lat, double _lon, int _cap);

    // Getters
    int getId();
    string getNombre();
    double getLatitud();
    double getLongitud();
    int getCapacidad();
    int getOcupadas();

    // Cantidad por tipo
    int getCantElectricas();
    int getCantMecanicas();

    // Gestión de bicicletas
    bool agregarBicicleta(Bicicleta* b);
    Bicicleta* retirarBicicleta(int idx);

    // Mostrar datos
    void mostrar();
};

#endif //PROYECTOPROGRA_ESTACION_H
