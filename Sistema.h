#ifndef PROYECTOPROGRA_SISTEMA_H
#define PROYECTOPROGRA_SISTEMA_H

#include "Transaccion.h"
#include "usuario.h"
#include "Zona.h"
#include "utils.h"

class Sistema {
private:
    vector<Usuario*> usuarios;
    vector<Zona *> zonas;
    vector<Transaccion *> transacciones;
public:
    Sistema();
    ~Sistema();

    void inicializarZonas();
    void inicializarEstaciones();
    void inicializarUsuarios(int cantidad);
    void simularDia(int cantViajes);
    void reporteFinal();

    // FUNCIONES AUXILIARES
    Usuario* eligirUsuario();
    Estacion* eligirEstacionOrigen(Usuario *u);
    Estacion* eligirEstacionDestino(Estacion *origen, Usuario *u);
    Bicicleta* elegirBicicleta(Estacion* origen);
    int generarTiempo();
    float generarDistancia(int tiempo);
    void moverBicicleta(Estacion* origen, Estacion* destino, Bicicleta*bici);

};

#endif //PROYECTOPROGRA_SISTEMA_H