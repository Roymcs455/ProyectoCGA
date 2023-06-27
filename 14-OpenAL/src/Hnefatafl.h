#pragma once
#include <iostream>
#include <vector>
const int BOARD_SIZE = 11;
enum CellState
{
	EMPTY,ESCAPE,KING,DEFENDER,ATTACKER,INVALID
};
enum Jugadores
{
	BLANCO,
	NEGRO,
	INDETERMINADO
};
class Hnefatafl
{
public:
	//constantes
	//variables
	std::vector<std::vector<CellState>> tablero;
	int jugadorActual = NEGRO;
	bool juegoActivo = false;
	int piezasBlancas = 0;
	int piezasNegras= 0;
	int victoria = INDETERMINADO;

	//funciones
	Hnefatafl();
	~Hnefatafl();
	void ResetTablero();
	bool MoverFicha(int origenX, int origenY, int destinoX, int destinoY);
	bool EvalFichaRodeada(int x, int y);
	CellState TipoCasilla(int x, int y);
	Jugadores CapturarEnCasilla(int x, int y, CellState turno);


private:

};

