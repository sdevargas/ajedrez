#pragma once
#include"Pieza.h"

class Caballo :public Pieza {
public:
	Caballo(Color _color, Modo m) : Pieza(_color, CABALLO, m) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
	Color getColor() {
		return color;
	}

	Tipo getTipo() {
		return tipo;
	}
};