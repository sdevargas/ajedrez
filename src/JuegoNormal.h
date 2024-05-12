#pragma once
#include "Juego.h"

class JuegoNormal : public Juego {
public:
	JuegoNormal();
	void Dibuja();
	void Mueve(int columna, int fila);

protected:
	Tablero* tablero;
};