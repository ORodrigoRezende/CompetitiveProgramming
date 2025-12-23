while True:
    d , n  = input().split()
    if d == '0' and n == '0':
        break
    r = []
    for i in n :
        if i != d  :
            r.append(i)
    while len(r)>0 and r[0] == '0':
        r.pop(0)
    
    if len(r) == 0:
        print("0")
    else :
        print("".join(r))
    
        