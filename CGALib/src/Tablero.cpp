#include "Headers/Tablero.h"
#include "Headers/Casilla.h"
#include "Headers/Ficha.h"
#include <iostream>

Tablero::Tablero() {
	// Constructor del tablero
	inicializarTablero();
}

void Tablero::inicializarTablero() {
	// Lógica para inicializar el tablero con casillas vacías y colocar las fichas en sus posiciones iniciales
	// Colocar las fichas según las reglas iniciales del juego
	casillas[0][0].establecerFicha(Ficha(TipoFicha::VACIA, 0, 0));
	casillas[0][1].establecerFicha(Ficha(TipoFicha::VACIA, 0, 1));
	casillas[0][2].establecerFicha(Ficha(TipoFicha::VACIA, 0, 2));
	casillas[0][3].establecerFicha(Ficha(TipoFicha::ATACANTE, 0, 3));
	casillas[0][4].establecerFicha(Ficha(TipoFicha::ATACANTE, 0, 4));
	casillas[0][5].establecerFicha(Ficha(TipoFicha::ATACANTE, 0, 5));
	casillas[0][6].establecerFicha(Ficha(TipoFicha::ATACANTE, 0, 6));
	casillas[0][7].establecerFicha(Ficha(TipoFicha::ATACANTE, 0, 7));
	casillas[0][8].establecerFicha(Ficha(TipoFicha::VACIA, 0, 8));
	casillas[0][9].establecerFicha(Ficha(TipoFicha::VACIA, 0, 9));
	casillas[0][10].establecerFicha(Ficha(TipoFicha::VACIA, 0, 10));

	casillas[1][0].establecerFicha(Ficha(TipoFicha::VACIA, 1, 0));
	casillas[1][1].establecerFicha(Ficha(TipoFicha::VACIA, 1, 1));
	casillas[1][2].establecerFicha(Ficha(TipoFicha::VACIA, 1, 2));
	casillas[1][3].establecerFicha(Ficha(TipoFicha::VACIA, 1, 3));
	casillas[1][4].establecerFicha(Ficha(TipoFicha::VACIA, 1, 4));
	casillas[1][5].establecerFicha(Ficha(TipoFicha::ATACANTE, 1, 5));
	casillas[1][6].establecerFicha(Ficha(TipoFicha::VACIA, 1, 6));
	casillas[1][7].establecerFicha(Ficha(TipoFicha::VACIA, 1, 7));
	casillas[1][8].establecerFicha(Ficha(TipoFicha::VACIA, 1, 8));
	casillas[1][9].establecerFicha(Ficha(TipoFicha::VACIA, 1, 9));
	casillas[1][10].establecerFicha(Ficha(TipoFicha::VACIA, 1, 10));

	casillas[2][0].establecerFicha(Ficha(TipoFicha::VACIA, 2, 0));
	casillas[2][1].establecerFicha(Ficha(TipoFicha::VACIA, 2, 1));
	casillas[2][2].establecerFicha(Ficha(TipoFicha::VACIA, 2, 2));
	casillas[2][3].establecerFicha(Ficha(TipoFicha::VACIA, 2, 3));
	casillas[2][4].establecerFicha(Ficha(TipoFicha::VACIA, 2, 4));
	casillas[2][5].establecerFicha(Ficha(TipoFicha::VACIA, 2, 5));
	casillas[2][6].establecerFicha(Ficha(TipoFicha::VACIA, 2, 6));
	casillas[2][7].establecerFicha(Ficha(TipoFicha::VACIA, 2, 7));
	casillas[2][8].establecerFicha(Ficha(TipoFicha::VACIA, 2, 8));
	casillas[2][9].establecerFicha(Ficha(TipoFicha::VACIA, 2, 9));
	casillas[2][10].establecerFicha(Ficha(TipoFicha::VACIA, 2, 10));

	casillas[3][0].establecerFicha(Ficha(TipoFicha::ATACANTE, 3, 0));
	casillas[3][1].establecerFicha(Ficha(TipoFicha::VACIA, 3, 1));
	casillas[3][2].establecerFicha(Ficha(TipoFicha::VACIA, 3, 2));
	casillas[3][3].establecerFicha(Ficha(TipoFicha::VACIA, 3, 3));
	casillas[3][4].establecerFicha(Ficha(TipoFicha::VACIA, 3, 4));
	casillas[3][5].establecerFicha(Ficha(TipoFicha::DEFENSOR, 3, 5));
	casillas[3][6].establecerFicha(Ficha(TipoFicha::VACIA, 3, 6));
	casillas[3][7].establecerFicha(Ficha(TipoFicha::VACIA, 3, 7));
	casillas[3][8].establecerFicha(Ficha(TipoFicha::VACIA, 3, 8));
	casillas[3][9].establecerFicha(Ficha(TipoFicha::VACIA, 3, 9));
	casillas[3][10].establecerFicha(Ficha(TipoFicha::ATACANTE, 3, 10));

	casillas[4][0].establecerFicha(Ficha(TipoFicha::ATACANTE, 4, 0));
	casillas[4][1].establecerFicha(Ficha(TipoFicha::VACIA, 4, 1));
	casillas[4][2].establecerFicha(Ficha(TipoFicha::VACIA, 4, 2));
	casillas[4][3].establecerFicha(Ficha(TipoFicha::VACIA, 4, 3));
	casillas[4][4].establecerFicha(Ficha(TipoFicha::DEFENSOR, 4, 4));
	casillas[4][5].establecerFicha(Ficha(TipoFicha::DEFENSOR, 4, 5));
	casillas[4][6].establecerFicha(Ficha(TipoFicha::DEFENSOR, 4, 6));
	casillas[4][7].establecerFicha(Ficha(TipoFicha::VACIA, 4, 7));
	casillas[4][8].establecerFicha(Ficha(TipoFicha::VACIA, 4, 8));
	casillas[4][9].establecerFicha(Ficha(TipoFicha::VACIA, 4, 9));
	casillas[4][10].establecerFicha(Ficha(TipoFicha::ATACANTE, 4, 10));

	casillas[5][0].establecerFicha(Ficha(TipoFicha::ATACANTE, 5, 0));
	casillas[5][1].establecerFicha(Ficha(TipoFicha::ATACANTE, 5, 1));
	casillas[5][2].establecerFicha(Ficha(TipoFicha::VACIA, 5, 2));
	casillas[5][3].establecerFicha(Ficha(TipoFicha::DEFENSOR, 5, 3));
	casillas[5][4].establecerFicha(Ficha(TipoFicha::DEFENSOR, 5, 4));
	casillas[5][5].establecerFicha(Ficha(TipoFicha::REY, 5, 5));
	casillas[5][6].establecerFicha(Ficha(TipoFicha::DEFENSOR, 5, 6));
	casillas[5][7].establecerFicha(Ficha(TipoFicha::DEFENSOR, 5, 7));
	casillas[5][8].establecerFicha(Ficha(TipoFicha::VACIA, 5, 8));
	casillas[5][9].establecerFicha(Ficha(TipoFicha::ATACANTE, 5, 9));
	casillas[5][10].establecerFicha(Ficha(TipoFicha::ATACANTE, 5, 10));

	casillas[6][0].establecerFicha(Ficha(TipoFicha::ATACANTE, 6, 0));
	casillas[6][1].establecerFicha(Ficha(TipoFicha::VACIA, 6, 1));
	casillas[6][2].establecerFicha(Ficha(TipoFicha::VACIA, 6, 2));
	casillas[6][3].establecerFicha(Ficha(TipoFicha::VACIA, 6, 3));
	casillas[6][4].establecerFicha(Ficha(TipoFicha::DEFENSOR, 6, 4));
	casillas[6][5].establecerFicha(Ficha(TipoFicha::DEFENSOR, 6, 5));
	casillas[6][6].establecerFicha(Ficha(TipoFicha::DEFENSOR, 6, 6));
	casillas[6][7].establecerFicha(Ficha(TipoFicha::VACIA, 6, 7));
	casillas[6][8].establecerFicha(Ficha(TipoFicha::VACIA, 6, 8));
	casillas[6][9].establecerFicha(Ficha(TipoFicha::VACIA, 6, 9));
	casillas[6][10].establecerFicha(Ficha(TipoFicha::ATACANTE, 6, 10));

	casillas[7][0].establecerFicha(Ficha(TipoFicha::ATACANTE, 7, 0));
	casillas[7][1].establecerFicha(Ficha(TipoFicha::VACIA, 7, 1));
	casillas[7][2].establecerFicha(Ficha(TipoFicha::VACIA, 7, 2));
	casillas[7][3].establecerFicha(Ficha(TipoFicha::VACIA, 7, 3));
	casillas[7][4].establecerFicha(Ficha(TipoFicha::VACIA, 7, 4));
	casillas[7][5].establecerFicha(Ficha(TipoFicha::DEFENSOR, 7, 5));
	casillas[7][6].establecerFicha(Ficha(TipoFicha::VACIA, 7, 6));
	casillas[7][7].establecerFicha(Ficha(TipoFicha::VACIA, 7, 7));
	casillas[7][8].establecerFicha(Ficha(TipoFicha::VACIA, 7, 8));
	casillas[7][9].establecerFicha(Ficha(TipoFicha::VACIA, 7, 9));
	casillas[7][10].establecerFicha(Ficha(TipoFicha::ATACANTE, 7, 10));

	casillas[8][0].establecerFicha(Ficha(TipoFicha::VACIA, 8, 0));
	casillas[8][1].establecerFicha(Ficha(TipoFicha::VACIA, 8, 1));
	casillas[8][2].establecerFicha(Ficha(TipoFicha::VACIA, 8, 2));
	casillas[8][3].establecerFicha(Ficha(TipoFicha::VACIA, 8, 3));
	casillas[8][4].establecerFicha(Ficha(TipoFicha::VACIA, 8, 4));
	casillas[8][5].establecerFicha(Ficha(TipoFicha::VACIA, 8, 5));
	casillas[8][6].establecerFicha(Ficha(TipoFicha::VACIA, 8, 6));
	casillas[8][7].establecerFicha(Ficha(TipoFicha::VACIA, 8, 7));
	casillas[8][8].establecerFicha(Ficha(TipoFicha::VACIA, 8, 8));
	casillas[8][9].establecerFicha(Ficha(TipoFicha::VACIA, 8, 9));
	casillas[8][10].establecerFicha(Ficha(TipoFicha::VACIA, 8, 10));

	casillas[9][0].establecerFicha(Ficha(TipoFicha::VACIA, 9, 0));
	casillas[9][1].establecerFicha(Ficha(TipoFicha::VACIA, 9, 1));
	casillas[9][2].establecerFicha(Ficha(TipoFicha::VACIA, 9, 2));
	casillas[9][3].establecerFicha(Ficha(TipoFicha::VACIA, 9, 3));
	casillas[9][4].establecerFicha(Ficha(TipoFicha::VACIA, 9, 4));
	casillas[9][5].establecerFicha(Ficha(TipoFicha::ATACANTE, 9, 5));
	casillas[9][6].establecerFicha(Ficha(TipoFicha::VACIA, 9, 6));
	casillas[9][7].establecerFicha(Ficha(TipoFicha::VACIA, 9, 7));
	casillas[9][8].establecerFicha(Ficha(TipoFicha::VACIA, 9, 8));
	casillas[9][9].establecerFicha(Ficha(TipoFicha::VACIA, 9, 9));
	casillas[9][10].establecerFicha(Ficha(TipoFicha::VACIA, 9, 10));

	casillas[10][0].establecerFicha(Ficha(TipoFicha::VACIA, 10, 0));
	casillas[10][1].establecerFicha(Ficha(TipoFicha::VACIA, 10, 1));
	casillas[10][2].establecerFicha(Ficha(TipoFicha::VACIA, 10, 2));
	casillas[10][3].establecerFicha(Ficha(TipoFicha::ATACANTE, 10, 3));
	casillas[10][4].establecerFicha(Ficha(TipoFicha::ATACANTE, 10, 4));
	casillas[10][5].establecerFicha(Ficha(TipoFicha::ATACANTE, 10, 5));
	casillas[10][6].establecerFicha(Ficha(TipoFicha::ATACANTE, 10, 6));
	casillas[10][7].establecerFicha(Ficha(TipoFicha::ATACANTE, 10, 7));
	casillas[10][8].establecerFicha(Ficha(TipoFicha::VACIA, 10, 8));
	casillas[10][9].establecerFicha(Ficha(TipoFicha::VACIA, 10, 9));
	casillas[10][10].establecerFicha(Ficha(TipoFicha::VACIA, 10, 10));
}

