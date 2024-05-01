#include "Torre.h"
#include"freeglut.h"
void Torre::Dibuja(){
    glColor3ub(169, 50, 38);
    glutSolidSphere(0.2, 20, 20);
}

bool Torre::ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10])
{
	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) {
		return false;
	}
	else {

		Vector2D res = destino - origen;

		if (res.x == 0 && res.y != 0)
			return true;
		if (res.y == 0 && res.x != 0)
			return true;
		else return false;
	}
}
