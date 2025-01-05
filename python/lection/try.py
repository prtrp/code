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

a = [2, 3, 12, 32, 12, 54, 34]
def merge_sort(b, lx=0, rx = None):
  if rx == None:
    rx = len(b)

  if lx+1 >= rx:
    return None

  cx = (lx + rx)//2

  merge_sort(a, lx, cx)
  merge_sort(a, cx, rx)
  merge(b, lx, cx, rx)

print(a)
merge_sort(a)
print(a)
