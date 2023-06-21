#ifndef FICHA_H
#define FICHA_H

enum class TipoFicha { REY, DEFENSOR, ATACANTE, VACIA };

class Ficha {
private:
	TipoFicha tipo;
	int posicionX;
	int posicionY;

public:
	Ficha(TipoFicha tipo, int posicionX, int posicionY);
	void establecerPosicion(int x, int y);
	TipoFicha obtenerTipo() const;
	int obtenerPosicionX() const;
	int obtenerPosicionY() const;
};

#endif
