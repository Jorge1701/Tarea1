/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../Headers/Empleado.h"

Empleado::Empleado(string ci, string nombre, string apellido, Direccion* direccion){
    this->ci = ci;
    this->nombre = nombre;
    this->apellido = apellido;
    this->direccion = direccion;
    int i;
    for (i=0;i<50;i++)
        this->relaciones[i] = NULL;
            
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
RelacionLaboral** Empleado::getRelaciones(){
    return this->relaciones;
}
void Empleado::addRelacion(RelacionLaboral* rl){
    int i;
    for (i=0;i<50;i++){
        if (this->relaciones[i]==NULL){
            relaciones[i]=rl;
            break;
        }
    }
    if (i==50)
        cout<<"Lista llena"<<endl;
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