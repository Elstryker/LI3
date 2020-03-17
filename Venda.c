#include "Venda.h"


AVLC lookupAVLC(AVLC a, char* key) {
    AVLC r=NULL;
    if(a) {
        int i=strcmp(a->key,key);
        if(i>0) r=lookupAVLC(a->left,key);
        else if(i<0) r=lookupAVLC(a->right,key);
        else r=a;  
    }
    return r;
}

int alturaC(AVLC a) {
    int i;
    if(a==NULL) {
        i=0;
    }
    else i=a->height;
    return i;
}

AVLC rotateRC(AVLC y)
{
    AVLC x = y->left;
    AVLC T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max3(alturaC(y->left), alturaC(y->right))+1;
    x->height = max3(alturaC(x->left), alturaC(x->right))+1;
    return x;
}

AVLC rotateLC(AVLC x)
{
    AVLC y = x->right;
    AVLC T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max3(alturaC(x->left), alturaC(x->right))+1;
    y->height = max3(alturaC(y->left), alturaC(y->right))+1;
    return y;
}

AVLC insertAVLC(AVLC node,char* key)
{
    if (node == NULL){
        AVLC new=NULL;
        new=malloc(sizeof(struct AVLC));
        new->key=strdup(key);
        new->prod=NULL;
        new->right=new->left=NULL;
        new->height=1;
        node=new;
        return node;
    }
    if (strcmp(key,node->key)<0)
        node->left  = insertAVLC(node->left, key);
    else if (strcmp(key,node->key)>0)
        node->right = insertAVLC(node->right, key);
    else
        return node;
    node->height = 1 + max3(alturaC(node->left),
                           alturaC(node->right));
    int balance = (alturaC(node->left))-(alturaC(node->right));
    if (balance > 1 && strcmp(key,node->left->key)<0)
        return rotateRC(node);
    if (balance < -1 && strcmp(key,node->right->key)>0)
        return rotateLC(node);
    if (balance > 1 && strcmp(key,node->left->key)>0)
    {
        node->left = rotateLC(node->left);
        return rotateRC(node);
    }
    if (balance < -1 && strcmp(key,node->right->key)<0)
    {
        node->right = rotateRC(node->right);
        return rotateLC(node);
    }
    return node;
}

