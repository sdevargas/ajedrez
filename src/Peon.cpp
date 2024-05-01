#include "Peon.h"
#include "freeglut.h"

void Peon::Dibuja(){
	glColor3ub(100, 255, 100);
	glutSolidSphere(0.2, 20, 20);
}

bool Peon::ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10])
{

	Vector2D res = destino - origen; 

	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) {
		return false;
	}
	else {
		if (Pieza::color == BLANCO) { //piezas blancas
			if (origen.y == 2) //posicion de salida de los peones
			{
				if ((res.y == 2 && res.x == 0) || (res.y == 1 && res.x == 0))
					return true;
				else
					return false;
			}
			else {  //En el resto del tablero, solo mover hacia alante
				if (res.y == 1 && res.x == 0)
					return true;
				else
					return false;
			}
		}

		else { //piezas negras

			if (origen.y == 7)
			{
				if ((res.y == -2 && res.x == 0) || (res.y == -1 && res.x == 0)) //posicion de salida de los peones
					return true;
				else
					return false;
			}
			else {
				if (res.y == -1 && res.x == 0) //En el resto del tablero, solo mover hacia alante
					return true;
				else
					return false;
			}
		}
	}
	
}
