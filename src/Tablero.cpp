#include "Tablero.h"
#include <freeglut.h>
#include"ETSIDI.h"
#include<iostream>
#include <fstream>
using namespace std;
int cont = 1;

Tablero::Tablero(Tablero::Modo m){
	contadorClick = 0;
	srand(static_cast<unsigned>(time(0)));
	modo = m;
	cont = 1;
	empate = false;
	//Hacemos nullptr todas las casillas para que no haya basura
	for (int columna = 0; columna < limite_columnas; columna++) {
		for (int fila = 0; fila < limite_filas; fila++) {
			posicionPiezas[columna][fila] = nullptr;
		}
	}
	//Inicializamos en la matriz las posiciones de partida {PosicionPieza[i][j]= new "constructor del tipo de pieza" }
	/*Se hace de manera den�mica porque no siempre tendr�s las mismas piezas*/
	//PEONES
	for (int columna = 2; columna < 9; columna++) {
		posicionPiezas[columna][2] = new Peon(Pieza::BLANCO , (Pieza::Modo) m);
	}
	for (int columna = 2; columna < 9; columna++) {
		posicionPiezas[columna][7] = new Peon(Pieza::NEGRO, (Pieza::Modo) m);
	}
	//TORRES
	posicionPiezas[3][1] = new Torre(Pieza::BLANCO, (Pieza::Modo)m);
	posicionPiezas[7][1] = new Torre(Pieza::BLANCO, (Pieza::Modo)m);
	posicionPiezas[3][8] = new Torre(Pieza::NEGRO, (Pieza::Modo)m);
	posicionPiezas[7][8] = new Torre(Pieza::NEGRO, (Pieza::Modo)m);
	//CABALLOS
	posicionPiezas[4][1] = new Caballo(Pieza::BLANCO, (Pieza::Modo)m);
	posicionPiezas[6][1] = new Caballo(Pieza::BLANCO, (Pieza::Modo)m);
	posicionPiezas[4][8] = new Caballo(Pieza::NEGRO, (Pieza::Modo)m);
	posicionPiezas[6][8] = new Caballo(Pieza::NEGRO, (Pieza::Modo)m);
	//ALFILES
	posicionPiezas[5][1] = new Alfil(Pieza::BLANCO, (Pieza::Modo)m);
	posicionPiezas[5][0] = new Alfil(Pieza::BLANCO, (Pieza::Modo)m);
	posicionPiezas[5][8] = new Alfil(Pieza::NEGRO, (Pieza::Modo)m);
	posicionPiezas[5][9] = new Alfil(Pieza::NEGRO, (Pieza::Modo)m);
	//REYES
	posicionPiezas[4][0] = new Rey(Pieza::BLANCO, (Pieza::Modo)m);
	posicionPiezas[4][9] = new Rey(Pieza::NEGRO, (Pieza::Modo)m);
	//REINAS
	posicionPiezas[6][0] = new Reina(Pieza::BLANCO, (Pieza::Modo)m);
	posicionPiezas[6][9] = new Reina(Pieza::NEGRO, (Pieza::Modo)m);

	//mate blanco y negro
	mate_b = false;
	mate_n = false;


	this->turno = BLANCAS;
}

