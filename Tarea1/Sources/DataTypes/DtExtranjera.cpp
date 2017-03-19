#include "../../Headers/DataTypes/DtExtranjera.h"

DtExtranjera::DtExtranjera(string id, Direccion* direccion, string nombreFantasia) :
		DtEmpresa(id, direccion) {
	this->nombreFantasia = nombreFantasia;
}

string DtExtranjera::getNombreFantasia() {
	return nombreFantasia;
}

DtExtranjera::~DtExtranjera() {

}
