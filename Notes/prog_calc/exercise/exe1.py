def space_in() :
  a = "io sono una stringa e ho degli sapzi  "
  count = 0
  num_space = 0

  print(len(a))
  while count < len(a):

    while count < len(a) and a[count] != " " :
      count += 1

    while count < len(a) and a[count] == " " :
      num_space += 1
      count += 1

  print(num_space)

space_in()
