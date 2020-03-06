CC = gcc
CFLAGS = -Wall
SGV: Venda.o main.o Cliente.o Produto.o
Cliente.o: Cliente.c Cliente.h
Produto.o: Produto.c Produto.h
Venda.o: Venda.c Venda.h
main.o:  main.c interface.h
clean:
	rm SGV *.o

