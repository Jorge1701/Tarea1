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
using namespace std;

// Definir variables globales
#define MAX_EMPLEADOS 6
#define MAX_EMPRESAS 3

// Definir arreglos globales
Empleado** empleados;
Empresa** empresas;

// Definir prototipos
void agregarEmpleado(string ci, string nombre, string apellido, Direccion dir);
void agregarEmpresa(DtEmpresa& empresa);

// Main

int main() {
    // Inicializar arreglos globales
    empleados = (Empleado**) malloc(sizeof (Empleado) * MAX_EMPLEADOS);
    empresas = (Empresa**) malloc(sizeof (Empresa) * MAX_EMPRESAS);

    // Colocar todas las posiciones a NULL
    for (int i = 0; i < MAX_EMPLEADOS; i++)
        empleados[i] = NULL;

    for (int i = 0; i < MAX_EMPRESAS; i++)
        empresas[i] = NULL;

    agregarEmpleado("ci", "nombre", "apellido", Direccion("Pais", "Ciudad", "Numero", "Calle"));

    Direccion* d = new Direccion("Uruguay", "Rio Negro", "3541", "Mendoza");
    cout << *d << endl;

    Fecha* f = new Fecha(24, 3, 2017);
    cout << *f << endl;

    cout << "\nNacional:\n";

    DtEmpresa* nac = new DtNacional("id", new Direccion("P", "C", "N", "Call"), "Rut");
    cout << *nac << endl;

    cout << "\nExtranjera:\n";

    DtEmpresa* ext = new DtExtranjera("id2", new Direccion("P2", "C2", "N2", "Call2"), "Nombre Fantasia");
    cout << *ext << endl;
    return 0;
}

// Implementaciones

void agregarEmpleado(string ci, string nombre, string apellido, Direccion dir) {
    int posiciones_libres = 0; // Cuantas posiciones libres (no NULL) hay en el arreglo
    int posicion; // La posicion en la que va a ir el nuevo empleado

    for (int i = MAX_EMPLEADOS - 1; i >= 0; i--) {
        if (empleados[i] != NULL && empleados[i]->getCi() == ci) {
            // Si el empleado no es NULL, me fijo si tiene la misma ci que el nuevo, en cuyo caso tiro excepcion
            // TODO: throw make exception
            cout << "ya existe el empleado";
            return;
        } else {
            // Si el empleado es NULL, aumento las posiciones libres y coloco la posicion actual como posicion para el nuevo empleado
            posiciones_libres++;
            posicion = i;

            /*
             * El colocar la posicion = i cada vez que hay algun empleado NULL, genera que cada nuevo empleado
             * se agregue en la posicion mas cerca del final del arreglo
             */
        }
    }

    if (posiciones_libres == 0) {
        // Si no hay posiciones libres, tiro excepcion
        // TODO: throw make exception
        cout << "no hay mas espacio";
        return;
    } else {
        // Si habia alguna posicion libre, agrego el nuevo empleado en la posicion calculada arriba
        empleados[posicion] = new Empleado(ci, nombre, apellido, &dir);
    }
}

void agregarEmpresa(DtEmpresa& empresa) {
    // Tiene la misma logica que la funcion agregarEmpleado
    // Solo cambia al momento de ingresar la nueva empresa

    int posiciones_libres = 0;
    int posicion;

    for (int i = MAX_EMPRESAS - 1; i >= 0; i--) {
        if (empresas[i] != NULL) {
            if (empresas[i]->getId() == empresa.getId()) {
                // TODO: throw make exception
                cout << "ya existe la empresa";
                return;
            }
        } else {
            posiciones_libres++;
            posicion = i;
        }
    }

    if (posiciones_libres == 0) {
        // TODO: throw make exception
        cout << "no hay mas espacio para empresas";
        return;
    } else {
        // Trato de convertir la empresa en una de tipo DtNacional
        DtNacional* dtNac = dynamic_cast<DtNacional*> (&empresa);

        if (dtNac != NULL) {
            // Si dtNac no es NULL, significa que empresa tenia DtNacional como tipo dinamico
            empresas[posicion] = new Nacional(dtNac->getId(), dtNac->getDireccion(), dtNac->getRut());
        } else {
            DtExtranjera* dtExt = dynamic_cast<DtExtranjera*> (&empresa);

            /* Aqui no se verifica si dtExt es NULL, ya que DtEmpresa solo tiene como derivadas 
             * a DtNacional y DtExtranjera, si no era DtNacional, solo va a poder ser DtExtranjera
             */

            empresas[posicion] = new Extranjera(dtExt->getId(), dtExt->getDireccion(), dtExt->getNombreFantasia());
        }
    }
}
