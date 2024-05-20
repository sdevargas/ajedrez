#pragma once
#include"Pieza.h"
#include "Tablero.h"

class Alfil :public Pieza {
public:
	Alfil(Color _color, Modo m) : Pieza(_color, ALFIL, m) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
	void ObtenerMovimientosValidos(int x, int y, bool movimientos[11][10], Pieza* posicionPiezas[11][10]);
};