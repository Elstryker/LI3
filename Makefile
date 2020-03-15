CC = gcc
CFLAGS =-I -g -Wall
SGV: Cliente.o main.o Produto.o Venda.o SGV.o
	$(CC) -g -o SGV Cliente.o main.o Produto.o Venda.o SGV.o
clean:
	rm SGV *.o

