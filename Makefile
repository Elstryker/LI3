CC = gcc
CFLAGS =-I -Wall
SGV: Cliente.o main.o Produto.o Venda.o SGV.o
	$(CC) -o SGV Cliente.o main.o Produto.o Venda.o SGV.o
clean:
	rm SGV *.o

