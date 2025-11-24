#ifndef PROYECTOPROGRA_BIMECANICA_H
#define PROYECTOPROGRA_BIMECANICA_H

#include "Bicicleta.h"

class BiMecanica : public Bicicleta {
private:
    int cantCambios;

public:
    BiMecanica(string _cod, int cambios);
    void mostrar() override;
    float costoxKm(float km) override;
};

#endif //PROYECTOPROGRA_BIMECANICA_H
