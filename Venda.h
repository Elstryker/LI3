#ifndef venda_h
#define venda_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct AVLC{
    char* key;
    int height;
    struct AVLP *prod;
    struct AVLC *right;
    struct AVLC *left;
} *AVLC;

typedef struct repetidos {
    float price;
    int quant;
    char promo;
} Repetidos;

typedef struct AVLP{
    char* key;
    int height;
    int tam;
    int ocup;
    struct repetidos *array;
    struct AVLP *right;
    struct AVLP *left;
} *AVLP;

typedef AVLC **Venda;

int alturaC(AVLC a);
int max3(int a,int b);
AVLC rotateRC(AVLC a);
AVLC rotateLC(AVLC a);
AVLC insertAVLC(AVLC a,char* x);
void printAVLC(AVLC a,int i);


//------------------------------------------------------------------------------------------------------------//


int alturaP(AVLP a);
AVLP rotateRp(AVLP a);
AVLP rotateLP(AVLP a);
AVLP insertAVLP(AVLP a,char* x,float price,int quantity,char promo);
void printAVLP(AVLP a,int i);


//------------------------------------------------------------------------------------------------------------//


Venda initVenda();
void destroyVenda(Venda v);
char getPromo(AVLP a,int index);
int getQuantity(AVLP a,int index);
float getPrice(AVLP a,int index);
AVLC lookupAVLC(AVLC a, char* key);
AVLP lookupAVLP(AVLP a, char* key);
int percorreAVLP(AVLP a);
int percorreAVLC(AVLC a);
int salesAndProfitP(AVLP a, float *totalN, float *totalP);
int salesAndProfitC(AVLC a, float *totalN, float *totalP, char* key);
int monthlySalesAndProfit(AVLC a, float *totalN, float *totalP);


#endif 