
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
	piezasBlancas = 13;
	piezasNegras = 24;
}
bool Hnefatafl::MoverFicha(int origenX, int origenY, int destinoX, int destinoY)
{
	std::cout << "intentando mover: " << origenX << "." << origenY
		<< " a " << destinoX << "." << destinoY << std::endl;
	
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
	if (destino != EMPTY && destino != ESCAPE)
		return false;
	if (origenX == destinoX) //Moviendose en el eje Y;
	{
		for (size_t i = 1; i < std::abs(origenY - destinoY); i++)
		{
			if (origenY > destinoY)
			{
				if (TipoCasilla(origenX, origenY - i) == ATTACKER || TipoCasilla(origenX, origenY - i) == DEFENDER || TipoCasilla(origenX, origenY - i) == KING)
					return false;
			}
			if (origenY < destinoY)
			{
				if (TipoCasilla(origenX, origenY + i) == ATTACKER || TipoCasilla(origenX, origenY + i) == DEFENDER || TipoCasilla(origenX, origenY + i) == KING  )
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
				if (TipoCasilla(origenX - i, origenY) == ATTACKER || TipoCasilla(origenX - i, origenY) == DEFENDER || TipoCasilla(origenX - i, origenY) == KING )
					return false;
			}
			if (origenX < destinoX)
			{
				if (TipoCasilla(origenX + i, origenY) == ATTACKER || TipoCasilla(origenX + i, origenY) == DEFENDER || TipoCasilla(origenX + i, origenY) == KING)
					return false;
			}
		}
	}
	
	
	tablero[destinoX][destinoY] = tablero[origenX][origenY];
	if (TipoCasilla(destinoX,destinoY) == KING )
	{
		if (destinoX == 0 && destinoY == 0) // el rey escapó
		{
			victoria = BLANCO;
			return true;
		}
		if (destinoX == 0 && destinoY == 10) // el rey escapó
		{
			victoria = BLANCO;
			return true;
		}
		if (destinoX == 10 && destinoY == 0) // el rey escapó
		{
			victoria = BLANCO;
			return true;
		}
		if (destinoX == 10 && destinoY == 10) // el rey escapó
		{
			victoria = BLANCO;
			return true;
		}
	}
	if (origenX == 5 && origenY == 5)
	{
		tablero[origenX][origenY] = ESCAPE;
		
	}
	else
	{
		tablero[origenX][origenY] = EMPTY;
	}
	victoria = CapturarEnCasilla(destinoX, destinoY, origen);
	return true;


}
bool Hnefatafl::EvalFichaRodeada(int x, int y)
{
	CellState tipoDeCasilla = TipoCasilla(x, y);
	/*
	*/
	std::cout << "Prueba Ficha rodeada: x:" << x <<" y:"<<y
		<< " x+1 y " << TipoCasilla(x + 1, y) << " "  
		<< "x-1 y " << TipoCasilla(x - 1, y) << " "  
		<< "x y+1 " << TipoCasilla(x , y+1) << " "  
		<< "x y-1 " << TipoCasilla(x , y-1) << " "  
		<<std::endl;
		
	if (TipoCasilla(x + 1, y) == EMPTY)//Abajo hay casilla vacía
		return false;
	if (TipoCasilla(x - 1, y) == EMPTY)//Abajo hay casilla vacía
		return false;
	if (TipoCasilla(x , y+1) == EMPTY)//Abajo hay casilla vacía
		return false;
	if (TipoCasilla(x , y-1) == EMPTY)//Abajo hay casilla vacía
		return false;

	if (tipoDeCasilla == KING)
	{
		if (TipoCasilla(x + 1, y) == ESCAPE)//Abajo hay casilla de escape
			return false;
		if (TipoCasilla(x - 1, y) == ESCAPE)//Arriba hay casilla de escape
			return false;
		if (TipoCasilla(x, y + 1) == ESCAPE)//A la derecha hay casilla de escape
			return false;
		if (TipoCasilla(x, y - 1) == ESCAPE)//A la izq hay casilla de escape
			return false;
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
		if (TipoCasilla(x + 1, y) == ATTACKER && (TipoCasilla(x + 2, y) == ESCAPE || TipoCasilla(x + 2, y) == DEFENDER || TipoCasilla(x + 2, y) == KING))
		{
			tablero[x + 1][y] = EMPTY;
			piezasNegras--;
		}
		if (TipoCasilla(x - 1, y) == ATTACKER && (TipoCasilla(x - 2, y) == ESCAPE || TipoCasilla(x - 2, y) == DEFENDER || TipoCasilla(x - 2, y) == KING))
		{
			tablero[x - 1][y] = EMPTY;
			piezasNegras--;
		}
		if (TipoCasilla(x, y + 1) == ATTACKER && (TipoCasilla(x, y + 2) == ESCAPE || TipoCasilla(x, y + 2) == DEFENDER || TipoCasilla(x , y + 2) == KING))
		{
			tablero[x][y + 1] = EMPTY;
			piezasNegras--;
		}
		if (TipoCasilla(x, y - 1) == ATTACKER && (TipoCasilla(x, y - 2) == ESCAPE || TipoCasilla(x, y - 2) == DEFENDER || TipoCasilla(x , y - 2) == KING))
		{
			tablero[x][y - 1] = EMPTY;
			piezasNegras--;
		}
		//CONDICIONES DE VICTORIA 
		if (piezasBlancas == 0) // Jugador blanco sin piezas, gana el negro.
			return NEGRO;
		if (piezasNegras == 0) //Jugador negro sin piezas, gana el blanco.
			return BLANCO;
		//Todavía nadie gana, el juego está INDETERMINADO.
		return INDETERMINADO;

	}
}