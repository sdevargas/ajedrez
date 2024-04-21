#include "Rey.h"
#include"freeglut.h"

void Rey::Dibuja(){
	glColor3ub(0, 0, 34);
	glutSolidSphere(0.2, 20, 20);
}

bool Rey::ValidaMov(Vector2D origen, Vector2D destino, Pieza* PosicionPiezas)
{
	return false;
}
