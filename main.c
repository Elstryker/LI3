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
    int soma=0;
    a=initSGV();
    a=loadSGVFromFiles(a);
    printf("\n\nDone!\n\n");
    getProductsSalesAndProfit(a, "XY1464", 1);
    printf("%d\n", soma);
    destroySGV(a);
    return 0;
}
