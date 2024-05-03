#include "freeglut.h"
#include "ETSIDI.h"
//#include "Tablero.h"
#include "Mundo.h"

#include<iostream>
using namespace std;

Mundo mundo;
//Tablero tablero;

//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

void ClicRaton(int button, int state, int x, int y);


int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(ClicRaton);

	//POSIBLE INICIALIZACION
		
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	

	return 0;   
}

void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	//funciones de dibujo

	gluLookAt(5, 5.5, 20, 
		5.0, 5.5, 0.0,      
		0.0, 1.0, 0.0);

	//CODIGO SPRITE FONDO
	/*glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("bin/imagenes/fondo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-10, 0, -1);
	glTexCoord2d(1, 1); glVertex3f(10, 0, -1);
	glTexCoord2d(1, 0); glVertex3f(10, 15, -1);
	glTexCoord2d(0, 0); glVertex3f(-10, 15, -1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);*/

	//DIBUJAR TABLERO
	mundo.tablero.Dibuja();


	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//poner aqui el código de teclado
	

	glutPostRedisplay();
}

void OnTimer(int value)
{
//poner aqui el código de animacion
	

	//no borrar estas lineas
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}

void ClicRaton(int button, int state, int x, int y) {
	/*
	button->sabemos el botón
	state-> sabemos si está pulsado o sin pulsar
	x y -> coordenadas del ratón
	*/
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		int columna = (x - 212) / 40;
		int fila = -(y - 510) / 40;
		
		if (fila + columna > 15 || fila + columna < 4 ||
			columna - fila < -5 || columna - fila > 6) {//Restricción de casillas
			ETSIDI::playMusica("bin/sonidos/error-fuera.mp3"); //Sonido de fuera del tablero
			cout << "Casilla no valida" << endl;
			
		}
		else {
			cout << x << "," << y << "       ";
			cout << columna << "," << fila << endl;
			
			mundo.PuedeHacerMov(columna, fila); //Pasamos al objeto mundo las coordenadas de un click válido
		}

	}

	//Puede dar problemas en los límites de la casilla

}
