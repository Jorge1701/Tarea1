#ifndef DIRECCION_H
#define	DIRECCION_H

#include <string>
#include <iostream>
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

    friend ostream& operator<<(ostream&, const Direccion&);

    ~Direccion();
};

#endif