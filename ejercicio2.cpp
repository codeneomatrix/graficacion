#include <GL/glut.h>
#include <math.h>

/*
//#-----------------------------------------------------------------
COMPILAR!!!!!

g++ ejercicio2.cpp -o ejercicio2 -lGL -lGLU -lglut

//#------------------------------------------------------------------
*/

float xr(float radio,int an){
  float ran= an/57.3;
  return radio*(cos(ran));

}
float yr(float radio,int an){
  float ran= an/57.3; 
  return radio*(sin(ran));

}


//Función de dibujado
void dibujar(void)
{
  //Color de fondo
  glClearColor(0,1,0,1);
  glClear(GL_COLOR_BUFFER_BIT );


  glColor3f(1,0,0);
  glBegin(GL_POLYGON);


  int lados=13,angulo;
  float radio=0.5;

  angulo = 360/lados;
  int n=0,an=0;

  for (int i = 0; i < lados; i++){
      glVertex2f((xr(radio,an)),(yr(radio,an)+0.5));
    an=an+angulo;

  }



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
  glutCreateWindow("ejercicio2.cpp");
  //Llamada a la función de dibujado
  glutDisplayFunc(dibujar);
  glutMainLoop();
  return 0;
}