void Tablero::Dibuja(){
	//DIBUJO DE LAS CASILLAS
	for (int columna = 0; columna < limite_columnas; columna++) {
		for (int fila = 0; fila < limite_filas; fila++) {
			if (fila + columna > 15 || fila + columna < 4 ||	
				columna - fila < -5 || columna - fila > 6) { //Restricci�n de casillas
				continue;
			}else{
				glDisable(GL_LIGHTING);
				if ((fila + columna) % 2 == 0) {
					glColor3ub(/*30, 132, 73*//*70, 41, 5*/79, 69, 60); //OSCURO
				}
				else glColor3ub(/*169, 223, 191*//*245, 203, 138*/162, 157, 135); //CLARO
				glBegin(GL_POLYGON);
				glVertex3d(columna, fila, 0);
				glVertex3d(columna +1, fila, 0);
				glVertex3d(columna + 1, fila + 1, 0);
				glVertex3d(columna, fila +1, 0);
				glEnd();
				glEnable(GL_LIGHTING);
			
			}
		}
	}
	//Copia de tablero
	Pieza* posicionPiezas_aux[limite_columnas][limite_filas];
	for (int i = 0; i < limite_columnas; i++) {
		for (int j = 0; j < limite_filas; j++) {
			posicionPiezas_aux[i][j] = posicionPiezas[i][j]; 
		}
	}
	//DIBUJO CASILLAS POSIBLES MOVIMIENTOS
	Vector2D  destino;
	if (contadorClick == 1) {
		for (int k = 0; k < limite_columnas; k++) {
			for (int l = 0; l < limite_filas; l++) {
				destino = { k,l };
				if (CompMovCompleto(origenPieza, destino)) {
					posicionPiezas[destino.x][destino.y] = posicionPiezas[origenPieza.x][origenPieza.y]; //Se le asigna la nueva posici�n a la pieza
					posicionPiezas[origenPieza.x][origenPieza.y] = nullptr; //Se elimina la pieza del origen
					if (!Jaque(posicionPiezas)) {
						for (int i = 0; i < limite_columnas; i++) {
							for (int j = 0; j < limite_filas; j++) {
								posicionPiezas[i][j] = posicionPiezas_aux[i][j]; //Devolvemos el tablero a su posici�n original deshaciendo el movimiento
							}
						}

						//Dibujo de la casilla
						glDisable(GL_LIGHTING);
						if (posicionPiezas[destino.x][destino.y] != nullptr) {
							glColor3f(0.925f, 0.439f, 0.388f);
							glBegin(GL_POLYGON);
							glVertex3d(destino.x, destino.y, 0.001);
							glColor3f(0.752f, 0.223f, 0.168f);
							glVertex3d(destino.x + 1, destino.y, 0.001);
							glColor3f(0.925f, 0.439f, 0.388f);
							glVertex3d(destino.x + 1, destino.y + 1, 0.001);
							glColor3f(0.752f, 0.223f, 0.168f);
							glVertex3d(destino.x, destino.y + 1, 0.001);
							glEnd();
							glEnable(GL_LIGHTING);
						}
						else {
							glColor3f(0.282f, 0.788f, 0.69f);
							glBegin(GL_POLYGON);
							glVertex3d(destino.x, destino.y, 0.001);
							glColor3f(0.074f, 0.552f, 0.458f);
							glVertex3d(destino.x + 1, destino.y, 0.001);
							glColor3f(0.282f, 0.788f, 0.69f);
							glVertex3d(destino.x + 1, destino.y + 1, 0.001);
							glColor3f(0.074f, 0.552f, 0.458f);
							glVertex3d(destino.x, destino.y + 1, 0.001);
							glEnd();
							glEnable(GL_LIGHTING);
						}
					}
					else{
						for (int i = 0; i < limite_columnas; i++) {
							for (int j = 0; j < limite_filas; j++) {
								posicionPiezas[i][j] = posicionPiezas_aux[i][j]; //Se mantienen las posiciones originales
							}
						}
					}
				}
			}
		}
	}

	//DIBUJO DE LAS PIEZAS
	for (int columna = 0; columna < limite_columnas; columna++) {
		for (int fila = 0; fila < limite_filas; fila++) {
			if (posicionPiezas[columna][fila] != nullptr) {
				glPushMatrix();
				glTranslatef(columna +0.5, fila+0.5, 0); //Desplazas el eje de cordenadas
				posicionPiezas[columna][fila]->Dibuja(); //Llamada al m�todo Dibuja de la pieza que corresponde
				glTranslatef(-columna - 0.5, -fila - 0.5, 0);
				glPopMatrix();
			}
		}
	}

}

