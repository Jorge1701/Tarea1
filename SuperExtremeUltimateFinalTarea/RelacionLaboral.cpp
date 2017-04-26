#include "RelacionLaboral.h"

RelacionLaboral::RelacionLaboral(float sueldo, Fecha* fecha, Empresa* empresa) {
    this->sueldo = sueldo;
    this->fechaDesvinculacion = fecha;
    this->empresa = empresa;
}

RelacionLaboral::RelacionLaboral() {
    this->sueldo = 0;
    this->fechaDesvinculacion = NULL;
    this->empresa = NULL;
}

float RelacionLaboral::getSueldo() {
    return sueldo;
}

Fecha* RelacionLaboral::getFechaDesvinculacion() {
    return fechaDesvinculacion;
}

Empresa* RelacionLaboral::getEmpresa() {
    return empresa;
}

float RelacionLaboral::getSueldoLiquido() {
    float sueldoLiquido;
    sueldoLiquido = this->sueldo * empresa->getDescuento();
    return sueldoLiquido;
}

void RelacionLaboral::setSueldo(float sueldo) {
    this->sueldo = sueldo;
}

void RelacionLaboral::setFecha(Fecha* fechaDesvinculacion) {
    this->fechaDesvinculacion = fechaDesvinculacion;
}

void RelacionLaboral::setEmpresa(Empresa* empresa) {
    this->empresa = empresa;
}

RelacionLaboral::~RelacionLaboral() {
    delete fechaDesvinculacion;
}