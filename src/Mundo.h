#pragma once
#include "Tablero.h"

class Mundo {
public:
	Tablero tablero;

	Mundo();
	void PuedeHacerMov(int x, int y);	//Le pide a tablero que compruebe si puede realizar un movimiento despu�s de hacer un click
};