#ifndef PROYECTOPROGRA_USUARIO_H
#define PROYECTOPROGRA_USUARIO_H
#include <string>
using namespace  std;

class Usuario {
private:
    string Nombre;
    string ID;
    string Apellido;
    string DNI;
    string TarjetaPago;
    bool EsVecino;
    int Zona;
public:
    Usuario(string _name, string _ape);
    Usuario(string _Nombre, string _ID, string _Apellido,
    string _DNI, string _TarjetaPago, bool _EsVecino, int _zona);

    //Getters
    string getNombre();
    string getID();
    string getApellido();
    string getDNI();
    string getTarjetaPago();
    bool getEsVecino();
    int getZona();

    //Setters
    void setNombre(string nombre);
    void setID(string id);
    void setApellido(string apellido);
    void setDNI(string dni);
    void setTarjetaPago(string _TarjetaPago);
    void setEsVecino(bool esvecino);
    void setZona(int zona);

    //Mostrar informacion
    void imp();
};
#endif //PROYECTOPROGRA_USUARIO_H