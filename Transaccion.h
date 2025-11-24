#ifndef PROYECTOPROGRA_TRANSACCION_H
#define PROYECTOPROGRA_TRANSACCION_H

#include <string>
#include <fstream>
using namespace std;

#include "usuario.h"
#include "Bicicleta.h"

class Transaccion {
private:
    Usuario* cli;
    Bicicleta* bici;

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
                int _idEstacionA,
                int _idEstacionB,
                int _tiempoSeg,
                float _distanciaKm);

    float calcularTarifa();
    void mostrar();
    void guardarEnArchivo(ofstream &archivo);

    float getMonto() const;
};

#endif //PROYECTOPROGRA_TRANSACCION_H
