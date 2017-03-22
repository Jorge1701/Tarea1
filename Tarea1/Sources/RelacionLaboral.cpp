#include "../Headers/RelacionLaboral.h"


RelacionLaboral::RelacionLaboral(float sueldo,Fecha* fecha,Empresa* Em){
	this->sueldo=sueldo;
	this->fechaDesvinculacion=fecha;
	this->Em=Em;
}

float RelacionLaboral::getSueldoLiquido(){
	return sueldo;
}
Fecha RelacionLaboral::*getFechaDesvinculacion(){
	return *Fecha;
}
Empresa* RelacionLaboral::getEm(){
	return *Em;
}


void RelacionLaboral::setSueldo(float sueldo){
	this->sueldo=sueldo;
}
void RelacionLaboral::setFecha(Fecha *fechaDesvinculacion){
	this->*fechaDesvinculacion= *fechaDesvinculacion;
}
void RelacionLaboral::setEm(Empresa* Em){
	this->Em=Em;
}
RelacionLaboral ::~RelacionLaboral(){}



