#ifndef EMPRESA_H
#define	EMPRESA_H

#include "Direccion.h"
#include <iostream>
#include <string>

using namespace std;

class Empresa {
private:
    string id;
    Direccion* direccion;

public:
    Empresa(string, Direccion*);
    Empresa();

    string getId();
    Direccion* getDireccion();

    void setId(string);
    void setDireccion(Direccion*);

    virtual float getDescuento() = 0;

    virtual ~Empresa();
};

#endif