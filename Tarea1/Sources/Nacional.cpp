#include "../Header/Nacional.h"

#include <string>
using namespace std;

Nacional::Nacional(string id, Direccion* direccion, string rut) :
		Empresa(id, direccion) {
	this->rut = rut;
}

int Nacional::getRut() {
	return rut;
}

void Nacional::setRut(string rut) {
	this->rut = rut;
}

float Nacional::getDescuento() {
	return 0.65;
}

Nacional::~Nacional() {

}
