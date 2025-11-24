#ifndef PROYECTOPROGRA_BIMECANICA_H
#define PROYECTOPROGRA_BIMECANICA_H

#include "Bicicleta.h"

class BiMecanica : public Bicicleta {
private:
    int cantCambios;

public:
    BiMecanica(string _cod, int cambios);
    void mostrar() const override;
    float costoxKm(float km) const override;
};

#endif //PROYECTOPROGRA_BIMECANICA_H
