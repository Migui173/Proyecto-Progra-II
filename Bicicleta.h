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

    string getCodigo() const;
    bool isElectrico() const;
    void camMec();
    void camElec();

    virtual void mostrar() const;
    virtual float costoxKm(float km) const = 0;  // método abstracto
};

#endif //PROYECTOPROGRA_BICICLETA_H
