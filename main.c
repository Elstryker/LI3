//
//  main.c
//  LI3
//
//  Created by Rúben Cerqueira on 13/02/2020.
//  Copyright © 2020 Rúben Cerqueira. All rights reserved.
//
#include "Venda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    FILE* cliente,*produto,*venda;
    int i;
    char** clientes,**produtos,**vendas;
    char buffer[35], *prod, prom, *cli;
    float prec;
    int un, mes,super;
    produto=fopen("Produtos.txt","r");
    cliente=fopen("Clientes.txt","r");
    venda=fopen("Vendas_1M.txt","r");
    if(cliente==NULL || produto==NULL || venda==NULL) printf("Erro\n");
    clientes=malloc(20000*sizeof(char*));
    produtos=malloc(200000*sizeof(char*));
    vendas=malloc(1000000*sizeof(char*));
    for(i=0;i<20000;i++) {
        clientes[i]=malloc(8*sizeof(char));
        fgets(clientes[i], 8, cliente);
        strtok(clientes[i], "\r\n");
        if(feof(cliente)) break;
    }
    for(i=0;i<200000;i++) {
        produtos[i]=malloc(9*sizeof(char));
        fgets(produtos[i], 9, produto);
        strtok(produtos[i], "\r\n");
        if(feof(produto)) break;
    }
    for(i=0;i<1000000;){
        vendas[i]=malloc(34*sizeof(char));
        fgets(buffer,34, venda);
        strtok(buffer,"\r\n");
        prod=strtok(buffer, " ");
        prec=atof(strtok(NULL, " "));
        un=atoi(strtok(NULL, " "));
        prom=(*strtok(NULL, " "));
        cli=strtok(NULL, " ");
        mes=atoi(strtok(NULL, " "));
        super=atoi(strtok(NULL, " \r\n"));
        if (valvenda(prod,prec,un,prom,cli,mes,super) == 1) {
            vendas[i++]=buffer;
        }
        if(feof(venda)) break;
    }
    if(clientes[0]!=NULL) {puts(clientes[0]);
        puts(produtos[0]);
        puts(vendas[0]);
    }
    
    fclose(produto);
    fclose(cliente);
    fclose(venda);
    return 0;
}
