#include "interface.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct AVL {
    int valor;
    int bal;
    struct AVL* dir;
    struct AVL* esq;
};

struct SGV {
    int **produtos;
    int **clientes;
    int **filiais;
};

AVL insertAVL(AVL a, int x) { 
    if (a == NULL) {
        AVL new=NULL;
        new=malloc(sizeof(struct AVL));
        new->valor=x;
        new->dir=new->esq=NULL;
        a=new;
        return a; 
    }  
    if (x < a->valor) 
        a->esq  = insertAVL(a->esq, x); 
    else if (x > a->valor) 
        a->dir = insertAVL(a->dir, x);    
    return a; 
}

void printAVL (AVL a, int i) {
    int j;
    if (a==NULL) return;
    printAVL(a->dir,i+1);
    for(j=0;j<i;j++) printf(" ");
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
