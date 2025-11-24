#include "utils.h"

//Generar fabricante - EJM : FAB01
string FabAleo() {
    int n = rand() % 5 + 1;
    return "FAB0" + to_string(n);
}

// Crear ID aleatorio - EJM : ABC123
string CrearID() {
    string id;
    for (int i=0; i<3;i++)
        id+= char(rand() % 26 + 65);
    for (int i=0; i<3; i++)
        id+= char(rand()% 10+48);
    return id;
}

// Crear DNI de 8 digitos - EJM : 12345678
string CrearDNI() {
    string DNI;
    for (int i=0; i<8;i++)
        DNI+= char(rand() % 10 + 48);
    return DNI;
}

// Tarjeta - EJM : Visa
string ElegirTarjeta() {
    vector<string> opciones = {"Visa",
        "MasterCard", "American Express"};
    return opciones[rand() % opciones.size()];
}

// Bool aleatorio (Vecino o no)
bool Vecinidad() {
    return rand() % 2 == 1;
}

// Zona aleatoria entre 1 y 8
int elegirzona() {
    return rand() % 8 + 1;
}
