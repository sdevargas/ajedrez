#pragma once
#include "Juego.h"

class JuegoNormal : public Juego {

public:
	JuegoNormal(bool contraBot);
	void Dibuja();
	void Mueve(int columna, int fila);
	bool getmate_b() { return tablero->getmate_b(); }
	bool getmate_n() { return tablero->getmate_n(); }
	bool getPromocion() { return promocion; }
	void setTipoPromo(Pieza::Tipo tipo) { tablero->cambiaPromocion(tipo); }
	bool getempate() { return tablero->getempate(); }
protected:
	Tablero* tablero;
	bool promocion;
};