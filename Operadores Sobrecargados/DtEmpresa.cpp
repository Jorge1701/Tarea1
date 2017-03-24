#include "DtEmpresa.h"
#include "DtNacional.h"
#include "DtExtranjera.h"

DtEmpresa::DtEmpresa(string id, Direccion* direccion) {
    this->id = id;
    this->direccion = direccion;
}

string DtEmpresa::getId() {
    return id;
}

Direccion* DtEmpresa::getDireccion() {
    return direccion;
}

DtEmpresa::~DtEmpresa() {
    delete direccion;
}

ostream& operator<<(ostream& os, const DtEmpresa& emp) {
    os << "Id Empresa: " << emp.id << endl;
    os << "Direccion: " << *emp.direccion << endl;

    const DtNacional* dtNac = dynamic_cast<const DtNacional*> (&emp);

    if (dtNac) {
        os << *dtNac;
    } else {
        const DtExtranjera* dtExt = dynamic_cast<const DtExtranjera*> (&emp);
        os << *dtExt;
    }

    return os;
}