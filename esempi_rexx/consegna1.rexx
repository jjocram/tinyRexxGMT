pull a
pull b
pull c

if a+b == c | a-b == 2*c then 
do
	do i = 1 to 10 
		say i
	end
end
else do
	do j = 11 to 20
		say j
	end
end


if (\a & \(b == c)) & a == c  then
do
	do while a > b 
		say a
		a = a-1
	end		
	do while b < c 
		say b*b
		b = b+2
	end		
end 

do i = 0 to a
	do while i<10
		if i < 5 then 
		do
			say i
		end
		else do
			say i*a
		end
	end
	pull d
	if d % 0 then
	do 
		say 1
	end
end 		
