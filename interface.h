//
//  Venda.h
//  LI3
//
//  Created by Rúben Cerqueira on 20/02/2020.
//  Copyright © 2020 Rúben Cerqueira. All rights reserved.
//

#ifndef interface_h
#define interface_h

#include <stdio.h>

typedef struct SGV SGV;

typedef struct AVL *AVL;

AVL insertAVL(AVL a, int x);
void printAVL(AVL a, int i);
int valvenda(char * a,float b,int c,char d,char * e,int f,int g);
int findProd(char *a, char **b);
#endif /* interface_h */
