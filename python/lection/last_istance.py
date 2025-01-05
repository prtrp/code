def last_istance(arr, val):
  lx = 0
  rx = len(arr)-1

  while lx <= rx:
    m = (lx + rx) // 2
    if arr[m] > val:
      rx = m-1

    elif val == arr[m] and (m == len(arr)-1 or arr[m+1] > val):
      return m
    
    else:
      lx = m+1

  return -1

arr1 = [1,1,2,2,3,4,4,4,5,6,6,6,6,7]

print(last_istance(arr1, 4))
