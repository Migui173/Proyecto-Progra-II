#include "Bicicleta.h"
#include "utils.h"
#include <iostream>
using namespace std;

Bicicleta::Bicicleta(string _cod) {
    codigo = _cod;
    fabricante = FabAleo();
}

string Bicicleta::getCodigo() const {
    return codigo;
}

bool Bicicleta::isElectrico() const{
    return esElectrico;
}

void Bicicleta::camMec() {
    esElectrico = false;
}

void Bicicleta::camElec() {
    esElectrico = true;
}

void Bicicleta::mostrar() const{
    cout << "BICICLETA" << endl;
    cout << "  | Codigo: " << codigo << endl;
    cout << "  | Fabricante: " << fabricante << endl;
    cout << "  | Tipo: " << (esElectrico ? "Eléctrica" : "Mecánica") << endl;
}
