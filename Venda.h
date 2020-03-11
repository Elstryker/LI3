#ifndef venda_h
#define venda_h

#include <stdio.h>
#include <stdlib.h>

typedef struct AVLC *AVLC;
typedef struct AVLP *AVLP;

typedef AVLC **Venda;

int alturaC(AVLC a);
int max(int a,int b);
AVLC rotateRC(AVLC a);
AVLC rotateLC(AVLC a);
AVLC insertAVLC(AVLC a,char* x);
void printAVLC(AVLC a,char* i);


//------------------------------------------------------------------------------------------------------------//


int alturaP(AVLP a);
int max(int a,int b);
AVLP rotateRp(AVLP a);
AVLP rotateLP(AVLP a);
AVLP insertAVLP(AVLP a,char* x,float price,int quantity,char promo);
void printAVLP(AVLP a,char* i);


//------------------------------------------------------------------------------------------------------------//


Venda initVenda();
char getPromo(AVLP a);
int getQuantity(AVLP a);
float getPrice(AVLP a);
int valvenda(char *prod,float prec,int un,char prom,char *cli,int mes,int super);

#endif venda_h