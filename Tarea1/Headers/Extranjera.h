#ifndef DATATYPES_EXTRANJERA_H_
#define DATATYPES_EXTRANJERA_H_

#include "Empresa.h"
#include <string>
using namespace std;

class Extranjera: public Empresa {
private:
	string nombreFantasia;
public:

	Extranjera(string, Direccion*, string);

	string getNombreFantasia();

	float getDescuento();

	void setNombreFantasia(string);

	~Extranjera();
};


#endif
