#include "Mundo.h"

Mundo::Mundo()
{
	
}

void Mundo::PuedeHacerMov(int x, int y)
{
	tablero.Mueve(x, y); //Le pasamos a trablero las coordenadas del click
}
