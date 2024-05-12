#pragma once
#include "Juego.h"

class JuegoSW : public Juego {
public:
	JuegoSW();
	void Dibuja();
	void Mueve(int columna, int fila);

protected:
	Tablero* tablero;
};