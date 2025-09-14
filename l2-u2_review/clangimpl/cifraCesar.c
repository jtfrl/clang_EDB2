#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct No{
    char l;
    struct No* prox;
}No;

typedef struct{
    No* inicio;
}Cifra;

Cifra createCifra(){
    Cifra cfr;
    cfr.inicio=NULL;
    return cfr;
}

void insertLtrtoCif(Cifra* cfr, char l){
    No* novo_n = (No*)malloc(sizeof(No)); 

    novo_n->l=l;
    novo_n->prox=NULL;

    if(cfr->inicio==NULL){
        cfr->inicio=novo_n;
    }else{
        No* temp=cfr->inicio;
        while(temp->prox!=NULL){
            temp=temp->prox;
        }
        temp->prox=novo_n;
    }
}

int sizeCif(Cifra* cfr){
    No* at=cfr->inicio;
    int count=0;
    while(at!=NULL){
        count++;
        at=at->prox;
    }
    return count;
}

char* cesCiph(Cifra* cfr){
    //No* at=(No*)malloc(sizeof(No));
    No* at=cfr->inicio;
    int tam=sizeCif(cfr);
    int valorMudanca=3;
    int index=0;

    //char* res=(char*)malloc(sizeof(char));
    char* res = (char*)malloc((tam + 1) * sizeof(char)); //soma 1 para o caractere '\0'

    while(at!=NULL){
        char auth=at->l; //original
        char cfr_conv=auth; //'cfr_conv' ---> encriptado
    
        if(auth>='A' && auth<='Z'){
            cfr_conv=((auth-'A'+valorMudanca)%26)+'A';
        }else if(auth>='a' && auth<='z'){
            cfr_conv=((auth-'a'+valorMudanca)%26)+'a';
        }


        res[index++]=cfr_conv;
        at=at->prox;
    }

    res[index]='\0';  //ultimo caractere é nulo

    return res;
}


void freelist(Cifra* cfr){
    No* at=cfr->inicio;
    while(at!=NULL){
        No* temp=at;
        at=at->prox;
        free(temp);
    }

    cfr->inicio=NULL;
}

int main(){

    Cifra buildCfr=createCifra();
    char pal[100];

    printf("Insira a palavra para cifrar\n");
    fgets(pal, sizeof(pal), stdin);

    pal[strcspn(pal, "\n")] = '\0'; //converte o último caractere 

    for(int i=0;pal[i]!='\0';i++) insertLtrtoCif(&buildCfr, pal[i]);


    char* res=cesCiph(&buildCfr);

    printf("\nPalavra cifrada: %s\n", res);

    free(res);
    freelist(&buildCfr);

    return 0;
}