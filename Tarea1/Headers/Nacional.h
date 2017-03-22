#ifndef NACIONAL_H_
#define NACIONAL_H_

#include "Empresa.h"
#include <string>
using namespace std;

class Nacional: public Empresa {
private:
	string rut;
public:
	Nacional(string, Direccion*, string);

	string getRut();

	void setRut(string);

	float getDescuento();

	~Nacional();
};

#endif
