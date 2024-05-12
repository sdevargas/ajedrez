#include "JuegoNormal.h"
#include "ETSIDI.h"
#include "freeglut.h"
JuegoNormal::JuegoNormal() 
{
	tablero = new Tablero(Tablero::NORMAL);
	promocion = false;
}

void JuegoNormal::Dibuja()
{
	tablero->Dibuja();

	//DIBUJO DEL FONDO
	glTranslatef(5.6, -2, 0); //Movemos el eje para que se dibuje centrado
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-10, 0, -0.01f);
	glTexCoord2d(1, 1); glVertex3f(10, 0, -0.01f);
	glTexCoord2d(1, 0); glVertex3f(10, 15, -0.01f);
	glTexCoord2d(0, 0); glVertex3f(-10, 15, -0.01f);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glTranslatef(-5.6, +2, 0); //Revertimos el desplazamiento del eje
}

void JuegoNormal::Mueve(int columna, int fila)
{
	tablero->Mueve(columna, fila);
	promocion = tablero->getPromocion();
}
