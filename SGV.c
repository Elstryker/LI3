
#include "interface.h"
#include "Cliente.h"

SGV initSGV() {
    int i;
    SGV sgv;
    sgv.produtos = malloc(2*sizeof(int *)); 
    sgv.filiais = malloc(3*sizeof(int *));
    sgv.clientes = malloc(2*sizeof(int *));
    sgv.produtos[0]= malloc(26*sizeof(struct AVL));
    sgv.produtos[1]= malloc(26*sizeof(struct AVL));
    sgv.clientes[0]= malloc(26*sizeof(struct AVL));
    sgv.clientes[1]= malloc(26*sizeof(struct AVL));
    sgv.filiais[0]= malloc(12*sizeof(struct AVL));
    sgv.filiais[1]= malloc(12*sizeof(struct AVL));
    sgv.filiais[2]= malloc(12*sizeof(struct AVL));

    for(i=0;i<2;i++) {
        for (int j=0;j<26;j++) {
        (sgv.clientes[i])[j] = NULL;
        (sgv.produtos[i])[j] = NULL;
        }
    }

    for(i=0;i<3;i++) {
        for(int j=0;j<12;j++) {
            (sgv.filiais[i])[j] = NULL;
        }
    }
    return sgv;

}