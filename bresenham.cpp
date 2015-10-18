#include <math.h>
#include <stdlib.h>

int* bresen(int x0,int yi,int x1,int yf){
	int dx,dy,y,x,A,B,e,horizontal,lineavertical,vertical,adx,ady;

	if(x0==x1){
		lineavertical=1;
	}
	if(x0>x1){
	 horizontal=0; //izquierda
	 //printf("izquierda!!!!!!!!\n");
	}else{
	 horizontal= 1; //derecha
	 //printf("derecha!!!!!!!!\n");
	}

	if(yi>yf){
	 vertical = 0; //bajar
	 //printf("bajar!!!!!!!!\n");
	}else{
	 vertical = 1; //subir
	 //printf("subir!!!!!!!!\n");
	}


	dx = x1-x0;
	dy = yf-yi;
	adx = abs(dx);
	ady= abs(dy);

	y = yi;
	x = x0;
	A= 2*dy;

	//printf("x0=%d yi=%d x1=%d  yf=%d dx=%d  dy=%d    A=%d",x0,yi,x1,yf,dx,dy,A) ;

	if (adx>=ady){

		if(horizontal==0 && vertical==1){
			dx=dx*-1;
			B = A-(2*dx);
			e = A-dx;
			//printf("B=%d  \n     %d             (x,y) \n",B,e);
			//printf("e=(%d-%d) %d",A,dx,e);
			int datos[((x0-x1)*2)];
			int contador=0;

			for (int px=x0;px>=x1;px--){
			 //printf("       (%d,%d)\n",px,y);

			 datos[contador++]=px;
			 datos[contador++]=y;

			 	if(e>0){
			 			y++;
			 			//printf(" e=(%d+%d)= ",e,B);
			 			e =e+B;
			 			//printf("%d ",e);
			 		}
				else{
						
						//printf(" e=(%d+%d)=",e,A);
				 		e = e+A;
				 		//printf(" %d ",e);
				 	}
			}
			 //printf("\n");
			 return datos;
		}
		else if(horizontal==0 && vertical==0){
			B = A-(2*dx);
			e = A-dx;
			//printf("B=%d  \n     %d             (x,y) \n",B,e);
			//printf("e=(%d-%d) %d",A,dx,e);
			int datos[(x0-x1)*2];
			int contador=0;
			for (int px=x0;px >= x1;px--){
			 
			 //printf("       (%d,%d)\n",px,y);
				datos[contador++]=px;
				datos[contador++]=y;
			 	if(e<0){
			 			y--;
			 			//printf(" e=(%d+%d)= ",e,B);
			 			e =e+B;
			 			//printf("%d ",e);
			 		}
				else{	
						//printf(" e=(%d+%d)=",e,A);
				 		e = e+A;
				 		//printf(" %d ",e);
				 	}
			}
			 //printf("\n");
			 return datos;
		}
		else if(horizontal==1 && vertical==0 && lineavertical!=1){
			dx=dx*-1;
			B = A-(2*dx);
			e = A-dx;
			//printf("B=%d  \n     %d             (x,y) \n",B,e);
			//printf("e=(%d-%d) %d",A,dx,e);
			int datos[(x1-x0)*2];
			int contador=0;
			for (int px=x0;px<=x1;px++){
			 
			 //printf("       (%d,%d)\n",px,y);
			 datos[contador++]=px;
			 datos[contador++]=y;

			 	if(e<0){

			 			y--;
			 			//printf(" e=(%d+%d)= ",e,B);
			 			e =e+B;
			 			//printf("%d ",e);
			 		}
				else{
						
						//printf(" e=(%d+%d)=",e,A);
				 		e = e+A;
				 		//printf(" %d ",e);
				 	}

			}
			 //printf("\n");
			 return datos;
		}

		else if(horizontal==1 && vertical==1 && lineavertical!=1){
			B = A-(2*dx);
			e = A-dx;
			//printf("B=%d  \n     %d             (x,y) \n",B,e);
			//printf("e=(%d-%d) %d",A,dx,e);
			int datos[(x1-x0)*2];
			int contador=0;
			for (int px=x0;px<=x1;px++){
			 //printf("       (%d,%d)\n",px,y);
			 datos[contador++]=px;
			 datos[contador++]=y;

			 	if(e>0){
			 			y++;
			 			//printf(" e=(%d+%d)= ",e,B);
			 			e =e+B;
			 			//printf("%d ",e);
			 		}
				else{
						//printf(" e=(%d+%d)=",e,A);
				 		e = e+A;
				 		//printf(" %d ",e);
				 	}
			}
			 //printf("\n");
			 return datos;

		}

	}else{

		if(horizontal==0 && vertical==1){
			A= 2*dx;
			dy=dy*-1;
			B = A-(2*dy);
			e = A-dy;
			//printf("B=%d  \n     %d             (x,y) \n",B,e);
			//printf("e=(%d-%d) %d",A,dx,e);
			
			int datos[(yf-yi)*2];
			int contador=0;

			for (int py=yi;py<=yf;py++){
			 //printf("       (%d,%d)\n",x,py);
			 datos[contador++]=x;
			 datos[contador++]=py;

			 	if(e<0){
			 			x--;
			 			//printf(" e=(%d+%d)= ",e,B);
			 			e =e+B;
			 			//printf("%d ",e);
			 		}
				else{
						
						//printf(" e=(%d+%d)=",e,A);
				 		e = e+A;
				 		//printf(" %d ",e);
				 	}
			}
			 //printf("\n");
			 return datos;

		}
		else if(horizontal==0 && vertical==0){
			A= 2*dx;
			B = A-(2*dy);
			e = A-dy;
			//printf("B=%d  \n     %d             (x,y) \n",B,e);
			//printf("e=(%d-%d) %d",A,dy,e);
			int datos[(yi-yf)*2];
			int contador=0;
			for (int py=yi;py>=yf;py--){
			 //printf("       (%d,%d)\n",x,py);
			 datos[contador++]=x;
			 datos[contador++]=py;

			 	if(e<0){
			 			x--;
			 			//printf(" e=(%d+%d)= ",e,B);
			 			e =e+B;
			 			//printf("%d ",e);
			 		}
				else{
						
						//printf(" e=(%d+%d)=",e,A);
				 		e = e+A;
				 		//printf(" %d ",e);
				 	}

			}
			 //printf("\n");
			 return datos;
		}
		else if(horizontal==1 && vertical==0 && lineavertical!=1){
			A= 2*dx;
			dy=dy*-1;
			B = A-(2*dy);
			e = A-dy;
			//printf("B=%d  \n     %d             (x,y) \n",B,e);
			//printf("e=(%d-%d) %d",A,dx,e);
			int datos[(yi-yf)*2];
			int contador=0;
			for (int py=yi;py>=yf;py--){
			 //printf("       (%d,%d)\n",x,py);
			 datos[contador++]=x;
			 datos[contador++]=py;

			 	if(e>0){
			 			x++;
			 			//printf(" e=(%d+%d)= ",e,B);
			 			e =e+B;
			 			//printf("%d ",e);
			 		}
				else{
						//printf(" e=(%d+%d)=",e,A);
				 		e = e+A;
				 		//printf(" %d ",e);
				 	}
			}
			 //printf("\n");
			 return datos;
		}
		else if(horizontal==1 && vertical==1 && lineavertical!=1){
			A= 2*dx;
			B = A-(2*dy);
			e = A-dy;
			//printf("B=%d  \n     %d             (x,y) \n",B,e);
			//printf("e=(%d-%d) %d",A,dy,e);
			int datos[(yf-yi)*2];
			int contador=0;
			for (int py=yi;py<=yf;py++){
			 //printf("       (%d,%d)\n",x,py);
			 datos[contador++]=x;
			 datos[contador++]=py;


			 	if(e>0){
			 			x++;
			 			//printf(" e=(%d+%d)= ",e,B);
			 			e =e+B;
			 			//printf("%d ",e);
			 		}
				else{
						//printf(" e=(%d+%d)=",e,A);
				 		e = e+A;
				 		//printf(" %d ",e);
				 	}
			}
			 //printf("\n");
			 return datos;
		}
	}
	if(horizontal==1 && vertical==0 && lineavertical==1){
		dx=dx*-1;
		B = A-(2*dx);
		e = A-dx;
		//printf("B=%d  \n     %d             (x,y) \n",B,e);
		//printf("e=(%d-%d) %d",A,dx,e);
		int datos[(yi-yf)*2];
		int contador=0;
		int px=x0;
		for (int y=yi;y>=yf;y--){
			 //printf("       (%d,%d)\n",px,y);
			 datos[contador++]=px;
			 datos[contador++]=y;
		}
		 //printf("\n");
		 return datos;
	}

	else if(horizontal==1 && vertical==1 && lineavertical==1){
		B = A-(2*dx);
		e = A-dx;
		//printf("B=%d  \n     %d             (x,y) \n",B,e);
		//printf("e=(%d-%d) %d",A,dx,e);
		int datos[(yf-yi)*2];
		int contador=0;
		int px=x0;
		for (int y=yi;y<=yf;y++){
			 //printf("       (%d,%d)\n",px,y);
			 datos[contador++]=px;
			 datos[contador++]=y;
		}
		 //printf("\n");
		 return datos;
	}
}

