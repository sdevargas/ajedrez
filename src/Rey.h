#pragma once
#include"Pieza.h"

class Rey :public Pieza {
public:
	Rey(Color _color, Modo m) : Pieza(_color, REY, m) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
	Color getColor() {
		return color;
	}

	Tipo getTipo(){
		return tipo;
	}
};