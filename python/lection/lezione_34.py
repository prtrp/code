import matplotlib.pyplot as plt


def prima_parte():
    print("programma", 3.14, ['uno', 'due', 3], 6)
    # come scrivere una funzione che accetti un numero di argomenti arbitrario, come *values in printf()

    def concatena(*args):
            return ''.join(args)

    print(concatena('uno', 'due', 'tre', 'quattro'))

    b = ['uno', 'due', 'tre']
    print(' '.join(b))

    print(*b)
p = [(3, 1), (10, -3), (2, 6), (8, -6)]

#plt.plot([0, 3, 9, 4], [1, -3, 2, 10])
#plt.show()


f = open('testo.txt')
for line in f:
    print(line, end='')

f.close()
