#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream archivo;
    archivo.open("transacciones.txt");

    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo transacciones.txt" << endl;
        return 0;
    }

    string linea;
    double sumaMec = 0.0;
    double sumaEle = 0.0;
    double sumaMastercard = 0.0;
    double sumavisa = 0.0;
    double sumaamericanexpress = 0.0;

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

    cout << "================================================================" << endl;
    cout << "el precio total para las bicicletas electricas: " << sumaEle << endl;
    cout << "el precio total para las bicicletas mecanicas: " << sumaMec << endl;
    cout << "el precio total por el uso de MasterCard: "<< sumaMastercard << endl;
    cout << "el precio total por el uso de Visa: "<< sumavisa << endl;
    cout << "el precio total por el uso de American Express: "<< sumaamericanexpress<< endl;
    cout << "================================================================" << endl;
}