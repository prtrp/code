x = 25;
g = 1000;

while (g*g - x) > 0.0000001:
    print(g)
    g = (g+x/g)/2
