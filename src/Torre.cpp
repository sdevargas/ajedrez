#include "Torre.h"
#include"freeglut.h"
#include"ETSIDI.h"

void Torre::Dibuja(){
	glEnable(GL_TEXTURE_2D);
	if (color == BLANCO) {
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/torreB.png").id);
	}
	else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/torreN.png").id);

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
