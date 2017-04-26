#include "Direccion.h"

Direccion::Direccion(string pais, string ciudad, string numero, string calle) {
    this->pais = pais;
    this->ciudad = ciudad;
    this->numero = numero;
    this->calle = calle;
}

string Direccion::getPais() {
    return pais;
}

string Direccion::getCiudad() {
    return ciudad;
}

string Direccion::getNumero() {
    return numero;
}

string Direccion::getCalle() {
    return calle;
}

Direccion::~Direccion() {
}

ostream& operator<<(ostream& os, const Direccion& direccion) {
    os << direccion.pais << ", " << direccion.ciudad << ", " << direccion.calle << " " << direccion.numero;
    return os;
}