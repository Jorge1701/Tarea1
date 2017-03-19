#ifndef DTNACIONAL_H_
#define DTNACIONAL_H_

#include "DtEmpresa.h"
#include <string>
using namespace std;

class DtNacional: public DtEmpresa {
private:
	string rut;
public:
	DtNacional(string, Direccion*, string);

	string getRut();

	~DtNacional();
};

#endif
