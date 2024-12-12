a = [('A', 2, 7), ('B', 3, -1), ('C', 0, 1), ('D', -2, -2)]
r = 2.9

b = []

def distanza_da_r():
    for point, x, y in a:
        if x**2+y**2 <= r**2:
            b.append(point)
    print(b)
# contiene tutti i punti che sono distanti al massimo r da (0, 0)

def trova_posizioni(a, v):
    '''
    Input: a una lista, v un valore
    Return: una lista di interi contenente le posizioni di v in a
    '''
    b = []

    for i in range(len(a)):
        if v == a[i]:
            b.append(i)
    return b



a = [2, 5, 1, 5, 2, 3, 6, 2, 4, 7, 8, 5]
print(trova_posizioni(a, 5))


def sottoliena_errata(a):
    '''
    stampa e sottolinea con * le vocali con # le cifre decimali
    '''
    
    b = ""
    for x in a:
        if x in "aeiouAEIOU":
            b += '*'
        elif x >= '0' and x <= '9':
            b += '#'
        else:
            b += ' '
    return b
# questa e sbagliata perche non le stringhe sono immutabili, quindi per ogni b += ... va a creare una nuova stringa.

def sottolinea_corretta(a):
    b = []
    for x in a:
        if x in 'aeiouAEIOU': # O(1)
            b.append( '*' ) # O(1)
        elif x >= '0' and x <= '9': # O(1)'
            b.append( '#' ) # O(1)
        else:
            b.append( ' ' ) # O(1)
          
    print(a)
    print( ''.join(b) )   # O(n)
# in questo modo append() ha costo 0(1), quidni si vanno ad accumulare formando costo O(n)


