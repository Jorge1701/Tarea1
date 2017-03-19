#include "Headers/DataTypes/Fecha.h"
#include "Headers/DataTypes/Direccion.h"
#include "Headers/DataTypes/DtEmpleado.h"
#include "Headers/DataTypes/DtEmpresa.h"
#include "Headers/DataTypes/DtExtranjera.h"
#include "Headers/DataTypes/DtNacional.h"

#include <iostream>

using namespace std;

Fecha* fecha;
DtEmpleado* dtEmpleado;
DtEmpresa* dtEmpresa;
DtExtranjera* dtExtranjera;
DtNacional* dtNacional;

void imprimirFecha(Fecha* fecha) {
	cout << fecha->getDia();
	cout << "/";
	cout << fecha->getMes();
	cout << "/";
	cout << fecha->getAnio();
}

void imprimirDireccion(Direccion* direccion) {
	cout << direccion->getPais();
	cout << ", ";
	cout << direccion->getCiudad();
	cout << ", ";
	cout << direccion->getCalle();
	cout << " ";
	cout << direccion->getNumero();
}

void imprimirEmpleado(DtEmpleado* dtEmpleado) {
	cout << "CI: ";
	cout << dtEmpleado->getCi();
	cout << "\nNombre: ";
	cout << dtEmpleado->getNombre();
	cout << "\nApellido:";
	cout << dtEmpleado->getApellido();
	cout << "\nDireccion: ";
	imprimirDireccion(dtEmpleado->getDireccion());
	cout << "\nSueldo Liquido: ";
	cout << dtEmpleado->getSueldoLiquido();
}

void imprimirEmpresa(DtEmpresa* dtEmpresa) {
	cout << "ID: ";
	cout << dtEmpresa->getId();
	cout << "\nDireccion: ";
	imprimirDireccion(dtEmpresa->getDireccion());
}

void imprimirNacional(DtNacional* dtNacional) {
	imprimirEmpresa(dtNacional);
	cout << "\nRUT: ";
	cout << dtNacional->getRut();
}

void imprimirExtranjera(DtExtranjera* dtExtranjera) {
	imprimirEmpresa(dtExtranjera);
	cout << "\nNombre Fantasia: ";
	cout << dtExtranjera->getNombreFantasia();
}

int main() {
	fecha = new Fecha(19, 3, 2017);
	dtEmpleado = new DtEmpleado("4.742.523-5", "Jorge", "Rosas", new Direccion("Uruguay", "Fray Bentos", "3541", "Mendoza"), 10000);
	dtEmpresa = new DtEmpresa("0", new Direccion("DirEmp0Pais", "DirEmp0Ciudad", "DirEmp0Numero", "DirEmp0Calle"));
	dtExtranjera = new DtExtranjera("1", new Direccion("DirEmp1Pais", "DirEmp1Ciudad", "DirEmp1Numero", "DirEmp1Calle"), "Emp1RUT");
	dtNacional = new DtNacional("2", new Direccion("DirEmp2Pais", "DirEmp2Ciudad", "DirEmp2Numero", "DirEmp2Calle"), "Emp2NombreFantasia");

	cout << "Hoy es: ";
	imprimirFecha(fecha);

	cout << "\n\nEmpleado:\n\n";
	imprimirEmpleado(dtEmpleado);

	cout << "\n\nEmpresa:\n\n";
	imprimirEmpresa(dtEmpresa);

	cout << "\n\nExtranjera:\n\n";
	imprimirExtranjera(dtExtranjera);

	cout << "\n\nNacional:\n\n";
	imprimirNacional(dtNacional);

	return 0;
}
