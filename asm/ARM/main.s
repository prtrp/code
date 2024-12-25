  .section .data
msg:
  .asciz "Hello, World!\n"

  .section .text
  .global _start

_start:
  /* Syscall per scrivere (write) */
  MOV r7, #4              /* Numero della syscall: 4 è write in ARM Linux */
  MOV r0, #1              /* Primo argomento: file descriptor 1 (stdout) */
  LDR r1, =msg            /* Secondo argomento: puntatore al messaggio */
  MOV r2, #14             /* Terzo argomento: lunghezza del messaggio */
  SWI 0                   /* Invoca la syscall */

  /* Syscall per terminare il programma (exit) */
  MOV r7, #1              /* Numero della syscall: 1 è exit */
  MOV r0, #0              /* Argomento: codice di uscita 0 (successo) */
  SWI 0                   /* Invoca la syscall */

