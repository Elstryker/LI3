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
    while(feof(f)) {
        fgets(buffer,8,f);
        strtok(buffer," \r\n");
        p=insertAVL(p[buffer[0]-65],buffer);
    }
}

int compareKey(char* s1, char* s2) {
    int i;
    for(i=0;s1[i]!='\0';i++) {
        if(s1[i]!=s2[i]) return s1[i]-s2[i];
    }
    return 0;
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

AVL rotateR(AVL a) {
    AVL b=a->left;
    a->left=b->right;
    b->right=a;
    b->height=max(altura(b->right),altura(b->left)) +1;
    a->height=max(altura(a->right),altura(a->left)) +1;
    return b;
}

AVL rotateL(AVL a) {
    AVL b=a->right;
    a->right=b->left;
    b->left=a;
    b->height=max(altura(b->right),altura(b->left)) +1;
    a->height=max(altura(a->right),altura(a->left)) +1;
    return b;
}

AVL insertAVL(AVL a,char* x) { 
    if (a == NULL) {
        AVL new=NULL;
        new=malloc(sizeof(struct AVL));
        new->key=strdup(x);
        new->right=new->left=NULL;
        new->height=1;
        a=new;
        return a; 
    }  
    if(compareKey(a->key,x)>0) a->left = insertAVL(a->left,x);
    else if(compareKey(a->key,x)<0) a->right = insertAVL(a->right,x);  
    else return a; 
    a->height=1+max(altura(a->left),altura(a->right));
    int bal = (altura(a->left))-(altura(a->right));
    if (bal > 1 && x < a->left->key) 
        return rotateR(a); 
    if (bal < -1 && x > a->right->key) 
        return rotateL(a); 
    if (bal > 1 && x > a->left->key) 
    { 
        a->left =  rotateL(a->left); 
        return rotateR(a); 
    } 
    if (bal < -1 && x < a->right->key) 
    { 
        a->right = rotateR(a->right); 
        return rotateL(a); 
    } 
    return a;
}

void printAVL (AVL a, int i) {
    int j;
    if (a==NULL) return;
    printAVL(a->right,i+1);
    for(j=0;j<i;j++) printf("  ");
    printf("%d\n",a->key);
    printAVL(a->left,i+1);
}