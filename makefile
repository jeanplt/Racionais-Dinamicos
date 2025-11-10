# Makefile
     
CFLAGS = -Wall -g # flags de compilacao
CC = gcc

all: racionaisDinamicos.o racionais.o
	$(CC) -o racionaisDinamicos racionaisDinamicos.o racionais.o

racionais.o: racionais.c racionais.h
	$(CC) -c $(CFLAGS) racionais.c

racionaisDinamicos.o: racionaisDinamicos.c racionais.h
	$(CC) -c $(CFLAGS) racionaisDinamicos.c

clean:
	rm -f *.o *~ racionaisDinamicos
