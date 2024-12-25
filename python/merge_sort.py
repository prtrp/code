a = [1, 3, 5, 4, 6, 5, 12, 45, 34, 21, 26]
b = [1, 2, 6, 6, 9, 19]

# algoritmo di funsione
# ordina 2 sequenze ordinate in un' unica sequenza

def merge(a, lx, cx, rx):
  '''
  input: a una lista di elementi da ordinare
  lx, cx e rx indici in a t.c. lx <= cx <= rx
  con la proprietà che a[lx:cx] e a[cx:rx] sono oridnate
  output: None
  '''
  i, j = lx,cx 
  c = []
  while i < cx and j < rx:
    if a[i] < a[j]:
      c.append(a[i])
      i+=1
    else :
      c.append(a[j])
      j+=1
  while i < cx:
    c.append(a[i])
    i += 1

  while j < rx:
    c.append(a[j])
    j += 1

  i = lx
  for e in c:
    a[i] = e
    i += 1

  # complessità temporale: O(n) = len(a) + len(b)
  # complessitò spaziale: O(1), non ci sono strutture di appoggio 

def merge_sort(a, lx=0, rx=None): #non posso dargli len(a) perchè a non è ancora definita
                                  #lx e rx sono gli estremi della lista che vogliamo ordinare
  '''
  input: a una sequenza di elementi che possono essere confrontate.
  OUtput: None
  Effetto collaterale: ordinare in loco gli elementi di a
  '''
  if rx == None:
    rx = len(a)

  if lx+1 >= rx:
    return 0
  
  cx = (lx+rx)//2 # è il punto di mezzo

  merge_sort(a, lx, cx)
  merge_sort(a, cx, rx)
  merge(a, lx, cx, rx)

  # ordinare a[:n/2], ordinare a[n/2:]
  # fondere

a = [10, 21, 0, 30, 34, 34, 38, 11, 13, 16, 17, 19, 0, 0, 10, 10]
merge(a, 3, 7, 12)
print(a)

merge_sort(a)
print(a)
