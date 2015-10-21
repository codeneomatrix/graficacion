#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "bresenham.cpp"

int x0,yi,x1,yf,dx,dy,y,x,A,B,e,horizontal,lineavertical,vertical,maxtan=40,poseje=maxtan/2,adx,ady;
char salida;
int sol=0;
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
         if(matrix[y][x]==4){
            printf("\033[1;32m▓\033[1;37m");
         }
         if(matrix[y][x]==6){
            printf("\033[1;33m☀\033[1;37m");
         }
         if(matrix[y][x]==8){
            printf("\033[1;32m⚫\033[1;37m");
         }
      }
    printf("\n");
    lineavertical=0;

   }

}

void juego(int pxp, int pyp,int velocidadx, int velocidady){
   int cambio=0;
   //int velocidadx=1;
   //int velocidady=1;
   
   //int pxp=maxtan-1;
   //int pyp=(maxtan-1)/2;

   while (true){

      matrix[pxp][pyp]=0;

      //printf("pxp: %d\n",pxp );
      //printf("pyp: %d\n",pyp );


      pxp -= velocidadx;
      pyp += velocidady;
      
      if (matrix[pxp][pyp]==3){
         int ra = (1+ (rand()% 2));
         matrix[pxp][pyp]= 6;
         grafica();
         sleep(1);
            if (ra>0.3){
               velocidady*=-1;      
            }
         matrix[pxp][pyp]= 0;
         if(sol==2){
            grafica();
            break; 
         }
         
         
      }

      if (pxp>=(maxtan-1)){
         velocidadx*=-1;
          if (cambio==0 && (1+ (rand()% 2)) >1.3){
             cambio=1;
             //printf("velocidadx = 2\n");
             velocidadx*=2;
             velocidady=1;
          }
          if (cambio==1 && (1+ (rand()% 2)) <1.5){
            cambio=0;
            //printf("velocidadx = 1\n");
            velocidadx=1;
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
      sleep(1);

      }

}

void rotacion(int xc,int yc,int *x, int *y,int an){
  int xs= xc+((*x-xc)*cos(an/57.3))-((*y-yc)*sin(an/57.3));
  *x=xs;
  int ys= yc+((*x-xc)*sin(an/57.3))+((*y-yc)*cos(an/57.3));
  *y=ys;
  printf("xs=%d, ys=%d\n",xs,ys );
}


int main(){

  printf("BIENVENIDO\n1)JUGAR SOLO \n2)JUGAR CON ALGUIEN\n");
  scanf("%d",&sol);


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


  //###################canon#######################################
  int longitud= 5; 
  int salid=-1;
  
  int pfy=(pyp+(longitud-1));
  int pfx=(pxp-(longitud-1));
  
  printf("4+enter:izquierda\n6+enter:derecha\n0+enter:dispara\n\n");
 while(salid!=-2){

     int* sa = bresen(pyp,pxp,pfy,pfx);

    int j= 0; 
      for (int i = 0; i <longitud; i++){
        matrix[sa[j+1]][sa[j]]=4;
        j=j+2;
      }

    //printf("xf: %d,yf:%d\n",pfy,pfx );
    
    if(salid==4){
      j= 0;
      for (int i = 0; i <longitud; i++){
        matrix[sa[j+1]][sa[j]]=0;
        j=j+2;
      }

      rotacion(pyp,pxp,&pfy,&pfx,-1);
      printf("xf: %d,yf:%d\n",pfy,pfx );

      sa = bresen(pyp,pxp,pfy,pfx);

      j= 0; 
      for (int i = 0; i <longitud; i++){
        matrix[sa[j+1]][sa[j]]=4;
        j=j+2;
      }
    }

    if(salid==6){
      j= 0;
      for (int i = 0; i <longitud; i++){
        matrix[sa[j+1]][sa[j]]=0;
        j=j+2;
      }

      rotacion(pyp,pxp,&pfy,&pfx,5);
      printf("xf: %d,yf:%d\n",pfy,pfx );

      sa = bresen(pyp,pxp,pfy,pfx);

      j= 0; 
      for (int i = 0; i <longitud; i++){
        matrix[sa[j+1]][sa[j]]=4;
        j=j+2;
      }
    }

    if(salid==0){

       int vx=pfx-pxp;
       int vy=pfy-pyp;
       int sent=1;
      if(vx<0){
          sent=-1;
       }
      if (vx!=0){
          vx=vx*sent;
       }
       
       printf("\nvx %d\n",vx );
       printf("vy %d\n", vy);

       juego(sa[((longitud*2)-1)],sa[((longitud*2)-2)],vx,vy);
    }

    grafica();
    scanf("%d",&salid);
  }

return 0;
}