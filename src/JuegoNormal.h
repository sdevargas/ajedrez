#pragma once
#include "Juego.h"

class JuegoNormal : public Juego {
public:
	JuegoNormal();
	void Dibuja();
	void Mueve(int columna, int fila);
	bool getmate_b() { return tablero->getmate_b(); }
	bool getmate_n() { return tablero->getmate_n(); }
	bool getPromocion() { return promocion; }
	void setTipoPromo(Pieza::Tipo tipo) { tablero->cambiaPromocion(tipo); }
protected:
	Tablero* tablero;
	bool promocion;
};