arr = [1, 4, 2, 6, 5, 12, 65, 12, 67, 12, 65, 3, 7, 23]

def bubbleSort(arr):
  n = len(arr)
  for i in range(n-1):
    is_sort = True
    for j in range(n-1-i):
      if arr[j+1] < arr[j]:
        arr[j+1], arr[j] = arr[j], arr[j+1]
        is_sort = False

    if is_sort:
      return 0

print(arr)
bubbleSort(arr)
print(arr)
        


