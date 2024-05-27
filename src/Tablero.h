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
	typedef enum {NORMAL = 0, SW}Modo;

private:
	Turno turno;
	int contadorClick;
	Vector2D origenPieza, destinoPieza;
	bool alPasoTurn = 0; //Para indicar que al siguiente turno se puede producir captura al paso
	bool promocion = false; //Flag para saber si puede o no haber promocion
	Vector2D coordPromocion;
	Modo modo;
	bool mate_b;
	bool mate_n;

public:
	Pieza* posicionPiezas[limite_columnas][limite_filas]; //Se crea una matriz para albergar la posición de las piezas en el tablero
														/*Se necesita una matriz de piezas para registrar dónde se encuentran las piezas en el tablero
														Con esa matriz verificas que puedes acceder a la casilla de destino */
	Tablero(Modo m);

	void Dibuja();
	void Mueve(int x, int y);
	bool Jaque(Pieza* [limite_columnas][limite_filas]);
	bool Mate();
	void Promocion();
	void cambiaPromocion(Pieza::Tipo tipo);
	bool CompMovCompleto(Vector2D origen, Vector2D destino);
	void Historial(Pieza* p, int x, int y, bool r);


	bool getPromocion() {
		bool result = promocion;
		promocion = false;
		return result;
	}
	bool getmate_b() {
		return mate_b;
	}
	bool getmate_n() {
		return mate_n;
	}
};
