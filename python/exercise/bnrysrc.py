arr = [1, 3, 5, 7, 9]
value = 5

def bnrysrc(arr, val):
    lx = 0
    rx = len(arr) -1
    cx = 0

    while lx <= rx:
        cx = (lx + rx) // 2
        if arr[cx] == val:
            return cx
        elif arr[cx] < val:
            lx = cx + 1
        else:
            rx = cx - 1
    return None

arr_base = [1, 2, 3, 4, 4, 5, 6, 7, 12, 14, 16]
value = 16 

#print(bnrysrc(arr_base, value))


def bnrystr(arr, fnd_str):
    lx = 0
    rx = len(arr) -1

    while lx <= rx :
        cx = (lx + rx) // 2
        if arr[cx] == value :
            return value
        elif arr[cx] < value :
            lx = cx +1
        else :
            rx = cx -1

    return None

arr_in = ["apple", "banana", "cherry", "date", "elephant", "elfphant"]
str_in = "elephant"

#print(bnrysrc(arr_in, str_in))

def bnrysrc2d(arr2d, val):
    lx_2d = 0
    rx_2d = len(arr2d) -1

    while lx_2d <= rx_2d:

        cx_2d = (lx_2d + rx_2d) // 2

        lx_1d = 0
        rx_1d = len(arr2d[cx_2d])-1

        if arr2d[cx_2d][0] <= val and arr2d[cx_2d][-1] >= val:

            while lx_1d <= rx_1d:

                cx_1d = (lx_1d + rx_1d) // 2
                if arr2d[cx_2d][cx_1d] == val:
                    return f"cx_2d: {cx_2d}, cx_1d: {cx_1d}"

                elif arr2d[cx_2d][cx_1d] > val:
                    rx_1d = cx_1d -1

                else:
                    lx_1d = cx_1d +1

        if arr2d[cx_2d][0] > val:
            rx_2d = cx_2d -1

        else:
            lx_2d = cx_2d +1

    return None

arr_2d = [[1, 3, 5], [7, 9, 11], [13, 15, 17]]

for i in arr_2d:
  for j in i:
    print("result is: ", bnrysrc2d(arr_2d, j), j)

print(bnrysrc2d(arr_2d, 17))
