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
int cantEmpleados;

// Definir prototipos obligatorios
void agregarEmpleado(string ci, string nombre, string apellido, Direccion dir);
void agregarEmpresa(DtEmpresa& empresa);
DtEmpleado** listarEmpleados(int& cantEmpleados);
void agregarRelacionLaboral(string ciEmpleado, string idEmpresa, float sueldo);
void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculacion);
DtEmpresa** obtenerInfoEmpresaPorEmpleado(string ciEmpleado, int& cantEmpresas);

// Otros prototipos
Direccion* generarDireccion();
Fecha* generarFecha();

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

    // Fin inicializacion

    int opcion = 0;

    do {
        // Imprimir menu
        cout << "===== Menu ===========================" << endl;
        cout << "   1) Agregar Empleado" << endl;
        cout << "   2) Agregar Empresa" << endl;
        cout << "   3) Listar Empleados" << endl;
        cout << "   4) Agregar Relacion Laboral" << endl;
        cout << "   5) Finalizar Relacion Laboral" << endl;
        cout << "   6) Obtener Informacion Empresa" << endl;
        cout << "   -----------------------------------" << endl;
        cout << "   7) Mostrar Empleados" << endl;
        cout << "   8) Mostrar Empresas" << endl;
        cout << "   9) Mostrar Relaciones Laborales" << endl;

        cout << "   0) Salir" << endl;

        // Obtener opcion
        cout << endl << "opcion: ";
        cin >> opcion;

        // Variables a usar
        // Empleado
        string ci, nombre, apellido;
        // Empresa
        string id, rut, nombreFantasia;
        // Relacion Laboral
        string ciEmpleado, idEmpresa;
        int sueldo;

        // Otros
        int tipoEmpresa = 0;

        // Limpiar buffer
        cin.clear();
        fflush(stdin);

        // Hacer lo correspondiente
        switch (opcion) {
            case 1:
                cout << "===== Agregar Empleado ===============" << endl;
                cout << "CI: ";
                getline(cin, ci);
                cout << "Nombre: ";
                getline(cin, nombre);
                cout << "Apeliido: ";
                getline(cin, apellido);

                agregarEmpleado(ci, nombre, apellido, *generarDireccion());
                break;
            case 2:
                cout << "===== Agregar Empresa ================" << endl;
                cout << "   1) Nacional" << endl;
                cout << "   2) Extranjera" << endl;
                cout << "   0) Cancelar" << endl;

                cout << endl << "opcion: ";
                cin >> tipoEmpresa;

                if (tipoEmpresa == 0) {
                    break;
                }

                // Limpiar buffer
                cin.clear();
                fflush(stdin);

                cout << "ID: ";
                getline(cin, id);

                if (tipoEmpresa == 1) {
                    cout << "RUT: ";
                    getline(cin, rut);

                    agregarEmpresa(*(new DtNacional(id, generarDireccion(), rut)));
                } else {
                    cout << "Nombre Fantasia: ";
                    getline(cin, nombreFantasia);
                    agregarEmpresa(*(new DtExtranjera(id, generarDireccion(), nombreFantasia)));
                }
                break;
            case 3:
                cout << "===== Listar Empleados ===============" << endl;

                cout << "Coming soon..." << endl;
                break;
            case 4:
                cout << "===== Agregar Relacion Laboral =======" << endl;

                cout << "CI Empleado: ";
                getline(cin, ciEmpleado);
                cout << "ID Empresa: ";
                getline(cin, idEmpresa);
                cout << "Sueldo: ";
                cin >> sueldo;

                agregarRelacionLaboral(ciEmpleado, idEmpresa, sueldo);
                break;
            case 5:
                cout << "===== Finalizar Relacion Laboral =====" << endl;

                cout << "CI Empleado: ";
                getline(cin, ciEmpleado);
                cout << "ID Empresa: ";
                getline(cin, idEmpresa);

                finalizarRelacionLaboral(ciEmpleado, idEmpresa, *generarFecha());
                break;
            case 6:
                cout << "===== Obtener Informacion Empresa ====" << endl;

                cout << "Coming soon..." << endl;
                break;
            case 7:
                for (int i = 0; i < MAX_EMPLEADOS; i++) {
                    if (empleados[i] != NULL) {
                        cout << "----------" << endl;
                        cout << "CI: " << empleados[i]->getCi() << endl;
                        cout << "Nombre: " << empleados[i]->getNombre() << endl;
                        cout << "Apellido: " << empleados[i]->getApellido() << endl;
                        cout << "Direccion: " << *empleados[i]->getDireccion() << endl;
                    }
                }
                break;
            case 8:
                for (int i = 0; i < MAX_EMPRESAS; i++) {
                    if (empresas[i] != NULL) {
                        Empresa* e = empresas[i];

                        cout << "----------" << endl;
                        cout << "ID: " << e->getId() << endl;
                        cout << "Direccion: " << *e->getDireccion() << endl;

                        Nacional* nac = dynamic_cast<Nacional*> (e);
                        if (nac) {
                            cout << "RUT: " << nac->getRut() << endl;
                        } else {
                            Extranjera* ext = dynamic_cast<Extranjera*> (e);
                            cout << "Nombre Fantasia: " << ext->getNombreFantasia() << endl;
                        }
                    }
                }
                break;
            case 9:
                for (int i = 0; i < MAX_EMPLEADOS; i++) {
                    if (empleados[i] != NULL) {
                        cout << "----------" << endl;
                        cout << "Empleado: " << empleados[i]->getCi() << ", " << empleados[i]->getNombre() << ", " << empleados[i]->getApellido() << endl;

                        RelacionLaboral** r = empleados[i]->getRelaciones();

                        int cant = 0;

                        for (int j = 0; j < 50; j++) {
                            if (r[j] != NULL) {
                                cout << "Relacion 1:" << endl;
                                cout << "Empresa: " << r[j]->getEmpresa()->getId() << endl;
                                cout << "Sueldo Liquido: " << r[j]->getSueldoLiquido() << endl;
                                cout << "Fecha: " << *r[j]->getFechaDesvinculacion();
                                if (r[j]->getFechaDesvinculacion() != NULL) {
                                    cout << " (Relacion Finalizada)" << endl;
                                }

                                cant++;
                            }
                        }

                        if (cant == 0) {
                            cout << "No hay relaciones laborales" << endl;
                        }
                    }
                }
                break;
        }
    } while (opcion != 0);
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

// Implementaciones extras

Direccion* generarDireccion() {
    string pais, ciudad, numero, calle;

    cout << "   Direccion" << endl;
    cout << "Pais: ";
    getline(cin, pais);
    cout << "Ciudad: ";
    getline(cin, ciudad);
    cout << "Calle: ";
    getline(cin, calle);
    cout << "Numero: ";
    getline(cin, numero);

    return new Direccion(pais, ciudad, calle, numero);
}

Fecha* generarFecha() {
    int dia, mes, anio;

    cout << "   Fecha" << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Año: ";
    cin >> anio;

    return new Fecha(dia, mes, anio);
}
