def sum(a):
  if a == 0:
    return 0
  else:
    return a + sum(a-1)

print(sum(5))

