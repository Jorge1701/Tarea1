#ifndef DIRECCION_H_
#define DIRECCION_H_

#include <string>
using namespace std;

class Direccion {
private:
	string pais;
	string ciudad;
	string numero;
	string calle;
public:
	Direccion(string, string, string, string);

	string getPais();
	string getCiudad();
	string getNumero();
	string getCalle();

	~Direccion();
};

#endif
