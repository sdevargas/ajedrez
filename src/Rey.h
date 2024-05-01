#pragma once
#include"Pieza.h"

class Rey :public Pieza {
public:
	Rey(Color _color) : Pieza(_color, REY) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza** posicionPiezas);
};