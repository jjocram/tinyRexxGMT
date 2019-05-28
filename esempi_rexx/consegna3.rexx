pull a
pull b

if /(a == 0) || /(b == 0) then
do
    if a < 0 then
    do
        a = -a;
    end
    if b < 0 then
    do
        b = -b;
    end

    r = a % b;
    old_r = 0;
    do while /(r == 0)
        a = b;
        old_r = r;
        r = a % b;
    end
    r = old_r;
    say r
    say -r
end