void Tablero::Mueve(int x, int y)
{
	if (contadorClick == 2) {
		contadorClick = 1;
	}
	else contadorClick++;

	if (contadorClick == 1) {

		if (posicionPiezas[x][y] != nullptr) {

			if (posicionPiezas[x][y]->getColor() == turno) { //Si el color de la posici�n es igual al turno
				cout << "1er click valido" << endl;
				origenPieza.x = x;
				origenPieza.y = y;
				return; //Salimos de la funci�n esperando el siguiente click
			}
			else { 
				contadorClick = 0; 
				ETSIDI::playMusica("bin/sonidos/error.mp3");
				cout << "1er click NO valido por color" << endl; 
			}//Reiniciamos el turno 
		}
		else {
			contadorClick = 0; 
			ETSIDI::playMusica("bin/sonidos/error.mp3");
			cout << "1er click NO valido por pieza" << endl;
		} //Reiniciamosel turno
	}
	else if (contadorClick == 2) {

		Pieza* posicionPiezas_aux[limite_columnas][limite_filas];
		for (int i = 0; i < limite_columnas; i++) {
			for (int j = 0; j < limite_filas; j++) {
				posicionPiezas_aux[i][j] = posicionPiezas[i][j]; //Se copia la matriz de PosicionPiezas para la comprobaci n de las posiciones
			}
		}

		if (posicionPiezas[x][y]!=nullptr && posicionPiezas[x][y]->getColor() == turno) { 
			ETSIDI::playMusica("bin/sonidos/error.mp3");
			contadorClick = 0; cout << "2o click NO valido por pieza de turno" << endl;
		}
		else {
			destinoPieza.x = x;
			destinoPieza.y = y;

			if (posicionPiezas[origenPieza.x][origenPieza.y]->ValidaMov(origenPieza, destinoPieza, posicionPiezas)) { //Pieza del 1er click llama a SU validar movimiento (polimorfismo)
				bool r = false;
				if (posicionPiezas[destinoPieza.x][destinoPieza.y] != nullptr) {
					r = true;
				}

				posicionPiezas[destinoPieza.x][destinoPieza.y] = posicionPiezas[origenPieza.x][origenPieza.y]; //Se le asigna la nueva posici�n a la pieza
				posicionPiezas[origenPieza.x][origenPieza.y] = nullptr; //Se elimina la pieza del origen

				// Captura al paso
				if (posicionPiezas[destinoPieza.x][destinoPieza.y] != nullptr) {
					if (posicionPiezas[destinoPieza.x][destinoPieza.y]->alPasoPresa) {
						alPasoTurn = true;
						for (int i = 0; i < limite_columnas; i++) {
							for (int j = 0; j < limite_filas; j++) {
								if (posicionPiezas[i][j] != nullptr && posicionPiezas[i][j] != posicionPiezas[destinoPieza.x][destinoPieza.y]) {
									posicionPiezas[i][j]->alPasoPresa = false;
								}
							}
						}
					}
					else if (alPasoTurn) {
						if (posicionPiezas[destinoPieza.x][destinoPieza.y]->alPasoDone == true) {
							if (turno == BLANCAS)
								posicionPiezas[destinoPieza.x][5] = nullptr;
							else if (turno == NEGRAS)
								posicionPiezas[destinoPieza.x][4] = nullptr;
							posicionPiezas[destinoPieza.x][destinoPieza.y]->alPasoDone = false;
						}
						else {
							for (int i = 0; i < limite_columnas; i++) {
								for (int j = 0; j < limite_filas; j++) {
									if (posicionPiezas[i][j] != nullptr && posicionPiezas[i][j] != posicionPiezas[destinoPieza.x][destinoPieza.y]) {
										posicionPiezas[i][j]->alPasoPresa = false;
									}
								}
							}
						}
						alPasoTurn = false;
					}
				}
				//

				if (Jaque(posicionPiezas)) {
					contadorClick = 0;
					cout << "Movimiento no valido por posicion en jaque" << endl;
					for (int i = 0; i < limite_columnas; i++) {
						for (int j = 0; j < limite_filas; j++) {
							posicionPiezas[i][j] = posicionPiezas_aux[i][j]; //Se mantienen las posiciones originales
						}
					}

				}
				else {
					ETSIDI::playMusica("bin/sonidos/correcto.mp3");
					Promocion();//Llamamos a la funcion que comprueba si es posible la promocion del peon
					turno = (turno == BLANCAS) ? NEGRAS : BLANCAS; //Cambio de turno
					cout << "TURNO DE: " << turno << endl;
		
					Historial(posicionPiezas[x][y], x, y, r);
					if (Jaque(posicionPiezas) && Mate() == true) {
						cout << "Jaque Mate" << endl;	
						cont = 1;
					}
					else if (!Jaque(posicionPiezas)){
						if (Empate())
							empate = true;
					}
				}
			}
			else {
				contadorClick = 0;
				ETSIDI::playMusica("bin/sonidos/error.mp3");
				cout << "2o click NO valido por movimiento de la propia pieza" << endl;
			}//Reiniciamos el turno
		}
	}
	
}



