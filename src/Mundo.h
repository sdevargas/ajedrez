#pragma once
#include "Tablero.h"
#include"Juego.h"
#include"JuegoNormal.h"
#include"JuegoSW.h"

class Mundo {
public:
	Mundo();
	void PuedeHacerMov(int columna, int fila);	//Le pide a tablero que compruebe si puede realizar un movimiento después de hacer un click

	/*virtual ~Mundo();*/
	
	void Dibuja();
	void tecla(unsigned char key);

protected:
	Juego* juego;

	enum Estado {INICIO, SELECCION_JUGADORES, JUEGO_NORMAL, JUEGO_SW, PAUSA, MATE_AL_B, MATE_AL_N, PROMOCION, EMPATE};
	Estado estadoAnterior;
	Estado estado;
	Estado modoJuego;
	int jugadores;
};