#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/*
//#-----------------------------------------------------------------
COMPILAR!!!!!

g++ ejercicio3.cpp -o ejercicio3 -lGL -lGLU -lglut

//#------------------------------------------------------------------
*/
float mayorx;
float menorx;
float mayory;
float menory;

int lados=3;
float radio=1;


float rota= 0.0f;
float muevex= 0.0f;
float muevey= 0.0f;
float escala= 1.0f;

void rotacion(float xc,float yc,float *x, float *y,float an){
  float xs= xc+((*x-xc)*cos(an/57.3))-((*y-yc)*sin(an/57.3));
  *x=xs;
  float ys= yc+((*x-xc)*sin(an/57.3))+((*y-yc)*cos(an/57.3));
  *y=ys;
  //printf("xs=%d, ys=%d\n",xs,ys );
}


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

//******************************************[creacion de la figura]  
	  int angulo = 360/lados;
	  int an=0;
	  int n=0;
	  for (int i = 0; i < lados; i++){
	  	  x= xr(radio,an);
	  	  y= yr(radio,an);
	  	  figura[n++]=x;
	  	  figura[n++]=y;
	      an=an+angulo;
	  }
//******************************************************************
//********************************************************************[desplazamiento]
	  n=0;
	  for (int i = 0; i < lados*2; i=i+2){
        figura[n]+=muevex;
        n++;
        figura[n]+=muevey;
        n++;
	  }
//************************************************************************************	
//********************************************************************[CENTRO DE LA FIGURA]      
	  //printf("figura[0]:::%f\n",figura[0] );
	  mayorx=figura[0];
	  menorx=figura[0];
      mayory=figura[1];
      menory=figura[1];
      n=0;
	  for (int i = 0; i < lados*2; i=i+2){
        x=figura[n++];
        y=figura[n++];

        if(x>mayorx){
        	mayorx=x;
        }
        if(x<menorx){
        	menorx=x;
        }
        if(y>mayory){
        	mayory=y;
        }
        if(y<menory){
        	menory=y;
        }
	  }
	  //printf("max%f;;mex%f;;may%f;;mey%f\n",mayorx,menorx,mayory,menory);
	  centrox= (mayorx+menorx)/2;
	  centroy= (mayory+menory)/2;
	  printf("x::%f;;y::%f\n",centrox,centroy);
//********************************************************************

//********************************************************************[rotacion]
	  n=0;
	  for (int i = 0; i < lados*2; i=i+2){
        
	  	x= figura[n++];
        y= figura[n++];
        n-=2;


        rotacion(centrox,centroy,&x, &y,rota);


        figura[n++]= x;
        figura[n++]= y;
	  }
//************************************************************************************

//********************************************************************[dibujo de los puntos]
  glBegin(GL_POLYGON);
      n=0;
	  for (int i = 0; i < lados*2; i=i+2){
        x=figura[n++];
        y=figura[n++];
	  	glVertex2f(x,y);
	  }
   glEnd();
  
//********************************************************************



  //Ordenar dibujado
  glFlush();
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
  printf("%d\n",key );
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
      rota+=1;  
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