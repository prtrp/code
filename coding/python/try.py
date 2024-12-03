arr = [2, 4, 5, 1, 3, 5, 2, 7, 8, 9, 32, 1023]

def bubble_sort(arr):
  tmp = 0

  for _ in range(len(arr)-1):
    for i in range(len(arr)-1):
      if arr[i] > arr[i+1]:
        
        tmp = arr[i]
        arr[i] = arr[i+1]
        arr[i+1] = tmp
  return arr

def printbbls(arr):
  for i in arr:
    print(i)
  print("\n")

printbbls(bubble_sort(arr))
