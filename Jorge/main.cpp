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

#include <string>
#include <iostream>
#include <stdexcept>
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
void agregarRelacionLaboral(string ciEmpleado, string idEmpresa, float sueldo);
void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculacion);

// Main

void a() {
    RelacionLaboral** r1 = empleados[0]->getRelaciones();
    cout << "\nEmpleado: " << empleados[0]->getCi() << endl;
    for (int i = 0; i < 10; i++) {
        if (r1[i] != NULL) {
            cout << "Id: " << r1[i]->getEmpresa()->getId() << endl;
            cout << "Sueldo: " << r1[i]->getSueldoLiquido() << endl;
            cout << "Fecha: ";
            Fecha* f = r1[i]->getFechaDesvinculacion();
            if (f == NULL)
                cout << "NULL";
            else
                cout << *f;
            cout << endl;
        }
    }

    RelacionLaboral** r2 = empleados[1]->getRelaciones();
    cout << "\nEmpleado: " << empleados[1]->getCi() << endl;
    for (int i = 0; i < 10; i++) {
        if (r2[i] != NULL) {
            cout << "Id: " << r2[i]->getEmpresa()->getId() << endl;
            cout << "Sueldo: " << r2[i]->getSueldoLiquido() << endl;
            cout << "Fecha: ";
            Fecha* f = r2[i]->getFechaDesvinculacion();
            if (f == NULL)
                cout << "NULL";
            else
                cout << *f;
            cout << endl;
        }
    }
}

int main() {
    // Inicializar arreglos globales
    empleados = (Empleado**) malloc(sizeof (Empleado) * MAX_EMPLEADOS);
    empresas = (Empresa**) malloc(sizeof (Empresa) * MAX_EMPRESAS);

    // Colocar todas las posiciones a NULL
    for (int i = 0; i < MAX_EMPLEADOS; i++)
        empleados[i] = NULL;

    for (int i = 0; i < MAX_EMPRESAS; i++)
        empresas[i] = NULL;

    try {
        agregarEmpleado("123", "Nombre1", "Apellidp1", Direccion("Pais1", "Ciudad1", "Numero1", "Calle1"));
    } catch (invalid_argument e) {
        cout << "Existe-A\n";
    }
    try {
        agregarEmpleado("234", "Nombre2", "Apellidp2", Direccion("Pais2", "Ciudad2", "Numero2", "Calle2"));
    } catch (invalid_argument e) {
        cout << "Exi-B\n";
    }

    for (int i = 0; i < MAX_EMPLEADOS; i++) {
        if (empleados[i] != NULL) {
            cout << i << " existe" << endl;
        }
    }

    agregarEmpresa(*(new DtNacional("987", new Direccion("Pais3", "Ciudad3", "Numero3", "Calle3"), "Rut1")));
    agregarEmpresa(*(new DtExtranjera("876", new Direccion("Pais4", "Ciudad4", "Numero4", "Calle4"), "NombreFantasia1")));
    agregarEmpresa(*(new DtNacional("765", new Direccion("Pais5", "Ciudad5", "Numero5", "Calle5"), "Rut2")));

    try {
        agregarRelacionLaboral("234", "987", 1000);
    } catch (invalid_argument e) {
        cout << "A\n";
    }
    try {
        agregarRelacionLaboral("234", "876", 1000);
    } catch (invalid_argument e) {
        cout << "B\n";
    }
    try {
        agregarRelacionLaboral("123", "876", 1000);
    } catch (invalid_argument e) {
        cout << "C\n";
    }
    try {
        agregarRelacionLaboral("123", "765", 1000);
    } catch (invalid_argument e) {
        cout << "D\n";
    }

    a();

    finalizarRelacionLaboral("234", "987", Fecha(28, 3, 2017));

    cout << "\n\nDespues de finalizar relaciones:\n\n";

    a();

    cout << "\nFin\n";

    return 0;
}

// Implementaciones

