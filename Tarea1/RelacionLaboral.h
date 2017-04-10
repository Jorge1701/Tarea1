#ifndef TAREA1_HEADERS_RELACIONLABORAL_H_
#define TAREA1_HEADERS_RELACIONLABORAL_H_

#include "Fecha.h"
#include "Empresa.h"

class RelacionLaboral {
private:
    float sueldo;
    Fecha* fechaDesvinculacion;
    Empresa* empresa;

public:
    RelacionLaboral(float, Fecha*, Empresa*);
    RelacionLaboral();

    float getSueldo();
    Fecha* getFechaDesvinculacion();
    Empresa* getEmpresa();

    void setSueldo(float);
    void setFecha(Fecha*);
    void setEmpresa(Empresa*);

    float getSueldoLiquido();

    ~RelacionLaboral();
};

#endif