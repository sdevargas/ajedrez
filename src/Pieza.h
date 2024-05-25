#pragma once
#include "Vector2D.h"
#include "Tablero.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "Tablero.h"
#include "Pieza.h"
#include "Mundo.h"


class Pieza {
public:
	typedef enum {BLANCO=0, NEGRO} Color; //Se define un tipo de dato para color
	typedef enum {PEON=0, TORRE, CABALLO, ALFIL, REINA, REY} Tipo; //Se define un tipo de dato para las piezas
	typedef enum { NORMAL = 0, SW }Modo;

protected:
	Color color;
	Tipo tipo;
	Modo modoJuego;

public: 
	Pieza(Color color, Tipo tipo, Modo m) {
		this->color = color;
		this-> tipo = tipo;
		this->modoJuego = m;
	}
	virtual ~Pieza() {}
	
	/*Estos m�todos son virtuales porque cada pieza haga lo que le toca de una manera concreta,
	que las funciones sean virtuales es lo que les permite hacer esto que es el poliformismo*/
	virtual void Dibuja()=0; 
	virtual bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]) = 0;
	virtual void ObtenerMovimientosPosibles(int x, int y, bool movimientos[11][10], Pieza* posicionPiezas[11][10])=0;
	Color getColor() {
		return color;
	}

	Tipo getTipo() {
		return tipo;
	}

	bool alPasoPresa = 0; //Facultad de pieza que es susceptible a captura al peon
	bool alPasoDone = 0; //Flag de pieza que ha capturado al peon exitosamente
};

