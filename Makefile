CC = gcc
CFLAGS = -Wall
Venda: Venda.o main.o
Venda.o: Venda.c Venda.h
main.o:  main.c
clean:
	rm Venda *.o

