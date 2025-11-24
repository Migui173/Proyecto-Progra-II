#ifndef PROYECTOPROGRA_BICICLETA_H
#define PROYECTOPROGRA_BICICLETA_H

#include <string>
using namespace std;

class Bicicleta {
protected:
    string codigo;
    string fabricante;
    bool esElectrico;

public:
    Bicicleta(string _cod);
    virtual ~Bicicleta() = default;

    bool isElectrico();
    void camMec();
    void camElec();

    virtual void mostrar();
    virtual float costoxKm(float km) = 0;  // método abstracto
};

#endif //PROYECTOPROGRA_BICICLETA_H
