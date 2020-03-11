#include "interface.h"
#include "Cliente.h"
#include "Produto.h"
#include "Venda.h"

SGV initSGV() {
    SGV a;
    a.p = initProduto();
    a.c = initCliente();
    a.v = initVenda();
    return a;
}


// A XANA ACHA QUE NÃO É ASSIM, ACHA QUE TEM DE SE DESTRUIR UMA SGV EXISTENTE NA MAIN
SGV destroySGV() {
    SGV a;
    destroyProduto(a.p);
    destroyCliente(a.c);
    destroyVenda(a.v);
    return a;
}

SGV loadSGVFromFiles(SGV sgv,char * path) {
    readFiletoCliente(sgv.c,*path);
    readFiletoProduto(sgv.p,*path);
    //não temos readFiletoVenda
}

AVL getProductsStartedByLetter (SGV sgv, char letter) {
   AVL prod;    //SERÁ ASSIM, RUBEN?
   int i= letter-65;
   prod=sgv.p[i]; 
   return prod;

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