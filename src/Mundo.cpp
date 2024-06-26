#include "Mundo.h"
#include <stdlib.h>
#include "freeglut.h"
#include "ETSIDI.h"

Mundo::Mundo()
{
	estado = INICIO;
	estadoAnterior = INICIO;
	jugadores = 0;
}

void Mundo::Dibuja()
{
	if (estado == INICIO) {
		
		//Sprite Men� principal
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

	else if (estado == SELECCION_JUGADORES) {

		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 50);
		ETSIDI::printxy("Seleccione el numero de jugadores", -16, 20);

		ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 35);
		ETSIDI::printxy("Pulse 1 para un jugador (contra IA)", -10, 5);
		ETSIDI::printxy("Pulse 2 para dos jugadores", -10, 0);

	}


	else if (estado == JUEGO_NORMAL) {
		
		juego->Dibuja();
	}
	else if (estado == JUEGO_SW) {
		
		juego->Dibuja();
	}
	else if (estado == MATE_AL_B) {
		if (estadoAnterior==JUEGO_NORMAL) {
			//Sprite Ganan las negras
		//DIBUJO DEL FONDO
			glTranslatef(5.6, -2, 0); //Movemos el eje para que se dibuje centrado
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/mate_RB.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex3f(-10.5, 0, -0.01f);
			glTexCoord2d(1, 1); glVertex3f(10, 0, -0.01f);
			glTexCoord2d(1, 0); glVertex3f(10, 15, -0.01f);
			glTexCoord2d(0, 0); glVertex3f(-10.5, 15, -0.01f);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);

			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 40);
			ETSIDI::printxy("m para salir al MENU PRINCIPAL", -6, 1);
		}
		else if (estadoAnterior==JUEGO_SW) {
			//Sprite Ganan las negras
		//DIBUJO DEL FONDO
			glTranslatef(5.6, -2, 0); //Movemos el eje para que se dibuje centrado
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/mate_RBsw.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex3f(-10.5, 0, -0.01f);
			glTexCoord2d(1, 1); glVertex3f(10, 0, -0.01f);
			glTexCoord2d(1, 0); glVertex3f(10, 15, -0.01f);
			glTexCoord2d(0, 0); glVertex3f(-10.5, 15, -0.01f);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);

			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 40);
			ETSIDI::printxy("m para salir al MENU PRINCIPAL", -6, 1);
		}
		
	
	}
	else if (estado == MATE_AL_N) {
		if (estadoAnterior == JUEGO_NORMAL) {
			//Sprite Ganan las blancas
			//DIBUJO DEL FONDO
			glTranslatef(5.6, -2, 0); //Movemos el eje para que se dibuje centrado
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/mate_RN.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex3f(-10.5, 0, -0.01f);
			glTexCoord2d(1, 1); glVertex3f(10, 0, -0.01f);
			glTexCoord2d(1, 0); glVertex3f(10, 15, -0.01f);
			glTexCoord2d(0, 0); glVertex3f(-10.5, 15, -0.01f);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);

			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 40);
			ETSIDI::printxy("m para salir al MENU PRINCIPAL", -6, 1);
		}
		else if (estadoAnterior == JUEGO_SW) {
			//Sprite Ganan las blancas
			//DIBUJO DEL FONDO
			glTranslatef(5.6, -2, 0); //Movemos el eje para que se dibuje centrado
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/mate_RNsw.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex3f(-10.5, 0, -0.01f);
			glTexCoord2d(1, 1); glVertex3f(10, 0, -0.01f);
			glTexCoord2d(1, 0); glVertex3f(10, 15, -0.01f);
			glTexCoord2d(0, 0); glVertex3f(-10.5, 15, -0.01f);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);

			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 40);
			ETSIDI::printxy("m para salir al MENU PRINCIPAL", -6, 1);
		}
		
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
		

		//Sprite Selecci�n promocionado 
	}
	else if (estado == PAUSA) {
		//juego->Dibuja(); //Esto o el sprite
		//sprite pausa
				

		if (estadoAnterior == JUEGO_NORMAL) {

			glTranslatef(5.6, -2, 0); //Movemos el eje para que se dibuje centrado
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/FondoPausa.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex3f(-10.5, -5, -0.01f);
			glTexCoord2d(1, 1); glVertex3f(10, -5, -0.01f);
			glTexCoord2d(1, 0); glVertex3f(10, 22, -0.01f);
			glTexCoord2d(0, 0); glVertex3f(-10.5, 22, -0.01f);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
			//glTranslatef(-5.6, +2, 0); //Revertimos el desplazamiento del eje
			
			ETSIDI::setTextColor(0.752f, 0.223f, 0.168f);
			/*ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 50);
			ETSIDI::printxy("Pulse: ", -16, 30);*/

			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 40);
			ETSIDI::printxy("c para CONTINUAR", -2, 3);

			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 40);
			ETSIDI::printxy("n para NUEVA PARTIDA", -3, 2);

			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 40);
			ETSIDI::printxy("m para salir al MENU PRINCIPAL", -6, 1);


		}
		else if (estadoAnterior == JUEGO_SW) {

			glTranslatef(5.6, -2, 0); //Movemos el eje para que se dibuje centrado
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/PausaModoSW.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex3f(-10.5, -5, -0.01f);
			glTexCoord2d(1, 1); glVertex3f(9, -5, -0.01f);
			glTexCoord2d(1, 0); glVertex3f(9, 15, -0.01f);
			glTexCoord2d(0, 0); glVertex3f(-10.5, 15, -0.01f);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);
			//glTranslatef(-5.6, +2, 0); //Revertimos el desplazamiento del eje

			ETSIDI::setTextColor(0.752f, 0.223f, 0.168f);
			//ETSIDI::setFont("bin/fuentes/Starjedi.ttf", 50);
			//ETSIDI::printxy("Pulse: ", -6, 5);

			ETSIDI::setFont("bin/fuentes/Starjedi.ttf", 20);
			ETSIDI::printxy("c para continuar", -2, 12);

			ETSIDI::setFont("bin/fuentes/Starjedi.ttf", 20);
			ETSIDI::printxy("n para nueva partida", -4, 11);

			ETSIDI::setFont("bin/fuentes/Starjedi.ttf", 20);
			ETSIDI::printxy("m para salir al menu principal", -7, 1);


			
		}

	}
	else if (estado == EMPATE) {
		if (estadoAnterior == JUEGO_SW) {
			glTranslatef(5.6, -2, 0); //Movemos el eje para que se dibuje centrado
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/empate_sw.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex3f(-10.5, 0, -0.01f);
			glTexCoord2d(1, 1); glVertex3f(10, 0, -0.01f);
			glTexCoord2d(1, 0); glVertex3f(10, 15, -0.01f);
			glTexCoord2d(0, 0); glVertex3f(-10.5, 15, -0.01f);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);

			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 40);
			ETSIDI::printxy("m para salir al MENU PRINCIPAL", -6, 1);
		}
		else if (estadoAnterior == JUEGO_NORMAL) {
			glTranslatef(5.6, -2, 0); //Movemos el eje para que se dibuje centrado
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/empate_normal.png").id);
			glDisable(GL_LIGHTING);
			glBegin(GL_POLYGON);
			glColor3f(1, 1, 1);
			glTexCoord2d(0, 1); glVertex3f(-10.5, 0, -0.01f);
			glTexCoord2d(1, 1); glVertex3f(10, 0, -0.01f);
			glTexCoord2d(1, 0); glVertex3f(10, 15, -0.01f);
			glTexCoord2d(0, 0); glVertex3f(-10.5, 15, -0.01f);
			glEnd();
			glEnable(GL_LIGHTING);
			glDisable(GL_TEXTURE_2D);

			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("bin/fuentes/DecoheadFREE.otf", 40);
			ETSIDI::printxy("m para salir al MENU PRINCIPAL", -6, 1);
		}
	}
}

