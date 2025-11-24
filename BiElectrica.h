#ifndef PROYECTOPROGRA_BIELECTRICA_H
#define PROYECTOPROGRA_BIELECTRICA_H

#include "Bicicleta.h"

class BiElectrica : public Bicicleta {
private:
    float capBateria;

public:
    BiElectrica(string _cod, float bat);
    void mostrar() const override;
    float costoxKm(float km) const override;
};

#endif //PROYECTOPROGRA_BIELECTRICA_H
