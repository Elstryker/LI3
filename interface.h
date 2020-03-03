//
//  Venda.h
//  LI3
//
//  Created by Rúben Cerqueira, Júlio Alves and Alexandra Reigada on 20/02/2020.
//  Copyright © 2020 Rúben Cerqueira, Júlio Alves and Alexandra Reigada. All rights reserved.
//

#ifndef interface_h
#define interface_h

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct SGV SGV;
typedef struct AVL *AVL;

int altura(AVL a);
int max(int a,int b);
AVL rotateR(AVL a);
AVL rotateL(AVL a);
AVL insertAVL(AVL a, int x);
void printAVL(AVL a, int i);
int valvenda(char * a,float b,int c,char d,char * e,int f,int g);
int findProd(char *a, char **b);
#endif /* interface_h */
