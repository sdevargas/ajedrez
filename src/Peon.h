#pragma once
#include "Pieza.h"
#include "Tablero.h"

class Peon :public Pieza {
public:
	Peon(Color _color, Modo m) : Pieza(_color, PEON, m) {}
	void Dibuja();
	bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]);
	void ObtenerMovimientosValidos(int x, int y,bool movimiento [limite_columnas][limite_filas], Pieza* posicionPiezas[limite_columnas][limite_filas]);
};