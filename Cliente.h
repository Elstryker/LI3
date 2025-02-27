#ifndef cliente_h
#define cliente_h

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> 

typedef struct AVL *AVL;

typedef AVL *Cliente;

Cliente initCliente();
void destroyCliente(Cliente c);
void readFiletoCliente(Cliente c, FILE* f);
int altura(AVL a);
int max(int a,int b);
AVL rotateR(AVL a);
AVL rotateL(AVL a);
AVL insertAVL(AVL a,char* x);
void printAVL(AVL a, int i);
int findCli(AVL a,char* key);
void cleanBought(AVL a);
int numCliNeverBought(AVL a);
void printAVLasList (AVL a);

#endif 