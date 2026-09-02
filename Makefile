#Compiler
CC=clang

#Program
all: main

main:
	${CC} -o main main.c

clean:
	rm main
