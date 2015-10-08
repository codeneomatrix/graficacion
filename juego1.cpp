#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
int x0,yi,x1,yf,dx,dy,y,x,A,B,e,horizontal,lineavertical,vertical,maxtan=40,poseje=maxtan/2,adx,ady;
char salida;
int matrix[40][40];


void grafica(){
   printf("\033[0;0f");
   for (int y=0;y<maxtan;y++){
      printf("\t\t");
      for (int x=0;x<maxtan;x++){
         if(matrix[y][x]==0){
            printf("\033[1;37m \033[1;37m");
         }
         if(matrix[y][x]==3){
            printf("\033[1;31m▓\033[1;37m");
         }
         if(matrix[y][x]==8){
            printf("\033[1;32m⚫\033[1;37m");
         }
      }
    printf("\n");
    lineavertical=0;

   }

}



int main(){
   int metodintro;

   for (int i=0;i<maxtan;i++){
      for (int j=0;j<maxtan;j++){
         matrix[j][i]=0;   
      }
    }


    for (int i=0;i<100;i++){
         matrix[(1+ (rand()% 10))][(1+ (rand()% maxtan))]=3;   
    }
      
      int pxp=maxtan-1;
      int pyp=(maxtan-1)/2;

       matrix[pxp][pyp]=8;



   //printf("\n PROGRAMA ESCRITO POR ACEVEDO!!!!!!!!!!!!!!!!\n");

   grafica();

   //juego();
   int cambio=0;

   int velocidadx=1;
   int velocidady=1;

   for (int i = 0; i < 10000; i++){
      
      


      matrix[pxp][pyp]=0;

      //printf("pxp: %d\n",pxp );
      //printf("pyp: %d\n",pyp );


      pxp -= velocidadx;
      pyp += velocidady;
      
      if (matrix[pxp][pyp]==3){
         int ra = (1+ (rand()% 2));
            if (ra>0.3){
               velocidady*=-1;      
            }
         
      }

      if (pxp>=(maxtan-1)){
         velocidadx*=-1;
          if (cambio==0 && (1+ (rand()% 2)) >0.3){
             cambio=1;
             printf("velocidadx = 2\n");
             velocidadx*=2;
          }
          else{
            cambio=0;
            printf("velocidadx = 1\n");
            velocidadx=-1;
         }
      }
      if (pxp<=0){
         pxp=0;
         velocidadx*=-1;
      }
      if (pyp<=0){
         pyp=0;
         velocidady*=-1;
      }
      if (pyp>=(maxtan-1)){
         velocidady*=-1;
      }

      matrix[pxp][pyp]=8;
      
      grafica();
      sleep(0.90);

      }

return 0;
}