def del_item(a, v):
  '''
  input: una stringa V con un valore
  Return: None

  elimina da a tutte le occorenze di v
  '''

  i = 0
  while i < len(a):
    if a[i] == v:
      del(a[i])
  else:
    i += 1

  a = [1, 2, 3, 4, 5, 6, 1, 5, 6, 2, 1, 2]

  del_item(a, 1)
  print(a)
# inefficace perche ha costo O(n^2) a causa del del(a[i]) che nei peggiori dei casi e quadratico.

def del_liner_item(a, v):

  b = []
  for i in range(len(a)):
    if a[i] != v:
      b.append(a[i])

  i = 0
  while i < len(b):
    a[i] = a[b]
  i += 1

  while i < len(a):
    del(a[-1]) # non del(a[i]) perche se no richiederebbe tempo quadratico dato che dovrabbe
    # spostare tutti gli elementi a sinistra epoi da li rieliminare

