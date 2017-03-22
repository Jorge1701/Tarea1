#include "../Headers/RelacionEmpleado.h"


	RelacionEmpleado::RelacionEmpleado(float sueldo,Fecha * fecha){
	this->sueldo=sueldo;
	this->fechaDesvinculacion=fecha;
	}

	float RelacionEmpleado::getSueldoLiquido(){
	return sueldo;
	}
	Fecha RelacionEmpleado::*getFechaDesvinculacion(){
	return *Fecha;
	}
	RelacionEmpleado ::~RelacionEmpleado(){}



