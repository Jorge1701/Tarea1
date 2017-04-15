#include "Direccion.h"
#include "DtEmpleado.h"
#include "DtEmpresa.h"
#include "DtExtranjera.h"
#include "DtNacional.h"
#include "Empleado.h"
#include "Empresa.h"
#include "Extranjera.h"
#include "Fecha.h"
#include "Nacional.h"
#include "RelacionLaboral.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdexcept>

using namespace std;

/*VARIABLES GLOBALES*/
#define MAX_EMPLEADOS 50
#define MAX_EMPRESAS 50
#define MAX_RELACIONES 50

/*ARREGLOS GLOBALES*/
Empleado** empleados;
Empresa** empresas;
int cantEmpleados;
int cantEmpresas;

/*ENCABEZADOS DE FUNCIONES*/
void agregarEmpleado(string ci, string nombre, string apellido, Direccion dir);
void agregarEmpresa(DtEmpresa& empresa);
DtEmpleado** listarEmpleados(int& cantEmpleados);
void agregarRelacionLaboral(string ciEmpleado, string idEmpresa, float sueldo);
void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculacion);
DtEmpresa** obtenerInfoEmpresaPorEmpleado(string ciEmpleado, int& cantEmpresas);

/*ENCABEZADOS EXTRAS*/
Direccion* generarDireccion();
Fecha* generarFecha();


int main() {
    
    empleados = (Empleado**) malloc(sizeof (Empleado) * MAX_EMPLEADOS);
    empresas = (Empresa**) malloc(sizeof (Empresa) * MAX_EMPRESAS);
    
    for (int i = 0; i < MAX_EMPLEADOS; i++)
    empleados[i] = NULL;
    
    for (int i = 0; i < MAX_EMPRESAS; i++)
    empresas[i] = NULL;
    
    int opcion = 0;
    
    do {
        cout << "===== Menu ===========================" << endl;
        cout << "   1) Agregar Empleado" << endl;
        cout << "   2) Agregar Empresa" << endl;
        cout << "   3) Listar Empleados" << endl;
        cout << "   4) Agregar Relacion Laboral" << endl;
        cout << "   5) Finalizar Relacion Laboral" << endl;
        cout << "   6) Obtener Informacion Empresa" << endl;
        cout << "   0) Salir" << endl;
        
        cout << endl << "opcion: ";
        cin >> opcion;
      
        string ci, nombre, apellido;
  
        string id, rut, nombreFantasia;
       
        string ciEmpleado, idEmpresa;
        int sueldo;
       
        int tipoEmpresa = 0;
        DtEmpleado** dtEmpleados;
        DtEmpresa** dtEmpresas;
       	
	cin.clear();
      	fflush(stdin);
        
        switch (opcion) {
            case 1:
            cout << "===== Agregar Empleado ===============" << endl;
            cout << "CI: ";
            getline(cin, ci);
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Apellido: ";
            getline(cin, apellido);
            
            try {
                agregarEmpleado(ci, nombre, apellido, *generarDireccion());
                } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            
            break;
            case 2:
            cout << "===== Agregar Empresa ================" << endl;
            cout << "   1) Nacional" << endl;
            cout << "   2) Extranjera" << endl;
            cout << "   0) Cancelar" << endl;
            
            cout << endl << "opcion: ";
            cin >> tipoEmpresa;
            
            if (tipoEmpresa == 0)
            break;
            
            cin.clear();
            fflush(stdin);
            
            cout << "ID: ";
            getline(cin, id);
            
            try {
                if (tipoEmpresa == 1) {
                    cout << "RUT: ";
                    getline(cin, rut);
                    
                    agregarEmpresa(*(new DtNacional(id, generarDireccion(), rut)));
                    } else {
                    cout << "Nombre Fantasia: ";
                    getline(cin, nombreFantasia);
                    agregarEmpresa(*(new DtExtranjera(id, generarDireccion(), nombreFantasia)));
                }
                } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
            case 3:
            cout << "===== Listar Empleados ===============" << endl;
            
            dtEmpleados = listarEmpleados(cantEmpleados);
            
            for (int i = 0; i < cantEmpleados; i++) {
                cout << "----------" << endl;
                cout << "CI: " << dtEmpleados[i]->getCi() << endl;
                cout << "Nombre: " << dtEmpleados[i]->getNombre() << endl;
                cout << "Apellido: " << dtEmpleados[i]->getApellido() << endl;
                cout << "Direccion: " << *dtEmpleados[i]->getDireccion() << endl;
                cout << "Sueldo Liquido: " << dtEmpleados[i]->getSueldoLiquido() << endl;
            }
            break;
            case 4:
            cout << "===== Agregar Relacion Laboral =======" << endl;
            cout << "CI Empleado: ";
            getline(cin, ciEmpleado);
            cout << "ID Empresa: ";
            getline(cin, idEmpresa);
            cout << "Sueldo: ";
            cin >> sueldo;
            
            try {
                agregarRelacionLaboral(ciEmpleado, idEmpresa, sueldo);
                } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
            case 5:
            cout << "===== Finalizar Relacion Laboral =====" << endl;
            cout << "CI Empleado: ";
            getline(cin, ciEmpleado);
            cout << "ID Empresa: ";
            getline(cin, idEmpresa);
            try{
                finalizarRelacionLaboral(ciEmpleado, idEmpresa, *generarFecha());
                } catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
            case 6:
            cout << "===== Obtener Informacion Empresa ====" << endl;
            cout << "CI Empleado: ";
            getline(cin, ci);
            dtEmpresas = obtenerInfoEmpresaPorEmpleado(ci, cantEmpresas);
            
            for (int i = 0; i < cantEmpresas; i++) {
                cout << "----------" << endl;
                cout << *dtEmpresas[i] << endl;
            }
            break;
        }
    } while (opcion != 0);
    
    return 0;
}