void Mundo::tecla(unsigned char key)
{
	if (estado == INICIO) {
		if (key == 'n') {
			modoJuego = JUEGO_NORMAL;
			estado = SELECCION_JUGADORES;
		}
		else if (key == 's') {
			modoJuego = JUEGO_SW;
			estado = SELECCION_JUGADORES;
		}
		else if (key == 'e') {
			exit(0);
		}
	}
	else if (estado == SELECCION_JUGADORES) {
		if (key == '1') {
			jugadores = 1;
			if (modoJuego == JUEGO_NORMAL) {
				delete juego;
				juego = new JuegoNormal(true); // true indica que hay un bot
			}
			else if (modoJuego == JUEGO_SW) {
				delete juego;
				juego = new JuegoSW(true); // true indica que hay un bot
			}
			estado = modoJuego;
		}
		
		else if (key == '2') {
			jugadores = 2;
			if (modoJuego == JUEGO_NORMAL) {
				delete juego;
				juego = new JuegoNormal(false); // false indica que no hay bot
			}
			else if (modoJuego == JUEGO_SW) {
				delete juego;
				juego = new JuegoSW(false); // false indica que no hay bot
			}
			estado = modoJuego;
		}
		
	}	

    else if(estado==JUEGO_NORMAL||estado==JUEGO_SW){
		if (key == 'p') {
			estadoAnterior = estado;
			estado = PAUSA;
		}
	}
	else if (estado == PAUSA) {
		if (key == 'c') {
			estado = estadoAnterior;
		}
		else if (key == 'n') {
			if (jugadores == 1) {
				if (estadoAnterior == JUEGO_NORMAL) {
					delete juego;
					juego = new JuegoNormal(true);
					estado = estadoAnterior;
				}
				else if (estadoAnterior == JUEGO_SW)
				{
					delete juego;
					juego = new JuegoSW(true);
					estado = estadoAnterior;
				}
			}
			else if (jugadores == 2) {
				if (estadoAnterior == JUEGO_NORMAL) {
					delete juego;
					juego = new JuegoNormal(false);
					estado = estadoAnterior;
				}
				else if (estado == JUEGO_SW)
				{
					delete juego;
					juego = new JuegoSW(false);
					estado = estadoAnterior;
				}
			}
						
		}
		else if (key == 'm') {
			estado = INICIO;
			jugadores = 0;
		}
		//Seleccion de opciones del menu Pausa
	}
	else if (estado == MATE_AL_B || estado == MATE_AL_N || estado == EMPATE) {
		if (key == 'm') {
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
		//Seleccion de pieza en funci�n de letra
	}
}

void Mundo::PuedeHacerMov(int columna, int fila)
{
	if (estado == JUEGO_NORMAL || estado == JUEGO_SW) {
		juego->Mueve(columna, fila); //Le pasamos a trablero las coordenadas del click
		if (juego->getmate_n()) {
			estadoAnterior = estado;
			estado = MATE_AL_N;
		}
		else if (juego->getmate_b()) {
			estadoAnterior = estado;
			estado = MATE_AL_B;
		}
		else if (juego->getPromocion()) {
			estadoAnterior = estado;
			estado = PROMOCION;
		}
		else if (juego->getempate()) {
			estadoAnterior = estado;
			estado = EMPATE;
		}
	}
}
