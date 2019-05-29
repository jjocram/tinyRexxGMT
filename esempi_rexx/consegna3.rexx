pull a
pull b

if \(a == 0) | \(b == 0) then
do
    if a < 0 then
    do
        a = -a
    end
    if b < 0 then
    do
        b = -b
    end

    r = a % b
    do while \(r == 0)
        a = b
        r = a % b
	b = r
    end
    say b 
end
