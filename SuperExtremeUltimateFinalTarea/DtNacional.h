#ifndef DTNACIONAL_H
#define DTNACIONAL_H

#include "Direccion.h"
#include "DtEmpresa.h"
#include <string>
using namespace std;

class DtNacional : public DtEmpresa {
private:
    string rut;

public:
    DtNacional(string, Direccion*, string);

    string getRut();

    friend ostream& operator<<(ostream&, const DtNacional&);

    ~DtNacional();
};

#endif