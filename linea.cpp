#include <stdio.h>
#include <stdlib.h>

int x0,y0,x1,y1,dx,dy,y,x,A,B,e,horizontal,lineavertical,vertical,maxtan=40,poseje=maxtan/2,adx,ady;



int main(){
char salida;
int matrix[maxtan][maxtan];
//char ejes='▓',linea='#',fondo[]="\033[1;37m.\033[1;32m";

for (int i=0;i<maxtan;i++){
	for (int j=0;j<maxtan;j++){
		if(j==poseje || i== poseje){
        matrix[j][i]=3;
		}else{
		matrix[j][i]=0;	
		}
	}
}

printf("\n PROGRAMA ESCRITO POR ACEVEDO!!!!!!!!!!!!!!!!\n");


while(salida!='x'){

	printf("x0:");
scanf("%d",&x0);
//x0=2;
printf("y0:");
scanf("%d",&y0);
//y0=1;

printf("x1:");
scanf("%d",&x1);
//x1=10;
printf("y1:");
scanf("%d",&y1);
//y1=5;

if(x0==x1){
	lineavertical=1;
}

if(x0>x1){
 horizontal=0; //izquierda
 printf("izquierda!!!!!!!!\n");
}else{
 horizontal= 1; //derecha
 printf("derecha!!!!!!!!\n");
}

if(y0>y1){
 vertical = 0; //bajar
 printf("bajar!!!!!!!!\n");
}else{
 vertical = 1; //subir
 printf("subir!!!!!!!!\n");
}


dx = x1-x0;
dy = y1-y0;
adx = abs(dx);
ady= abs(dy);

y = y0;
x = x0;
A= 2*dy;
//B = A-(2*dx);
//e = A-dx;

printf("x0=%d y0=%d x1=%d  y1=%d dx=%d  dy=%d    A=%d",x0,y0,x1,y1,dx,dy,A) ;

if (adx>=ady){

	if(horizontal==0 && vertical==1){
dx=dx*-1;
B = A-(2*dx);
e = A-dx;
printf("B=%d  \n     %d             (x,y) \n",B,e);
printf("e=(%d-%d) %d",A,dx,e);
for (int px=x0;px>=x1;px--){
 printf("       (%d,%d)\n",px,y);
 matrix[poseje-y][poseje+px]=1;

 	if(e>0){
 			y++;
 			printf(" e=(%d+%d)= ",e,B);
 			e =e+B;
 			printf("%d ",e);
 		}
	else{
			
			printf(" e=(%d+%d)=",e,A);
	 		e = e+A;
	 		printf(" %d ",e);
	 	}
}
 printf("\n");

}


else if(horizontal==0 && vertical==0){
B = A-(2*dx);
e = A-dx;
printf("B=%d  \n     %d             (x,y) \n",B,e);
printf("e=(%d-%d) %d",A,dx,e);
for (int px=x0;px >= x1;px--){
 
 printf("       (%d,%d)\n",px,y);
	matrix[poseje-y][poseje+px]=1;
 	if(e<0){

 			y--;
 			printf(" e=(%d+%d)= ",e,B);
 			e =e+B;
 			printf("%d ",e);
 		}
	else{
			
			printf(" e=(%d+%d)=",e,A);
	 		e = e+A;
	 		printf(" %d ",e);
	 	}

}
 printf("\n");


}

else if(horizontal==1 && vertical==0 && lineavertical!=1){
dx=dx*-1;
B = A-(2*dx);
e = A-dx;
printf("B=%d  \n     %d             (x,y) \n",B,e);
printf("e=(%d-%d) %d",A,dx,e);
for (int px=x0;px<=x1;px++){
 
 printf("       (%d,%d)\n",px,y);
 matrix[poseje-y][poseje+px]=1;

 	if(e<0){

 			y--;
 			printf(" e=(%d+%d)= ",e,B);
 			e =e+B;
 			printf("%d ",e);
 		}
	else{
			
			printf(" e=(%d+%d)=",e,A);
	 		e = e+A;
	 		printf(" %d ",e);
	 	}

}
 printf("\n");


}

else if(horizontal==1 && vertical==1 && lineavertical!=1){
B = A-(2*dx);
e = A-dx;
printf("B=%d  \n     %d             (x,y) \n",B,e);
printf("e=(%d-%d) %d",A,dx,e);
for (int px=x0;px<=x1;px++){
 printf("       (%d,%d)\n",px,y);
 matrix[poseje-y][poseje+px]=1;

 	if(e>0){
 			y++;
 			printf(" e=(%d+%d)= ",e,B);
 			e =e+B;
 			printf("%d ",e);
 		}
	else{
			
			printf(" e=(%d+%d)=",e,A);
	 		e = e+A;
	 		printf(" %d ",e);
	 	}
}
 printf("\n");

}
}else{

if(horizontal==0 && vertical==1){
A= 2*dx;
dy=dy*-1;
B = A-(2*dy);
e = A-dy;
printf("B=%d  \n     %d             (x,y) \n",B,e);
printf("e=(%d-%d) %d",A,dx,e);
for (int py=y0;py<=y1;py++){
 printf("       (%d,%d)\n",x,py);
 matrix[poseje-py][poseje+x]=1;

 	if(e<0){
 			x--;
 			printf(" e=(%d+%d)= ",e,B);
 			e =e+B;
 			printf("%d ",e);
 		}
	else{
			
			printf(" e=(%d+%d)=",e,A);
	 		e = e+A;
	 		printf(" %d ",e);
	 	}
}
 printf("\n");

}


else if(horizontal==0 && vertical==0){
A= 2*dx;

B = A-(2*dy);
e = A-dy;

printf("B=%d  \n     %d             (x,y) \n",B,e);
printf("e=(%d-%d) %d",A,dy,e);
for (int py=y0;py>=y1;py--){
 printf("       (%d,%d)\n",x,py);
 matrix[poseje-py][poseje+x]=1;

 	if(e<0){
 			x--;
 			printf(" e=(%d+%d)= ",e,B);
 			e =e+B;
 			printf("%d ",e);
 		}
	else{
			
			printf(" e=(%d+%d)=",e,A);
	 		e = e+A;
	 		printf(" %d ",e);
	 	}

}
 printf("\n");


}

else if(horizontal==1 && vertical==0 && lineavertical!=1){
A= 2*dx;
dy=dy*-1;
B = A-(2*dy);
e = A-dy;
printf("B=%d  \n     %d             (x,y) \n",B,e);
printf("e=(%d-%d) %d",A,dx,e);
for (int py=y0;py>=y1;py--){
 
 printf("       (%d,%d)\n",x,py);
 matrix[poseje-py][poseje+x]=1;

 	if(e>0){

 			x++;
 			printf(" e=(%d+%d)= ",e,B);
 			e =e+B;
 			printf("%d ",e);
 		}
	else{
			
			printf(" e=(%d+%d)=",e,A);
	 		e = e+A;
	 		printf(" %d ",e);
	 	}

}
 printf("\n");


}

else if(horizontal==1 && vertical==1 && lineavertical!=1){

A= 2*dx;

B = A-(2*dy);
e = A-dy;

printf("B=%d  \n     %d             (x,y) \n",B,e);
printf("e=(%d-%d) %d",A,dy,e);
for (int py=y0;py<=y1;py++){
 printf("       (%d,%d)\n",x,py);
 matrix[poseje-py][poseje+x]=1;

 	if(e>0){
 			x++;
 			printf(" e=(%d+%d)= ",e,B);
 			e =e+B;
 			printf("%d ",e);
 		}
	else{
			
			printf(" e=(%d+%d)=",e,A);
	 		e = e+A;
	 		printf(" %d ",e);
	 	}
}
 printf("\n");

}
}


if(horizontal==1 && vertical==0 && lineavertical==1){
dx=dx*-1;
B = A-(2*dx);
e = A-dx;
printf("B=%d  \n     %d             (x,y) \n",B,e);
printf("e=(%d-%d) %d",A,dx,e);
int px=x0;
for (int y=y0;y>=y1;y--){
 printf("       (%d,%d)\n",px,y);
 matrix[poseje-y][poseje+px]=1;
}
 printf("\n");


}

else if(horizontal==1 && vertical==1 && lineavertical==1){
B = A-(2*dx);
e = A-dx;
printf("B=%d  \n     %d             (x,y) \n",B,e);
printf("e=(%d-%d) %d",A,dx,e);
int px=x0;
for (int y=y0;y<=y1;y++){
 printf("       (%d,%d)\n",px,y);
 matrix[poseje-y][poseje+px]=1;
}
 printf("\n");


}

for (int y=0;y<maxtan;y++){
	printf("\t\t");
	for (int x=0;x<maxtan;x++){
		//printf("la matrix vale%d\n",matrix[x][y] );
		if(matrix[y][x]==0){
			//printf("[%d%d:%d]",x, y,matrix[y][x] );
			printf("\033[1;37m.\033[1;37m");
		}
		if(matrix[y][x]==1){
			//printf("[%d%d:%d]",x, y,matrix[y][x] );
			printf("\033[1;32m▓\033[1;37m");
		}
		if(matrix[y][x]==3){
			//printf("[%d%d:%d]",x, y,matrix[y][x] );
			printf("\033[1;31m▓\033[1;37m");
		}
	}
 printf("\n");
 lineavertical=0;

}


printf("desea colocar un nuevo punto?(s) (x para salir):");
scanf("%c",&salida);
printf("\n");
}




return 0;
}