// Metodo provisional en lo que se dibuja con OpenGL
void Tablero::mostrarTablero() const {
	// Imprimir encabezado de columnas
	std::cout << "   ";
	for (int col = 0; col < TAMANIO_TABLERO; ++col) {
		std::cout << col << " ";
	}
	std::cout << std::endl;

	// Imprimir filas
	for (int fila = 0; fila < TAMANIO_TABLERO; ++fila) {
		// Imprimir número de fila
		std::cout << fila << " ";

		// Imprimir contenido de las casillas en la fila
		for (int col = 0; col < TAMANIO_TABLERO; ++col) {
			const Casilla& casilla = casillas[fila][col];
			const Ficha& ficha = casilla.obtenerFicha();

			// Imprimir el símbolo correspondiente al tipo de ficha en la casilla o un espacio vacío si no hay ficha
			if (ficha.obtenerTipo() == TipoFicha::VACIA) {
				std::cout << "  "; // Espacio vacío
			}
			else if (ficha.obtenerTipo() == TipoFicha::REY) {
				std::cout << "R "; // Símbolo del rey (por ejemplo, un símbolo de ajedrez)
			}
			else if (ficha.obtenerTipo() == TipoFicha::DEFENSOR) {
				std::cout << "D "; // Símbolo del defensor
			}
			else if (ficha.obtenerTipo() == TipoFicha::ATACANTE) {
				std::cout << "A "; // Símbolo del atacante
			}
			else {
				std::cout << "  "; // Puedes agregar más casos según tus tipos de ficha
			}
		}

		std::cout << std::endl;
	}
}

