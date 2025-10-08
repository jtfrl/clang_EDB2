//Carrega os arquivos em csv
#ifndef FILE_LOAD
#define FILE_LOAD

#define MAX_CAT 1000
#define MAX_CAT_NAME 15

//cat.=="CATEGORIA"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool checkOpenFile(FILE* arqCsv){
    //bool isok=true;

    if(!arqCsv){
        perror("Abertura do arquivo falhou");
        return false;
    }

    return true;
}

FILE* openFile(const char *fileAdd){
    FILE* abrir=fopen(fileAdd, "r");
    if(!checkOpenFile(abrir)) return NULL; //checa o .csv
    return abrir;
}


void readFile(FILE* dataCsv){
    if(!dataCsv) return;

    int c;

    while((c=fgetc(dataCsv))!=EOF) putchar(c);

    if(ferror(dataCsv)){
        puts("ERRO DE LEITURA");
    }

    //caso n haja erro, significa que a leitura foi concluída
}


void closeFile(FILE* f){
    if(f){
        fclose(f);
    } 
}

/* #### DEFININDO CATEGORIAS DENTRO DO ARQ #### */

typedef struct{
    char **cat; //array de strings
    int count;
    int cap; //capacidade
}CatVector;


void initCatVector(CatVector* v, int cap_inicial){
    v->cat=(char**)malloc(sizeof(char*)*cap_inicial);
    v->count=0;
    v->cap=cap_inicial;

}

CatVector* criaVtCat(){
    // trata o bloco a seguir como se fosse CatVector, mesmo com retorno void
    // assim podemos usar ref. com '->'
    CatVector* vet=(CatVector*)malloc(sizeof(CatVector)); 

    if(!vet) return NULL;

    initCatVector(vet, 100);

    return vet;
}

/*a implementar: adicionar cat. ||| liberar memoria ||| extrair as cat. do csv */


#endif //FILE_LOAD