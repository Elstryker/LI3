#include "interface.h"

SGV initSGV() {
    SGV a;
    a.p = initProduto();
    a.c = initCliente();
    a.v = initVenda();
    return a;
}

void destroySGV(SGV a) {
    destroyProduto(a.p);
    destroyCliente(a.c);
    destroyVenda(a.v);
}

SGV loadSGVFromFiles(SGV sgv) {
    FILE* cliente, *produto, *venda;
    cliente=fopen("Clientes.txt","r");
    produto=fopen("Produtos.txt","r");
    venda=fopen("Vendas_1M.txt","r");
    if(cliente==NULL || produto==NULL || venda==NULL) {
        printf("Erro: ficheiro não encontrado");
        exit(1);
    }
    readFiletoCliente(sgv.c,cliente);
    readFiletoProduto(sgv.p,produto);
    readFiletoVenda(sgv,venda);
    fclose(cliente);
    fclose(produto);
    fclose(venda);
    return sgv;
}

void getProductsStartedByLetter (SGV sgv, char letter) {
   AVL prod;
   prod=getAVLLetter(sgv,letter);
   int contador=inorderAVL(prod);
   printf("\nNúmero de Produtos começados pela letra '%c': %d\n",letter,contador);
}

void getProductsSalesAndProfit (SGV sgv, char * productID, int month) {
    int i, totalSales = 0; 
    float totalN = 0, totalP = 0;
    AVLC a;
    for(i=0;i<3;i++) {
        a=getAVLC(sgv,i,month-1);
        totalSales += salesAndProfitC(a, &totalN, &totalP, productID);
    }
    printf("Vendas totais do produto %s no %d mes: %d\n"
           "Vendas totais em venda normal: %0.2f\n"
           "Vendas totais em promoçao: %0.2f\n\n",productID, month, totalSales, totalN, totalP);
}

int getProductsNeverBought (SGV sgv, int branchID) {
    int total = 0;
    AVLC a;
    for(int i=0; i<26; i++) {
        cleanBought(getAVLProd(sgv,i));
        cleanBought(getAVLCLi(sgv,i));
    }
    if(branchID == 0) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<12; j++) {
                a = getAVLC(sgv,i,j);
                scanProdBoughtC(a,getProduto(sgv));
            }
        }
        for(int i=0; i<26; i++) total += printBought(getAVLProd(sgv,i));
    }
    else if(branchID > 0 && branchID < 4) {
        for(int i=0; i<12; i++) {
            a=getAVLC(sgv,branchID-1,i);
            scanProdBoughtC(a,getProduto(sgv));
        }
        for(int i=0; i<26; i++) total += printBought(getAVLProd(sgv,i));
    }
    else printf("Error, branch not found!\n");
    return total; 
}

Cliente getClientsOfAllBranches(SGV sgv)
{
    Cliente newCliente = initCliente();
    for(int l=0; l<26; l++)
    {
        if(sgv.c[l])
        {
            percorreArvore(sgv, sgv.c[l], newCliente);
        }
    }
    for(int i=0; i<26; i++)
    {
        if (newCliente[i]) printAVLasList(newCliente[i]);
    }
    return newCliente;
}



void getClientsAndProductsNeverBoughtCount (SGV sgv) {
    int i,j,totalP = 0, totalC = 0;
    AVLC a;
    for(i=0; i<26; i++) {
        cleanBought(getAVLProd(sgv,i));
        cleanBought(getAVLCLi(sgv,i));
    }
    for(i=0;i<3;i++) {
        for(j=0;j<12;j++) {
            a = getAVLC(sgv,i,j);
            scanCliBoughtC(a,getCliente(sgv));
            scanProdBoughtC(a,getProduto(sgv));
        }
    }
    for(i=0;i<26;i++) {
        totalC += numCliNeverBought(getAVLCLi(sgv,i));
        totalP += numProdNeverBought(getAVLProd(sgv,i));
    }
    printf("Número de produtos nunca comprados: %d\n"
           "Número de clientes que nunca compraram: %d\n",totalP,totalC);

}
/*
Produto getProductsBoughtByClient(SGV sgv,char* clientID) {

}
*/

void getSalesAndProfit (SGV sgv,int minMonth, int maxMonth) {
    int i,month, totalSales =0;
    float totalN = 0, totalP=0;
    AVLC a;
    for(month=minMonth-1;month<maxMonth-1;month++){
        for(i=0;i<3;i++) {
            a=getAVLC(sgv,i,month);
            totalSales += monthlySalesAndProfit(a,&totalN,&totalP);
        }
    }
    printf("Vendas totais entre o mes %d e o mes %d: %d\n"
            "Vendas totais em venda normal: %0.2f\n"
            "Vendas totais em promocao: %0.2f\n",minMonth,maxMonth,totalSales,totalN,totalP);
}


void getProductBuyers (SGV sgv, char * productID, int branch) {
    int i;
    AVLC a;
    for(i=0;i<12;i++) {
        a=getAVLC(sgv,branch,i);
        printProductBuyers(a,productID);
        
    }
}


