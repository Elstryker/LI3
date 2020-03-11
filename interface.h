//
//  Venda.h
//  LI3
//
//  Created by Rúben Cerqueira, Júlio Alves and Alexandra Reigada on 20/02/2020.
//  Copyright © 2020 Rúben Cerqueira, Júlio Alves and Alexandra Reigada. All rights reserved.
//

#ifndef interface_h
#define interface_h

#include "Cliente.h"
#include "Produto.h"
#include "Venda.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct SGV{
    Cliente c;
    Produto p;
    Venda v;
} SGV;

SGV initSGV();
void destroySGV(SGV a);
SGV loadSGVFromFiles(SGV sgv);
void getProductsStartedByLetter (SGV sgv, char letter);
void getProductsSalesAndProfit (SGV sgv, char * productID, int month);
Produto getProductsNeverBought (SGV sgv, int branchID);
Cliente getClientsOfAllBranches(SGV sgv);
void getClientsAndProductsNeverBoughtCount (SGV sgv);
Produto getProductsBoughtByClient(SGV sgv,char* clientID);
void getSalesAndProfit (SGV sgv,int minMonth, int maxMonth);
Cliente getProductBuyers (SGV sgv, char * productID, int branch);
Produto getClientFavoriteProducts (SGV sgv, char* clientID, int month);
Produto getTopSelledProducts(SGV sgv, int limit);
Produto getClientTopProfitProducts(SGV sgv, char * clientID, int limit);


AVL getAVL(SGV a,int index);


#endif 
