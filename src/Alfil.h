#pragma once
#include"Pieza.h"

class Alfil :public Pieza {
public:
	Alfil(Color _color, Modo m) : Pieza(_color, ALFIL, m) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
};