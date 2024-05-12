#include "Rey.h"
#include"freeglut.h"
#include"ETSIDI.h"

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

		if (abs(res.x) == 1 && res.y == 0)
			return true;
		else if (res.x == 0 && abs(res.y) == 1)
			return true;
		else if ((abs(res.x) == abs(res.y)) && (abs(res.x) == 1))
			return true;
		else
			return false;
	}
}
