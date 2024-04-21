#include "Tablero.h"
#include <freeglut.h>

Tablero::Tablero(){
	//Hacemos nullptr todas las casillas para que no haya basura
	for (int columna = 0; columna < limite_columnas; columna++) {
		for (int fila = 0; fila < limite_filas; fila++) {
			PosicionPiezas[columna][fila] = nullptr;
		}
	}
	//Inicializamos en la matriz las posiciones de partida {PosicionPieza[i][j]= new "constructor del tipo de pieza" }
	/*Se hace de manera denámica porque no siempre tendrás las mismas piezas*/
	//PEONES
	for (int columna = 2; columna < 9; columna++) {
		PosicionPiezas[columna][2] = new Peon(Pieza::BLANCO);
	}
	for (int columna = 2; columna < 9; columna++) {
		PosicionPiezas[columna][7] = new Peon(Pieza::NEGRO);
	}
	//TORRES
	PosicionPiezas[3][1] = new Torre(Pieza::BLANCO);
	PosicionPiezas[7][1] = new Torre(Pieza::BLANCO);
	PosicionPiezas[3][8] = new Torre(Pieza::NEGRO);
	PosicionPiezas[7][8] = new Torre(Pieza::NEGRO);
	//CABALLOS
	PosicionPiezas[4][1] = new Caballo(Pieza::BLANCO);
	PosicionPiezas[6][1] = new Caballo(Pieza::BLANCO);
	PosicionPiezas[4][8] = new Caballo(Pieza::NEGRO);
	PosicionPiezas[6][8] = new Caballo(Pieza::NEGRO);
	//ALFILES
	PosicionPiezas[5][1] = new Alfil(Pieza::BLANCO);
	PosicionPiezas[5][0] = new Alfil(Pieza::BLANCO);
	PosicionPiezas[5][8] = new Alfil(Pieza::NEGRO);
	PosicionPiezas[5][9] = new Alfil(Pieza::NEGRO);
	//REYES
	PosicionPiezas[4][0] = new Rey(Pieza::BLANCO);
	PosicionPiezas[4][9] = new Rey(Pieza::NEGRO);
	//REINAS
	PosicionPiezas[6][0] = new Reina(Pieza::BLANCO);
	PosicionPiezas[6][9] = new Reina(Pieza::NEGRO);



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
			if (PosicionPiezas[columna][fila] != nullptr) {
				glTranslatef(columna +0.5, fila+0.5, 0); //Desplazas el eje de cordenadas
				PosicionPiezas[columna][fila]->Dibuja(); //Llamada al método Dibuja de la pieza que corresponde
				glTranslatef(-columna - 0.5, -fila - 0.5, 0);
			}
		}
	}
}