float xr(int radio,int an){
	float ran= an/57.3;
	return radio*(cos(ran));
}

float yr(int radio,int an){
	float ran= an/57.3;	
	return radio*(sin(ran));
}

/*
int main(){
	int metodintro;
	printf("\n PROGRAMA ESCRITO POR ACEVEDO!!!!!!!!!!!!!!!!ja\n");
	int lados,radio,angulo;
	//printf("lados:");
	scanf("%d",&lados);
	//printf("radio:");
	scanf("%d",&radio);
	angulo = 360/lados;
	//printf("poligono de lados%d,radio%d y grados %d\n",lados,radio,angulo );
		//bresen(x0,yi,x1,yf);
	float vectorpuntos[lados*2];
	int n=0,an=0;
	for (int i = 0; i < lados; i++){	
		vectorpuntos[n]=(int)(xr(radio,an));
		n++;
		vectorpuntos[n]=(int)(yr(radio,an)+0.5);
		n++;
		an=an+angulo;
	}

	for (int i = 3; i < lados*2; i=i+2){	
		int* s = bresen(vectorpuntos[i-3],vectorpuntos[i-2],vectorpuntos[i-1],vectorpuntos[i]);
		printf("#############s[0]: %d\n", s[0]);
	}

	int* sa = bresen(vectorpuntos[(lados*2)-2],vectorpuntos[(lados*2)-1],vectorpuntos[0],vectorpuntos[1]);
	printf("##################sa[0]:[ ");
	
	for (int i = 0; i <32; i++){
		printf("%d ", sa[i]);
	}
	// tienes puntos iniciales modificalas primero a estos (traslada y escala) despues los graficas!!!!!!
return 0;
}
*/