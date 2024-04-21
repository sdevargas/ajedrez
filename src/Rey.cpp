#include "Rey.h"
#include"freeglut.h"

void Rey::Dibuja(){
	glColor3ub(0, 0, 34);
	glutSolidSphere(0.2, 20, 20);
}

bool Rey::ValidaMov(Vector2D origen, Vector2D destino, Pieza* PosicionPiezas)
{
	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) {
		return false;
	}
	else {
		//COMPLETAR
	}
}
