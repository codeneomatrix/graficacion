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

void pintar(int pi,int pf,char le[]){

	for (int i=0; i<pf; i++){
    	for (int j = 0; j < pf; j++)
    	{
    		printf("%s", le);	
    	}
    	printf("\n");
   	//espacio(e);
    }

}

void dividir(int pi, int pf){
	int t,pc1=0,pc2=0;
	t= (pf-pi)/3;
	pc1= pi+t;
	pc2= pc1+t;
	printf("pc1: %d\n",pc1 );
	printf("pc2: %d\n",pc2 );
	
}

void espacio(int p){
	for (int j = 0; j < p; j++)
    	{
    		printf("%s", " ");	
    	}
}
main()
{
    int e=20,r=40,n,mx1,mx2,my;
    //r=80

    printf("Alfombra de Sierpinski \n");
    
    printf("ingrese el nivel :\n");
    scanf("%d",&n);

    char x[]=".";
    pintar(0,27,x);

	//espacio(e);

    /*for (int i=0; i<mx1; i++){
    	for (int j = 0; j < mx1; j++)
    	{
    		printf("%s", "*");	
    	}

    	for (int j = mx1; j < mx2; j++)
    	{
    		printf("%s", "%");	
    	}
    	for (int j = mx2; j < r; j++)
    	{
    		printf("%s", "=");	
    	}
    	printf("\n");
   	espacio(e);
    }
     for (int i=mx1; i<mx2; i++){
    	for (int j = 0; j < mx1; j++)
    	{
    		printf("%s", "/");	
    	}

    	for (int j = mx1; j < mx2; j++)
    	{
    		printf("%s", "#");	
    	}
    	for (int j = mx2; j < r; j++)
    	{
    		printf("%s", "!");	
    	}
    	printf("\n");
   	espacio(e);
    }
    for (int i=mx2; i<r; i++){
    	for (int j = 0; j < mx1; j++)
    	{
    		printf("%s", "+");	
    	}

    	for (int j = mx1; j < mx2; j++)
    	{
    		printf("%s", "~");	
    	}
    	for (int j = mx2; j < r; j++)
    	{
    		printf("%s", "¨");	
    	}
    	printf("\n");
   	espacio(e);
    }*/

    dividir(0,27);

    system("pause");
    return 0;
    }

