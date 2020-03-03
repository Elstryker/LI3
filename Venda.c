#include "interface.h"

struct AVL {
    int valor;
    int alt;
    struct AVL* dir;
    struct AVL* esq;
};

struct SGV {
    int **produtos;
    int **clientes;
    int **filiais;
};

int altura(AVL a) {
    int i;
    if(a==NULL) {
        i=0;
    }
    else i=a->alt;
    return i;
}

int max(int a,int b) {
    return (a>b?a:b);
}

AVL rotateR(AVL a) {
    AVL b=a->esq;
    a->esq=b->dir;
    b->dir=a;
    b->alt=max(altura(b->dir),altura(b->esq)) +1;
    a->alt=max(altura(a->dir),altura(a->esq)) +1;
    return b;
}

AVL rotateL(AVL a) {
    AVL b=a->dir;
    a->dir=b->esq;
    b->esq=a;
    b->alt=max(altura(b->dir),altura(b->esq)) +1;
    a->alt=max(altura(a->dir),altura(a->esq)) +1;
    return b;
}

AVL insertAVL(AVL a, int x) { 
    if (a == NULL) {
        AVL new=NULL;
        new=malloc(sizeof(struct AVL));
        new->valor=x;
        new->dir=new->esq=NULL;
        new->alt=1;
        a=new;
        return a; 
    }  
    if (x < a->valor) 
        a->esq  = insertAVL(a->esq, x); 
    else if (x > a->valor) 
        a->dir = insertAVL(a->dir, x);    
    else return a; 
    a->alt=1+max(altura(a->esq),altura(a->dir));
    int bal = (altura(a->esq))-(altura(a->dir));
    if (bal > 1 && x < a->esq->valor) 
        return rotateR(a); 
    if (bal < -1 && x > a->dir->valor) 
        return rotateL(a); 
    if (bal > 1 && x > a->esq->valor) 
    { 
        a->esq =  rotateL(a->esq); 
        return rotateR(a); 
    } 
    if (bal < -1 && x < a->dir->valor) 
    { 
        a->dir = rotateR(a->dir); 
        return rotateL(a); 
    } 
    return a;
}

void printAVL (AVL a, int i) {
    int j;
    if (a==NULL) return;
    printAVL(a->dir,i+1);
    for(j=0;j<i;j++) printf("  ");
    printf("%d\n",a->valor);
    printAVL(a->esq,i+1);
}

int valvenda(char *prod,float prec,int un,char prom,char *cli,int mes,int super) {
    int i=0;
    if (isupper(prod[0]) && isupper(prod[1]) && isdigit(prod[2]) && isdigit(prod[3]) && isdigit(prod[4]) && isdigit(prod[5]))
    {
        
        if (prec>=0 && un>=0 && (mes>0 && mes<13) && (super>0 && super <4) && (prom=='N' || prom == 'P'))
       
        {
           
            if (isupper(cli[0]) && isdigit(cli[1]) && isdigit(cli[2]) && isdigit(cli[3]) && isdigit(cli[4])) i=1;
                
        }
               
    }
    
    
    return i;
    
}


int findProd(char *prod,char **produtos){
    int i=0;
    for (int j=0;j<171007;j++){
       if(strcmp(prod,produtos[j]) == 0) i=1;
    }
    
    return i;
}
