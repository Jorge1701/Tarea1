#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include "DataTypes/Direccion.h"
using namespace std;

class Empleado{
private: 
    string ci;
    string nombre;
    string apellido;
    Direccion* direccion;
public:
    Empleado(string, string, string, Direccion* );
    
    string getCi();
    string getNombre();
    string getApellido();
    Direccion* getDireccion();
    
    void setCi(string);
    void setNombre(string);
    void setApellido(string);
    void setDireccion(Direccion*);
    
    ~Empleado();
};
    
    
     


#endif /* EMPLEADO_H */

