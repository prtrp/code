arr = [1, 3, 5, 7, 9]
value = 5

def bnrysrc(arr, val):
  # binary search:
  # trovare gli estremi e poi trovare il centro
  # una volta fatto, vedere se il centro == valore, se si ritornare
  # se no, se il centro < valore, allora lx = m+1, altrimenti rx = m-1
  lx = 0
  rx = len(arr)
  while lx <= rx:
    m = (lx + rx) // 2
    if val == arr[m]:
      return m
    elif val > arr[m]:
      lx = m+1
    else:
      rx = m-1
  return -1

arr_base = [1, 2, 3, 4, 4, 5, 6, 7, 12, 14, 16]
value = 7


def bnrystr(arr, fnd_str):
  # trovare il primo e ultimo elemento
  # dividere in due così da trovare il putno medio
  # per farlo classico modo poiche abbiamo le l'inizio e la fine
  first_str = 0
  last_str = len(arr)-1

  while first_str <= last_str:
    mid = (first_str + last_str) // 2

    if fnd_str == arr[mid]:
      return mid
    
    elif fnd_str < arr[mid]:
      last_str = mid-1

    else:
      first_str = mid+1

  return -1

arr_in = ["apple", "banana", "cherry", "date", "elephat", "elfphant"]
str_in = "elfphant"

def bnrysrc2d(arr2d, value):
  # trovare il primo valore e l'ultimo e trovare il valore in mezzo
  # si potrebbe fare che applico un binary search tree prima sui array
  # e poi quando entra in un array lo facciamo cercare in maniera binary
  # search in quel array, così che impiega tempo logaritmico per gi array esterni
  # e tempo logaritmico per gli elementi interni.
  
  lx_2d = 0
  rx_2d = len(arr2d)-1
  
  while lx_2d <= rx_2d:
    cx_2d = (lx_2d + rx_2d)//2
    
    if arr2d[cx_2d][0]<= value <= arr2d[cx_2d][-1]:

      lx_1d = 0
      rx_1d = len(arr2d[cx_2d])-1

      while lx_1d <= rx_1d:
        cx_1d = (lx_1d + rx_1d)//2

        if value == arr2d[cx_2d][cx_1d]:
          return (cx_2d, cx_1d)

        elif arr2d[cx_2d][cx_1d] < value:
          lx_1d = cx_1d +1

        else:
          rx_1d = cx_1d -1

      return None

    elif arr2d[cx_2d][0] > value:
      rx_2d = cx_2d -1
    else:
      lx_2d = cx_2d +1
     
  return None

arr_2d = [[1, 3, 5], [7, 9, 11], [13, 15, 17]]

for i in arr_2d:
  for j in i:
    print("result is: ", bnrysrc2d(arr_2d, j), j)
