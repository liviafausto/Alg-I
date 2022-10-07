CC = gcc
objects = main.o sorting.o arrays.o

executa: main
	./main

main: sorting.o arrays.o main.c
	$(CC) -o main sorting.o arrays.o main.c

sorting.o: sorting.c sorting.h
	$(CC) -c sorting.c

arrays.o: arrays.c sorting.h
	$(CC) -c arrays.c

clean:
	rm main $(objects)