#pragma once
#include "Juego.h"

class JuegoSW : public Juego {
public:
	JuegoSW();
	void Dibuja();
	void Mueve(int columna, int fila);

	bool getPromocion() { return promocion; }
	void setTipoPromo(Pieza::Tipo tipo) { tablero->cambiaPromocion(tipo); }
protected:
	Tablero* tablero;
	bool promocion;
};