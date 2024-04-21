#include "Alfil.h"
#include "freeglut.h"
void Alfil::Dibuja()
{
	glColor3ub(41, 128, 185);
	glutSolidSphere(0.2, 20, 20);

}

bool Alfil::ValidaMov(Vector2D origen, Vector2D destino, Pieza* PosicionPiezas)
{
	return false;
}
