//
//  main.c
//  LI3
//
//  Created by Rúben Cerqueira, Júlio Alves and Alexandra Reigada on 13/02/2020.
//  Copyright © 2020 Rúben Cerqueira, Júlio Alves and Alexandra Reigada. All rights reserved.
//
#include "interface.h"

int main(int argc, const char * argv[]) {
    SGV a;
    char *productID;
    int opcao,mes=0;
    int filial=0;
    size_t bufsize = 10;
    char letra=' ';
    int minMonth,maxMonth;
    productID = (char *)malloc(bufsize * sizeof(char));

    printf("\n\nSelecione qual query deseja executar\n0 - Sair\n1 - initSGV\n2 - destroySGV\n3 - loadSGVFromFiles\n4 - getProductsStartedByLetter\n5 - getProductsSalesAndProfit\n6 - getProductsNeverBought\n7 - getClientsOfAllBranches\n8 - getClientsAndProductsNeverBoughtCount\n9 - getProductsBoughtByClient\n10 - getSalesAndProfit\n11 - getProductBuyers\n12 - getClientFavoriteProducts\n13 - getTopSelledProducts\n14 - getClientTopProfitProducts\n");

    do {

    scanf("%d",&opcao);
    switch (opcao)
    {
    case 0:
        break;
    case 1:
        a=initSGV();
        printf("\n\nDone!\n\n");
        break;
    case 2:
        destroySGV(a);
        printf("\n\nDone!\n\n");
        break;
    case 3:
        a=loadSGVFromFiles(a);
        printf("\n\nDone!\n\n");
        break;
    case 4:
        printf("\nIndique que letra deseja procurar\n");
        scanf(" %c*[^\n]",&letra);
        getProductsStartedByLetter(a,letra);
        break;
    case 5:
        printf("Indique o mes\n");
        scanf(" %d",&mes);
        fflush(stdin);
        printf("Indique o produto que deseja procurar\n");
        getline(&productID,&bufsize,stdin);
        strtok(productID,"\n");
        getProductsSalesAndProfit(a,productID,mes);    
        break;
    case 6: 
        printf("Indique a filial\n");
        scanf("%d",&filial);
        printf("Número de produtos nunca comprados: %d\n\n",getProductsNeverBought(a,filial));
        break;
  /*  case 7:
        getClientsOfAllBranches(a);
        break;
        */
    case 10:
        printf("Indique entre que meses deseja procurar\n");
        scanf(" %d",&minMonth);
        scanf(" %d",&maxMonth);
        getSalesAndProfit(a,minMonth,maxMonth);
        break;
    case 11:
        printf("Insira a filial\n");
        scanf("%d",&filial);
        printf("Insira o produto\n");
        getline(&productID,&bufsize,stdin);
        strtok(productID,"\n");
        getProductBuyers(a,productID,(filial-1));
        break;
    default:
        printf("\nOpcao invalida! Por favor tente novamente!\n");
        break;
    }        

    } while (opcao!=0);



    return 0;
}
