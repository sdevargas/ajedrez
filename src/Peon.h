#pragma once
#include"Pieza.h"

class Peon :public Pieza {
public:
	Peon(Color _color, Modo m) : Pieza(_color, PEON, m) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
};