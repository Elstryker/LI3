#include "Produto.h"

struct AVL {
    char* key;
    int height;
    struct AVL* right;
    struct AVL* left;
};

Produto initProduto(){
    Produto p;
    p=malloc(26*sizeof(struct AVL*));
    for(int i=0;i<26;i++) {
        p[i]=NULL;
    }
    return p;
}

void destroyProduto(Produto p){
    int i;
    for(i=25;i>=0;i--) free(p[i]);
}

void readFiletoProduto(Produto p, FILE* f) {
    char*buffer;
    buffer=(char*) malloc(9*sizeof(char));
    while(feof(f)==0) {
        fgets(buffer,8,f);
        strtok(buffer," \r\n");
        p[buffer[0]-65]=insertAVL2(p[buffer[0]-65],buffer);
    }
}

int altura2(AVL a) {
    int i;
    if(a==NULL) {
        i=0;
    }
    else i=a->height;
    return i;
}

int max2(int a,int b) {
    return (a>b?a:b);
}

AVL rotateR2(AVL y)
{
    AVL x = y->left;
    AVL T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max2(altura2(y->left), altura2(y->right))+1;
    x->height = max2(altura2(x->left), altura2(x->right))+1;
    return x;
}

AVL rotateL2(AVL x)
{
    AVL y = x->right;
    AVL T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max2(altura2(x->left), altura2(x->right))+1;
    y->height = max2(altura2(y->left), altura2(y->right))+1;
    return y;
}

AVL insertAVL2(AVL node,char* key)
{
    if (node == NULL){
        AVL new=NULL;
        new=malloc(sizeof(struct AVL));
        new->key=strdup(key);
        new->right=new->left=NULL;
        new->height=1;
        node=new;
        return node;
    }
    if (strcmp(key,node->key)<0)
        node->left  = insertAVL2(node->left, key);
    else if (strcmp(key,node->key)>0)
        node->right = insertAVL2(node->right, key);
    else
        return node;
    node->height = 1 + max2(altura2(node->left),
                           altura2(node->right));
    int balance = (altura2(node->left))-(altura2(node->right));
    if (balance > 1 && strcmp(key,node->left->key)<0)
        return rotateR2(node);
    if (balance < -1 && strcmp(key,node->right->key)>0)
        return rotateL2(node);
    if (balance > 1 && strcmp(key,node->left->key)>0)
    {
        node->left =  rotateL2(node->left);
        return rotateR2(node);
    }
    if (balance < -1 && strcmp(key,node->right->key)<0)
    {
        node->right = rotateR2(node->right);
        return rotateL2(node);
    }
    return node;
}

void printAVL2 (AVL a, int i) {
    int j;
    if (a==NULL) return;
    printAVL2(a->right,i+1);
    for(j=0;j<i;j++) printf("  ");
    puts(a->key);
    printAVL2(a->left,i+1);
}

int inorderAVL(AVL a) {
    int contador=0;
    if (a) {
        contador+=inorderAVL(a->left);
        puts(a->key);
        contador++;
        contador+=inorderAVL(a->right);
    }
    return contador;
}


int findProd(AVL a,char* key){
    int i=0;
    
    if(a) {
    int compare=strcmp(key,a->key);
    if(compare > 0) i=findProd(a->right,key);
    else if(compare < 0) i=findProd(a->left,key);
    else i=1;  
    }
return i;
}