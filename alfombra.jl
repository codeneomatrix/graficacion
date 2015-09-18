#=
  program:1
  Name: alfombra de sierpinski.cpp
  Author: josue acevedo maldonado, maldad, Luis E. Ramos Cruz
  Date: 27/08/15 
  Description:
=#


I=0
F=27
cn=1
puntos=[]
push!(puntos,I)
push!(puntos,F)

function dividir(pi, pf)
	if pi<pf
		t= (pf-pi)/3
		pc1= pi+t
		pc2= pc1+t
				#=print ("\033[%d;%dH",cn,40)
				print("pc1: %d\n",pc1 );=#
		push!(puntos,pc1)
				#=print ("\033[%d;%dH",cn,40)
				print("pc2: %d\n",pc2 );=#
		push!(puntos,pc2)	
	end
end


function pintar(al,pi,pf,le)

print("\033[0;0H")
print("\033[$(al+1);0H")
	for i=pi:(pf-1)
		print("\033[$(pi+1)C")
		for j = pi:(pf-1)
    		print(le)
    	end
    	print("\n")
    end

end



    x="\033[1;37m.\033[1;32m"
    O="▓" # ▆ ▇ ▉ ⬣ ◼ ▉ 

    print("Alfombra de Sierpinski \n")

    print("ingrese el nivel (minimo 1, maximo 3):\n")
 
    print("\033[1J"); #BORRA LA TERMINAL
    #print ("\033[47m"); #color de fondo blanco
    print("\033[1;32m"); 
    pintar(I,I,F,x)


for k=1:3
	ni=length(puntos)
	for i =1:length(puntos)
    	#=print ("\033[%d;%dH",cn,60)
    	    	print("%d .- primer punto %d\n",cn,puntos[i])
    	    	print ("\033[%d;%dH",cn,80)
    	    	print("segundo punto %d\n", puntos[i+1]);=#
    	dividir(puntos[i],puntos[i+1])
    end

	
	ni+=1

	for i = ni:2:length(puntos), j = ni:2:length(puntos)
		pintar(puntos[i],puntos[j],puntos[j+1],O)
	end
	
	sort(puntos)
end
	
	print("\033[1;37m")
    print("\033[$(F+2);1H")

 
   
