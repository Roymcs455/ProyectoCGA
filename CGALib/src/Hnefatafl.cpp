
#include "Headers/Hnefatafl.h"

/*
Hnefatafl::Hnefatafl()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		tablero.push_back(std::vector<CellState>(BOARD_SIZE, EMPTY));
	}
}

Hnefatafl::~Hnefatafl()
{
}*/
void Hnefatafl::ResetTablero()
{

}
bool Hnefatafl::MoverFicha(int origenX, int origenY, int destinoX, int destinoY)
{
	CellState fichaOrigen = TipoCasilla(origenX, origenY);
	CellState casillaDestino = TipoCasilla(destinoX, destinoY);
	int evalX = destinoX - origenX;
	int evalY= destinoY - origenY;
	if (fichaOrigen<KING||fichaOrigen>ATTACKER)//Evalúa si no es king(2), defender(3) o attacker (4) la casilla origen
	{ 
		return false;
	}
	if (fichaOrigen != KING && casillaDestino == ESCAPE) //evalua si se intenta mover ficha que no sea king a escape
	{
		return false;
	}
	else if (casillaDestino != EMPTY) //evalua si la casilla destino no está vacía
	{
		return false;
	}
	
	if (evalX == 0)
	{
		if (evalY > 0)
		{
			for (int i = 1; i < evalY; i++)
			{
				if (TipoCasilla(origenX, origenY+i) != EMPTY || (origenX, origenY + i) != ESCAPE)
				{
					return false;
				}
			}
		}
		else
		{
			for (int i = 1; i < -evalY; i++)
			{
				if (TipoCasilla(origenX, origenY - i) != EMPTY || (origenX, origenY - i) != ESCAPE)
				{
					return false;
				}
			}
		}
	}
	else if (evalY == 0)
	{
		if (evalX > 0)
		{
			for (int i = 1; i < evalX; i++)
			{
				if (TipoCasilla(origenX + i, origenY ) != EMPTY || (origenX + i, origenY ) != ESCAPE)
				{
					return false;
				}
			}
		}
		else
		{
			for (int i = 1; i < -evalY; i++)
			{
				if (TipoCasilla(origenX - i, origenY ) != EMPTY || (origenX - i, origenY ) != ESCAPE)
				{
					return false;
				}
			}
		}
	}
	if (fichaOrigen == KING && casillaDestino == ESCAPE && origenX != 5 && origenY != 5)
	{
		victoria = BLANCO;
		juegoActivo = false;

	}
	tablero[destinoX][destinoY] = tablero[origenX][origenY];
	if (origenX == 5 || origenY == 5)
	{
		tablero[origenX][origenY] = ESCAPE;
	}
	else
	{
		tablero[origenX][origenY] = EMPTY;
	}
	if (CapturarEnCasilla(destinoX, destinoY))
	{
		victoria = NEGRO;
		juegoActivo = false;
	}
	return true;

}
CellState Hnefatafl::TipoCasilla(int x, int y)
{
	if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE)
		return INVALID;
	else
	{
		return tablero[x][y];
	}
	return INVALID;
}
bool CapturarEnCasilla( int x, int y)
{
	/*CellState fichaCapturadora = TipoCasilla(x, y);
	if (fichaCapturadora == TipoCasilla(x + 2, y)) //Revisa arriba
	{
		
	}*/

	return false;
}

void Hnefatafl::CambiarJugadorActual()
{
	if (jugadorActual == NEGRO)
	{
		jugadorActual = BLANCO;
	}
	else
	{
		jugadorActual = NEGRO;
	}
}
void Hnefatafl::EmpezarJuego()
{

}