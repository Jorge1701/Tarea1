#ifndef DTEMPRESA_H
#define	DTEMPRESA_H

#include "Direccion.h"
#include <string>
#include <iostream>  
using namespace std;

class DtEmpresa {
protected:
    string id;
    Direccion* direccion;

public:
    DtEmpresa(string, Direccion*);

    virtual string getId();
    virtual Direccion* getDireccion();

    virtual ~DtEmpresa();

    friend ostream& operator<<(ostream&, const DtEmpresa&);
};

#endif