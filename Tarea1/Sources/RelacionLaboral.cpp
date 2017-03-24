#include "../Headers/RelacionLaboral.h"
#include "../Headers/Nacional.h"
#include "../Headers/Extranjera.h"
#include "../Headers/Empresa.h"

RelacionLaboral::RelacionLaboral(float sueldo,Fecha* fecha,Empresa* Em){
	this->sueldo=sueldo;
	this->fechaDesvinculacion=fecha;
	this->Em=Em;
}
RelacionLaboral::RelacionLaboral(){
    this->sueldo=0;
    this->fechaDesvinculacion=NULL;
    this->Em=NULL;
} 

float RelacionLaboral::getSueldo(){
	return sueldo;
}
Fecha* RelacionLaboral::getFechaDesvinculacion(){
	return  fechaDesvinculacion;
}
Empresa* RelacionLaboral::getEm(){
	return Em;
}

float RelacionLaboral::getSueldoLiquido(){
    float sueldoLiquido;
    sueldoLiquido=this->sueldo * Em->getDescuento();
    return sueldoLiquido;
}

void RelacionLaboral::setSueldo(float sueldo){
	this->sueldo=sueldo;
}
void RelacionLaboral::setFecha(Fecha* fechaDesvinculacion){
	this->fechaDesvinculacion= fechaDesvinculacion;
}
void RelacionLaboral::setEm(Empresa* Em){
	this->Em=Em;
}
RelacionLaboral ::~RelacionLaboral(){
delete fechaDesvinculacion;
}



