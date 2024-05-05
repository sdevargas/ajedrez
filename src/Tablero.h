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
	int contadorClick;
	Vector2D origenPieza, destinoPieza;
	bool alPasoTurn = 0; //Para indicar que al siguiente turno se puede producir captura al paso

public:
	Pieza* posicionPiezas[limite_columnas][limite_filas]; //Se crea una matriz para albergar la posici�n de las piezas en el tablero
														/*Se necesita una matriz de piezas para registrar d�nde se encuentran las piezas en el tablero
														Con esa matriz verificas que puedes acceder a la casilla de destino */
	Tablero();
	void Dibuja();
	void Mueve(int x, int y);
	bool Jaque(Pieza* [limite_columnas][limite_filas]);
};
