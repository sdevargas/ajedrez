#include "Peon.h"
#include "freeglut.h"

void Peon::Dibuja(){
	glColor3ub(100, 255, 100);
	glutSolidSphere(0.2, 20, 20);
}

bool Peon::ValidaMov(Vector2D origen, Vector2D destino, Pieza* PosicionPiezas)
{
	return false;
}
