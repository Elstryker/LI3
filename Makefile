CC = gcc
CFLAGS =-I -Wall
SGV: Cliente.o main.o Produto.o Venda.o
	$(CC) -o SGV Cliente.o main.o Produto.o Venda.o
clean:
	rm SGV *.o

