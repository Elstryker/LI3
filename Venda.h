#ifndef venda_h
#define venda_h

typedef struct AVLC *AVLC;
typedef struct AVLP *AVLP;

int alturaC(AVLC a);
int max(int a,int b);
AVLC rotateRC(AVLC a);
AVLC rotateLC(AVLC a);
AVLC insertAVLC(AVLC a, int x);
void printAVLC(AVLC a, int i);
int alturaC(AVLC a);
int max(int a,int b);
AVLP rotateRp(AVLP a);
AVLP rotateLP(AVLP a);
AVLP insertAVLP(AVLP a, int x);
void printAVLP(AVLP a, int i);

int valvenda(char *prod,float prec,int un,char prom,char *cli,int mes,int super);

#endif venda_h