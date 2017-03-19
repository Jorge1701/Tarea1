#include "../../Headers/DataTypes/DtNacional.h"

DtNacional::DtNacional(string id, Direccion* direccion, string rut) :
		DtEmpresa(id, direccion) {
	this->rut = rut;
}

string DtNacional::getRut() {
	return rut;
}

DtNacional::~DtNacional() {

}
