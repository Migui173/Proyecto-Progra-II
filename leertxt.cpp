#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "colors.h"

using namespace std;

int main() {
    ifstream archivo;
    archivo.open("transacciones.txt");

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo transacciones.txt" << endl;
        return 0;
    }

    string linea;
    double sumaMec = 0.0; double sumaEle = 0.0;
    double sumaMastercard = 0.0; double sumavisa = 0.0; double sumaamericanexpress = 0.0;

    while (getline(archivo, linea)) {
        stringstream ss(linea);

        // Leer todos los campos como strings usando getline
        string IDusuario, IDbicicleta, zonaestacionA, zonaestacionB, distancia, costo, targeta;

        getline(ss, IDusuario, ',');
        getline(ss, IDbicicleta, ',');
        getline(ss, zonaestacionA, ',');
        getline(ss, zonaestacionB, ',');
        getline(ss, distancia, ',');
        getline(ss, costo, ',');
        getline(ss, targeta, ',');

        // Convertir strings a tipos de datos correspondientes

        /*
        int zeA = stoi(zonaestacionA);
        int zeB = stoi(zonaestacionB);
        float d = stof(distancia);
        estas variables no las usamos :D
        */

        float c = stof(costo);

        if (targeta == "MasterCard") {
            sumaMastercard += c;
        }

        if (targeta == "Visa") {
            sumavisa += c;
        }

        if (targeta == "American Express") {
            sumaamericanexpress += c;
        }
        string primeras3 = IDbicicleta.substr(0, 3);

        if (primeras3 == "ELE") {
            sumaEle += c;
        }

        if (primeras3 == "MEC") {
            sumaMec += c;
        }
    }

    archivo.close();
    cout << ROJO <<"======= REPORTE POR TIPO DE BICICLETA =======" << endl<<RESET;
    cout << AZUL <<"Tipo : Electrica -> Monto total : " <<RESET<<VERDE<<"S/"<< sumaEle << endl<<RESET;
    cout << AZUL <<"Tipo : Mecanica  -> Monto total : " <<RESET<<VERDE<<"S/"<< sumaMec << endl<<RESET;
    cout << ROJO << string(45,'=')<<endl<<RESET<<endl;

    cout << ROJO <<"======== REPORTE POR TIPO DE TARJETA ========" << endl<<RESET;
    cout << AZUL <<"American Express -> Monto Total : "<<RESET<<VERDE<<"S/"<<sumaamericanexpress<< endl<<RESET;
    cout << AZUL <<"MasterCard       -> Monto Total : "<<RESET<<VERDE<<"S/"<< sumaMastercard << endl<<RESET;
    cout << AZUL <<"Visa             -> Monto Total : "<<RESET<<VERDE<<"S/"<< sumavisa << endl<<RESET;
    cout << ROJO << string(45,'=')<<endl<<RESET;
}