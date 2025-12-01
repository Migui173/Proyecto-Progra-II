#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

// Deducción de tipo de bici a partir del ID (MEC... o ELE...)
string tipoBiciDesdeID(const string& idBici) {
    if (idBici.rfind("MEC", 0) == 0) return "Mecanica";
    if (idBici.rfind("ELE", 0) == 0) return "Electrica";
    return "Desconocida";
}

int main() {
    ifstream archivo("transacciones.txt");
    if (!archivo.is_open()) {
        cerr << "[ERROR] No se pudo abrir transacciones.txt para lectura.\n";
        return 1;
    }

    map<string, double> montoPorTipoBici;
    map<string, double> montoPorTarjeta;

    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        // Campos esperados:
        // 0: idUsuario
        // 1: idBicicleta
        // 2: idEstacionA
        // 3: idEstacionB
        // 4: tiempoSeg
        // 5: monto
        // 6: tarjeta (extra)

        string campos[7];
        int idxCampo = 0;
        string actual;
        for (char c : linea) {
            if (c == ',' && idxCampo < 6) {
                campos[idxCampo++] = actual;
                actual.clear();
            } else {
                actual.push_back(c);
            }
        }
        // último campo (tarjeta)
        if (idxCampo <= 6) {
            campos[idxCampo] = actual;
        }

        string idBici   = campos[1];
        string montoStr = campos[5];
        string tarjeta  = campos[6];

        double monto = 0.0;
        try {
            monto = stod(montoStr);
        } catch (...) {
            continue; // si la línea está mal, la saltamos
        }

        // ----- Reporte por tipo de bicicleta -----
        string tipoB = tipoBiciDesdeID(idBici);
        montoPorTipoBici[tipoB] += monto;

        // ----- Reporte por tipo de tarjeta -----
        montoPorTarjeta[tarjeta] += monto;
    }

    archivo.close();

    cout << "\n=== REPORTE POR TIPO DE BICICLETA ===\n";
    for (auto &par : montoPorTipoBici) {
        cout << "Tipo: " << par.first << " -> Monto total: S/" << par.second << endl;
    }

    cout << "\n=== REPORTE POR TIPO DE TARJETA ===\n";
    for (auto &par : montoPorTarjeta) {
        cout << "Tarjeta: " << par.first << " -> Monto total: S/" << par.second << endl;
    }

    return 0;
}