#pragma once
#include"Pieza.h"

class Caballo :public Pieza {
public:
	Caballo(Color _color) : Pieza(_color, CABALLO) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
};