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
    int contador;
    a=initSGV();
    a=loadSGVFromFiles(a);
    contador=inorderAVL(a.c[1]);
    printf("%d\n",contador);
    return 0;
}
