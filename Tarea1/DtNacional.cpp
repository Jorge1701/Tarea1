#include "DtNacional.h"

DtNacional::DtNacional(string id, Direccion* direccion, string rut) :
DtEmpresa(id, direccion) {
    this->rut = rut;
}

string DtNacional::getRut() {
    return rut;
}

DtNacional::~DtNacional() {
}

ostream& operator<<(ostream& os, const DtNacional& nacional) {
    os << "RUT: " << nacional.rut << endl;
    return os;
}