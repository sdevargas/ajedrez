#pragma once
#include"Tablero.h"

class Juego {

public:
	Juego(bool contraBot);
	virtual void Dibuja()=0;
	virtual void Mueve(int columna, int fila)=0;
	virtual bool getmate_b() = 0;
	virtual bool getmate_n() = 0;
	virtual bool getPromocion() = 0;
	virtual void setTipoPromo(Pieza::Tipo tipo)=0;
	virtual bool getempate() = 0;
protected:
	Tablero* tablero;
	bool promocion;
	bool contraBot;
};