void agregarEmpleado(string ci, string nombre, string apellido, Direccion dir) {
    int posiciones_libres = 0; // Cuantas posiciones libres (no NULL) hay en el arreglo
    int posicion; // La posicion en la que va a ir el nuevo empleado

    for (int i = MAX_EMPLEADOS - 1; i >= 0; i--) {
        if (empleados[i] != NULL && empleados[i]->getCi() == ci) {
            // Si el empleado no es NULL, me fijo si tiene la misma ci que el nuevo, en cuyo caso tiro excepcion
            throw invalid_argument("Empleado ya existe");
        } else if (empleados[i] == NULL) {
            // Si el empleado es NULL, aumento las posiciones libres y coloco la posicion actual como posicion para el nuevo empleado
            posiciones_libres++;
            posicion = i;
        }
    }

    if (posiciones_libres == 0) {
        throw invalid_argument("No hay mas espacio para empleados");
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
                throw invalid_argument("Esa empresa ya existe");
            }
        } else {
            posiciones_libres++;
            posicion = i;
        }
    }

    if (posiciones_libres == 0) {
        throw invalid_argument("No hay espacio para empresas");
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

void agregarRelacionLaboral(string ciEmpleado, string idEmpresa, float sueldo) {
    // Empresa y empleado entre los que se va a agregar la relacion
    Empresa* empresa = NULL;
    Empleado* empleado = NULL;

    // Recorro las empresas para ver si encuentro una con el idEmpresa
    for (int i = 0; i < MAX_EMPRESAS; i++) {
        if (empresas[i] != NULL && empresas[i]->getId() == idEmpresa) {
            // Si encuentro una, la coloco en empresa
            empresa = empresas[i];
            break;
        }
    }

    // Si empresa es NULL, significa que no existia esa empresa
    if (empresa == NULL) {
        throw invalid_argument("Empresa no existe");
    }

    // Mismo procedimiento para encontrar el empleado
    for (int i = 0; i < MAX_EMPLEADOS; i++) {
        if (empleados[i] != NULL && empleados[i]->getCi() == ciEmpleado) {
            empleado = empleados[i];
            break;
        }
    }

    if (empleado == NULL) {
        throw invalid_argument("Empleado no existe");
    }

    // Obtengo las relaciones laborales del empleado con ciEmpleado
    RelacionLaboral** relaciones = empleado->getRelaciones();

    // Recorro las relaciones, y si entre esas ya hay una que apunte a la empresa idEmpresa, la relacion ya existia
    for (int i = 0; i < 50; i++) {
        if (relaciones[i] != NULL && relaciones[i]->getEmpresa()->getId() == idEmpresa) {
            throw invalid_argument("Relacion ya existe");
        }
    }

    // Si no existia esa relacion, la agrego utilizando addRelacion
    empleado->addRelacion(new RelacionLaboral(sueldo, NULL, empresa));
}

void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculacion) {
    // El empleado con el que la empresa va a estar relacionado
    Empleado* empleado = NULL;

    // Se busca al empleado igual que en agregarEmpleado
    for (int i = 0; i < MAX_EMPLEADOS; i++) {
        if (empleados[i] != NULL && empleados[i]->getCi() == ciEmpleado) {
            empleado = empleados[i];
            break;
        }
    }

    if (empleado == NULL) {
        throw invalid_argument("Empleado no existe");
    }

    // Obtengo las relaciones de ese empleado
    RelacionLaboral** relaciones = empleado->getRelaciones();

    // Recorro las relaciones del empleado y me fijo si una de ellas es con la idEmpresa
    for (int i = 0; i < 50; i++) {
        if (relaciones[i] != NULL && relaciones[i]->getEmpresa()->getId() == idEmpresa) {
            // Si encuentro la relacion, le seteo la fecha de desvinculacion
            relaciones[i]->setFecha(&desvinculacion);
            return;
        }
    }

    // Si la relacion no existe...
    throw invalid_argument("Relacion no existe");
}
