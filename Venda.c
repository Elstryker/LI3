//
//  Venda.c
//  LI3
//
//  Created by Rúben Cerqueira on 20/02/2020.
//  Copyright © 2020 Rúben Cerqueira. All rights reserved.
//

#include "Venda.h"
#include <ctype.h>
#include <string.h>



int valvenda(char *prod,float prec,int un,char prom,char *cli,int mes,int super) {
    int i=0;
    if (isupper(prod[0]) && isupper(prod[1]) && isdigit(prod[2]) && isdigit(prod[3]) && isdigit(prod[4]) && isdigit(prod[5]))
    {
        
        if (prec>=0 && un>=0 && (mes>0 && mes<13) && (super>0 && super <4) && (prom=='N' || prom == 'P'))
       
        {
           
            if (isupper(cli[0]) && isdigit(cli[1]) && isdigit(cli[2]) && isdigit(cli[3]) && isdigit(cli[4])) i=1;
                
        }
               
    }
    
    
    return i;
    
}


int findProd(char *prod,char **produtos){
    int i=0;
    for (int j=0;j<171007;j++){
       if(strcmp(prod,produtos[j]) == 0) i=1;
    }
    
    return i;
}

