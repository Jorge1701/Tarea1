#ifndef EXTRANJERA_H
#define	EXTRANJERA_H

#include "Empresa.h"
#include <string>
using namespace std;

class Extranjera : public Empresa {
private:
    string nombreFantasia;

public:
    Extranjera(string, Direccion*, string);

    string getNombreFantasia();

    void setNombreFantasia(string);

    float getDescuento();

    ~Extranjera();
};

#endif