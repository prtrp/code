section .data ; is where are defined statical variables
  text db "hello, world", 0xA ; db -> define bytes, 0xA or 10 means \n. text name asigned to 
section .text
  global _start

_start:
  mov rax, 1
  mov rdi, 1
  mov rsi, text
  mov rdx, 14
  syscall

  mov rax, 60
  mov rdi, 0
  syscall
