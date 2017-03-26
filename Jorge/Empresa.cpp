#include "Empresa.h"

Empresa::Empresa(string id, Direccion* dir) {
    this->id = id;
    this->direccion = dir;
}

Empresa::Empresa() {
    this->id = "no disponible";
    this->direccion = NULL;
}

Direccion* Empresa::getDireccion() {
    return direccion;
}

string Empresa::getId() {
    return id;
}

void Empresa::setDireccion(Direccion* dir) {
    this->direccion = dir;
}

void Empresa::setId(string i) {
    this->id = i;
}

Empresa::~Empresa() {
    delete direccion;
}