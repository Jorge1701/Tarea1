#include "DtExtranjera.h"

DtExtranjera::DtExtranjera(string id, Direccion* direccion, string nombreFantasia) :
DtEmpresa(id, direccion) {
    this->nombreFantasia = nombreFantasia;
}

string DtExtranjera::getNombreFantasia() {
    return nombreFantasia;
}

DtExtranjera::~DtExtranjera() {
}

ostream& operator<<(ostream& os, const DtExtranjera& extranjera) {
    os << "Nombre Fantasia: " << extranjera.nombreFantasia << endl;
    return os;
}