def prima_lezione ():
  # simbloli associati a un valore
  x = 20 # sono variablili
  g = 5  # sono variablili intere
  count = 0

  #type o il tipo
  # numeri floating point -> con la virgole
  z = 3.14
  #tesi di church

  while abs(g*g - x) > 0.00001:# signofica che ad esempio 1.4343...**2 - 2 > ...
    count += 1                 # quindi mi dice la precisione 
    print(g)                  
    g = 0.5*(g+x/g)

  print(g, count)

#----------------------------------------------------------------------------------------#
def terza_lezione ():
  # macchina di foin noyman. 
  # simblols are +,=,...,whlie,print
  # syntax = rules how combine symbols and instructions
  # semantic = meaning of sumbols, instruction and programs
  
  x = 2 
  g, count = x/2, 0 # assegnamento multimplo
  eps, count_max = 0.0000000000000000001, 1000

  while abs(g*g - x) > eps and count < count_max: 
    count += 1
    g = 0.5*(g+x/g)

  print(g, count)

  # operatore booleano:
  # &&, || e !

  # operatore relazionale:
  # >, < <=, >=, != 

  # operatore di modulo:
  # 7 % 3, return 1

  #stringa
  a = "questa e una stringa" 
  #ordinamento lessico grafico

  # stringa prefisso e contenuta dallla stringa
  print(a)

  b = "python "
  c = a + " " + b
  d = c*2 # ripetizione solo interi, questo caso stringa

  print(d)
  print(a[2])


