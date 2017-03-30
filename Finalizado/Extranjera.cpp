#include "Extranjera.h"

Extranjera::Extranjera(string id, Direccion* direccion, string nombreFantasia) :
Empresa(id, direccion) {
    this->nombreFantasia = nombreFantasia;
}

string Extranjera::getNombreFantasia() {
    return nombreFantasia;
}

float Extranjera::getDescuento() {
    return 0.8;
}

Extranjera::~Extranjera() {
}