x0=1
y0=1

x1=15
y1=9



matrix=zeros(y1,x1)
#print(size(matrix,1))
#print("\033[1J")

dx = x1-x0 
dy = y1-y0 
x = x0 
y = y0  

ix = 2dx 
iy = 2dy

e = iy-dx 

#print("dx=$dx\ndy=$dy\nx=$x\ny=$y\nix=$ix\niy=$iy\ne=$e\n")

for  px = x0:x1 
 #putpixel(px,y );
 print("\npy=$y")
 if y<=size(matrix,1)
 	matrix[y,px]=2;
 else
 	y=y-1
 	matrix[y,px]=2;
 end
 
 e = e+iy 
 print("e=$e\nsy=$y")
	if e>0 
		y =y+1 
		e =e-ix 
	end 
  #print("y=$y\ne=$e")
 
end 
#print(matrix)

for y=y0:y1
	for x=x0:x1
		if matrix[y,x] == 2
			print("#")
		else 
			print(".")
		end
	end
	print("\n")
end