bool Tablero::Jaque(Pieza* posicionPiezas_aux[limite_columnas][limite_filas])
{
	Vector2D rey_blanco, rey_negro;

	//Bucle para encontrar el rey
	for (int i = 0; i < limite_columnas; i++) {
		for (int j = 0; j < limite_filas; j++) {
			if (posicionPiezas_aux[i][j] != nullptr) {
				//Se guardan las posiciones de los dos reyes
				if (posicionPiezas_aux[i][j]->getTipo() == Pieza::Tipo::REY && posicionPiezas_aux[i][j]->getColor() == Pieza::Color::BLANCO) {
					rey_blanco.x = i;  
					rey_blanco.y = j;
				}
				if (posicionPiezas_aux[i][j]->getTipo() == Pieza::Tipo::REY && posicionPiezas_aux[i][j]->getColor() == Pieza::Color::NEGRO) {
					rey_negro.x = i;
					rey_negro.y = j;
				}
			}
		}
	}

	//cout << "Posicion rey blanco: " << rey_blanco.x << ", " << rey_blanco.y << endl;
	//cout << "Posicion rey negro: " << rey_negro.x << ", " << rey_negro.y << endl;
	
	Vector2D rey_comp; //Se crea un Vector2D para guardar las coordenadas del rey que utilizaremos para comprobar el jaque
	bool respuesta = false; //Esta ser� la respuesta bool a la funci�n

	//En funci�n del turno cogemos un rey u otro
	if (turno == Turno::BLANCAS) rey_comp = rey_blanco;
	if (turno == Turno::NEGRAS) rey_comp = rey_negro;
	

	for (int i = 0; i < limite_columnas; i++) {
		for (int j = 0; j < limite_filas; j++) {
			if (posicionPiezas_aux[i][j] != nullptr) {
				if (posicionPiezas_aux[i][j]->getColor() != turno) { //Si el color de la pieza es distinto al del turno
					Vector2D origen(i, j);                           //cogemos sus coordenadas
					if (posicionPiezas_aux[i][j]->ValidaMov(origen, rey_comp, posicionPiezas_aux) == true) { //comprobamos si es valido su movimiento hacia el rey
						cout << "Jaque" << endl;
						respuesta = true;
					}
					else {
						continue;
					}
				}
			}
		}
	}
	return respuesta;	
}

bool Tablero::Mate() {
	Vector2D origen,destino;
	Pieza* copia_tablero[limite_columnas][limite_filas];
	for (int i = 0; i < limite_columnas; i++) {
		for (int j = 0; j < limite_filas; j++) {
			copia_tablero[i][j] = posicionPiezas[i][j];
		}
	}
	for (int i = 0; i < limite_columnas; i++) {
		for (int j = 0; j < limite_filas; j++) {
			if (posicionPiezas[i][j] != nullptr && posicionPiezas[i][j]->getColor() == turno) {
				origen = { i,j };
				for (int k = 0; k < limite_columnas; k++) {
					for (int l = 0; l < limite_filas; l++) {
						destino = { k,l };
						if(CompMovCompleto(origen,destino)){
							posicionPiezas[destino.x][destino.y] = posicionPiezas[origen.x][origen.y]; //Se le asigna la nueva posici�n a la pieza
							posicionPiezas[origen.x][origen.y] = nullptr; //Se elimina la pieza del origen
							if (!Jaque(posicionPiezas)) {
								posicionPiezas[origen.x][origen.y] = copia_tablero[origen.x][origen.y];
								posicionPiezas[destino.x][destino.y] = copia_tablero[destino.x][destino.y];
								return false;
							}
							else {
								posicionPiezas[origen.x][origen.y] = copia_tablero[origen.x][origen.y];
								posicionPiezas[destino.x][destino.y] = copia_tablero[destino.x][destino.y];
								continue;
							}
						}
					}
				}
			}


		}
	}
	if (turno == BLANCAS) {
		mate_b = true;
	}
	else {
		mate_n = true;
	}
	return true;
}

