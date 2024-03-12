def sum(a, b):
    return a+b

def diff(a, b):
    return a-b

def mult(a, b):
    return a*b

def div(a,b):
    return a/b


def operator():
    num = int(input("isnert:\n1 for sum \n2 for diff \n3 for mult \n4 for div\n>> "))
    
    if num not in [1, 2, 3, 4]:
        return "invalid number"

    a = float(input("insetr a number: "))
    b = float(input("insert a number: "))

    if num == 1:
        return sum(a, b)
    elif num == 2:
        return diff(a, b)
    elif num == 3:
        return mult(a, b)
    elif num == 4:
        return div(a, b)


result = operator()
print(f"the result is: {result}")