/*
Produto getClientFavoriteProducts (SGV sgv, char* clientID, int month) {

}

Produto getTopSelledProducts(SGV sgv, int limit) {

}

Produto getClientTopProfitProducts(SGV sgv, char * clientID, int limit) {
    
}*/


//------------------------------------------------------------------------------------------------------//


AVL getAVLLetter(SGV a,char letter) {
    return a.p[letter-65];
}

AVLC getAVLC(SGV a, int filial, int mes) {
    return a.v[filial][mes];
}

AVLP getAVLP(AVLC a) {
    return a->prod;
}

AVL getAVLCLi(SGV a, int index) {
    return a.c[index];
}

AVL getAVLProd(SGV a, int index) {
    return a.p[index];
}

Venda getVenda(SGV a) {
    return a.v;
}

Produto getProduto(SGV a) {
    return a.p;
}

Cliente getCliente(SGV a) {
    return a.c;
}

void readFiletoVenda(SGV sgv, FILE* f) {
    char*prod, *cli = NULL, prom = '\0', *buffer;
    float price = 0;
    int quant = 0, mes = 0, filial = 0;
    char* eti;
    AVLC treeC;
    buffer=(char*) malloc(35*sizeof(char));
    while(feof(f)==0){
        fgets(buffer,35, f);
        strtok(buffer,"\r\n");
        prod=strdup(strtok(buffer, " "));
        if(((eti=(strtok(NULL, " ")))!=NULL)) price=atof(eti);
        else break;
        quant=atoi(strtok(NULL, " "));
        prom=(*strtok(NULL, " "));
        cli=strdup(strtok(NULL, " "));
        mes=atoi(strtok(NULL, " "));
        filial=atoi(strtok(NULL, " "));
        if (valvenda(sgv,prod,price,quant,prom,cli,mes,filial) == 1) {
            sgv.v[filial-1][mes-1]=insertAVLC(sgv.v[filial-1][mes-1],cli);
            treeC=lookupAVLC(sgv.v[filial-1][mes-1],cli);
            (treeC->prod)=insertAVLP(treeC->prod,prod,price,quant,prom);
        }
    }
}

int valvenda(SGV sgv, char *prod,float price,int quant,char prom,char *cli,int mes,int filial) {
    int i=0;
    if (isupper(prod[0]) && isupper(prod[1]) && isdigit(prod[2]) && isdigit(prod[3]) && isdigit(prod[4]) && isdigit(prod[5]))
        if (price>=0 && quant>=0 && (mes>0 && mes<13) && (filial>0 && filial <4) && (prom=='N' || prom == 'P'))
            if (isupper(cli[0]) && isdigit(cli[1]) && isdigit(cli[2]) && isdigit(cli[3]) && isdigit(cli[4]))
                if(findCli(sgv.c[cli[0]-65],cli)==1 && findProd(sgv.p[prod[0]-65],prod)==1) i=1;

    return i;
}

void cleanBoughtCP(Cliente c, Produto p) {
    for(int i=0; i<26; i++) {
        cleanBought(c[i]);
        cleanBought(p[i]);
    }
}

void scanProdBoughtP(AVLP a, Produto p) {
    if(a) {
        AVL b;
        scanProdBoughtP(a->left,p);
        b = lookupAVL(p[(a->key[0])-65],a->key);
        b->bought=1;
        scanProdBoughtP(a->right,p);
    }
}

void scanProdBoughtC(AVLC a, Produto p) {
    if(a) {
        scanProdBoughtC(a->left,p);
        scanProdBoughtP(a->prod,p);
        scanProdBoughtC(a->right,p);
    }
}

void percorreArvore(SGV sgv, AVL clientes, Cliente newCliente)
{
    if(clientes)
    {
        percorreArvore(sgv, clientes->left, newCliente);
        testClientOfAllBranches(sgv, newCliente, clientes->key);
        percorreArvore(sgv, clientes->right, newCliente);

    }

}

void testClientOfAllBranches(SGV sgv, Cliente newCliente, char *key)
{
    int vendaFilial=0;
    int vendaIncompleta=0;
    int vendaCompleta=0;

    for(int f=0; f<3 && vendaIncompleta==0; f++)
    {
        for(int m=0; m<12 && vendaFilial==0; m++)
        {
            if (lookupAVLC(sgv.v[f][m], key))
            {
                vendaFilial=1;
                vendaIncompleta=0;
            } 
            else vendaIncompleta=1;
        }
        if (vendaFilial==1) vendaCompleta++; 
    } 
    if (vendaCompleta==3) newCliente[key[0]-65] = insertAVL(newCliente[key[0]-65], key);
}

void scanCliBoughtC(AVLC a, Cliente c) {
    if(a) {
        AVL b;
        scanCliBoughtC(a->left,c);
        b = lookupAVL(c[a->key[0]-65],a->key);
        b->bought = 1;
        scanCliBoughtC(a->right,c);
    }
}
