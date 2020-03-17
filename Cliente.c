#include "Cliente.h"

struct AVL {
    char* key;
    int height;
    int bought;
    struct AVL* right;
    struct AVL* left;
};

Cliente initCliente(){
    Cliente c;
    c=malloc(26*sizeof(struct AVL*));
    for(int i=0;i<26;i++) {
        c[i]=NULL;
    }
    return c;
}

void destroyCliente(Cliente c){
    int i;
    for(i=25;i>=0;i--) free(c[i]);
}

void readFiletoCliente(Cliente c, FILE* f) {
    char*buffer;
    buffer=(char*) malloc(9*sizeof(char));
    while(feof(f)==0) {
        fgets(buffer,8,f);
        strtok(buffer," \r\n");
        c[buffer[0]-65]=insertAVL(c[buffer[0]-65],buffer);
    }

}

int altura(AVL a) {
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

AVL rotateR(AVL y)
{
    AVL x = y->left;
    AVL T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(altura(y->left), altura(y->right))+1;
    x->height = max(altura(x->left), altura(x->right))+1;
    return x;
}

AVL rotateL(AVL x)
{
    AVL y = x->right;
    AVL T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(altura(x->left), altura(x->right))+1;
    y->height = max(altura(y->left), altura(y->right))+1;
    return y;
}

AVL insertAVL(AVL node,char* key)
{
    if (node == NULL){
        AVL new=NULL;
        new=malloc(sizeof(struct AVL));
        new->key=strdup(key);
        new->right=new->left=NULL;
        new->height=1;
        new->bought=0;
        node=new;
        return node;
    }
    if (strcmp(key,node->key)<0)
        node->left  = insertAVL(node->left, key);
    else if (strcmp(key,node->key)>0)
        node->right = insertAVL(node->right, key);
    else
        return node;
    node->height = 1 + max(altura(node->left),
                           altura(node->right));
    int balance = (altura(node->left))-(altura(node->right));
    if (balance > 1 && strcmp(key,node->left->key)<0)
        return rotateR(node);
    if (balance < -1 && strcmp(key,node->right->key)>0)
        return rotateL(node);
    if (balance > 1 && strcmp(key,node->left->key)>0)
    {
        node->left =  rotateL(node->left);
        return rotateR(node);
    }
    if (balance < -1 && strcmp(key,node->right->key)<0)
    {
        node->right = rotateR(node->right);
        return rotateL(node);
    }
    return node;
}

void printAVL (AVL a, int i) {
    int j;
    if (a==NULL) return;
    printAVL(a->right,i+1);
    for(j=0;j<i;j++) printf("    ");
    puts(a->key);
    printAVL(a->left,i+1);
}

int findCli(AVL a,char* key){
    int i=0;
    if(a) {
        int compare=strcmp(key,a->key);
        if(compare > 0) i=findCli(a->right,key);
        else if(compare < 0) i=findCli(a->left,key);
        else i=1;
    }
    return i;
}

void cleanBought(AVL a) {
    if(a) {
        cleanBoughtC(a->left);
        a->bought=0;
        cleanBoughtC(a->right);
    }
}