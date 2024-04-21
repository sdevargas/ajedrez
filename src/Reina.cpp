#include "Reina.h"
#include"freeglut.h"

void Reina::Dibuja(){
	glColor3ub(195, 155, 211);
	glutSolidSphere(0.2, 20, 20);
}

bool Reina::ValidaMov(Vector2D origen, Vector2D destino, Pieza* PosicionPiezas)
{
	return false;
}
