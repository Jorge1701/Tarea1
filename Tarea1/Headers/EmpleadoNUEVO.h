/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Empleado.h
 * Author: Axel
 *
 * Created on 22 de marzo de 2017, 17:39
 */

#ifndef EMPLEADO_H
#define EMPLEADO_H
#include<iostream>
#include <string>
#include "../Headers/DataTypes/Direccion.h"
#include "RelacionLaboral.h"
using namespace std;

class Empleado{
private: 
    string ci;
    string nombre;
    string apellido;
    Direccion* direccion;
    RelacionLaboral* relaciones[50];
public:
    Empleado(string, string, string, Direccion* );
    
    string getCi();
    string getNombre();
    string getApellido();
    Direccion* getDireccion();
    RelacionLaboral** getRelaciones();
    
    void setCi(string);
    void setNombre(string);
    void setApellido(string);
    void setDireccion(Direccion*);
    void addRelacion(RelacionLaboral*);
    
    ~Empleado();
};
#endif /* EMPLEADO_H */
