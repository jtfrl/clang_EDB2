//Carrega apenas a árvore

#include "fileLoad.h"
#include "abbSys.h"


No* inserir(No* r, CatVector* vetorComCat) {
    char* cat_ext=vetorComCat->cat;
    
    if (r == NULL) return novoNo(cat_ext);
    if (cat_ext < r->catExt) r->esq = inserir(r->esq, vetorComCat);
    else if (cat_ext > r->catExt) r->dir = inserir(r->dir, vetorComCat);
    return r;
}


No* novoNo(char* catExt){
 
    No* n=(No*)malloc(sizeof(No));
    if(!n){
        perror("Erro ao alocar no");
        return NULL;
    }

    n->catExt=(char*)malloc(strlen(catExt)+1);

    if(!n->catExt){
        perror("Erro ao alocar dado em string da categoria");
        free(n);
        return NULL;
    }

    strcpy(n->catExt, catExt); //copia a informação da categoria
    n->esq=n->dir=NULL;

    return n;

}

No* buildABB(CatVector* vCats){
    if(!vCats || vCats->count==0) return NULL;

    No* raiz=NULL;
    int lmt=vCats->count;

    // como temos um vetor de strings, podemos alimentar a ABB com 
    // o que vem da struct CatVector 
    for(int i=0; i<lmt;i++) raiz=inserir(raiz,vCats->cat[i]);

    return raiz;
}

void emOrdem(No* raiz){
    if (raiz==NULL) return;
    emOrdem(raiz->esq);
    printf("%s ", raiz->catExt);
    emOrdem(raiz->dir);
}

No* buscaCat(No* raiz, const char* cat){
    if(raiz==NULL || raiz->catExt == cat) return raiz;
    return(cat < raiz->catExt) ? buscaCat(raiz->esq, cat) : buscaCat(raiz->dir, cat);
}

void liberarABB(No* raiz){
    if(raiz==NULL) return;

    liberarABB(raiz->esq);
    liberarABB(raiz->dir);

    free(raiz->catExt);
    free(raiz);
}

// já mostra as categorias em ordem e permite a busca
void processarCat(const char* arqCSV, int indexColCat){
    CatVector* categoria=leCSV_Cat(arqCSV, indexColCat);

    if(!categoria || categoria->count==0){
        printf("Nenhuma categoria encontrada. Insira um novo arquivo e tente novamente\n");
        return;
    }

    printf("Carregadas %d categorias do .CSV", categoria->count);

    // construindo a arvore
    No* tree=buildABB(categoria);

    printf("\n Categorias em ordem: ");
    emOrdem(tree);

    char busca[MAX_CAT_NAME];
    print("Digite uma categoria para a busca\n");
    scanf("%s", busca);

    No* resultado=buscaCat(tree, busca);
    if(resultado) printf("Categoria '%s' encontrada: ", busca, "| processando arquivo .csv correspondente\n");
    else printf("Não encontrada: ", busca);

    libera(tree);
    libera(categoria);

}

// arquivo em .csv que vai ser utilizado na heap
FILE* readCatCSV_provideHeap(char* busca){
    char* fileFormat=".csv";
    char* file_provHeap=strcat(busca, fileFormat);
    FILE* abrir=fopen(file_provHeap, "r");

    if(!checkOpenFile(abrir)) return NULL;

    return abrir;

}


/*

FILE* openFile(const char *fileAdd){
    FILE* abrir=fopen(fileAdd, "r");
    if(!checkOpenFile(abrir)) return NULL; // checa o .csv
    return abrir;
}


void readFile(FILE* dataCsv){
    if(!dataCsv) return;
    int c;

    while((c=fgetc(dataCsv))!=EOF) putchar(c);

    if(ferror(dataCsv)){
        puts("ERRO DE LEITURA");
    }
    // caso n haja erro, significa que a leitura foi concluída
}

*/