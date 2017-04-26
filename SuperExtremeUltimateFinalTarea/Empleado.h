#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Direccion.h"
#include "DtEmpresa.h"
#include "RelacionLaboral.h"
#include <string>
using namespace std;

class Empleado {
private:
    string ci;
    string nombre;
    string apellido;
    Direccion* direccion;
    RelacionLaboral* relaciones[50];

public:
    Empleado(string, string, string, Direccion*);

    string getCi();
    string getNombre();
    string getApellido();
    Direccion* getDireccion();

    void setCi(string);
    void setNombre(string);
    void setApellido(string);
    void setDireccion(Direccion*);

    void addRelacion(Empresa*, float);
    void finalizarRelacion(string, Fecha);
    int sueldoLiquidoTotal();
    DtEmpresa** getInfoEmpresas(int &);

    ~Empleado();
};

#endif