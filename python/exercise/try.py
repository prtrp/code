arr_2d = [[1, 3, 5], [7, 9, 11], [13, 15, 17]]

def bnry2d(arr2d, value):
    lx_2d = 0
    rx_2d = len(arr2d)

    while lx_2d <= rx_2d:
        cx_2d = (lx_2d+rx_2d)//2

        lx_1d = 0;
        rx_1d = len(arr2d[cx_2d])

        if arr2d[cx_2d][0] <= value <= arr2d[cx_2d][-1]:
            while lx_1d <= rx_1d:
                cx_1d = (lx_1d + rx_1d)//2

                if value == arr2d[cx_2d][cx_1d]:
                    return f"the value {value} in position [{cx_2d}][{cx_1d}]\n"
                elif value <= arr2d[cx_2d][cx_1d]:
                    rx_1d = cx_1d -1

                else:
                    lx_1d = cx_1d +1

        elif  value < arr2d[cx_2d][0]:
            rx_2d = cx_2d -1

        else:
            lx_2d = cx_2d +1

    return None

for i in arr_2d:
    for j in i: 
        print(bnry2d(arr_2d, j))

    
