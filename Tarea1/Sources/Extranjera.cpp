#ifndef DATATYPES_EXTRANJERA_CPP_
#define DATATYPES_EXTRANJERA_CPP_
#include "Extranjera.h"

Extranjera::Extranjera(string id,Direccion *direccion,string nombreFantasia) :
Empresa(id, direccion) {
	this->nombreFantasia = nombreFantasia;
}

string Extranjera::getNombreFantasia() {
	return nombreFantasia;
}

float getDescuento(){
	return 0.8;
}

void Extranjera::setNombreFantasia(string nombre){
	this->nombreFantasia=nombre;
}

Extranjera::~Extranjera() {

}
#endif 
