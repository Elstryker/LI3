#ifndef produto_h
#define produto_h

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct AVL {
    char* key;
    int height;
    struct AVL* right;
    struct AVL* left;
} *AVL;

typedef AVL *Produto;

Produto initProduto();
void destroyProduto(Produto p);
void readFiletoProduto(Produto p, FILE* f);
int altura2(AVL a);
int max2(int a,int b);
AVL rotateR2(AVL a);
AVL rotateL2(AVL a);
AVL insertAVL2(AVL a,char* x);
void printAVL2(AVL a, int i);
int inorderAVL(AVL a);
int findProd(AVL a,char* key);

#endif 
