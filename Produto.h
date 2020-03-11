#ifndef produto_h
#define produto_h

typedef struct AVL *AVL;

int altura(AVL a);
int max(int a,int b);
AVL rotateR(AVL a);
AVL rotateL(AVL a);
AVL insertAVL(AVL a,char* x);
void printAVL(AVL a, int i);

#endif produto_h