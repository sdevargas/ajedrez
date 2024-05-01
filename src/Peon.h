#pragma once
#include"Pieza.h"

class Peon :public Pieza {
public:
	Peon(Color _color) : Pieza(_color, PEON) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
};