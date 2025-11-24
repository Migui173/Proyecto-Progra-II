#ifndef PROYECTOPROGRA_TRANSACCION_H
#define PROYECTOPROGRA_TRANSACCION_H

#include <string>
#include <fstream>
using namespace std;

#include "usuario.h"
#include "Bicicleta.h"
#include "Estacion.h"

class Transaccion {
private:
    Usuario* cli;
    Bicicleta* bici;
    Estacion* origen;
    Estacion* destino;

    string idUsuario;
    string idBicicleta;
    int idEstacionA;
    int idEstacionB;
    int tiempoSeg;
    float distanciaKm;
    float monto;

public:
    Transaccion(Usuario* _cli,
                Bicicleta* _bici,
                Estacion* _origen,
                Estacion* _destino,
                int _tiempoSeg,
                float _distanciaKm);

    float calcularTarifa();
    void mostrar();
    void guardarEnArchivo(ofstream &archivo);

    float getMonto() const;
};

#endif //PROYECTOPROGRA_TRANSACCION_H
