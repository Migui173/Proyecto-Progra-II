#include "BiMecanica.h"
#include <iostream>
using namespace std;

BiMecanica::BiMecanica(string _cod, int cambios) : Bicicleta(_cod) {
    camMec();
    cantCambios = cambios;
}

void BiMecanica::mostrar() const {
    Bicicleta::mostrar();
    cout << "  | Cantidad de Cambios: " << cantCambios << endl;
}

float BiMecanica::costoxKm(float km) const{
    return 3.0f * km;
}
