#include "Headers/Casilla.h"
#include "Headers/Ficha.h"

Casilla::Casilla() : ficha(TipoFicha::VACIA, 0, 0) {
	// Constructor de la casilla sin ficha
}

void Casilla::establecerFicha(const Ficha& ficha) {
	this->ficha = ficha;
}

const Ficha& Casilla::obtenerFicha() const {
	return ficha;
}

bool Casilla::estaVacia() const {
	// Verificar si la casilla no tiene ficha
	return (ficha.obtenerTipo() == TipoFicha::VACIA);
}
