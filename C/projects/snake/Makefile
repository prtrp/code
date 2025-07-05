SRC = src/snake.c
OUT = bin/snake
CC = gcc
FLAGS = -Wall -Wextra -pedantic -std=gnu11 -D_POSIX_C_SOURCE=199309L

all:
	@mkdir -p bin
	@$(CC) $(FLAGS) $(SRC) -o $(OUT)

exec:
	@./bin/snake
