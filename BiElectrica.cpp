#include "BiElectrica.h"
#include <iostream>
using namespace std;

BiElectrica::BiElectrica(string _cod, float bat) : Bicicleta(_cod) {
    camElec();
    capBateria = bat;
}

void BiElectrica::mostrar() {
    Bicicleta::mostrar();
    cout << "  | Capacidad Batería: " << capBateria << " AMP" << endl;
}

float BiElectrica::costoxKm(float km) {
    return 4 * km;
}
