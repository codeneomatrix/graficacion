#include <GL/glut.h>


/*
//#-----------------------------------------------------------------
COMPILAR!!!!!

g++ ejercicio.cpp -o ejercicio -lGL -lGLU -lglut

//#------------------------------------------------------------------
*/

//Función de dibujado
void dibujar(void)
{
  //Color de fondo
  glClearColor(0,1,0,1);
  glClear(GL_COLOR_BUFFER_BIT );
  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(-0.5,-0.5);
  glVertex2f(0,-0.5);
  glVertex2f(0.5,0.5);
  glEnd();
  //Ordenar dibujado
  glFlush();
}

//Ejecución principal
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  //Buffer simple
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(0,0);
  glutInitWindowSize(500,500);
  glutCreateWindow("ejercicio.cpp");
  //Llamada a la función de dibujado
  glutDisplayFunc(dibujar);
  glutMainLoop();
  return 0;
}