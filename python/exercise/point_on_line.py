def t1(e):
    return e[1]

a =  [('A', 6), ('B', -2), ('C', 0), ('D', 5), ('E', 3)]

rx = max(a, key=t1)[1]
lx = min(a, key=t1)[1]

for x in range(lx, rx):
    c = '*'
    for e, v in a:
        if x == v:
            c = e
    print(c, end= '')


