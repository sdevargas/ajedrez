#include "Tablero.h"
#include <freeglut.h>

#include<iostream>
using namespace std;

Tablero::Tablero(){

	contadorClick = 0;

	//Hacemos nullptr todas las casillas para que no haya basura
	for (int columna = 0; columna < limite_columnas; columna++) {
		for (int fila = 0; fila < limite_filas; fila++) {
			posicionPiezas[columna][fila] = nullptr;
		}
	}
	//Inicializamos en la matriz las posiciones de partida {PosicionPieza[i][j]= new "constructor del tipo de pieza" }
	/*Se hace de manera denámica porque no siempre tendrás las mismas piezas*/
	//PEONES
	for (int columna = 2; columna < 9; columna++) {
		posicionPiezas[columna][2] = new Peon(Pieza::BLANCO);
	}
	for (int columna = 2; columna < 9; columna++) {
		posicionPiezas[columna][7] = new Peon(Pieza::NEGRO);
	}
	//TORRES
	posicionPiezas[3][1] = new Torre(Pieza::BLANCO);
	posicionPiezas[7][1] = new Torre(Pieza::BLANCO);
	posicionPiezas[3][8] = new Torre(Pieza::NEGRO);
	posicionPiezas[7][8] = new Torre(Pieza::NEGRO);
	//CABALLOS
	posicionPiezas[4][1] = new Caballo(Pieza::BLANCO);
	posicionPiezas[6][1] = new Caballo(Pieza::BLANCO);
	posicionPiezas[4][8] = new Caballo(Pieza::NEGRO);
	posicionPiezas[6][8] = new Caballo(Pieza::NEGRO);
	//ALFILES
	posicionPiezas[5][1] = new Alfil(Pieza::BLANCO);
	posicionPiezas[5][0] = new Alfil(Pieza::BLANCO);
	posicionPiezas[5][8] = new Alfil(Pieza::NEGRO);
	posicionPiezas[5][9] = new Alfil(Pieza::NEGRO);
	//REYES
	posicionPiezas[4][0] = new Rey(Pieza::BLANCO);
	posicionPiezas[4][9] = new Rey(Pieza::NEGRO);
	//REINAS
	posicionPiezas[6][0] = new Reina(Pieza::BLANCO);
	posicionPiezas[6][9] = new Reina(Pieza::NEGRO);



	this->turno = BLANCAS;
}

void Tablero::Dibuja(){
	//DIBUJO DE LAS CASILLAS
	for (int columna = 0; columna < limite_columnas; columna++) {
		for (int fila = 0; fila < limite_filas; fila++) {
			if (fila + columna > 15 || fila + columna < 4 ||	
				columna - fila < -5 || columna - fila > 6) { //Restricción de casillas
				continue;
			}else{
				glDisable(GL_LIGHTING);
				if ((fila + columna) % 2 == 0) {
					glColor3ub(30, 132, 73/*70, 41, 5*/); //OSCURO
				}
				else glColor3ub(169, 223, 191/*245, 203, 138*/); //CLARO
				glBegin(GL_POLYGON);
				glVertex3d(columna, fila, 0);
				glVertex3d(columna +1, fila, 0);
				glVertex3d(columna + 1, fila + 1, 0);
				glVertex3d(columna, fila +1, 0);
				glEnd();
				glEnable(GL_LIGHTING);
			
			}
		}
	}

	//DIBUJO DE LAS PIEZAS
	for (int columna = 0; columna < limite_columnas; columna++) {
		for (int fila = 0; fila < limite_filas; fila++) {
			if (posicionPiezas[columna][fila] != nullptr) {
				glTranslatef(columna +0.5, fila+0.5, 0); //Desplazas el eje de cordenadas
				posicionPiezas[columna][fila]->Dibuja(); //Llamada al método Dibuja de la pieza que corresponde
				glTranslatef(-columna - 0.5, -fila - 0.5, 0);
			}
		}
	}
}

void Tablero::Mueve(int x, int y)
{
	if (contadorClick == 2) {
		contadorClick = 1;
	}
	else contadorClick++;

	if (contadorClick == 1) {

		if (posicionPiezas[x][y] != nullptr) {

			if (posicionPiezas[x][y]->getColor() == turno) { //Si el color de la posición es igual al turno
				cout << "1er click valido" << endl;
				origenPieza.x = x;
				origenPieza.y = y;
				return; //Salimos de la función esperando el siguiente click
			}
			else { 
				contadorClick = 0; 
				cout << "1er click NO valido por color" << endl; 
			}//Reiniciamos el turno 
		}
		else {
			contadorClick = 0; 
			cout << "1er click NO valido por pieza" << endl;
		} //Reiniciamosel turno
	}
	else if (contadorClick == 2) {

		if (posicionPiezas[x][y]!=nullptr && posicionPiezas[x][y]->getColor() == turno) { 
			contadorClick = 0; cout << "2o click NO valido por pieza de turno" << endl;
		}
		else {
			destinoPieza.x = x;
			destinoPieza.y = y;

			if (posicionPiezas[origenPieza.x][origenPieza.y]->ValidaMov(origenPieza, destinoPieza, posicionPiezas)) { //Pieza del 1er click llama a SU validar movimiento (polimorfismo)
				posicionPiezas[destinoPieza.x][destinoPieza.y] = posicionPiezas[origenPieza.x][origenPieza.y]; //Se le asigna la nueva posición a la pieza
				posicionPiezas[origenPieza.x][origenPieza.y] = nullptr; //Se elimina la pieza del origen
				
				turno = (turno == BLANCAS) ? NEGRAS : BLANCAS; //Cambio de turno
				cout << "TURNO DE: " << turno << endl;
			} else { 
				contadorClick = 0; 
				cout << "2o click NO valido por movimiento de la propia pieza" << endl; 
			}//Reiniciamos el turno
		}
	}
	
}
