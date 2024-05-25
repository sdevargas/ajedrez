#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Tablero.h"
#include "Pieza.h"
#include "Mundo.h"

class Caballo :public Pieza {
public:
	Caballo(Color _color, Modo m) : Pieza(_color, CABALLO, m) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
	void ObtenerMovimientosPosibles(int x, int y, bool movimientos[11][10], Pieza* posicionPiezas[11][10]);
};