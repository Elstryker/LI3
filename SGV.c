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

}

Cliente getClientsOfAllBranches(SGV sgv){

}

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
    {
        if (price>=0 && quant>=0 && (mes>0 && mes<13) && (filial>0 && filial <4) && (prom=='N' || prom == 'P'))
        {
            if (isupper(cli[0]) && isdigit(cli[1]) && isdigit(cli[2]) && isdigit(cli[3]) && isdigit(cli[4])){
                if(findCli(sgv.c[cli[0]-65],cli)==1 && findProd(sgv.p[prod[0]-65],prod)==1) i=1;
            }      
        }        
    }

    return i;
}