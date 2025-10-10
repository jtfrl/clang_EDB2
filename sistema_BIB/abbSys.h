#ifndef ABBSYS
#define ABBSYS
#include "fileLoad.h"

typedef struct No{
    char* catExt; //categoria extraída
    struct No *esq, *dir;
}No;

No* inserir(No* r, CatVector* vetorComCat);
No* novoNo(char* catExt);

No* buildABB(CatVector* vCats);
void emOrdem(No* raiz);
No* buscaCat(No* raiz, const char* cat){

void liberarABB(No* raiz);
void processarCat(const char* arqCSV, int indexColCat);

FILE* readCatCSV_provideHeap(char* busca);

#endif //ABBSYS


