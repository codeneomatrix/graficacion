//#include "stdafx.h"
#include "ImageLoader.cpp"
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#define M_PI 3.14159265358979323846
using namespace std;

GLfloat xi = 0.0;
GLfloat yi = 0.0;
//GLint numLados = 3;
GLint escala = 1;
const float BOX_SIZE = 4.0f;
GLdouble anguloY = 0;
GLdouble anguloX = 0;
GLdouble anguloZ = 0;

GLuint loadTexture(Image* image) {
	GLuint idtextura;
	glGenTextures(1, &idtextura);
	glBindTexture(GL_TEXTURE_2D, idtextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return idtextura;
}
GLuint _uno;
GLuint _dos;
GLuint _tres;
GLuint _cuatro;
GLuint _cinco;
GLuint _seis;
void initRendering() {
	
	Image* uno = loadBMP("1.bmp");
	_uno = loadTexture(uno);
	delete uno;
	Image* dos = loadBMP("2.bmp");
	_dos = loadTexture(dos);
	delete dos;
	Image* tres = loadBMP("3.bmp");
	_tres = loadTexture(tres);
	delete tres;
	Image* cuatro = loadBMP("4.bmp");
	_cuatro = loadTexture(cuatro);
	delete cuatro;
	Image* cinco = loadBMP("5.bmp");
	_cinco = loadTexture(cinco);
	delete cinco;
	Image* seis = loadBMP("6.bmp");
	_seis = loadTexture(seis);
	delete seis;
}

void init(void){							
 glEnable(GL_TEXTURE_2D);							
 glShadeModel(GL_SMOOTH);							
 glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				
 glClearDepth(1.0f);									
 glEnable(GL_DEPTH_TEST);							
 glDepthFunc(GL_LEQUAL);								
 glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	

 glEnable(GL_LIGHT1);		
}


void ArrowKey(int key, int x, int y){
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		if (xi < 10)
			xi += 0.5;
		break;

	case GLUT_KEY_LEFT:
		if (xi > -10)
			xi -= 0.5;
		break;

	case GLUT_KEY_UP:
		if (yi < 10)
			yi += 0.5;
		break;

	case GLUT_KEY_DOWN:
		if (yi > -10)
			yi -= 0.5;
		break;
		case GLUT_KEY_HOME:
		if (escala > 5)
			escala = 5;
		cout << "Aumentando Escala" << endl;
		escala = escala + 1;
		break;
	case GLUT_KEY_PAGE_UP:
		if (escala <= 1)
			escala = 1;
		cout << "Reduciendo Escala" << endl;
		escala = escala - 1;
		break;

	case GLUT_KEY_PAGE_DOWN:
		cout << "Rotando positivamente" << endl;
		anguloY += 5;


		break;

	case GLUT_KEY_END:
		cout << "Rotando negativamente" << endl;
		anguloY -= 5;
		break;
	case GLUT_KEY_F2:
		cout << "Rotando positivamente" << endl;
		anguloZ += 5;

	case GLUT_KEY_F3:
		cout << "Rotando negativamente" << endl;
		anguloX -= 5;



	default:
		break;
	}

	glutPostRedisplay();
}



void display(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
    
	
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(xi, yi, -3);
	glScaled(escala, escala, 1.0);
	//gluPerspective(90.0, 1.0, 1.0, 100.0);

	
	glRotated(anguloX, 1.0, 0.0, 0.0);
	glRotated(anguloY,0.0,1.0,0.0);
	glRotated(anguloZ, 0.0, 0.0, 1.0);

	//Top face
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _uno);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2 , BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2 , BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);	
	glVertex3f(BOX_SIZE / 2 , BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2 , BOX_SIZE / 2, -BOX_SIZE / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
 
	//Bottom face
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _dos);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2  , -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
        glVertex3f(BOX_SIZE / 2  , -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
        glVertex3f(BOX_SIZE / 2  , -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2  , -BOX_SIZE / 2, BOX_SIZE / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
 
 
	//Left face 
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _tres);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2  , -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2  , -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2  , BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-BOX_SIZE / 2  , BOX_SIZE / 2, -BOX_SIZE / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
 
	//Right face
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _cuatro);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f); 
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2 , -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2 , BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2 , BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2 , -BOX_SIZE / 2, BOX_SIZE / 2);
	glEnd();
	glDisable(GL_TEXTURE_2D);
 
	//Front face : Polígono Texturizado
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _cinco);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);	
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2 , -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(BOX_SIZE / 2 , -BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2 , BOX_SIZE / 2, BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-BOX_SIZE / 2 , BOX_SIZE / 2, BOX_SIZE / 2);
	glEnd();	
	glDisable(GL_TEXTURE_2D);
 
	//Back face : Polígono Texturizado
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _seis);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glNormal3f(0.0, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 2, -BOX_SIZE / 2);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(BOX_SIZE / 2, -BOX_SIZE / 2, -BOX_SIZE / 2);	
	glEnd();
	glDisable(GL_TEXTURE_2D);
 
	glutSwapBuffers();
}
void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();//Inicializa la matriz de proyeccion
	glOrtho(-10.0, 10.0, -10.00, 10.0, 0.1, 20.0); // WorkSpace
	glMatrixMode(GL_MODELVIEW); // cambiamos la matrix :D

}
void keyboard(unsigned char key, int x, int y){
	switch (key)
	{
	case 27:
		exit(0);
		break;
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 300);

	glutInitWindowPosition(100, 100);
	glutCreateWindow("Ejemplo 3D");
	glEnable(GL_DEPTH_TEST);
	init();
	initRendering();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(ArrowKey);
	glutMainLoop();
	return 0;
}
