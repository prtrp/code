def func() :
  a = "io sono una StrInga e hO delle vocAli"
  count, num_vocali = 0, 0
  size = len(a)

  while count < size :

    while count < size and a[count] in "aeiou" :
      num_vocali += 1
      print(a[count], count, num_vocali)
      count += 1

    while count < size and a[count] not in "aeiou" : 
      count += 1

  print(num_vocali)

func()