void printAVLC (AVLC a, int i) {
    int j;
    if (a==NULL) return;
    printAVLC(a->right,i+1);
    for(j=0;j<i;j++) printf("    ");
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

int max3(int a,int b) {
    return (a>b?a:b);
}

AVLP rotateRP(AVLP y)
{
    AVLP x = y->left;
    AVLP T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max3(alturaP(y->left), alturaP(y->right))+1;
    x->height = max3(alturaP(x->left), alturaP(x->right))+1;
    return x;
}

AVLP rotateLP(AVLP x)
{
    AVLP y = x->right;
    AVLP T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max3(alturaP(x->left), alturaP(x->right))+1;
    y->height = max3(alturaP(y->left), alturaP(y->right))+1;
    return y;
}

AVLP insertAVLP(AVLP node, char* key, float price, int quantity, char promo){
    if (node == NULL){
        AVLP new=NULL;
        new=malloc(sizeof(struct AVLP));
        new->array=malloc(sizeof(struct repetidos));
        new->key=strdup(key); 
        new->right=new->left=NULL;
        new->height=1;
        new->tam = 1;
        new->ocup = 1; 
        (new->array)[0].price = price;
        (new->array)[0].quant= quantity;
        (new->array)[0].promo = promo;  
        node=new; 
        return node;
    }
    if (strcmp(key,node->key)<0)
        node->left  = insertAVLP(node->left, key, price, quantity, promo);
    else if (strcmp(key,node->key)>0)
        node->right = insertAVLP(node->right, key, price, quantity, promo);
    else {
        if(node->ocup == node->tam) {
        node->tam=2*node->tam;
        node->array=realloc(node->array,(node->tam)*sizeof(struct repetidos));
        }
        (node->array)[node->ocup].price=price;
        (node->array)[node->ocup].quant=quantity;
        (node->array)[node->ocup].promo=promo;
        node->ocup++;
        return node; 
    }
    node->height = 1 + max3(alturaP(node->left),
                           alturaP(node->right));
    int balance = (alturaP(node->left))-(alturaP(node->right));
    if (balance > 1 && strcmp(key,node->left->key)<0)
        return rotateRP(node);
    if (balance < -1 && strcmp(key,node->right->key)>0)
        return rotateLP(node);
    if (balance > 1 && strcmp(key,node->left->key)>0)
    {
        node->left =  rotateLP(node->left);
        return rotateRP(node);
    }
    if (balance < -1 && strcmp(key,node->right->key)<0)
    {
        node->right = rotateRP(node->right);
        return rotateLP(node);
    }
    return node;
}

void printAVLP (AVLP a, int i) {
    int j;
    if (a==NULL) return;
    printAVLP(a->right,i+1);
    for(j=0;j<i;j++) printf("    ");
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
    return a;
}

void destroyVenda(Venda v) {
    int i,j;
    for(i=2;i>=0;i--) {
        for(j=11;j>=0;j--) {
            free(v[i][j]);
        }
    }
}

float getPrice(AVLP a,int index) {
    return (a->array)[index].price;
}

int getQuantity(AVLP a,int index) {
    return (a->array)[index].quant; 
}

char getPromo(AVLP a,int index) { 
    return (a->array)[index].promo;
}

int percorreAVLP(AVLP a) {
    int i=0;
    if(a) {
        i+=percorreAVLP(a->left);
        i+=a->ocup;
        i+=percorreAVLP(a->right);
    }
    return i;
}

int percorreAVLC(AVLC a) {
    int i=0;
    if(a) {
        i+=percorreAVLC(a->left);
        i+=percorreAVLP(a->prod);
        i+=percorreAVLC(a->right);
    }
    return i;
}

int salesAndProfitP(AVLP a, float *totalN, float *totalP) {
    int totalSales=0;
    int ocupados = a->ocup;
    totalSales += ocupados;
    for(int i = 0; i < ocupados; i++) {
        if(a->array[i].promo == 'N') (*totalN) += (float)((a->array[i].price) * (a->array[i].quant));
        else (*totalP) += (float)((a->array[i].price) * (a->array[i].quant));
    }
    return totalSales;
}

int salesAndProfitC(AVLC a, float *totalN, float *totalP, char* key) {
    int totalSales=0;
    AVLP b;
    if(a) {
        totalSales+=salesAndProfitC(a->left, totalN, totalP, key);
        b = lookupAVLP(a->prod, key);
        if(b != NULL) totalSales+=salesAndProfitP(b, totalN, totalP);
        totalSales+=salesAndProfitC(a->right, totalN, totalP, key);
    }
    return totalSales;
}

/*
int currentMonthSalesAndProfit (AVLP prod, float *totalN, float *totalP) {
    int totalSales = 0;
    int ocup= prod->ocup;
    for(int i=0;i<ocup;i++) {
        if(prod->array[i].promo == 'N') (*totalN) +=(float) ((prod->array[i].price) * (prod->array[i].quant));
        else (*totalP) += (float) ((prod->array[i].price) * (prod->array[i].quant));
    }
    return totalSales;
}*/

int monthlySalesAndProfit(AVLC a, float *totalN, float *totalP) {
    
    int totalSales =0;
    if(a)  {
        totalSales += monthlySalesAndProfit(a->left,totalN,totalP);
        totalSales += salesAndProfitP(a->prod,totalN,totalP);
        totalSales += monthlySalesAndProfit(a->right,totalN,totalP);
    }
    return totalSales;
}


AVLP lookupAVLP(AVLP a, char* key) {
    AVLP r=NULL;
    int res=0;
    if(a) {
        res = strcmp(key,a->key);
        if(res > 0) r=lookupAVLP(a->right,key);
        else if(res < 0) r=lookupAVLP(a->left,key);
        else r=a;
    }
    return r;
}

