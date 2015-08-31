/*
  program:1
  Name: alfombra de sierpinski.cpp
  Author: josue acevedo maldonado, maldad, Luis E. Ramos Cruz
  Date: 27/08/15 
  Description:
*/
#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

int I=0,F=27,cn=1;
int puntos[100]={I,F};

void exchange(int i, int j) {
	int temp = puntos[i];
	puntos[i] = puntos[j];
	puntos[j] = temp;
}//exchange


void quicksort(int low, int high) {
	int i = low, j = high;
	// Pivote a la mitad del arreglo
	int pivot = puntos[low + (high-low)/2];
	// Dividir en dos listas
	while (i <= j) {
	// Si el valor actual de la lista izquierda
	// es mas pequeño que el pivote
	// entonces tomar el sig. elemento de la izquierda
		while (puntos[i] < pivot) {
			i++;
		}//while
	// Si el valor actual de la lista derecha
	// es mas grande que el pivote
	// entonces tomar el sig. elemento de la derecha
		while (puntos[j] > pivot) {
			j--;
		}//while
			if(i <= j){
				exchange(i, j);
				i++;	
				j--;
			}
	}//while
	
// Recursion
	if (low < j)
		quicksort(low, j);
	if (i < high)
		quicksort(i, high);
}//quicksort


void sort(int values[]) {
// Checar si el arreglo esta vacio o es nulo
	if (values ==NULL || cn==0) {
	return;
	}
	int number = cn;
	quicksort(0, number);
}//sort

void dividir(int pi, int pf){
	int t,pc1=0,pc2=0;
	if (pi<pf){	
		t= (pf-pi)/3;
		pc1= pi+t;
		pc2= pc1+t;
		/*printf ("\033[%d;%dH",cn,40);
		printf("pc1: %d\n",pc1 );*/
		cn++;
		puntos[cn]= pc1;
		/*printf ("\033[%d;%dH",cn,40);
		printf("pc2: %d\n",pc2 );*/
		cn++;
		puntos[cn]= pc2;
		}
}


void pintar(int al,int pi,int pf,char le[]){
printf ("\033[0;0H");
printf ("\033[%d;0H",al+1);
for (int i=pi; i<pf; i++){
	printf ("\033[%dC",pi+1);
    	for (int j = pi; j <pf; j++){
    		printf("%s", le);	
    	}
    	printf("\n");
    }
}

main(){	

    int n;
    char x[]="\033[1;37m.\033[1;32m", O[]="▓"; // ▆ ▇ ▉ ⬣ ◼ ▉ 

    printf("Alfombra de Sierpinski \n");
    
    printf("ingrese el nivel (minimo 1, maximo 3):\n");
    scanf("%d",&n);
    
    printf ("\033[1J"); //BORRA LA TERMINAL
    //printf ("\033[47m"); //color de fondo blanco
    printf ("\033[1;32m"); 
    pintar(I,I,F,x);


for (int k = 0; k < n; k++){

	int i = 0;
	int ni=cn;
    while (i < ni){
    	
    	/*printf ("\033[%d;%dH",cn,60);
    	printf("%d .- primer punto %d\n",cn,puntos[i]);
    	printf ("\033[%d;%dH",cn,80);
    	printf("segundo punto %d\n", puntos[i+1]);*/
    	dividir(puntos[i],puntos[i+1]);

    	i+=1;
    }

ni++;


for (int i = ni; i < cn; i+=2){
for (int j = ni; j <= cn; j+=2){
	pintar(puntos[i],puntos[j],puntos[j+1],O);
}
}
	
	sort(puntos);

/*if (k==n-1){	
for (int j = 0; j <= cn; j++){
	printf ("\033[%d;%dH",j+1,100);
	printf("punto fulano::: %d\n", puntos[j]);;
}
}*/

}
	
	printf ("\033[1;37m");
	printf ("\033[%d;%dH",F+2,1);

    //system("pause");
    return 0;
    }
