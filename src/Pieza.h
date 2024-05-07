#pragma once
#include "Vector2D.h"

class Pieza {
public:
	typedef enum {BLANCO=0, NEGRO} Color; //Se define un tipo de dato para color
	typedef enum {PEON=0, TORRE, CABALLO, ALFIL, REINA, REY} Tipo; //Se define un tipo de dato para las piezas

protected:
	Color color;
	Tipo tipo;

public: 
	Pieza(Color color, Tipo tipo) {
		this->color = color;
		this-> tipo = tipo;
	}
	
	/*Estos métodos son virtuales porque cada pieza haga lo que le toca de una manera concreta,
	que las funciones sean virtuales es lo que les permite hacer esto que es el poliformismo*/
	virtual void Dibuja()=0; 
	virtual bool ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10]) = 0;

	Color getColor() {
		return color;
	}

	Tipo getTipo() {
		return tipo;
	}

	bool alPasoPresa = 0; //Facultad de pieza que es susceptible a captura al peon
	bool alPasoDone = 0; //Flag de pieza que ha capturado al peon exitosamente
};

