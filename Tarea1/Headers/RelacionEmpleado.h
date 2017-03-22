#ifndef TAREA1_HEADERS_RELACIONEMPLEADO_H_
#define TAREA1_HEADERS_RELACIONEMPLEADO_H_

#include "DataTypes/Fecha.h"

class RelacionEmpleado{
private:
	float sueldo;
	Fecha *fechaDesvinculacion;
public:
	RelacionEmpleado(float,Fecha *);

	float getSueldoLiquido(); //TODO implementar correctamente
	Fecha *getFechaDesvinculacion();

	~RelacionEmpleado();
};



#endif
