#include "Tablero.h"
#include <freeglut.h>

void Tablero::Dibuja(){
;
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
}
