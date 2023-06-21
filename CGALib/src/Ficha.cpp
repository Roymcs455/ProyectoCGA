#include "Headers/Ficha.h"

Ficha::Ficha(TipoFicha tipo, int posicionX, int posicionY)
	: tipo(tipo), posicionX(posicionX), posicionY(posicionY) {}

void Ficha::establecerPosicion(int x, int y) {
	posicionX = x;
	posicionY = y;
}

TipoFicha Ficha::obtenerTipo() const {
	return tipo;
}

int Ficha::obtenerPosicionX() const {
	return posicionX;
}

int Ficha::obtenerPosicionY() const {
	return posicionY;
}
