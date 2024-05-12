#include "Mundo.h"
#include <stdlib.h>

Mundo::Mundo()
{
	estado = INICIO;
	estadoAnterior = INICIO;
}

void Mundo::Dibuja()
{
	if (estado == INICIO) {
		//Sprite Menú principal
	}
	else if (estado == JUEGO_NORMAL) {
		//Poner los sprites correspondientes, añadir atributo a las piezas
		juego->Dibuja();
	}
	else if (estado == JUEGO_SW) {
		//Poner los sprites correspondientes, añadir atributo a las piezas
		juego->Dibuja();
	}
	else if (estado == MATE_AL_B) {
		//Sprite Ganan las negras
	}
	else if (estado == MATE_AL_N) {
		//Sprite Ganan las blancas
	}
	else if (estado == PROMOCION) {
		//Sprite Selección promocionado 
	}
	else if (estado == PAUSA) {
		juego->Dibuja(); //Esto o el sprite
		//sprite pausa
	}
}

void Mundo::tecla(unsigned char key)
{
	if (estado == INICIO) {
		if (key == 'n') {
			juego = new JuegoNormal();			
			estado = JUEGO_NORMAL;
		}
		else if (key == 's') {
			juego = new JuegoSW();			
			estado = JUEGO_SW;
		}
		else if (key == 'e') {
			exit(0);
		}
	} else if(estado==JUEGO_NORMAL||estado==JUEGO_SW){
		if (key == 'p') {
			estadoAnterior = estado;
			estado = PAUSA;
		}
	}
	else if (estado == PAUSA) {
		if (key == 'r') {
			estado = estadoAnterior;
		}
	}
	else if (estado == MATE_AL_B || estado == MATE_AL_N) {
		if (key == 'c') {
			estado = INICIO;
		}
	}
	else if (estado == PROMOCION) {
		//Seleccion de pieza en función de letra
	}
}

void Mundo::PuedeHacerMov(int columna, int fila)
{
	if (estado == JUEGO_NORMAL || estado == JUEGO_SW) {

		juego->Mueve(columna, fila); //Le pasamos a trablero las coordenadas del click
	}
}
