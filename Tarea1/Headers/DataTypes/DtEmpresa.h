#ifndef DTEMPRESA_H_
#define DTEMPRESA_H_

#include "Direccion.h"
#include <string>
using namespace std;

class DtEmpresa {
private:
	string id;
	Direccion* direccion;
public:
	DtEmpresa(string, Direccion*);

	virtual string getId();
	virtual Direccion* getDireccion();

	virtual ~DtEmpresa();
};

#endif
