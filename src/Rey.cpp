#include "Rey.h"
#include"freeglut.h"

void Rey::Dibuja(){
	glColor3ub(0, 0, 34);
	glutSolidSphere(0.2, 20, 20);
}

bool Rey::ValidaMov(Vector2D origen, Vector2D destino, Pieza** posicionPiezas)
{
	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) {
		return false;
	}
	else {
		Vector2D res = destino - origen;

		if (abs(res.x) == 1 && res.y == 0)
			return true;
		else if (res.x == 0 && abs(res.y) == 1)
			return true;
		else if ((abs(res.x) == abs(res.y)) && (abs(res.x) == 1))
			return true;
		else
			return false;
	}
}
