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
	int victoria = INDETERMINADO;

	//funciones
	Hnefatafl();
	~Hnefatafl();
	/*
	Este método pone todas las casillas en EMPTY y luego pone las posiciones iniciales de las fichas;
	*/
	void ResetTablero();
	/*
		Si no pudo mover la ficha marca false, caso contrario marca true
	*/
	bool MoverFicha(int origenX, int origenY, int destinoX, int destinoY);
	/*
		Devuelve el tipo de la casilla;
	*/
	CellState TipoCasilla(int x, int y);
	/*
		Marca true si captura el rey
	*/
	bool CapturarEnCasilla(int x, int y);
	void CambiarJugadorActual();
	void EmpezarJuego();


private:

};

