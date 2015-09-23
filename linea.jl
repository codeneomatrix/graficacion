pₒ=(-2,-2)
p₁=(-10,-8)

xₒ=Abs(pₒ[1])
γₒ=Abs(pₒ[2])

x₁=Abs(p₁[1])
γ₁=Abs(p₁[2])



matrix=round(zeros(x₁,x₁))
#print(size(matrix,1))
#print("\033[1J")

δx = x₁-xₒ
δγ = γ₁-γₒ
γ = γₒ



A= 2δγ
B = A-2δx

ϵ = A-δx

print("xₒ=$xₒ γₒ=$γₒ x₁=$x₁  γ₁=$γ₁  δx=$δx  δγ=$δγ    A=$A B=$B  \n     ϵ             (x,γ) \n ϵ=($A-$δx) $ϵ")

for ρx = xₒ:x₁
 #putpixel(ρx,γ );
 print("       ($ρx,$γ)\n")

 	matrix[γ,ρx]=2;

 	if ϵ>0
		γ =γ+1
		print(" ϵ=($ϵ+$B)= ")
		ϵ =ϵ+B
		print("$ϵ ")
	else
		print(" ϵ=($ϵ+$A)=")
 		ϵ = ϵ+A
 		print(" $ϵ ")
	end

  #print("γ=$γ\nϵ=$ϵ")

end
 print("\n")
#print(matrix)

for γ=1:x₁
	for x=1:x₁
		if matrix[γ,x] == 2
			print("#")
		else
			print(".")
		end
	end
	print("\n")
end