void agregarEmpleado(string ci, string nombre, string apellido, Direccion dir) {
    int posiciones_libres = 0;
    int posicion;
    
    for (int i = MAX_EMPLEADOS - 1; i >= 0; i--)
    if (empleados[i] != NULL && empleados[i]->getCi() == ci) {
        throw invalid_argument("Empleado ya existe");
        } else if (empleados[i] == NULL) {
        posiciones_libres++;
        posicion = i;
    }
    
    if (posiciones_libres == 0) {
        throw invalid_argument("No hay mas espacio para empleados");
        } else {
        empleados[posicion] = new Empleado(ci, nombre, apellido, new Direccion(dir.getPais(),dir.getCiudad(),dir.getNumero(),dir.getCalle()));
    }
}

void agregarEmpresa(DtEmpresa& empresa) {
    int posiciones_libres = 0;
    int posicion;
    
    for (int i = MAX_EMPRESAS - 1; i >= 0; i--)
    if (empresas[i] != NULL) {
        if (empresas[i]->getId() == empresa.getId()) {
            throw invalid_argument("Esa empresa ya existe");
        }
        } else {
        posiciones_libres++;
        posicion = i;
    }
    
    if (posiciones_libres == 0) {
        throw invalid_argument("No hay espacio para empresas");
        } else {
        DtNacional* dtNac = dynamic_cast<DtNacional*> (&empresa);
        
        if (dtNac != NULL) {
            empresas[posicion] = new Nacional(dtNac->getId(), dtNac->getDireccion(), dtNac->getRut());
            } else {
            DtExtranjera* dtExt = dynamic_cast<DtExtranjera*> (&empresa);
            empresas[posicion] = new Extranjera(dtExt->getId(), dtExt->getDireccion(), dtExt->getNombreFantasia());
        }
    }
}

void agregarRelacionLaboral(string ciEmpleado, string idEmpresa, float sueldo) {
    Empresa* empresa = NULL;
    Empleado* empleado = NULL;
   
    for (int i = 0; i < MAX_EMPRESAS; i++)
    if (empresas[i] != NULL && empresas[i]->getId() == idEmpresa) {
        empresa = empresas[i];
        break;
    }
   
    if (empresa == NULL)
    throw invalid_argument("Empresa no existe");
   
    for (int i = 0; i < MAX_EMPLEADOS; i++)
    if (empleados[i] != NULL && empleados[i]->getCi() == ciEmpleado) {
        empleado = empleados[i];
        break;
    }
    
    if (empleado == NULL)
    throw invalid_argument("Empleado no existe");
    
    RelacionLaboral** relaciones = empleado->getRelaciones();
    
    for (int i = 0; i < MAX_RELACIONES; i++)
    if (relaciones[i] != NULL && relaciones[i]->getEmpresa()->getId() == idEmpresa)
    throw invalid_argument("Relacion ya existe");
    
    empleado->addRelacion(new RelacionLaboral(sueldo, NULL, empresa));
}

