def ricerca_dx(arr, vall):
  n = len(arr)
  left, right = 0, len(arr)-1

  while left <= right:
    mid = (left+right)//2

    if vall < arr[mid]:
      right = mid-1

    elif vall == arr[mid] and (mid == n-1 or arr[mid+1] > vall):
      return mid
    
    else:
      left = mid+1

  return -1

a = [1, 5, 5, 7, 7, 7, 9, 9, 10, 13, 13, 14, 16, 17, 18, 19]
k = 19

print( ricerca_dx(a, k) )
