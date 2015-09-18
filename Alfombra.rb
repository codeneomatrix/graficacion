class Alfombra

	base = "&&&\n& &\n&&&"
	p = "&&&"
	s = "& &"
	t = "&&&"
	e = " "
	##NIVEL 0
	puts "&&&\n&&&\n&&&"
	puts
	##NIVEL 1
	puts base
	puts
	
	##NIVEL 2
		for j in 1..3
			if j == 2 then
				puts p+(e*3)+p, s+(e*3)+s, t+(e*3)+t
				next
			end
			puts p*3, s*3, t*3
		end
		puts

	##NIVEL 3
		for j in 1..9
			if j == 5 then
				puts (p+(e*3)+p)+(e*9)+(p)+(e*3)+(p), (s+(e*3)+s)+(e*9)+(s+(e*3)+s), (t+(e*3)+t)+(e*9)+(t+(e*3)+t)
				next
			end
			if j == 2 || j == 8 then
				puts (p+(e*3)+p)*3, (s+(e*3)+s)*3, (t+(e*3)+t)*3
				next
			end
			puts p*9, s*9, t*9
		end
		puts
	
	#for j in 1..27
	#	if j == 14 then
	#		puts (p*9)+(e*27)+(p*9), (s*9)+(e*27)+(s*9), (t*9)+(e*27)+(t*9)
	#		next
	#	end
	#	puts p*27, s*27, t*27
	#end
end