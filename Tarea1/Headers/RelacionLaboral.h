#ifndef TAREA1_HEADERS_RELACIONLABORAL_H_
#define TAREA1_HEADERS_RELACIONLABORAL_H_

#include "DataTypes/Fecha.h"
#include "Empresa.h"

class RelacionLaboral{
private:
	float sueldo;
	Fecha* fechaDesvinculacion;
	Empresa* Em;

public:
	RelacionLaboral(float,Fecha*,Empresa*);

	float getSueldoLiquido(); //TODO implementar correctamente
	Fecha* getFechaDesvinculacion();
	Empresa* getEm();

	void setEm(Empresa*);
	void setSueldo(float);
	void setFecha(Fecha*);
	~RelacionLaboral();
};



#endif
