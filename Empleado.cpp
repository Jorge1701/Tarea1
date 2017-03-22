#include "../Headers/Empleado.h"

Empleado::Empleado(string ci, string nombre, string apellido, Direccion* direccion){
    this->ci = ci;
    this->nombre = nombre;
    this->apellido = apellido;
    this->direccion = direccion;
}
string Empleado::getCi(){
    return ci;
}
string Empleado::getNombre(){
    return nombre;
}
string Empleado::getApellido(){
    return apellido;
}
Direccion* Empleado::getDireccion(){
    return  direccion;
}



void Empleado::setCi(string ci){
    this->ci= ci;
}
void Empleado::setNombre(string nombre){
    this->nombre= nombre;
}
void Empleado::setApellido(string apellido){
    this->apellido= apellido;
}
void Empleado::setDireccion(Direccion* direccion){
    this->direccion= direccion;
}

Empleado::~Empleado() {
    delete direccion;
    
}
    
            
            
            
            
    
    
    
    