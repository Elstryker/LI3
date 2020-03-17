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
int getProductsNeverBought (SGV sgv, int branchID);
Cliente getClientsOfAllBranches(SGV sgv);
void getClientsAndProductsNeverBoughtCount (SGV sgv);
Produto getProductsBoughtByClient(SGV sgv,char* clientID);
void getSalesAndProfit (SGV sgv,int minMonth, int maxMonth);
void getProductBuyers (SGV sgv, char * productID, int branch);
Produto getClientFavoriteProducts (SGV sgv, char* clientID, int month);
Produto getTopSelledProducts(SGV sgv, int limit);
Produto getClientTopProfitProducts(SGV sgv, char * clientID, int limit);



AVL getAVLLetter(SGV a,char letter);
AVLC getAVLC(SGV a, int filial, int mes);
AVLP getAVLP(AVLC a);
AVL getAVLCLi(SGV a, int index);
AVL getAVLProd(SGV a, int index);
Venda getVenda(SGV a);
Produto getProduto(SGV a);
Cliente getCliente(SGV a);
int valvenda(SGV sgv,char *prod,float prec,int un,char prom,char *cli,int mes,int super);
void readFiletoVenda(SGV v, FILE* f);
int neverBoughtP(AVLP a, char* key);
int neverBoughtC(AVLC a,char* key);
int scanNeverBoughtP(char* key, Venda v);
int allProductNeverBoughtScan(AVL a, Venda v);
void cleanBoughtCP(Cliente c,Produto p);
void scanProdBoughtP(AVLP a, Produto p);
void scanProdBoughtC(AVLC a, Produto p);
void percorreArvore(SGV sgv, AVL clientes, Cliente newCliente);
void testClientOfAllBranches(SGV sgv, Cliente newCliente, char *key);
void scanCliBoughtC(AVLC a, Cliente c);

#endif 
