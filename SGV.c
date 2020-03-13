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
    readFiletoVenda(sgv.v,venda);
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

/*
void getProductsSalesAndProfit (SGV sgv, char * productID, int month) {

}

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