void Tablero::Promocion()
{
	int primeraFila = 0;
	int segundaFila = 0;
	if (turno == BLANCAS) {
		primeraFila = 9;
		segundaFila = 8;
	}
	else if (turno == NEGRAS) {
		primeraFila = 0;
		segundaFila = 1;
	}

	for (int j = 0; j < limite_columnas; j++) {
		if (j==3 || j==7) {
			if (posicionPiezas[j][segundaFila] != nullptr) {
				if ((posicionPiezas[j][segundaFila]->getTipo() == Pieza::PEON) && (posicionPiezas[j][segundaFila]->getColor() == turno)) {
					promocion = true;
					coordPromocion = { j, segundaFila };
					return;
				}
			}
		}
		else if (posicionPiezas[j][primeraFila] != nullptr) {
			if ((posicionPiezas[j][primeraFila]->getTipo() == Pieza::PEON) && (posicionPiezas[j][primeraFila]->getColor() == turno)) {
				promocion = true;
				coordPromocion = { j, primeraFila };
				return;
			}
			else continue;
		}
	}
	promocion = false;
}

void Tablero::cambiaPromocion(Pieza::Tipo tipo)
{
	turno = (turno == BLANCAS) ? NEGRAS : BLANCAS;
	switch (tipo) {
	case Pieza::TORRE:
		posicionPiezas[coordPromocion.x][coordPromocion.y] = new Torre((Pieza::Color) turno, (Pieza::Modo)modo);
		break;
	case Pieza::ALFIL:
		posicionPiezas[coordPromocion.x][coordPromocion.y] = new Alfil((Pieza::Color)turno, (Pieza::Modo)modo);
		break;
	case Pieza::CABALLO:
		posicionPiezas[coordPromocion.x][coordPromocion.y] = new Caballo((Pieza::Color)turno, (Pieza::Modo)modo);
		break;
	case Pieza::REINA:
		posicionPiezas[coordPromocion.x][coordPromocion.y] = new Reina((Pieza::Color)turno, (Pieza::Modo)modo);
		break;
	}
	turno = (turno == BLANCAS) ? NEGRAS : BLANCAS;
	
}

bool Tablero::CompMovCompleto(Vector2D origen, Vector2D destino)
{
	if (posicionPiezas[destino.x][destino.y]!=nullptr && posicionPiezas[destino.x][destino.y]->getColor() == turno) {
		return false;
	}else if(posicionPiezas[origen.x][origen.y]->ValidaMov(origen, destino, posicionPiezas))
		return true;
}

void Tablero::Historial(Pieza* p, int x, int y, bool r)
{
	char pos, tip, k = '\0';
	switch (x)
	{
	case 0:
		pos = 'a';
		break;
	case 1:
		pos = 'b';
		break;
	case 2:
		pos = 'c';
		break;
	case 3:
		pos = 'd';
		break;
	case 4:
		pos = 'e';
		break;
	case 5:
		pos = 'f';
		break;
	case 6:
		pos = 'g';
		break;
	case 7:
		pos = 'h';
		break;
	case 8:
		pos = 'i';
		break;
	case 9:
		pos = 'j';
		break;
	case 10:
		pos = 'k';
		break;
	default:
		break;
	}
	switch (p->getTipo())
	{
	case Pieza::Tipo::ALFIL:
		tip = 'A';
		break;
	case Pieza::Tipo::CABALLO:
		tip = 'C';
		break;
	case Pieza::Tipo::PEON:
		tip = 'P';
		break;
	case Pieza::Tipo::REINA:
		tip = 'D';
		break;
	case Pieza::Tipo::REY:
		tip = 'R';
		break;
	case Pieza::Tipo::TORRE:
		tip = 'T';
		break;
	default:
		break;
	}

	if (r == true) {
		k = 'x';
	}

	if (cont <= 1) { //Nos aseguramos de borrar el contenido cuando empecemos el programa
		if (p->getColor() == Pieza::Color::BLANCO) {
		fstream file("historial.txt", ios::in | ios::out | ios::trunc);
			if (file.is_open()) {
				file << cont << ".\t" << tip << k << pos << y;
			}
			else {
				std::cerr << "Error al abrir el archivo." << std::endl;
			}
		}
		if (p->getColor() == Pieza::Color::NEGRO) {
			fstream file("historial.txt", ios::in | ios::out | ios::app);
			file << "\t" << tip << k << pos << y << endl;
			cont++;
		}
	} else if (cont > 1) {
		fstream file("historial.txt", ios::in | ios::out | ios::app);

		if (file.is_open()) {

			if (p->getColor() == Pieza::Color::BLANCO) {

				file << cont << ".\t" << tip << k << pos << y;

			}
			else if (p->getColor() == Pieza::Color::NEGRO) {
				file << "\t" << tip << k << pos << y << endl;
				cont++;
			}
		}
		else {
			std::cerr << "Error al abrir el archivo." << std::endl;
		}
	}

}

