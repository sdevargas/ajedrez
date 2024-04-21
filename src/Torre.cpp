#include "Torre.h"
#include"freeglut.h"
void Torre::Dibuja(){
    glColor3ub(169, 50, 38);
    glutSolidSphere(0.2, 20, 20);
}

bool Torre::ValidaMov(Vector2D origen, Vector2D destino, Pieza* PosicionPiezas)
{
    return false;
}
