# Print()
usata per mandare in output informazioni
```python
print("hello i am petru")
```
## sintassi
```python
print("value", sep = '', end = "\n", file=file, flush=flush)
```
- `value` e il valore che noi vogliamo andare a stampare
- `sep` stringa che andrà a separare i vari valori
- `end` indica cosa vogliamo che sia alla fine della riga che abbiamo stampato
- `file` indica dove bisogna stampare il messaggio, di default e sys.stdout 
- `flush` indica se il buffer deve essere subito svuotato oppure se aspettare il normale svuotamento del programma (se pieno oppure se finisce il programma)
```python
arr = input("enter a string: ")
with open("file.txt", "w") as f:
  for i in range(len(arr)):
      print(ord(arr[i]), end=" ", file=f, flush=True)
print()
```
# len()
serve per misurare la grandezza di un oggetto.
## sintassi
```python
len(value) #value non puo essere un inter
```
## funzionamento
per farlo va a vedere il metodo `__len__(self)`:
```python
class MyClass:
	def __len__(slef):
		return 42

obj = MyClass()
print(len(obj)) # output = 42
```
and stop, non ha altri parametri opzionali come print, 
# range()
Viene utilizzato per generare una sequenza di numeri. Non crea una lista di numeri in memoria ma li crea al volo. Li crea uno alla volta quando richiesti.
## sintassi
i valori sono `start`, `stop`, `step`, da dove inizia, dove finisce, cosa deve saltare. Questi parametri devono essere interi.
```python
for i in range(0, 10, 2):
	print(i) # va da 0 escluso fino a stop incluso se non ci sono parmetri
```
## parametri negativi
```python
for i in range(10, 0, -1): # se vuoi lo step devi per forza esplicitare lo start:
	print(i)
```
questo significa che se `start` > `stop` allora dobbiamo fare come lo slicing e mettere un numero negativo, se no otterremmo una lista vuota o nulla.