bool Tablero::moverFicha(int origenX, int origenY, int destinoX, int destinoY) {
	// Obtener la ficha de origen y destino
	Ficha fichaOrigen = casillas[origenX][origenY].obtenerFicha();
	Ficha fichaDestino = casillas[destinoX][destinoY].obtenerFicha();
	
	// Verificar si la casilla de origen está vacía o la casilla de destino está ocupada
	if (fichaOrigen.obtenerTipo() == TipoFicha::VACIA || !casillas[destinoX][destinoY].estaVacia()) {
		return false; // Movimiento inválido
	}

	// Verificar si el movimiento es válido (como la torre del ajedrez)
	if (origenX != destinoX && origenY != destinoY) {
		return false; // Movimiento inválido
	}

	// Verificar si hay fichas en el trayecto del movimiento
	if (origenX != destinoX) {
		int direccionX = (destinoX - origenX) / abs(destinoX - origenX);
		for (int i = origenX + direccionX; i != destinoX; i += direccionX) {
			if (!casillas[i][origenY].estaVacia()) {
				return false; // Movimiento inválido
			}
		}
	}
	else {
		int direccionY = (destinoY - origenY) / abs(destinoY - origenY);
		for (int j = origenY + direccionY; j != destinoY; j += direccionY) {
			if (!casillas[origenX][j].estaVacia()) {
				return false; // Movimiento inválido
			}
		}
	}

	// El movimiento es válido, actualizar las casillas de origen y destino
	casillas[origenX][origenY].establecerFicha(fichaDestino);
	casillas[destinoX][destinoY].establecerFicha(fichaOrigen);

	// Actualizar la posición de la ficha
	fichaDestino.establecerPosicion(origenX, origenY);
	fichaOrigen.establecerPosicion(destinoX, destinoY);

	return true; // Movimiento válido
}




