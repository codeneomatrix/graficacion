#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
//#include <stdlib.h>
/*
//#-----------------------------------------------------------------
COMPILAR!!!!!

g++ nombretrans.cpp -o nombretrans -lGL -lGLU -lglut

//#------------------------------------------------------------------
*/
float mayorx;
float menorx;
float mayory;
float menory;

int lados=3;
float radio=1;


float rota= 0;
float muevex= 0.0f;
float muevey= 0.0f;
float escala= 1.0f;


void dibuja(){
	glRotatef(rota,0.0f,0.0f,1.0f);
	glScalef(escala,escala,1.0f);
	//********************************************************************[j]
  glBegin(GL_POLYGON);
	  	glVertex2f(-15+muevex,4+muevey);
		glVertex2f(-9+muevex,4+muevey);
		glVertex2f(-9+muevex,2+muevey);
		glVertex2f(-15+muevex,2+muevey);

  glEnd();

glBegin(GL_POLYGON);
        glVertex2f(-13+muevex,2+muevey);
        glVertex2f(-11+muevex,2+muevey);
		glVertex2f(-11+muevex,-2+muevey);
		glVertex2f(-13+muevex,-2+muevey);
glEnd();
glBegin(GL_POLYGON);
		glVertex2f(-11+muevex,0+muevey);
	    glVertex2f(-11+muevex,-2+muevey);
		glVertex2f(-15+muevex,-2+muevey);
		glVertex2f(-15+muevex,0+muevey);
glEnd();
//********************************************************************

//********************************************************************[o]
  glBegin(GL_POLYGON);
	  	glVertex2f(-4+muevex,4+muevey);
		glVertex2f(-4+muevex,-2+muevey);
		glVertex2f(-8+muevex,-2+muevey);
		glVertex2f(-8+muevex,4+muevey);

  glEnd();

//********************************************************************
//********************************************************************[s]
  glBegin(GL_POLYGON);
	  	glVertex2f(1+muevex,4+muevey);
		glVertex2f(1+muevex,2+muevey);
		glVertex2f(-3+muevex,2+muevey);
		glVertex2f(-3+muevex,4+muevey);

  glEnd();

glBegin(GL_POLYGON);
        glVertex2f(-1+muevex,2+muevey);
        glVertex2f(-3+muevex,2+muevey);
		glVertex2f(-3+muevex,-1+muevey);
		glVertex2f(-1+muevex,-1+muevey);
glEnd();

glBegin(GL_POLYGON);
		glVertex2f(-1+muevex,0+muevey);
	    glVertex2f(1+muevex,0+muevey);
		glVertex2f(1+muevex,-5+muevey);
		glVertex2f(-1+muevex,-5+muevey);
glEnd();
glBegin(GL_POLYGON);
		glVertex2f(-1+muevex,-3+muevey);
	    glVertex2f(-3+muevex,-3+muevey);
		glVertex2f(-3+muevex,-5+muevey);
		glVertex2f(-1+muevex,-5+muevey);
glEnd();
//********************************************************************

//********************************************************************[u]
  glBegin(GL_POLYGON);
	  	glVertex2f(2+muevex,4+muevey);
		glVertex2f(4+muevex,4+muevey);
		glVertex2f(4+muevex,-2+muevey);
		glVertex2f(2+muevex,-2+muevey);

  glEnd();

glBegin(GL_POLYGON);
        glVertex2f(4+muevex,0+muevey);
        glVertex2f(5+muevex,0+muevey);
		glVertex2f(5+muevex,-2+muevey);
		glVertex2f(4+muevex,-2+muevey);
glEnd();

glBegin(GL_POLYGON);
		glVertex2f(5+muevex,4+muevey);
	    glVertex2f(7+muevex,4+muevey);
		glVertex2f(7+muevex,-2+muevey);
		glVertex2f(5+muevex,-4+muevey);
glEnd();
//********************************************************************

//********************************************************************[e]
  glBegin(GL_POLYGON);
	  	glVertex2f(8+muevex,4+muevey);
		glVertex2f(12+muevex,4+muevey);
		glVertex2f(12+muevex,3+muevey);
		glVertex2f(8+muevex,3+muevey);

  glEnd();

  glBegin(GL_POLYGON);
	  	glVertex2f(8+muevex,2+muevey);
		glVertex2f(12+muevex,2+muevey);
		glVertex2f(12+muevex,1+muevey);
		glVertex2f(8+muevex,1+muevey);
  glEnd();

  glBegin(GL_POLYGON);
	  	glVertex2f(8+muevex,0+muevey);
		glVertex2f(12+muevex,0+muevey);
		glVertex2f(12+muevex,-2+muevey);
		glVertex2f(8+muevex,-2+muevey);
  glEnd();

    glBegin(GL_POLYGON);
	  	glVertex2f(8+muevex,4+muevey);
		glVertex2f(10+muevex,4+muevey);
		glVertex2f(10+muevex,-2+muevey);
		glVertex2f(8+muevex,-2+muevey);

  glEnd();

//********************************************************************

  //Ordenar dibujado
  glFlush();
}