DtEmpleado** listarEmpleados(int& cantEmpleados) {
    cantEmpleados = 0;
    
    for (int i = 0; i < MAX_EMPLEADOS; i++)
    if (empleados[i] != NULL)
    cantEmpleados++;
   
    DtEmpleado** resultado = (DtEmpleado**) malloc(sizeof (DtEmpleado) * cantEmpleados);
   
    for (int i = 0; i < MAX_EMPLEADOS; i++)
    if (empleados[i] != NULL) {
        Empleado* e = empleados[i];
        int sueldoLiquidoTotal = 0;
        RelacionLaboral** r = e->getRelaciones();
        
        for (int j = 0; j < MAX_RELACIONES; j++)
        if (r[j] != NULL && r[j]->getFechaDesvinculacion() == NULL)
        sueldoLiquidoTotal += r[j]->getSueldoLiquido();
        resultado[i] = new DtEmpleado(e->getCi(), e->getNombre(), e->getApellido(), e->getDireccion(), sueldoLiquidoTotal);
    }
    
    return resultado;
}

void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculacion) {
    Empleado* empleado = NULL;
   
    for (int i = 0; i < MAX_EMPLEADOS; i++)
    if (empleados[i] != NULL && empleados[i]->getCi() == ciEmpleado) {
        empleado = empleados[i];
        break;
    }
    
    if (empleado == NULL)
    throw invalid_argument("Empleado no existe");
    
    RelacionLaboral** relaciones = empleado->getRelaciones();
    
    for (int i = 0; i < MAX_RELACIONES; i++)
    if (relaciones[i] != NULL && relaciones[i]->getEmpresa()->getId() == idEmpresa) {
        if (relaciones[i]->getFechaDesvinculacion() != NULL)
        throw invalid_argument("La Relacion Ya Esta Finalizada");
        else
        relaciones[i]->setFecha(&desvinculacion);
        
        return;
    }
    throw invalid_argument("Relacion no existe");
}

DtEmpresa** obtenerInfoEmpresaPorEmpleado(string ciEmpleado, int& cantEmpresas) {
    cantEmpresas = 0;
    Empleado* e = NULL;
    
    for (int i = 0; i < MAX_EMPLEADOS; i++)
    if (empleados[i] != NULL && empleados[i]->getCi() == ciEmpleado)
    e = empleados[i];
    
    if (e == NULL)
    throw invalid_argument("Empleado no existe");
    
    RelacionLaboral** relaciones = e->getRelaciones();
    
    for (int i = 0; i < MAX_RELACIONES; i++)
    if (relaciones[i] != NULL && relaciones[i]->getFechaDesvinculacion() == NULL)
    cantEmpresas++;
    
    DtEmpresa** resultado = (DtEmpresa**) malloc(sizeof (DtEmpresa) * cantEmpresas);
    
    int pos = 0;
    for (int i = 0; i < MAX_RELACIONES; i++)
    if (relaciones[i] != NULL && relaciones[i]->getFechaDesvinculacion() == NULL) {
        Nacional* nacional = dynamic_cast<Nacional*> (relaciones[i]->getEmpresa());
        
        if (nacional != NULL) {
            resultado[pos] = new DtNacional(nacional->getId(), nacional->getDireccion(), nacional->getRut());
            } else {
            Extranjera* extranjera = dynamic_cast<Extranjera*> (relaciones[i]->getEmpresa());
            resultado[pos] = new DtExtranjera(extranjera->getId(), extranjera->getDireccion(), extranjera->getNombreFantasia());
        }
        
        pos++;
    }
    
    return resultado;
}

Direccion * generarDireccion() {
    string pais, ciudad, numero, calle;
    
    cout << "Direccion" << endl;
    cout << "Pais: ";
    getline(cin, pais);
    cout << "Ciudad: ";
    getline(cin, ciudad);
    cout << "Calle: ";
    getline(cin, calle);
    cout << "Numero: ";
    getline(cin, numero);
    
    return new Direccion(pais, ciudad, numero, calle);
}

Fecha * generarFecha() {
    Fecha* f;
    bool fechaInvalida = false;
    int dia, mes, anio;
    
    do {
        fechaInvalida = false;
        
        cout << "Fecha" << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Año: ";
        cin >> anio;
        
        try {
            f = new Fecha(dia, mes, anio);
            } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
            fechaInvalida = true;
        }
    } while (fechaInvalida);
    
    return f;
}