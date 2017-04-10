#ifndef NACIONAL_H
#define	NACIONAL_H

#include "Empresa.h"
#include <string>
using namespace std;

class Nacional : public Empresa {
private:
    string rut;

public:
    Nacional(string, Direccion*, string);

    string getRut();

    void setRut(string);

    float getDescuento();

    ~Nacional();
};

#endif