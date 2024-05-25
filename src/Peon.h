#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Tablero.h"
#include "Pieza.h"
#include "Mundo.h"

class Peon :public Pieza {
public:
	Peon(Color _color, Modo m) : Pieza(_color, PEON, m) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
	void ObtenerMovimientosPosibles(int x, int y,bool movimiento [11][10], Pieza* posicionPiezas[11][10]);
};