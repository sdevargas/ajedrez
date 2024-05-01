#pragma once
#include"Pieza.h"

class Reina :public Pieza {
public:
	Reina(Color _color) : Pieza(_color, REINA) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
};