#include "../../Headers/DataTypes/DtEmpresa.h"

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