bool Tablero::verificarVictoria() const {
	// Verificar si el rey está en las posiciones de victoria (0,0), (0,10), (10,0), (10,10)
	if (casillas[0][0].obtenerFicha().obtenerTipo() == TipoFicha::REY ||
		casillas[0][TAMANIO_TABLERO - 1].obtenerFicha().obtenerTipo() == TipoFicha::REY ||
		casillas[TAMANIO_TABLERO - 1][0].obtenerFicha().obtenerTipo() == TipoFicha::REY ||
		casillas[TAMANIO_TABLERO - 1][TAMANIO_TABLERO - 1].obtenerFicha().obtenerTipo() == TipoFicha::REY) {
		return true;
	}

	// Verificar si todas las fichas atacantes han sido capturadas
	for (int fila = 0; fila < TAMANIO_TABLERO; ++fila) {
		for (int col = 0; col < TAMANIO_TABLERO; ++col) {
			const Ficha& ficha = casillas[fila][col].obtenerFicha();
			if (ficha.obtenerTipo() == TipoFicha::ATACANTE) {
				return false;
			}
		}
	}

	return false;
}

bool Tablero::verificarDerrota() const {
	// Obtener la posición del rey
	int reyX = -1;
	int reyY = -1;

	// Buscar la posición del rey en el tablero
	for (int i = 0; i < TAMANIO_TABLERO; i++) {
		for (int j = 0; j < TAMANIO_TABLERO; j++) {
			if (casillas[i][j].obtenerFicha().obtenerTipo() == TipoFicha::REY) {
				reyX = i;
				reyY = j;
				break;
			}
		}
	}

	// Verificar si el rey está en una posición de derrota
	if (reyX == 0 || reyX == TAMANIO_TABLERO - 1 || reyY == 0 || reyY == TAMANIO_TABLERO - 1) {
		// El rey está en una posición de derrota, se ha producido la derrota
		return true;
	}

	// Verificar si el rey está rodeado por las fichas enemigas
	bool rodeado = true;

	// Verificar si las casillas adyacentes al rey están ocupadas por fichas enemigas
	if (reyX > 0 && casillas[reyX - 1][reyY].obtenerFicha().obtenerTipo() != TipoFicha::ATACANTE) {
		rodeado = false;
	}
	if (reyX < TAMANIO_TABLERO - 1 && casillas[reyX + 1][reyY].obtenerFicha().obtenerTipo() != TipoFicha::ATACANTE) {
		rodeado = false;
	}
	if (reyY > 0 && casillas[reyX][reyY - 1].obtenerFicha().obtenerTipo() != TipoFicha::ATACANTE) {
		rodeado = false;
	}
	if (reyY < TAMANIO_TABLERO - 1 && casillas[reyX][reyY + 1].obtenerFicha().obtenerTipo() != TipoFicha::ATACANTE) {
		rodeado = false;
	}

	if (rodeado) {
		// El rey está rodeado por fichas enemigas, se ha producido la derrota
		return true;
	}

	// No se ha producido la derrota
	return false;
}



// Otros métodos y funciones según la lógica del juego
