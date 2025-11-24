#include "Transaccion.h"
#include <iostream>
#include <cmath>
using namespace std;

Transaccion::Transaccion(Usuario* _cli,
                         Bicicleta* _bici,
                         Estacion* _origen,
                         Estacion* _destino,
                         int _tiempoSeg,
                         float _distanciaKm)
{
    cli = _cli;
    bici = _bici;

    idUsuario   = cli->getID();
    idBicicleta = "SIN_CODIGO";   // puedes luego cambiarlo si asignas códigos reales

    origen = _origen;
    destino = _destino;
    idEstacionA = origen->getID();
    idEstacionB = destino->getID();
    tiempoSeg   = _tiempoSeg;
    distanciaKm = _distanciaKm;
    monto       = 0;
}

float Transaccion::calcularTarifa() {
    float total = 0.0f;
    float tiempoMin = tiempoSeg / 60.0f;

    bool mismaEstacion = (idEstacionA == idEstacionB);

    /* ---------------- COSTO POR RECORRIDO ---------------- */
    if (!mismaEstacion) {
        float costoBaseDist = 3.0f * distanciaKm;

        if (bici->isElectrico()) 
            costoBaseDist += distanciaKm;

        total += costoBaseDist;

        bool ladoA_1_4 = (idEstacionA >= 1 && idEstacionA <= 4);
        bool ladoB_1_4 = (idEstacionB >= 1 && idEstacionB <= 4);

        if (ladoA_1_4 != ladoB_1_4)
            total += 5.0f;
    }
    else {
        int bloques5min = (int)ceil(tiempoMin / 5.0f);
        total += bloques5min * 1.0f;
    }

    /* ---------------- COSTO ADICIONAL POR TIEMPO ---------------- */
    if (tiempoMin > 20.0f) {
        float extraMin = tiempoMin - 20.0f;
        total += extraMin * 1.0f;
    }

    /* ---------------- DESCUENTOS ---------------- */

    // Descuento por zona
    int zonaUsuario = cli->getZona();
    bool coincideZona =
        (zonaUsuario == idEstacionA) || (zonaUsuario == idEstacionB);

    if (coincideZona)
        total *= 0.90f;

    // Descuento por tarjeta VISA
    string tarj = cli->getTarjetaPago();
    if (tarj == "visa" || tarj == "Visa" || tarj == "VISA")
        total *= 0.95f;

    monto = total;
    return monto;
}

void Transaccion::mostrar() {
    cout << "TRANSACCION" << endl;
    cout << "  | ID Usuario     : " << idUsuario << endl;
    cout << "  | ID Bicicleta   : " << idBicicleta << endl;
    cout << "  | Estacion A     : " << idEstacionA << endl;
    cout << "  | Estacion B     : " << idEstacionB << endl;
    cout << "  | Tiempo (seg)   : " << tiempoSeg << endl;
    cout << "  | Distancia (km) : " << distanciaKm << endl;
    cout << "  | Monto (S/)     : " << monto << endl;
    cout << "  | Vecino         : " << (cli->getEsVecino() ? "Si" : "No") << endl;
    cout << "  | Tarjeta        : " << cli->getTarjetaPago() << endl;
    cout << "  | Tipo Bici      : "
         << (bici->isElectrico() ? "Electrica" : "Mecanica") << endl;
    cout << "-----------------------------------------\n";
}

void Transaccion::guardarEnArchivo(ofstream &archivo) {
    archivo << idUsuario   << ","
            << idBicicleta << ","
            << idEstacionA << ","
            << idEstacionB << ","
            << tiempoSeg   << ","
            << monto       << "\n";
}

float Transaccion::getMonto() const {
    return monto;
}
