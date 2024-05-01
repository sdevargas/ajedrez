#pragma once
#include"Pieza.h"

class Alfil :public Pieza {
public:
	Alfil(Color _color) : Pieza(_color, ALFIL) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza** posicionPiezas);
};