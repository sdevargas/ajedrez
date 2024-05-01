#include "Peon.h"
#include "freeglut.h"

void Peon::Dibuja(){
	glColor3ub(100, 255, 100);
	glutSolidSphere(0.2, 20, 20);
}

bool Peon::ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10])
{
	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) { //Se sale del tablero
		return false;
	}
	else {
		Vector2D res = destino - origen;

		if (Pieza::color == BLANCO) { //Piezas blancas
			if (abs(res.x) == 1 && res.y == 1 && posicionPiezas[destino.x][destino.y] != nullptr) //Mover en diagonal comiendo pieza
				return true;
			else if (res.x == 0) { //Mover en vertical
				if (origen.y == 2) //Está en posicion de salida de los peones
				{
					if ((res.y == 2 && posicionPiezas[origen.x][origen.y + 1] == nullptr && posicionPiezas[origen.x][origen.y + 2] == nullptr)
						|| (res.y == 1 && posicionPiezas[origen.x][origen.y + 1] == nullptr)) //Puede moverse uno o dos si no hay pieza en destino
						return true;
					else
						return false;
				}
				else {  //Esta en el resto del tablero
					if (res.y == 1 && posicionPiezas[origen.x][origen.y + 1] == nullptr) //Solo puede moverse una
						return true;
					else
						return false;
				}
			}
			else //Mover en horizontal
				return false;
		}

		else { //Piezas negras
			if (abs(res.x) == 1 && res.y == -1 && posicionPiezas[destino.x][destino.y] != nullptr) //Mover en diagonal comiendo pieza
				return true;
			else if (res.x == 0) { //Mover en vertical
				if (origen.y == 7) //Está en posicion de salida de los peones
				{
					if ((res.y == -2 && posicionPiezas[origen.x][origen.y - 1] == nullptr && posicionPiezas[origen.x][origen.y - 2] == nullptr)
						|| (res.y == -1 && res.x == 0 && posicionPiezas[origen.x][origen.y - 1] == nullptr)) //Puede moverse uno o dos si no hay pieza en destino
						return true;
					else
						return false;
				}
				else { //Esta en el resto del tablero
					if (res.y == -1 && posicionPiezas[origen.x][origen.y - 1] == nullptr) //Solo puede moverse una
						return true;
					else
						return false;
				}
			}
			else //Mover en horizontal
				return false;
		}
	}
}