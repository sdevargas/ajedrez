#include "Peon.h"
#include "freeglut.h"

void Peon::Dibuja(){
	glColor3ub(100, 255, 100);
	glutSolidSphere(0.2, 20, 20);
}

bool Peon::ValidaMov(Vector2D origen, Vector2D destino, Pieza* PosicionPiezas)
{
	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) {
		return false;
	}
	else {
		//COMPLETAR
	}
	
}
