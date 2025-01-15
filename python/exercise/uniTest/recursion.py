def sum_rec(num):
    if  num == 0:
        return 0
    else:
        return num + sum_rec(num-1)

def walk(steps):
    if steps == 0:
        return
    else:
        print(f"i walk #{steps}")
        walk(steps-1)
        print(f"i walk #{steps}")

def factorial(num):
    if num == 1:
        return 1
    else:
        return num * factorial(num-1)

def fctprint(word, i = 10):
    if i == 0:
        return 0
    else:
        print(word)
        return fctprint(word, i-1)

fctprint("ciao")


