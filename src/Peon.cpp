#include "Peon.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "Tablero.h"
#include "Pieza.h"


void Peon::Dibuja(){
	
	glEnable(GL_TEXTURE_2D);
	if (modoJuego == NORMAL) {
		if (color == BLANCO) {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/peonB.png").id);
		}
		else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/peonN.png").id);
	}
	else if (modoJuego == SW) {
		if (color == BLANCO) {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/peonBsw.png").id);
		}
		else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/peonNsw.png").id);
	}

	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor4ub(255, 255, 255, 255); // Use glColor4ub to include alpha value
	glTexCoord2d(0, 1); glVertex3f(-0.5f, -0.5f, 0.01f);
	glTexCoord2d(1, 1); glVertex3f(0.5f, -0.5f, 0.01f);
	glTexCoord2d(1, 0); glVertex3f(0.5f, 0.5f, 0.01f);
	glTexCoord2d(0, 0); glVertex3f(-0.5f, 0.5f, 0.01f);
	glEnd();

	glDisable(GL_BLEND);
	glEnable(GL_LIGHTING);
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
			if (abs(res.x) == 1 && res.y == 1) { //Mover en diagonal para delante
				if (posicionPiezas[destino.x][destino.y] != nullptr) //Si puede comer pieza
					return true;
				else if (posicionPiezas[destino.x][destino.y - 1] != nullptr && posicionPiezas[destino.x][destino.y - 1]->alPasoPresa) { //Si puede hacer captura
					alPasoDone = true;
					return true;
				}
				else //Resto de movimientos diagonales invalidos
					return false;
			}
			else if (res.x == 0) { //Mover en vertical
				if (origen.y == 2) //Esta en posicion de salida de los peones
				{
					if ((res.y == 2 && posicionPiezas[origen.x][origen.y + 1] == nullptr && posicionPiezas[origen.x][origen.y + 2] == nullptr)
						|| (res.y == 1 && posicionPiezas[origen.x][origen.y + 1] == nullptr)) { //Puede moverse uno o dos si no hay pieza en destino
						alPasoPresa = true;
						return true;
					}
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
			else //Mover en horizontal u otros movimientos invalidos
				return false;
		}

		else { //Piezas negras
			if (abs(res.x) == 1 && res.y == -1) { //Mover en diagonal para delante
				if (posicionPiezas[destino.x][destino.y] != nullptr) //Si puede comer pieza
					return true;
				else if (posicionPiezas[destino.x][destino.y + 1] != nullptr && posicionPiezas[destino.x][destino.y + 1]->alPasoPresa) { //Si puede hacer captura
					alPasoDone = true;
					return true;
				}
				else //Resto de movimientos diagonales invalidos
					return false;
			}
			else if (res.x == 0) { //Mover en vertical
				if (origen.y == 7) //Esta en posicion de salida de los peones
				{
					if ((res.y == -2 && posicionPiezas[origen.x][origen.y - 1] == nullptr && posicionPiezas[origen.x][origen.y - 2] == nullptr)
						|| (res.y == -1 && res.x == 0 && posicionPiezas[origen.x][origen.y - 1] == nullptr)) { //Puede moverse uno o dos si no hay pieza en destino
						alPasoPresa = true;
						return true;
					}
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

void Peon::ObtenerMovimientosPosibles(int x, int y, bool movimientos[11][10], Pieza* posicionPiezas[11][10]) {
	// Reiniciamos la matriz de movimientos
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10; j++) {
			movimientos[i][j] = false;
		}
	}

	// Movimientos posibles del peón blanco
	if (getColor() == BLANCO) {
		// Avance normal
		if (y < 9 && posicionPiezas[x][y + 1] == nullptr) {
			movimientos[x][y + 1] = true;
			// Primer movimiento de dos casillas
			if (y == 2 && posicionPiezas[x][y + 2] == nullptr) {
				movimientos[x][y + 2] = true;
			}
		}
		// Captura hacia la derecha
		if (x < 10 && y < 9 && posicionPiezas[x + 1][y + 1] != nullptr && posicionPiezas[x + 1][y + 1]->getColor() == NEGRO) {
			movimientos[x + 1][y + 1] = true;
		}
		// Captura hacia la izquierda
		if (x > 0 && y < 9 && posicionPiezas[x - 1][y + 1] != nullptr && posicionPiezas[x - 1][y + 1]->getColor() == NEGRO) {
			movimientos[x - 1][y + 1] = true;
		}
	}
	// Movimientos posibles del peón negro
	else if (getColor() == NEGRO) {
		// Avance normal
		if (y > 0 && posicionPiezas[x][y - 1] == nullptr) {
			movimientos[x][y - 1] = true;
			// Primer movimiento de dos casillas
			if (y == 7 && posicionPiezas[x][y - 2] == nullptr) {
				movimientos[x][y - 2] = true;
			}
		}
		// Captura hacia la derecha
		if (x < 10 && y > 0 && posicionPiezas[x + 1][y - 1] != nullptr && posicionPiezas[x + 1][y - 1]->getColor() == BLANCO) {
			movimientos[x + 1][y - 1] = true;
		}
		// Captura hacia la izquierda
		if (x > 0 && y > 0 && posicionPiezas[x - 1][y - 1] != nullptr && posicionPiezas[x - 1][y - 1]->getColor() == BLANCO) {
			movimientos[x - 1][y - 1] = true;
		}
	}
}