
#include "Hnefatafl.h"


Hnefatafl::Hnefatafl()
{
	
	ResetTablero();
}

Hnefatafl::~Hnefatafl()
{
}
void Hnefatafl::ResetTablero()
{
	std::vector<std::vector<CellState>> nuevoTablero{
		{ESCAPE,EMPTY, EMPTY, ATTACKER,ATTACKER,ATTACKER,ATTACKER,ATTACKER, EMPTY,EMPTY,ESCAPE},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,ATTACKER,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
		{ATTACKER, EMPTY, EMPTY, EMPTY, EMPTY,DEFENDER,EMPTY,EMPTY,EMPTY,EMPTY,ATTACKER},
		{ATTACKER, EMPTY, EMPTY, EMPTY, DEFENDER,DEFENDER,DEFENDER,EMPTY,EMPTY,EMPTY,ATTACKER},
		{ATTACKER, ATTACKER, EMPTY, DEFENDER, DEFENDER,KING,DEFENDER,DEFENDER,EMPTY,ATTACKER,ATTACKER},
		{ATTACKER, EMPTY, EMPTY, EMPTY, DEFENDER,DEFENDER,DEFENDER,EMPTY,EMPTY,EMPTY,ATTACKER},
		{ATTACKER, EMPTY, EMPTY, EMPTY, EMPTY,DEFENDER,EMPTY,EMPTY,EMPTY,EMPTY,ATTACKER},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
		{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY,ATTACKER,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
		{ESCAPE,EMPTY, EMPTY, ATTACKER,ATTACKER,ATTACKER,ATTACKER,ATTACKER, EMPTY,EMPTY,ESCAPE}
	};
	tablero = nuevoTablero;
}
bool Hnefatafl::MoverFicha(int origenX, int origenY, int destinoX, int destinoY)
{
	CellState origen = TipoCasilla(origenX, origenY);
	CellState destino = TipoCasilla(destinoX, destinoY);
	if(origen == EMPTY || origen == INVALID || origen == ESCAPE) //se intenta mover una casilla vacía o inválida
		return false;
	if (origenX == destinoX && origenY == destinoY) //se intenta dejar en la posición original;
		return false;
	if (origenX != destinoX && origenY != destinoY) //se intenta mover de forma que no sea ortogonal
		return false;
	if (origen != KING && destino == ESCAPE) // se intenta mover pieza no rey a castillo
		return false;
	if (destino != EMPTY)
		return false;
	if (origenX == destinoX) //Moviendose en el eje Y;
	{
		for (size_t i = 1; i < std::abs(origenY - destinoY); i++)
		{
			if (origenY > destinoY)
			{
				if (TipoCasilla(origenX, origenY - i) != EMPTY)
					return false;
			}
			if (origenY < destinoY)
			{
				if (TipoCasilla(origenX, origenY + i) != EMPTY)
					return false;
			}
		}
	}
	else if ( origenY == destinoY ) //Moviendose en el eje X;
	{
		for (size_t i = 1; i < std::abs(origenX - destinoX); i++)
		{
			if (origenX > destinoX)
			{
				if (TipoCasilla(origenX - i, origenY ) != EMPTY)
					return false;
			}
			if (origenX < destinoX)
			{
				if (TipoCasilla(origenX + i, origenY) != EMPTY)
					return false;
			}
		}
	}
	
	
	tablero[destinoX][destinoY] = tablero[origenX][origenY];
	if (origenX == 5 && origenY == 5)
	{
		tablero[origenX][origenY] = ESCAPE;
		
	}
	else
	{
		tablero[origenX][origenY] = EMPTY;
		
	}
	/*
	for (int j = 0; j < BOARD_SIZE; j++)
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			std::cout << " " << tablero[j][i] << " ";
		}
		std::cout << std::endl;
	}*/
	CapturarEnCasilla(destinoX, destinoY, origen);
	return true;


}
bool Hnefatafl::EvalFichaRodeada(int x, int y)
{
	CellState tipoDeCasilla = TipoCasilla(x, y);
	if (TipoCasilla(x + 1, y) == EMPTY || (x - 1, y) == EMPTY || (x , y + 1) == EMPTY || (x , y - 1) == EMPTY )
	{
		return false; //no está rodeada
		if (tipoDeCasilla == KING)
		{
			if (TipoCasilla(x + 1, y) == ESCAPE || (x - 1, y) == ESCAPE || (x, y + 1) == ESCAPE || (x, y - 1) == ESCAPE )
				return false;
		}
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

Jugadores Hnefatafl::CapturarEnCasilla(int x, int y, CellState turno)
{
	if (turno == ATTACKER)
	{
		if (TipoCasilla(x + 1, y) == DEFENDER && (TipoCasilla(x + 2, y) == ESCAPE || TipoCasilla(x + 2, y) == ATTACKER) )
		{
			tablero[x + 1][y] = EMPTY;
			piezasBlancas--;
		}
		if (TipoCasilla(x - 1, y) == DEFENDER && (TipoCasilla(x - 2, y) == ESCAPE || TipoCasilla(x - 2, y) == ATTACKER) )
		{
			tablero[x - 1][y] = EMPTY;
			piezasBlancas--;
		}
		if (TipoCasilla(x, y + 1) == DEFENDER && (TipoCasilla(x, y + 2) == ESCAPE || TipoCasilla(x, y + 2) == ATTACKER))
		{
			tablero[x][y + 1] = EMPTY;
			piezasBlancas--;
		}
		if (TipoCasilla(x, y - 1) == DEFENDER && (TipoCasilla(x, y - 2) == ESCAPE || TipoCasilla(x, y - 2) == ATTACKER))
		{
			tablero[x][y - 1] = EMPTY;
			piezasBlancas--;
		}

		if (TipoCasilla(x + 1, y) == KING && (TipoCasilla(x + 2, y) == ESCAPE || TipoCasilla(x + 2, y) == ATTACKER))
		{
			return NEGRO; //Gana el jugador negro
		}
		if (TipoCasilla(x - 1, y) == KING && (TipoCasilla(x - 2, y) == ESCAPE || TipoCasilla(x - 2, y) == ATTACKER))
		{
			return NEGRO;
		}
		if (TipoCasilla(x, y + 1) == KING && (TipoCasilla(x, y + 2) == ESCAPE || TipoCasilla(x, y + 2) == ATTACKER))
		{
			return NEGRO;
		}
		if (TipoCasilla(x, y - 1) == KING && (TipoCasilla(x, y - 2) == ESCAPE || TipoCasilla(x, y - 2) == ATTACKER))
		{
			return NEGRO;
		}
	}
	else //Turno == DEFENDER
	{
		if (TipoCasilla(x + 1, y) == ATTACKER && (TipoCasilla(x + 2, y) == ESCAPE || TipoCasilla(x + 2, y) == DEFENDER))
		{
			tablero[x + 1][y] = EMPTY;
			piezasNegras--;
		}
		if (TipoCasilla(x - 1, y) == ATTACKER && (TipoCasilla(x - 2, y) == ESCAPE || TipoCasilla(x - 2, y) == DEFENDER))
		{
			tablero[x - 1][y] = EMPTY;
			piezasNegras--;
		}
		if (TipoCasilla(x, y + 1) == ATTACKER && (TipoCasilla(x, y + 2) == ESCAPE || TipoCasilla(x, y + 2) == DEFENDER))
		{
			tablero[x][y + 1] = EMPTY;
			piezasNegras--;
		}
		if (TipoCasilla(x, y - 1) == ATTACKER && (TipoCasilla(x, y - 2) == ESCAPE || TipoCasilla(x, y - 2) == DEFENDER))
		{
			tablero[x][y - 1] = EMPTY;
			piezasNegras--;
		}
	}
}