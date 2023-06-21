#ifndef TABLERO_H
#define TABLERO_H

#include "Casilla.h"

const int TAMANIO_TABLERO = 11; // Tamaño del tablero de Hnefatafl

class Tablero {
private:
	Casilla casillas[TAMANIO_TABLERO][TAMANIO_TABLERO];

public:
	Tablero();
	void inicializarTablero();
	void mostrarTablero() const;
	bool moverFicha(int origenX, int origenY, int destinoX, int destinoY);
	bool verificarVictoria() const;
	bool verificarDerrota() const;
	// Otros métodos y funciones según la lógica del juego
};

#endif
