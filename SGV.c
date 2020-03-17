#include "interface.h"

SGV initSGV() {
    SGV a;
    a.p = initProduto();
    a.c = initCliente();
    a.v = initVenda();
    return a;
}

void destroySGV(SGV a) {
    destroyProduto(a.p);
    destroyCliente(a.c);
    destroyVenda(a.v);
}

SGV loadSGVFromFiles(SGV sgv) {
    FILE* cliente, *produto, *venda;
    cliente=fopen("Clientes.txt","r");
    produto=fopen("Produtos.txt","r");
    venda=fopen("Vendas_1M.txt","r");
    if(cliente==NULL || produto==NULL || venda==NULL) {
        printf("Erro: ficheiro não encontrado");
        exit(1);
    }
    readFiletoCliente(sgv.c,cliente);
    readFiletoProduto(sgv.p,produto);
    readFiletoVenda(sgv,venda);
    fclose(cliente);
    fclose(produto);
    fclose(venda);
    return sgv;
}

void getProductsStartedByLetter (SGV sgv, char letter) {
   AVL prod;
   prod=getAVLLetter(sgv,letter);
   int contador=inorderAVL(prod);
   printf("\nNúmero de Produtos começados pela letra '%c': %d\n",letter,contador);
}

void getProductsSalesAndProfit (SGV sgv, char * productID, int month) {
    int i, totalSales = 0; 
    float totalN = 0, totalP = 0;
    AVLC a;
    for(i=0;i<3;i++) {
        a=getAVLC(sgv,i,month-1);
        totalSales += salesAndProfitC(a, &totalN, &totalP, productID);
    }
    printf("Vendas totais do produto %s no %d mes: %d\n"
           "Vendas totais em venda normal: %0.2f\n"
           "Vendas totais em promoçao: %0.2f\n\n",productID, month, totalSales, totalN, totalP);
}

/*
Produto getProductsNeverBought (SGV sgv, int branchID) {

}*/









//Determinar a lista ordenada de códigos de clientes que realizaram compras em todas as filiais



Cliente getClientsOfAllBranches(SGV sgv)
{
    Cliente newCliente = malloc(sizeof(Cliente));

    for(int l=0; l<26; l++)
    {
        //AVL arv = sgv.c[l];
        if(sgv.c[l])
        {
            percorreArvore(sgv, sgv.c[l], &newCliente);

            //AQUI EU QUERO IR BUSCAR A KEY DE CADA CLIENTE E MANDAR COMPARAR COM AS VENDAS 
            //MANTER SEMPRE O MESMO APONTADOR PARA O NEW CLIENTE PARA IR ADICIONANDO AS KEYS DOS CLIENTES QUE CUMPREM
        }
    }
    return newCliente;
}

void percorreArvore(SGV sgv, AVL clientes, Cliente *newCliente)
{
    if(clientes)
    {
        percorreArvore(sgv, clientes->left, &newCliente);
        percorreArvore(sgv, clientes->right, &newCliente);
        testClientOfAllBranches(sgv, &newCliente, clientes->key);

    }

}

int getProductsNeverBought (SGV sgv, int branchID) {
    int total = 0;
    AVL a;
    for(int i=0; i<26; i++) {
        a = getAVL(sgv,i);
        total+=allProductNeverBoughtScan(a, getVenda(sgv));
    }
    return total;
}

/*
Cliente getClientsOfAllBranches(SGV sgv){

//procurar na arvore das vendas
//se encontrou venda, entao venda filial é positiva, sai de procurar desse mes
//se nao encontrou venda nesse mes, entao passa para o proximo mes e a venda está incompleta para ja 
void testClientOfAllBranches(SGV sgv, Cliente *newCliente, char *key)
{
    int vendaFilial=0;
    int vendaIncompleta=0;
    int vendaCompleta=0;

    for(int f=0; f<3 && vendaIncompleta==0; f++)
    {
        for(int m=0; m<12 && vendaFilial==0; m++)
        {
            if (findVendaCliente(sgv.v[f][m], key) == 1)
            {
                vendaFilial=1;
                vendaIncompleta=0;
            } 
            else vendaIncompleta=1;
        }
        if (vendaFilial==1) vendaCompleta++; 
    } 
    if (vendaCompleta==3) insertAVL(&newCliente, key);
}


int findVendaCliente(AVLC clientes, char* key) {
    int find=0;
    if(clientes) {
        int i=strcmp(clientes->key,key);
        if(i>0) find=findVendaCliente(clientes->left, key);
        else if(i<0) find=findVendaCliente(clientes->right, key);
        
        else 
            if (clientes->prod->ocup>0) return 1; 
    }
    return find;
}



















/*
void getClientsAndProductsNeverBoughtCount (SGV sgv) {
    
}

Produto getProductsBoughtByClient(SGV sgv,char* clientID) {

}

void getSalesAndProfit (SGV sgv,int minMonth, int maxMonth) {

}

Cliente getProductBuyers (SGV sgv, char * productID, int branch) {

}

Produto getClientFavoriteProducts (SGV sgv, char* clientID, int month) {

}

Produto getTopSelledProducts(SGV sgv, int limit) {

}

Produto getClientTopProfitProducts(SGV sgv, char * clientID, int limit) {
    
}*/


