#include "Reina.h"
#include"freeglut.h"

void Reina::Dibuja(){
	glColor3ub(195, 155, 211);
	glutSolidSphere(0.2, 20, 20);
}

bool Reina::ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10])
{
	int arriba = ((destino.y - origen.y) > 0) ? 1 : -1; // comprobamos si el movimiente es hacia arriba o hacia abajo
	int dcha = ((destino.x - origen.x) > 0) ? 1 : -1;// igual pero derecha izquierda

	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) {
		return false;
	}
	else {
		Vector2D res = destino - origen;

		if (res.x == 0 && res.y != 0) {
			for (int i = origen.y + arriba; i != destino.y; i += arriba) { //recorremos la trayectoria  vertical comprobando que no haya piezas en esta 

				if (posicionPiezas[origen.x][i] == nullptr) {
					continue;
				}
				return false;
			}
			return true;
		}
		else if (res.x != 0 && res.y == 0) {
			for (int i = origen.x + dcha; i != destino.x; i += dcha) { // igual que la linea 23 pero en horizontal

				if (posicionPiezas[i][origen.y] == nullptr) {
					continue;
				}

				return false;

			}
			return true;
		}
			

		else if (abs(res.x) == abs(res.y)) { //Movimiento diagonal
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
