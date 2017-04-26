#include "DtEmpleado.h"

DtEmpleado::DtEmpleado(string ci, string nombre, string apellido, Direccion* direccion, float sueldoLiquido) {
    this->ci = ci;
    this->nombre = nombre;
    this->apellido = apellido;
    this->direccion = direccion;
    this->sueldoLiquido = sueldoLiquido;
}

string DtEmpleado::getCi() {
    return ci;
}

string DtEmpleado::getNombre() {
    return nombre;
}

string DtEmpleado::getApellido() {
    return apellido;
}

Direccion* DtEmpleado::getDireccion() {
    return direccion;
}

float DtEmpleado::getSueldoLiquido() {
    return sueldoLiquido;
}

DtEmpleado::~DtEmpleado() {
    delete direccion;
}