//Carrega apenas a árvore

#include "fileLoad.h"

typedef struct No{
    char* catExt; //categoria extraída
    struct No *esq, *dir;
}No;

No* novoNo(const char* f, int indexCol){
    printf("Informe o endereço do arquivo");

    //verificar como pegar o endereço do arquivo e o restante



    //fornecerá o char* para alimentar os nós
    CatVector* arq=leCSV_Cat(f, indexCol);


    //processamento da criação do nó

    /*
    
    ADAPTAR ROTINA A SEGUIR 
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->valor = v;
    n->esq = n->dir = NULL;
    return n;
    
    */
 
    No* n=(No*)malloc(sizeof(No));

    return n;

}

//char*[] = 

/*
necessário tomar o nome de cada categoria e colocar num vetor
*/

/*FUNÇÕES DE ÁRVORE AQUI: ADPATAR*/

/*
No* novoNo(const char* f, int index) {

// -- F. PARA CARREGAR CATEGORIAS NUM VETOR -- //
CatVector[] cat_No=leCSV_Cat(f, i);


// -- ::: pendente ::: passar para o nó
    No* n = (No*) malloc(sizeof(No));
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->valor = v;
    n->esq = n->dir = NULL;
    return n;
}


No* inserir(No* r, int v) {
    if (r == NULL) return novoNo(v);
    if (v < r->valor)      r->esq = inserir(r->esq, v);
    else if (v > r->valor) r->dir = inserir(r->dir, v);
    return r;
}


No* buscar(No* r, int v) {
    if (r == NULL || r->valor == v) return r;
    return (v < r->valor) ? buscar(r->esq, v) : buscar(r->dir, v);
}


void emOrdem(No* r) {
    if (r == NULL) return;
    emOrdem(r->esq);
    printf("%d ", r->valor);
    emOrdem(r->dir);
}

No* maiorNo(No* r) {
    No* atual = r;
    while (atual && atual->dir) atual = atual->dir;
    return atual;
}


No* remover(No* r, int v) {
    if (r == NULL) return NULL;

    if (v < r->valor) {
        r->esq = remover(r->esq, v);
    } else if (v > r->valor) {
        r->dir = remover(r->dir, v);
    } else {
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            return NULL;
        } else if (r->esq == NULL) {
            No* tmp = r->dir;
            free(r);
            return tmp;
        } else if (r->dir == NULL) {
            No* tmp = r->esq;
            free(r);
            return tmp;
        } else {
            No* pred = maiorNo(r->esq);
            r->valor = pred->valor;
            r->esq = remover(r->esq, pred->valor);
        }
    }
    return r;
}


void liberarArvore(No* r) {
    if (!r) return;
    liberarArvore(r->esq);
    liberarArvore(r->dir);
    free(r);
}


*/


