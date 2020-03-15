//
//  main.c
//  LI3
//
//  Created by Rúben Cerqueira, Júlio Alves and Alexandra Reigada on 13/02/2020.
//  Copyright © 2020 Rúben Cerqueira, Júlio Alves and Alexandra Reigada. All rights reserved.
//
#include "interface.h"

int percorreAVLP(AVLP a) {
    int i=0;
    if(a) {
        i+=percorreAVLP(a->left);
        i+=a->tam;
        i+=percorreAVLP(a->right);
    }
    return i;
}

int percorreAVLC(AVLC a) {
    int i=0;
    if(a) {
        i+=percorreAVLC(a->left);
        i+=percorreAVLP(a->prod);
        i+=percorreAVLC(a->right);
    }
    return i;
}

int main(int argc, const char * argv[]) {
    int i,j,r=0;
    SGV a;
    a=initSGV();
    a=loadSGVFromFiles(a);
    printf("\n\nDone!\n\n");
    for(i=0;i<3;i++) {
        for(j=0;j<12;j++) {
            r+=percorreAVLC(a.v[i][j]);
        }
    }
    printf("%d\n\n",r);
    return 0;
}
