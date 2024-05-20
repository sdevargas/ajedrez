#include "Torre.h"
#include"freeglut.h"
#include"ETSIDI.h"
#include "Tablero.h"

void Torre::Dibuja(){
	glEnable(GL_TEXTURE_2D);
	if (modoJuego == NORMAL) {
		if (color == BLANCO) {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/torreB.png").id);
		}
		else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/torreN.png").id);
	}
	else if (modoJuego == SW) {
		if (color == BLANCO) {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/torreBsw.png").id);
		}
		else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/torreNsw.png").id);
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

bool Torre::ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10])
{
	int arriba = ((destino.y - origen.y) > 0) ? 1: -1; // comprobamos si el movimiente es hacia arriba o hacia abajo
	int dcha  = ((destino.x - origen.x) > 0) ? 1 : -1;// igual pero derecha izquierda

	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) {
		return false;
	}
	else {
		
		Vector2D res = destino - origen;

		if (res.x == 0 && res.y != 0) {
			
			for (int i = origen.y+arriba; i != destino.y; i+=arriba) { //recorremos la trayectoria  vertical comprobando que no haya piezas en esta 

				if (posicionPiezas[origen.x][i] == nullptr) {
					continue;
				}
				return false;
			}
            return true;
		}
		if (res.y == 0 && res.x != 0) {
			for (int i = origen.x + dcha; i != destino.x; i += dcha) { // igual que la linea 23 pero en horizontal

				if (posicionPiezas[i][origen.y] == nullptr) {
					continue;
				}
				return false;

			}
			return true;
		}
		else return false;
	}
}

void Torre::ObtenerMovimientosPosibles(int x, int y, bool movimientos[11][10], Pieza* posicionPiezas[11][10]) {
	// Reiniciamos la matriz de movimientos
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10; j++) {
			movimientos[i][j] = false;
		}
	}

	// Movimientos verticales hacia arriba
	for (int i = y + 1; i < 10; i++) {
		if (posicionPiezas[x][i] == nullptr) {
			movimientos[x][i] = true;
		}
		else {
			if (posicionPiezas[x][i]->getColor() != getColor()) {
				movimientos[x][i] = true;
			}
			break;
		}
	}

	// Movimientos verticales hacia abajo
	for (int i = y - 1; i >= 0; i--) {
		if (posicionPiezas[x][i] == nullptr) {
			movimientos[x][i] = true;
		}
		else {
			if (posicionPiezas[x][i]->getColor() != getColor()) {
				movimientos[x][i] = true;
			}
			break;
		}
	}

	// Movimientos horizontales hacia la derecha
	for (int i = x + 1; i < 11; i++) {
		if (posicionPiezas[i][y] == nullptr) {
			movimientos[i][y] = true;
		}
		else {
			if (posicionPiezas[i][y]->getColor() != getColor()) {
				movimientos[i][y] = true;
			}
			break;
		}
	}

	// Movimientos horizontales hacia la izquierda
	for (int i = x - 1; i >= 0; i--) {
		if (posicionPiezas[i][y] == nullptr) {
			movimientos[i][y] = true;
		}
		else {
			if (posicionPiezas[i][y]->getColor() != getColor()) {
				movimientos[i][y] = true;
			}
			break;
		}
	}
}
