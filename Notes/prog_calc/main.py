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


# terza lezioone--------------------------------------------------------
def terza_lezione () :
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
  # &&, || e ! ; and or not

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


# quarta lezione----------------------------------------------------
def soluzione_esercizio() :
  a = "  prgrammazione dei   calcolatori   "
  spaces = 0
  i = 0

  while i < len(a):
    spaces_from_i = 0

    while i+spaces_from_i < len(a) and a[i+spaces_from_i] == " ":
      spaces_from_i += 1

    spaces += spaces_from_i
    i += spaces_from_i + 1
  print(spaces) 


def lezione_if() :
  a = 'programmazione dei calcolatori'
  vocali = 0
  i = 0

  while i < len(a) :
    if a[i] in 'aeiou' :
      vocali += 1
    i += 1

  print(vocali)


def for_ciclo() :
  a = 'programmazione dei calcolatori'
  vocali = 0 

  for x in a:
    if x in "aeiou" :
      vocali += 1
    print(vocali)


# stampa a e sottolinea con * le vocali e con # le cifre decimali
def exe_4_1 ():
  a = "programmazion3 de1 calcolatori"
  b = ""

  for x in a:

    if x in "aeiouAEIOU" : # non e una operazione scalare, assegnazione, confronto, bool, aritmetico, 
      b += '*'

    elif x >= '0' and x <= '9': # per l'ordinamento lessico grafico
      b += '#'

    else:
      b += ' '

  print(a)
  print(b)


def ordinamento() :
  print(ord('a'), ord('b'))
  print(ord('A'), ord('B'))
  print(ord('0'), ord('1'))
  # sono una l'una l' inversa dell' altra. trasformare un carattere in lettera o viceversa

  print( chr(100) )
  


# quinta lezione----------------------------------------------------
# da maiuscolo a minuscolo
def maius_minusc():
  c = 'A'
  if c >= 'A' and c <= 'Z':
    delta = ord(c) - ord('A')
    c_min = chr(ord('a') + delta) # la lettera minuscola
    print(c_min)
  

#funzioni
x = 20 
def sqrt(x):
  g, c = x/2, 0  # variabili locali non visibili all' esterno 
  eps, c_max = 0.000001, 1000

  while abs(g*g - x) > eps and c < c_max:
    c = c + 1
    g = ( g + x/g )/2

  return g 

def sqrt(x, eps = 0.00001, c_max = 1000):  # valori di default
  g, c = x/2, 0  # variabili locali non visibili all' esterno 

  while abs(g*g - x) > eps and c < c_max:
    c = c + 1
    g = ( g + x/g )/2

  return g 


#ris = sqrt(20, c_max = 100, eps = 0.000001) # se non ce return il valore sara None; no ignorare valore
# #posizionale  #---------nominale---------#
#print(ris)
#print(sqrt(20, 0.1)) # misto tra default e impostato
#print(sqrt(20, c_max = 2) ) # mettere parametri 


#priblema parola palindroma------------------------
a = "123456789"

def plaindromo( a ):
  n = len(a)
  i = 0 
  while i < n/2 and a[i] == a[n-1-i]:
    i += 1
    if a[i] != a[n-1-i]:
      return False # return fa uscire dalla funzione e restituire l'argomento
    else:
      return True
  print(a[1:7])    # slicing sottostringa di a da 1 a 7 pero e una nuova stringa
  print(a[:7])     # da inizio a 7
  print(a[1:])     # da 1 alla fine
  print(a[:])      # tutta la string
  print(a[::-1])  # step dall' ultimo alla fine


def stupid_palidormo( a ):
  return a == a[::-1]


