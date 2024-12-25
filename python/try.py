def merge(a, lx, cx, rx):
  i, j = lx, cx
  b = []

  while i < cx and j < rx:
    if a[i] < a[j]:
      b.append(a[i])
      i += 1
    else:
      b.append(a[j])
      j += 1

  while i < cx:
    b.append(a[i])
    i += 1

  while j < rx:
    b.append(a[j])
    j += 1

  i = lx
  for e in b:
    a[i] = e
    i += 1

a = [10, 21, 0, 30, 34, 34, 38, 11, 13, 16, 17, 19, 0, 0, 10, 10]

def merge_sort(a, lx = 0, rx = None):
  if rx == None:
    rx = len(a)

  if lx+1 >= rx:
    return None
  
  cx = (rx + lx)//2

  merge_sort(a,lx, cx)
  merge_sort(a, lx, cx)
  merge(a, lx, cx, rx)

merge_sort(a)
print(a)



def foo():
  a = 23
  b = a

  print(a, b)
  print(id(a), id(b))
  b += 1
  print(a ,b)
  print(id(a), id(b))

foo()
