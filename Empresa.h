/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empresa.h
 * Author: Axel
 *
 * Created on 21 de marzo de 2017, 17:30
 */

#ifndef EMPRESA_H
#define EMPRESA_H
#include <iostream>
#include <string>
#include "../Headers/Datatypes/Direccion.h"

using namespace std;

class Empresa {
private:
    string id;
    Direccion* direccion;
public:
    Empresa(string,Direccion*);
    Empresa();
    string GetId();
    Direccion* GetDireccion();
    void setId(string);
    void setDireccion(Direccion*);
    virtual float getDescuento()=0;
    ~Empresa();
        
};



#endif /* EMPRESA_H */