//------------------------------------------------------------------------------------------------------//


AVL getAVLLetter(SGV a,char letter) {
    return a.p[letter-65];
}

AVLC getAVLC(SGV a, int filial, int mes) {
    return a.v[filial][mes];
}

AVLP getAVLP(AVLC a) {
    return a->prod;
}

AVL getAVL(SGV a, int index) {
    return a.p[index];
}

Venda getVenda(SGV a) {
    return a.v;
}

void readFiletoVenda(SGV sgv, FILE* f) {
    char*prod, *cli = NULL, prom = '\0', *buffer;
    float price = 0;
    int quant = 0, mes = 0, filial = 0;
    char* eti;
    AVLC treeC;
    buffer=(char*) malloc(35*sizeof(char));
    while(feof(f)==0){
        fgets(buffer,35, f);
        strtok(buffer,"\r\n");
        prod=strdup(strtok(buffer, " "));
        if(((eti=(strtok(NULL, " ")))!=NULL)) price=atof(eti);
        else break;
        quant=atoi(strtok(NULL, " "));
        prom=(*strtok(NULL, " "));
        cli=strdup(strtok(NULL, " "));
        mes=atoi(strtok(NULL, " "));
        filial=atoi(strtok(NULL, " "));
        if (valvenda(sgv,prod,price,quant,prom,cli,mes,filial) == 1) {
            sgv.v[filial-1][mes-1]=insertAVLC(sgv.v[filial-1][mes-1],cli);
            treeC=lookupAVLC(sgv.v[filial-1][mes-1],cli);
            (treeC->prod)=insertAVLP(treeC->prod,prod,price,quant,prom);
        }
    }
}

int valvenda(SGV sgv, char *prod,float price,int quant,char prom,char *cli,int mes,int filial) {
    int i=0;
    if (isupper(prod[0]) && isupper(prod[1]) && isdigit(prod[2]) && isdigit(prod[3]) && isdigit(prod[4]) && isdigit(prod[5]))
        if (price>=0 && quant>=0 && (mes>0 && mes<13) && (filial>0 && filial <4) && (prom=='N' || prom == 'P'))
            if (isupper(cli[0]) && isdigit(cli[1]) && isdigit(cli[2]) && isdigit(cli[3]) && isdigit(cli[4]))
                if(findCli(sgv.c[cli[0]-65],cli)==1 && findProd(sgv.p[prod[0]-65],prod)==1) i=1;

    return i;
}

int isBoughtP(AVLP a, char* key) {
    int bool = 0;
    AVLP b=a;
    int cmp;
    while(b!=NULL && bool!=1) {
        cmp = strcmp(key, b->key);
        if(cmp > 0) b=b->right;
        else if(cmp < 0) b=b->left;
        else bool = 1;
    }
    return bool;
}

int isBoughtC(AVLC a,char* key) {
    int bool = 0;
    if(a) {
        if( isBoughtC(a->left,key) ||
            isBoughtP(a->prod,key) ||
            isBoughtC(a->right,key)) bool = 1;
    }
    return bool;
} 

int scanNeverBoughtP(char* key, Venda v) {
    int i,j, r = 0;
    for(i=0; i<3 && r==0; i++) {
        for(j=0; j<12 && r==0; j++) {
            if(isBoughtC(v[i][j],key)) r=1;
        }
    }
    return r;
}

int allProductNeverBoughtScan(AVL a, Venda v) {
    int total = 0;
    if(a) {
        total+=allProductNeverBoughtScan(a->left,v);
        if(scanNeverBoughtP(a->key,v)==0) {
            printf("%s\n", a->key);
            total++;
        }
        total+=allProductNeverBoughtScan(a->right,v);
    }
    return total;
} 