void Tablero::MovimientoBot()
{
	vector<pair<Vector2D, Vector2D>> movimientos_validos;
	Vector2D origen, destino;

	for (int i = 0; i < limite_columnas; i++) {
		for (int j = 0; j < limite_filas; j++) {
			if (posicionPiezas[i][j] != nullptr && posicionPiezas[i][j]->getColor() == NEGRAS) {
				origen = { i, j };
				for (int k = 0; k < limite_columnas; k++) {
					for (int l = 0; l < limite_filas; l++) {
						destino = { k, l };
						if (CompMovCompleto(origen, destino)) {
							// Hacer una copia del tablero para simular el movimiento
							Pieza* tmpPosiciones[limite_columnas][limite_filas];
							for (int m = 0; m < limite_columnas; m++) {
								for (int n = 0; n < limite_filas; n++) {
									tmpPosiciones[m][n] = posicionPiezas[m][n];
								}
							}
							tmpPosiciones[destino.x][destino.y] = tmpPosiciones[origen.x][origen.y];
							tmpPosiciones[origen.x][origen.y] = nullptr;

							// Verificar si el movimiento deja al rey en jaque
							if (!Jaque(tmpPosiciones)) {
								movimientos_validos.push_back({ origen, destino });
							}
						}
					}
				}
			}
		}
	}
	
	if (!movimientos_validos.empty()) {
		int indice = rand() % movimientos_validos.size();
		origen = movimientos_validos[indice].first;
		destino = movimientos_validos[indice].second;

		Mueve(origen.x, origen.y);
		Mueve(destino.x, destino.y);

		// Alternar turno despu�s del movimiento del bot
		turno = BLANCAS;

	}
}

bool Tablero::Empate()
{
	Pieza* copia_tablero[limite_columnas][limite_filas];

	for (int i = 0; i < limite_columnas; i++) {
		for (int j = 0; j < limite_filas; j++) {
			copia_tablero[i][j] = posicionPiezas[i][j];
		}
	}

	Vector2D destino;
	Vector2D origen;
	for (int i = 0; i < limite_columnas; i++) {
		for (int j = 0; j < limite_filas; j++) {
			if (posicionPiezas[i][j] != nullptr && posicionPiezas[i][j]->getColor() == turno) {
				origen = { i,j };
				for (int k = 0; k < limite_columnas; k++) {
					for (int l = 0; l < limite_filas; l++) {
						destino = { k,l };
						if (CompMovCompleto(origen, destino)) {
							posicionPiezas[destino.x][destino.y] = posicionPiezas[origen.x][origen.y];
							posicionPiezas[origen.x][origen.y] = nullptr;
							if (!Jaque(posicionPiezas)) {
								for (int a = 0; a < limite_columnas; a++) {
									for (int b = 0; b < limite_filas; b++) {
										posicionPiezas[a][b] = copia_tablero[a][b]; //Devolvemos el tablero a su posici�n original deshaciendo el movimiento
									}
								}
								return false;
							}
							else {
								for (int a = 0; a < limite_columnas; a++) {
									for (int b = 0; b < limite_filas; b++) {
										posicionPiezas[a][b] = copia_tablero[a][b]; //Devolvemos el tablero a su posici�n original deshaciendo el movimiento
									}
								}
							}
							
						}
					}
				}
			}
		}
	}
	return true;
}

