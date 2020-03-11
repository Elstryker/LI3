#include "Venda.h"

struct AVLC {
    char* key;
    int height;
    struct AVLP *prod;
    struct AVLC *right;
    struct AVLC *left;
};

struct AVLP {
    char* key;
    int height;
    float price;
    int quant;
    char promo;
    struct AVLP *right;
    struct AVLP *left;
};

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

int compareKey(char* s1, char* s2) {
    int i;
    for(i=0;s1[i]!='\0';i++) {
        if(s1[i]!=s2[i]) return s1[i]-s2[i];
    }
    return 0;
}

int alturaC(AVLC a) {
    int i;
    if(a==NULL) {
        i=0;
    }
    else i=a->height;
    return i;
}

AVLC rotateRC(AVLC a) {
    AVLC b=a->left;
    a->left=b->right;
    b->right=a;
    b->height=max(alturaC(b->right),alturaC(b->left)) +1;
    a->height=max(alturaC(a->right),alturaC(a->left)) +1;
    return b;
}

AVLC rotateLC(AVLC a) {
    AVLC b=a->right;
    a->right=b->left;
    b->left=a;
    b->height=max(alturaC(b->right),alturaC(b->left)) +1;
    a->height=max(alturaC(a->right),alturaC(a->left)) +1;
    return b;
}

AVLC insertAVLC(AVLC a,char* x) { 
    if (a == NULL) {
        AVLC new=NULL;
        new=malloc(sizeof(struct AVLC));
        new->key=strdup(x);
        new->prod=NULL;
        new->right=new->left=NULL;
        new->height=1;
        a=new;
        return a; 
    }  
    if(compareKey(a->key,x)>0) a->left = insertAVLC(a->left,x);
    else if(compareKey(a->key,x)<0) a->right = insertAVLC(a->right,x);  
    else return a; 
    a->height=1+max(alturaC(a->left),alturaC(a->right));
    int bal = (alturaC(a->left))-(alturaC(a->right));
    if (bal > 1 && x < a->left->key) 
        return rotateRC(a); 
    if (bal < -1 && x > a->right->key) 
        return rotateLC(a); 
    if (bal > 1 && x > a->left->key) 
    { 
        a->left =  rotateLC(a->left); 
        return rotateRC(a); 
    } 
    if (bal < -1 && x < a->right->key) 
    { 
        a->right = rotateRC(a->right); 
        return rotateLC(a); 
    } 
    return a;
}

void printAVLC (AVLC a,char* i) {
    int j;
    if (a==NULL) return;
    printAVLC(a->right,i+1);
    for(j=0;j<i;j++) printf("  ");
    puts(a->key);
    printAVLC(a->left,i+1);
}

//--------------------------------------------------------------------------------------------------------------------//

int alturaP(AVLP a) {
    int i;
    if(a==NULL) {
        i=0;
    }
    else i=a->height;
    return i;
}

int max(int a,int b) {
    return (a>b?a:b);
}

AVLP rotateRP(AVLP a) {
    AVLP b=a->left;
    a->left=b->right;
    b->right=a;
    b->height=max(alturaP(b->right),alturaP(b->left)) +1;
    a->height=max(alturaP(a->right),alturaP(a->left)) +1;
    return b;
}

AVLP rotateLP(AVLP a) {
    AVLP b=a->right;
    a->right=b->left;
    b->left=a;
    b->height=max(alturaP(b->right),alturaP(b->left)) +1;
    a->height=max(alturaP(a->right),alturaP(a->left)) +1;
    return b;
}

AVLP insertAVLP(AVLP a,char* x,float price,int quantity,char promo) { 
    if (a == NULL) {
        AVLP new=NULL;
        new=malloc(sizeof(struct AVLP));
        new->key=strdup(x);
        new->price=price;
        new->promo=promo;
        new->quant=quantity;
        new->right=new->left=NULL;
        new->height=1;
        a=new;
        return a; 
    }  
    if(compareKey(a->key,x)>0) a->left = insertAVLP(a->left,x,price,quantity,promo);
    else if(compareKey(a->key,x)<0) a->right = insertAVLP(a->right,x,price,quantity,promo);  
    else return a; 
    a->height=1+max(alturaP(a->left),alturaP(a->right));
    int bal = (alturaP(a->left))-(alturaP(a->right));
    if (bal > 1 && x < a->left->key) 
        return rotateRP(a); 
    if (bal < -1 && x > a->right->key) 
        return rotateLP(a); 
    if (bal > 1 && x > a->left->key) 
    { 
        a->left =  rotateLP(a->left); 
        return rotateRP(a); 
    } 
    if (bal < -1 && x < a->right->key) 
    { 
        a->right = rotateRP(a->right); 
        return rotateLP(a); 
    } 
    return a;
}

void printAVLP (AVLP a,char* i) {
    int j;
    if (a==NULL) return;
    printAVLP(a->right,i+1);
    for(j=0;j<i;j++) printf("  ");
    puts(a->key);
    printAVLP(a->left,i+1);
}


//------------------------------------------------------------------------------------------------------------//


Venda initVenda() {
    Venda a;
    a=malloc(3*sizeof(AVLC*));
    a[0]=malloc(12*sizeof(AVLC));
    a[1]=malloc(12*sizeof(AVLC));
    a[2]=malloc(12*sizeof(AVLC));
    for(int i=0;i<3;i++) {
        for(int j=0;j<12;j++) {
            a[i][j]=NULL;
        }
    }
}

float getPrice(AVLP a) {
    return a->price;
}

int getQuantity(AVLP a) {
    return a->quant;
}

char getPromo(AVLP a) {
    return a->promo;
}

