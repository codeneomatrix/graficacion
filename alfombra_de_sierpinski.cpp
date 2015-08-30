/*
  program:1
  Name: alfombra de sierpinski.cpp
  Author: josue acevedo maldonado, maldad, Luis E. Ramos Cruz
  Date: 27/08/15 
  Description:
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void dividir(int pi, int pf){
	int t,pc1=0,pc2=0;
	t= (pf-pi)/3;
	pc1= pi+t;
	pc2= pc1+t;
	printf("pc1: %d\n",pc1 );
	printf("pc2: %d\n",pc2 );
	
}


void pintar(int al,int pi,int pf,char le[]){
printf ("\033[%d;0H",al+1);
for (int i=pi; i<pf; i++){
	printf ("\033[%dC",pi+1);
    	for (int j = pi; j <pf; j++)
    	{
    		printf("%s", le);	
    	}
    	printf("\n");
    }
}

main()
{
    int r=40,n,I=0,F=27;
    char x[]=".", O[]="#";
    //r=80

    printf("Alfombra de Sierpinski \n");
    
    printf("ingrese el nivel :\n");
    scanf("%d",&n);

    printf ("\033[1J"); //BORRA LA TERMINAL

    printf ("\033[0;0H");
    //printf ("\033[47m"); //color de fondo blanco
    //printf ("\033[1;37m"); //color del texto blanco
    pintar(I,I,F,x);

    printf ("\033[0;0H");
    pintar(9,9,18,O);


    printf ("\033[0;0H");
    pintar(1,1,2,O);

    printf ("\033[0;0H");
    pintar(1,4,5,O);

    printf ("\033[0;0H");
    pintar(3,3,6,O);

    printf ("\033[0;0H");
    pintar(3,12,15,O);

    printf ("\033[0;0H");
    pintar(3,21,24,O);


   // dividir(I,F);



    //system("pause");
    return 0;
    }