//Función de dibujado
void dibujar(void)
{
  float x;
  float y;
  float centrox;
  float centroy;
  float figura[lados*2];

//*****************************************************[configuracion del renderizado]
  //glClearColor(0,1,0,1); //Color de fondo
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  //glRotatef(rota,0.0f,0.0f,1.0f);
  //glTranslatef(rota,0.0f,0.0f);
  //glTranslatef(1.0f,1.0f,0.0f);
  //glScalef(rota,rota,1.0f);

  gluLookAt(0.0, 0.0, 1.0, //donde esta la camara
  	        0.0, 0.0, 0.0, //para donde ve
  	        0.0, 1.0, 0.0); //donde es arriba

  glColor3f(1,0,0);
//************************************************************************************
dibuja();



}

void reshape(int w, int h){
  if(h<=0){
  	h=1;
  }
  glViewport(0.0,0.0,(GLsizei)w,(GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glOrtho(-10.0,10,-10.0,10.0,-0.1,20.0);
  gluPerspective(45.0f,float(w)/float(h),1.0f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Keyboard(unsigned char key, int x, int y){
  //printf("%d\n",key );
  switch(key){
    case 27:
      exit(0);
      break;
    case 108: //tecla l aumenta el numero de lados
      lados+=1;  
    break;
    case 109: //tecla m disminuye el numero de lados
      if(lados>3){
      	lados-=1;  
      }
    break;
    case 114: //tecla r aumenta el angulo de rotacion
	if(rota>=360){
        rota=0;
    }else{
    	rota+=1;
    }
    break;
    case 110: //tecla n disminuye el angulo de rotacion
	if(rota<=0){
        rota=0;
    }else{
    	rota-=1;
    }
    break;
    case 101: //tecla e aumenta la escala
	escala+=0.5;
    break;
    case 98: //tecla b disminuye la escala
	if(escala<=0.5){
        escala=0.5;
    }else{
    	escala-=0.5;
    }
    break;
  }
  glutPostRedisplay();
}

void ArrowKey(int key,int x, int y ){
  switch(key){
    case(GLUT_KEY_LEFT):
    muevex-=1;
    break;
    case(GLUT_KEY_RIGHT):
    muevex+=1;
    break;
    case(GLUT_KEY_UP):
    muevey+=1;
    break;
    case(GLUT_KEY_DOWN):
    muevey-=1;
    break;
  }
  glutPostRedisplay();
}
//Ejecución principal
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  //Buffer simple
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
  glutInitWindowPosition(0,0);
  glutInitWindowSize(700,700);
  glutCreateWindow("ejercicio3.cpp");
  //Llamada a la función de dibujado
  glutDisplayFunc(dibujar);

  glutReshapeFunc(reshape);
  glutKeyboardFunc(Keyboard);
  glutSpecialFunc(ArrowKey);

  glutMainLoop();
  return 0;
}