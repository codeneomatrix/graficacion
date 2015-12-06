//#include "stdafx.h"
#include <GL/glut.h>
#include "ImageLoader.cpp"
GLuint loadTexture(Image* image) {
	GLuint idtextura;
	glGenTextures(1, &idtextura);
	glBindTexture(GL_TEXTURE_2D, idtextura);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->width, image->height, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
	return idtextura;
}
GLuint _madera_pared;
void initRendering() {
	Image* madera_pared = loadBMP("madera_pared.bmp");
	_madera_pared = loadTexture(madera_pared);
	delete madera_pared;
}
void display(void) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _madera_pared);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex2f(-0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex2f(-0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex2f(0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex2f(0.5, -0.5);
	glEnd();

	glutSwapBuffers();
}
int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Hello World");
	initRendering();
	glutDisplayFunc(display);
	glutMainLoop();
}