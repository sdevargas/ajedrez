#include "Caballo.h"
#include"freeglut.h"

void Caballo::Dibuja()
{
	glColor3ub(255, 255, 255);
	glutSolidSphere(0.2, 20, 20);
}

bool Caballo::ValidaMov(Vector2D origen, Vector2D destino, Pieza* PosicionPiezas)
{
	return false;
}
