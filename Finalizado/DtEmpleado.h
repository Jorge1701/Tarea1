#ifndef DTEMPLEADO_H
#define	DTEMPLEADO_H

#include "Direccion.h"
#include <string>
using namespace std;

class DtEmpleado {
private:
    string ci;
    string nombre;
    string apellido;
    Direccion* direccion;
    float sueldoLiquido;

public:
    DtEmpleado(string, string, string, Direccion*, float);

    string getCi();
    string getNombre();
    string getApellido();
    Direccion* getDireccion();
    float getSueldoLiquido();

    ~DtEmpleado();
};

#endif