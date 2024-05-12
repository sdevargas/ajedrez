#pragma once
#include"Tablero.h"

class Juego {
public:
	Juego() ;
	virtual void Dibuja()=0;
	virtual void Mueve(int columna, int fila)=0;

protected:
	Tablero* tablero;
};