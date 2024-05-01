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
		destino.x - destino.y < -5 || destino.x - destino.y > 6) { //Se sale del tablero
		return false;
	}
	else {
		Vector2D res = destino - origen;

		if (abs(res.x) == abs(res.y)) { //Movimiento diagonal
			if (res.x > 0 && res.y > 0) //Direccion 1er cuadrante (/)
				for (int i = origen.x + 1, j = origen.y + 1; i < destino.x && j < destino.y; i++, j++) {
					if (posicionPiezas[i][j] != nullptr)
						return false;
				}
			else if (res.x < 0 && res.y > 0) //Direccion 2o cuadrante (\)
				for (int i = origen.x - 1, j = origen.y + 1; i > destino.x && j < destino.y; i--, j++) {
					if (posicionPiezas[i][j] != nullptr)
						return false;
				}
			else if (res.x < 0 && res.y < 0) //Direccion 3er cuadrante (/)
				for (int i = origen.x - 1, j = origen.y - 1; i > destino.x && j > destino.y; i--, j--) {
					if (posicionPiezas[i][j] != nullptr)
						return false;
				}
			else //Direccion 4o cuadrante (\)
				for (int i = origen.x + 1, j = origen.y - 1; i < destino.x && j > destino.y; i++, j--) {
					if (posicionPiezas[i][j] != nullptr)
						return false;
				}
			return true;
		}
		else
			return false;
	}
}