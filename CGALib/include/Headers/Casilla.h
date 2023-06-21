#ifndef CASILLA_H
#define CASILLA_H

#include "Ficha.h"

class Casilla {
private:
	Ficha ficha;

public:
	Casilla();
	void establecerFicha(const Ficha& ficha);
	const Ficha& obtenerFicha() const;
	bool estaVacia() const;
};

#endif
