#include "Empleado.h"
#include "DtEmpresa.h"
#include "Nacional.h"
#include "Extranjera.h"
#include "DtNacional.h"
#include "DtExtranjera.h"

Empleado::Empleado(string ci, string nombre, string apellido, Direccion* direccion) {
    this->ci = ci;
    this->nombre = nombre;
    this->apellido = apellido;
    this->direccion = direccion;
    int i;

    for (i = 0; i < 50; i++)
        this->relaciones[i] = NULL;
}

string Empleado::getCi() {
    return ci;
}

string Empleado::getNombre() {
    return nombre;
}

string Empleado::getApellido() {
    return apellido;
}

Direccion* Empleado::getDireccion() {
    return direccion;
}

void Empleado::addRelacion(Empresa* e, float sueldo) {
    for (int i = 0; i < 50; i++)
        if (relaciones[i] != NULL && relaciones[i]->getEmpresa()->getId() == e->getId())
            throw invalid_argument("Relacion ya existe");

    for (int i = 0; i < 50; i++)
        if (relaciones[i] == NULL) {
            relaciones[i] = new RelacionLaboral(sueldo, NULL, e);
            return;
        }

    throw invalid_argument("Maximo de relaciones alcanzado");
}

void Empleado::finalizarRelacion(string idEmpresa, Fecha desvinculacion) {
    for (int i = 0; i < 50; i++)
        if (relaciones[i] != NULL && relaciones[i]->getEmpresa()->getId() == idEmpresa) {
            if (relaciones[i]->getFechaDesvinculacion() != NULL)
                throw invalid_argument("La Relacion Ya Esta Finalizada");
            else
                relaciones[i]->setFecha(new Fecha(desvinculacion.getDia(), desvinculacion.getMes(), desvinculacion.getAnio()));

            return;
        }

    throw invalid_argument("Relacion no existe");
}

void Empleado::setCi(string ci) {
    this->ci = ci;
}

void Empleado::setNombre(string nombre) {
    this->nombre = nombre;
}

void Empleado::setApellido(string apellido) {
    this->apellido = apellido;
}

void Empleado::setDireccion(Direccion* direccion) {
    this->direccion = direccion;
}

int Empleado::sueldoLiquidoTotal() {
    int sueldoLiquidoTotal = 0;

    for (int j = 0; j < 50; j++)
        if (relaciones[j] != NULL && relaciones[j]->getFechaDesvinculacion() == NULL)
            sueldoLiquidoTotal += relaciones[j]->getSueldoLiquido();

    return sueldoLiquidoTotal;
}

DtEmpresa** Empleado::getInfoEmpresas(int& cantEmpresas) {
    for (int i = 0; i < 50; i++)
        if (relaciones[i] != NULL && relaciones[i]->getFechaDesvinculacion() == NULL)
            cantEmpresas++;

    DtEmpresa** resultado = (DtEmpresa**) malloc(sizeof (DtEmpresa) * cantEmpresas);

    int pos = 0;
    for (int i = 0; i < 50; i++)
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

Empleado::~Empleado() {
    delete direccion;
    for (int i = 0; i < 50; i++)
        delete relaciones[i];
}