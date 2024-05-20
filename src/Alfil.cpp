#include "Alfil.h"
#include "freeglut.h"
#include"ETSIDI.h"

void Alfil::Dibuja()
{
	glEnable(GL_TEXTURE_2D);
	if (modoJuego == NORMAL) {
		if (color == BLANCO) {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/alfilB.png").id);
		}
		else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/alfilN.png").id);
	}
	else if (modoJuego == SW) {
		if (color == BLANCO) {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/alfilBsw.png").id);
		}
		else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/alfilNsw.png").id);
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
void Alfil::ObtenerMovimientosValidos(int x, int y, bool movimientos[11][10], Pieza* posicionPiezas[11][10]) {
	// Reiniciamos la matriz de movimientos
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10; j++) {
			movimientos[i][j] = false;
		}
	}
// Movimientos posibles del alfil
	
	// Diagonal superior derecha
	for (int i = 1; x + i < 11 && y + i < 10; i++) {
		if (posicionPiezas[x + i][y + i] == nullptr) {
			movimientos[x + i][y + i] = true;
		}
		else {
			if (posicionPiezas[x + i][y + i]->getColor() != getColor()) {
				movimientos[x + i][y + i] = true;
			}
			break;
		}
	}

	// Diagonal superior izquierda
	for (int i = 1; x - i >= 0 && y + i < 10; i++) {
		if (posicionPiezas[x - i][y + i] == nullptr) {
			movimientos[x - i][y + i] = true;
		}
		else {
			if (posicionPiezas[x - i][y + i]->getColor() != getColor()) {
				movimientos[x - i][y + i] = true;
			}
			break;
		}
	}

	// Diagonal inferior derecha
	for (int i = 1; x + i < 11 && y - i >= 0; i++) {
		if (posicionPiezas[x + i][y - i] == nullptr) {
			movimientos[x + i][y - i] = true;
		}
		else {
			if (posicionPiezas[x + i][y - i]->getColor() != getColor()) {
				movimientos[x + i][y - i] = true;
			}
			break;
		}
	}

	// Diagonal inferior izquierda
	for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
		if (posicionPiezas[x - i][y - i] == nullptr) {
			movimientos[x - i][y - i] = true;
		}
		else {
			if (posicionPiezas[x - i][y - i]->getColor() != getColor()) {
				movimientos[x - i][y - i] = true;
			}
			break;
		}
	}
}