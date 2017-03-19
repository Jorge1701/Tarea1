#include "../../Headers/DataTypes/Fecha.h"

Fecha::Fecha(int dia, int mes, int anio) {
	if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || anio < 1900) {
		// TODO: Levantar excepion std::invalid_argument
	}

	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

int Fecha::getDia() {
	return dia;
}

int Fecha::getMes() {
	return mes;
}

int Fecha::getAnio() {
	return anio;
}

Fecha::~Fecha() {
}
