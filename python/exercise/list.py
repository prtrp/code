def trova_posizione(a, v):

    '''
	Input: a una lista, v un valore
	Return: una lista di interi contenente le posizioni di v in a
	'''
    pass
    b = []
    for i in range(len(a)):
        if a[i] == v:
            b.append(i)
    return b 

def trova_posizione_short(a, v):

    b = [i for i in range(len(a)) if a[i] == v]
    print(b)

a = [1, 3, 4, 5, 2, 5, 7, 5, 3, 1, 3, 4]
v = 3


def del_item(a, v):
    b = []

    for x in a:
        if x != v:
            b.append(x)
    a = b[:]

    return None

print(a)

