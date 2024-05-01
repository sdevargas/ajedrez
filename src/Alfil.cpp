#include "Alfil.h"
#include "freeglut.h"
void Alfil::Dibuja()
{
	glColor3ub(41, 128, 185);
	glutSolidSphere(0.2, 20, 20);

}

bool Alfil::ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10])
{
	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) {
		return false;
	}
	else {

		Vector2D res = destino - origen;

		if (abs(res.x) == abs(res.y))
			return true;
		else
			return false;
	}
}
