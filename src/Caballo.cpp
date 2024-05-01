#include "Caballo.h"
#include"freeglut.h"

void Caballo::Dibuja()
{
	glColor3ub(255, 255, 255);
	glutSolidSphere(0.2, 20, 20);
}

bool Caballo::ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10])
{
	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) {
		return false;
	}
	else {

		Vector2D res = destino - origen;

		if (abs(res.x) == 2 && abs(res.y) == 1)
			return true;
		if (abs(res.y) == 2 && abs(res.x) == 1)
			return true;
		else
			return false;
	}
}
