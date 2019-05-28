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
    oldr = 0
    do while \(r == 0)
        a = b
        oldr = r
        r = a % b
    end
    r = oldr
    say r
    say -r
end
