#ifndef DTEXTRANJERA_H_
#define DTEXTRANJERA_H_

#include "DtEmpresa.h"
#include <string>
using namespace std;

class DtExtranjera: public DtEmpresa {
private:
	string nombreFantasia;
public:
	DtExtranjera(string, Direccion*, string);

	string getNombreFantasia();

	~DtExtranjera();
};

#endif
