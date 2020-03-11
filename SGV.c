#include "interface.h"
#include "Cliente.h"
#include "Produto.h"
#include "Venda.h"

SGV initSGV() {

}

SGV destroySGV() {

}

SGV loadSGVFromFiles(SGV sgv,char * filesFolderPath) {

}

Produto getProductsStartedByLetter (SGV sgv, char letter) {

}

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
    
}