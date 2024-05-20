#include "Rey.h"
#include"freeglut.h"
#include"ETSIDI.h"
#include "Tablero.h"
#include "Pieza.h"


void Rey::Dibuja(){
	glEnable(GL_TEXTURE_2D);
	if (modoJuego == NORMAL) {
		if (color == BLANCO) {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/reyB.png").id);
		}
		else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/reyN.png").id);
	}
	else if (modoJuego == SW){
		if (color == BLANCO) {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/reyBsw.png").id);
		}
		else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/reyNsw.png").id);
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

bool Rey::ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10])
{
	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) {
		return false;
	}
	else {
		Vector2D res = destino - origen;

		if (abs(res.x) == 1 && res.y == 0) {

			return true;
		}
		else if (res.x == 0 && abs(res.y) == 1) {
			return true;
		}
		else if ((abs(res.x) == abs(res.y)) && (abs(res.x) == 1)){
			return true;
			}
		else
			return false;
	}
}
void Rey::ObtenerMovimientosPosibles(int x, int y, bool movimientos[11][10], Pieza* posicionPiezas[11][10], Tablero& tablero) {
	// Reiniciamos la matriz de movimientos
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10; j++) {
			movimientos[i][j] = false;
		}
	}
	// Calcular los movimientos posibles del Rey
	for (int i = x - 1; i <= x + 1; ++i) {
		for (int j = y - 1; j <= y + 1; ++j) {
			// Verificar si la posición está dentro del tablero y si el movimiento es válido
			if (i >= 0 && i < 11 && j >= 0 && j < 10 && ValidaMov(Vector2D(x, y), Vector2D(i, j), posicionPiezas)) {
				// Verificar si el movimiento pone al Rey en jaque
				Pieza* piezaTemp = posicionPiezas[x][y];
				posicionPiezas[x][y] = nullptr;
				posicionPiezas[i][j] = piezaTemp;
				if (!tablero.Jaque(posicionPiezas)) {
					movimientos[i][j] = true; // Marcar el movimiento como posible
				}
				// Restaurar la posición original de las piezas
				posicionPiezas[x][y] = piezaTemp;
				posicionPiezas[i][j] = nullptr;
			}
		}
	}
}
