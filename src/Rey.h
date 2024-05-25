#pragma once
#include"Pieza.h"
#include "Tablero.h"

class Rey :public Pieza {
public:
	Rey(Color _color, Modo m) : Pieza(_color, REY, m) {}
	void Dibuja() override;
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]) override;
	void ObtenerMovimientosPosibles(int x, int y, bool movimientos[11][10], Pieza* posicionPiezas[11][10], Tablero& tablero);
};