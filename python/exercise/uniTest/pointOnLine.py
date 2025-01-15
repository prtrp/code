points = [('A', 2), ('B', -3), ('C', 1), ('R', 0), ('G', 5)]

def t1(e):
    return e[1]

def printPoint(points):
    lx = min(points, key = t1)[1]
    rx = max(points, key = t1)[1]

    for p in range(lx, rx):
        c = '*'
        for lett, num in points:
            if num == p:
                c = lett 
        print(c, end = ' ')
printPoint(points)
