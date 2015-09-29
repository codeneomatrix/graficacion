#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x0,yi,x1,yf,dx,dy,y,x,A,B,e,horizontal,lineavertical,vertical,maxtan=40,poseje=maxtan/2,adx,ady;
char salida;
int matrix[40][40];

void puntos(int x0,int yi,int x1,int yf){

	//char ejes='▓',linea='#',fondo[]="\033[1;37m.\033[1;32m";

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

	if(yi>yf){
	 vertical = 0; //bajar
	 printf("bajar!!!!!!!!\n");
	}else{
	 vertical = 1; //subir
	 printf("subir!!!!!!!!\n");
	}


	dx = x1-x0;
	dy = yf-yi;
	adx = abs(dx);
	ady= abs(dy);

	y = yi;
	x = x0;
	A= 2*dy;
	//B = A-(2*dx);
	//e = A-dx;

	printf("x0=%d yi=%d x1=%d  yf=%d dx=%d  dy=%d    A=%d",x0,yi,x1,yf,dx,dy,A) ;

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
	for (int py=yi;py<=yf;py++){
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
	for (int py=yi;py>=yf;py--){
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
	for (int py=yi;py>=yf;py--){
	 
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
	for (int py=yi;py<=yf;py++){
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
	for (int y=yi;y>=yf;y--){
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
	for (int y=yi;y<=yf;y++){
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

}


float xr(int radio,int an){
	//printf("----------------------------\n");
	float ran= an/57.3;
	// printf("ran = %f\n",ran );
	// printf("radio = %d\n", radio);
	// printf("cos(ran)= %.2f\n",cos(ran));
	// printf("operacion === %.2f\n",radio*(cos(ran)) );
	return radio*(cos(ran));

}
float yr(int radio,int an){
	//printf("----------------------------\n");
	float ran= an/57.3;	
	// printf("ran= %d\n",ran );
	// printf("radio= %d\n", radio);
	// printf("sin(ran)= %.2f\n",sin(ran));
	// printf("operacion===%.2f\n",radio*(sin(ran)) );
	return radio*(sin(ran));

}

int main(){
	int metodintro;

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

	printf("\t1:Graficar serie de puntos\n\t2:Graficar un poligono\n");
	scanf("%d",&metodintro);

	if (metodintro==1){
		while(salida!='x'){

		printf("x0:");
	scanf("%d",&x0);
	printf("yi:");
	scanf("%d",&yi);
	printf("x1:");
	scanf("%d",&x1);
	printf("yf:");
	scanf("%d",&yf);

		puntos(x0,yi,x1,yf);

	 printf("desea colocar un nuevo punto?(s) (ctr+c para salir):");
	 printf("\n"); }
	}

	if (metodintro==2){
		
	int lados,radio,angulo;

	printf("lados:");
	scanf("%d",&lados);
	printf("radio:");
	scanf("%d",&radio);

	angulo = 360/lados;

	printf("poligono de lados%d,radio%d y grados %d\n",lados,radio,angulo );
		
		//puntos(x0,yi,x1,yf);

	float vectorpuntos[lados*2];
	int n=0,an=0;

	for (int i = 0; i < lados; i++){
		
		vectorpuntos[n]=(int)(xr(radio,an));
		n++;
		vectorpuntos[n]=(int)(yr(radio,an)+0.5);
		n++;
		an=an+angulo;

	}


	for (int i = 0; i < lados*2; i++){
		
		printf("vectorpuntos[%d]: %.2f\n",i,vectorpuntos[i] );

	}

	for (int i = 3; i < lados*2; i=i+2){
		
		puntos(vectorpuntos[i-3],vectorpuntos[i-2],vectorpuntos[i-1],vectorpuntos[i]);

	}

	puntos(vectorpuntos[(lados*2)-2],vectorpuntos[(lados*2)-1],vectorpuntos[0],vectorpuntos[1]);


	}

return 0;
}