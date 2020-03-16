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
    int i,j,soma;
    a=initSGV();
    a=loadSGVFromFiles(a);
    printf("\n\nDone!\n\n");
    getProductsSalesAndProfit(a,"PE1822",3);
    for(i=0;i<3;i++){
        for(j=0;j<12;j++){
            soma += percorreAVLC((a.v)[i][j]);
        }
    }
    destroySGV(a);
    printf("%d",soma);
    return 0;
}
