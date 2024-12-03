arr = [1, 3, 5, 2, 5, 6, 8, 4]
arr1 = [1,1,1,1,1,2,2,2,2,2,7,7,7,7,7,3,3,3,3,3]
arr2 = [39, 12, 18, 85, 72, 10, 2, 18]

def bubble_sort(arr):
  tmp = 0

  for _ in range(len(arr)-1):
      for i in range(len(arr)-1):
        if arr[i] > arr[i+1]:

          tmp = arr[i]
          arr[i] = arr[i+1]
          arr[i+1] = tmp

  return arr

def print_bbls(arr):
  for i in range(len(arr)):
    print(arr[i])


print_bbls(bubble_sort(arr2))
