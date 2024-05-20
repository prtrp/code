
list1 = [1,3,4,5,3,5,7,43,4,5]

def numOdd(lst):
    for i in range(len(lst)):
        if i % 2 != 0:
            lst.pop(i)

numOdd(list1)
print(list1)
