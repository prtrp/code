def binary_search(a, val):
  lx = 0
  rx = len(a) -1

  while lx <= rx:
    m = (x + r) // 2

    if val < a[m]:
      lx = m+1
    
    elif val >= a[m]:
      rx = m-1

    else:
      return True

  return False
