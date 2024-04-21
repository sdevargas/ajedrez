#pragma once
#include "Pieza.h"
#include"Vector2D.h"
#include "Peon.h"
#include "Torre.h"
#include "Caballo.h"
#include "Rey.h"
#include "Reina.h"
#include"Alfil.h"

#define limite_filas 10
#define limite_columnas 11

class Tablero {
public:
	typedef enum { BLANCAS = 0, NEGRAS } Turno;

private:
	Turno turno;

public:
	Pieza* PosicionPiezas[limite_columnas][limite_filas]; //Se crea una matriz para albergar la posición de las piezas en el tablero
/*Se necesita una matriz de piezas para registrar dónde se encuentran las piezas en el tablero
Con esa matriz verificas que puedes acceder a la casilla de destino */

	Tablero();
	void Dibuja();

};
