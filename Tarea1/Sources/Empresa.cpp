/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "../Headers/Empresa.h"

Empresa::Empresa(string id, Direccion* dir){
    this->id=id;
    this->direccion=dir;
}
Empresa::Empresa(){
    this->id="no disponible";
    this->direccion=NULL;
}
Direccion* Empresa::GetDireccion(){
    return direccion;
}
string Empresa::GetId(){
    return id;
}
void Empresa::setDireccion(Direccion* dir){
    this->direccion=dir;
}
void Empresa::setId(string i){
    this->id=i;
}
Empresa::~Empresa(){
    delete direccion;
}