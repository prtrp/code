def merge(lx, rx):

    i, j = 0, 0
    b = []
    while i < len(lx) and j < len(rx):
        if lx[i] < rx[j]:
            b.append(lx[i])
            i+

        else:
            b.append(rx[j])
            j+=1

    while i < len(lx):
        b.append(lx[i])
        i+=1

    while j < len(rx):
        b.append(rx[j])
        j+=1

    return b

def merge_sort(arr):
    if len(arr) == 1:
        return arr

    lx = arr[:len(arr)//2]
    rx = arr[len(arr)//2:]

    lx = merge_sort(lx)
    rx = merge_sort(rx)

    return merge(lx, rx)

arr = [11, 2, 3, 4, 12, 4, 32, 3, 5, 3, 5, 7, 8, 12, 67, 23, 45]

print(merge_sort(arr))
