#pragma once
#include"Pieza.h"

class Torre :public Pieza {

public:
	Torre(Color _color): Pieza(_color, TORRE) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
};