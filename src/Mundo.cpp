#include "Mundo.h"
#include <stdlib.h>
#include "freeglut.h"
#include "ETSIDI.h"

Mundo::Mundo()
{
	estado = INICIO;
	estadoAnterior = INICIO;
}

void Mundo::Dibuja()
{
	if (estado == INICIO) {
		//Sprite Menú principal
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 100);
		ETSIDI::printxy("JAQUE MATEAM", -13, 20);

		ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 35);
		ETSIDI::printxy("Pulse n para modo normal", -10, 5);

		ETSIDI::setFont("bin/fuentes/Starjedi.ttf", 20);
		ETSIDI::printxy("Pulse s para modo STAR WARS", -10, 0);
	}
	else if (estado == JUEGO_NORMAL) {
		
		juego->Dibuja();
	}
	else if (estado == JUEGO_SW) {
		
		juego->Dibuja();
	}
	else if (estado == MATE_AL_B) {
		//Sprite Ganan las negras
	}
	else if (estado == MATE_AL_N) {
		//Sprite Ganan las blancas
	}
	else if (estado == PROMOCION) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		if (estadoAnterior==JUEGO_NORMAL) {
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 50);
			ETSIDI::printxy("Seleccione la pieza a promocionar", -16, 20);

			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 30);
			ETSIDI::printxy("Pulse:", -16, 15);

			ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 60);
			ETSIDI::printxy("b", -6, 7);
			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 30);
			ETSIDI::printxy("a", -4, 5);

			ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 60);
			ETSIDI::printxy("h", -1, 7);
			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 30);
			ETSIDI::printxy("c", 1, 5);

			ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 60);
			ETSIDI::printxy("q", 4, 7);
			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 30);
			ETSIDI::printxy("r", 6, 5);

			ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 60);
			ETSIDI::printxy("r", 9, 7);
			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 30);
			ETSIDI::printxy("t", 11, 5);
			
		}
		else if (estadoAnterior==JUEGO_SW) {
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("bin/fuentes/Starjedi.ttf", 24);
			ETSIDI::printxy("Seleccione la pieza a promocionar", -16, 20);

			ETSIDI::setFont("bin/fuentes/Starjedi.ttf", 30);
			ETSIDI::printxy("Pulse:", -16, 15);

			ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 60);
			ETSIDI::printxy("b", -6, 7);
			ETSIDI::setFont("bin/fuentes/Starjedi.ttf", 30);
			ETSIDI::printxy("a", -4, 5);

			ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 60);
			ETSIDI::printxy("h", -1, 7);
			ETSIDI::setFont("bin/fuentes/Starjedi.ttf", 30);
			ETSIDI::printxy("c", 1, 5);

			ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 60);
			ETSIDI::printxy("q", 4, 7);
			ETSIDI::setFont("bin/fuentes/Starjedi.ttf", 30);
			ETSIDI::printxy("r", 6, 5);

			ETSIDI::setFont("bin/fuentes/CHEQ_TT.TTF", 60);
			ETSIDI::printxy("r", 9, 7);
			ETSIDI::setFont("bin/fuentes/Starjedi.ttf", 30);
			ETSIDI::printxy("t", 11, 5);
		}
		

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
		if (key == 't') {
			juego->setTipoPromo(Pieza::TORRE);
			estado = estadoAnterior;
		}
		else if (key == 'a') {
			juego->setTipoPromo(Pieza::ALFIL);
			estado = estadoAnterior;
		}
		else if (key == 'c') {
			juego->setTipoPromo(Pieza::CABALLO);
			estado = estadoAnterior;
		}
		else if (key == 'r') {
			juego->setTipoPromo(Pieza::REINA);
			estado = estadoAnterior;
		}
		//Seleccion de pieza en función de letra
	}
}

void Mundo::PuedeHacerMov(int columna, int fila)
{
	if (estado == JUEGO_NORMAL || estado == JUEGO_SW) {
		juego->Mueve(columna, fila); //Le pasamos a trablero las coordenadas del click
		if (juego->getPromocion()) {
			estadoAnterior = estado;
			estado = PROMOCION;
		}
	}
}
