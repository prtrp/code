arr = input("enter a string: ")
with open("file.txt", "w") as f:
  for i in range(len(arr)):
      print(ord(arr[i]), end=" ", file=file, flush=True)
print()

