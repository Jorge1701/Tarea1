#ifndef FECHA_H_
#define FECHA_H_

class Fecha {
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int, int, int);

	int getDia();
	int getMes();
	int getAnio();

	~Fecha();
};

#endif
