#ifndef DTEXTRANJERA_H
#define	DTEXTRANJERA_H

#include "Direccion.h"
#include "DtEmpresa.h"
#include <string>
using namespace std;

class DtExtranjera : public DtEmpresa {
private:
    string nombreFantasia;

public:
    DtExtranjera(string, Direccion*, string);

    string getNombreFantasia();

    friend ostream& operator<<(ostream&, const DtExtranjera&);

    ~DtExtranjera();
};

#endif