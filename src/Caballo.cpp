#include "Caballo.h"
#include"freeglut.h"
#include"ETSIDI.h"

void Caballo::Dibuja()
{
	glEnable(GL_TEXTURE_2D);

	if (modoJuego == NORMAL) {
		if (color == BLANCO) {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/caballoB.png").id);
		}
		else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/caballoN.png").id);
	}
	else if (modoJuego == SW) {
		if (color == BLANCO) {
			glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/caballoBsw.png").id);
		}
		else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/caballoNsw.png").id);
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

bool Caballo::ValidaMov(Vector2D origen, Vector2D destino, Pieza* posicionPiezas[11][10])
{
	if (destino.y + destino.x > 15 || destino.y + destino.x < 4 ||
		destino.x - destino.y < -5 || destino.x - destino.y > 6) {
		return false;
	}
	else {

		Vector2D res = destino - origen;

		if (abs(res.x) == 2 && abs(res.y) == 1)
			return true;
		if (abs(res.y) == 2 && abs(res.x) == 1)
			return true;
		else
			return false;
	}
}

void Caballo::ObtenerMovimientosPosibles(int x, int y, bool movimientos[11][10], Pieza* posicionPiezas[11][10]) {
	// Reiniciamos la matriz de movimientos
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 10; j++) {
			movimientos[i][j] = false;
		}
	}

	// Posibles movimientos del caballo en forma de L
	int dx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
	int dy[] = { -2, -2, -1, 1, 2, 2, 1, -1 };

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < 11 && ny >= 0 && ny < 10) {
			if (posicionPiezas[nx][ny] == nullptr || posicionPiezas[nx][ny]->getColor() != getColor()) {
				movimientos[nx][ny] = true;
			}
		}
	}
}
