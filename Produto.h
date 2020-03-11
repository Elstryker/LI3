#ifndef produto_h
#define produto_h

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct AVL *AVL;
typedef AVL *Produto;

Produto initProduto();
void destroyProduto(Produto p);
void readFiletoProduto(Produto p, FILE* f);
int compareKey(char* s1, char* s2);
int altura(AVL a);
int max(int a,int b);
AVL rotateR(AVL a);
AVL rotateL(AVL a);
AVL insertAVL(AVL a,char* x);
void printAVL(AVL a, int i);

#endif 
