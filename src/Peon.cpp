#include "Peon.h"
#include "freeglut.h"
#include "ETSIDI.h"

void Peon::Dibuja(){
	
	glEnable(GL_TEXTURE_2D);
	if (color == BLANCO) {
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/peonB.png").id);
	}else glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/peonN.png").id);
	
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