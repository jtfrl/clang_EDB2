#include "heap.h"
#include "abbSys.h"
#include "fileLoad.h" 

Livro* readCatCSV_provideHeap(const char* busca);

// Funções auxiliares:
int pai(int i) { return (i - 1) / 2; }
int esquerda(int i) { return 2 * i + 1; }
int direita(int i) { return 2 * i + 2; }

void trocar(Livro *a, Livro *b) {
    Livro temp = *a;
    *a = *b;
    *b = temp;
}

// Criação:
HeapMax* criarHeap(int capacidade) {
    HeapMax *heap = (HeapMax*) malloc(sizeof(HeapMax));
    heap->livros = (Livro*) malloc(capacidade * sizeof(Livro));
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

// Liberação:
void liberarHeap(HeapMax *heap) {
    if (!heap) return;
    free(heap->livros);
    free(heap);
}

// Inserção:
void inserirHeap(HeapMax *heap, Livro* livro) {
    if (heap->tamanho == heap->capacidade) {
        printf("Heap cheia, não é possível inserir '%s'\n", livro->titulo);
        return;
    }

    int i = heap->tamanho;
    heap->livros[i] = *livro;
    heap->tamanho++;

    while (i > 0 && heap->livros[pai(i)].vendas < heap->livros[i].vendas) {
        trocar(&heap->livros[i], &heap->livros[pai(i)]);
        i = pai(i);
    }
}

// Heapify (para casos de reconstrução e extração):
void heapify(HeapMax *heap, int i) {
    int esq = esquerda(i);
    int dir = direita(i);
    int maior = i;

    if (esq < heap->tamanho && heap->livros[esq].vendas > heap->livros[maior].vendas)
        maior = esq;

    if (dir < heap->tamanho && heap->livros[dir].vendas > heap->livros[maior].vendas)
        maior = dir;

    if (maior != i) {
        trocar(&heap->livros[i], &heap->livros[maior]);
        heapify(heap, maior);
    }
}

// Extrair o livro mais vendido:
Livro extrairMax(HeapMax *heap) {
    Livro vazio = {0};

    if (heap->tamanho <= 0) {
        printf("Heap vazia!\n");
        return vazio;
    }

    Livro raiz = heap->livros[0];
    heap->livros[0] = heap->livros[heap->tamanho - 1];
    heap->tamanho--;
    heapify(heap, 0);

    return raiz;
}

// Retornar o topo (sem remoção):
Livro topoHeap(HeapMax *heap) {
    Livro vazio = {0};
    if (heap->tamanho == 0) return vazio;
    return heap->livros[0];
}

// Reconstruir a heap (após atualizar vendas):
void reconstruirHeap(HeapMax *heap) {
    for (int i = heap->tamanho / 2 - 1; i >= 0; i--) {
        heapify(heap, i);
    }
}

// Imprimir os Top N livros:
void imprimirTopN(HeapMax *heap, int n) {
    if (heap->tamanho == 0) {
        printf("Nenhum livro na heap!\n");
        return;
    }

    if (n > heap->tamanho) {
        printf("N maior que a quantidade de livros (%d). Listando todos.\n", heap->tamanho);
        n = heap->tamanho;
    }

    printf("\nTop %d livros mais vendidos:\n", n);
    printf("----------------------------------\n");

    // Cópia temporária da heap:
    HeapMax *temp = criarHeap(heap->tamanho);
    memcpy(temp->livros, heap->livros, heap->tamanho * sizeof(Livro));
    temp->tamanho = heap->tamanho;

    for (int i = 0; i < n; i++) {
        Livro l = extrairMax(temp);
        printf("%dº - %s (%d vendas)\n", i + 1, l.titulo, l.vendas);
    }

    liberarHeap(temp);
}

// nessa função, usamos a categoria em arqCSV
HeapMax* processaLivro(const char* arqCSV, int indexCol_Vendas){

    Livro* liv=readCatCSV_provideHeap(arqCSV);

    if(liv==NULL){
        printf("Informações sobre vendas dos livros não estão disponíveis.\n");
        return NULL;
    }

    int totalLivros=0;
    while(liv[totalLivros].isbn!=-1) totalLivros++;

    HeapMax* livroHeap=criarHeap(totalLivros);

    if(!livroHeap){ 
        free(liv);
        return NULL;
    }

    for(int i=0; i<totalLivros; i++){
        inserirHeap(livroHeap, &liv[i]);
    }

    free(liv);

    return livroHeap;    
}

void mostraPrimeiroMaisVendido(HeapMax* heap){
    Livro primeiroMaisVendido=topoHeap(heap);

    if(!primeiroMaisVendido.titulo){
        perror("Não foi possível obter o título do livro\n");
        return;
    }

    printf("Livro mais vendido (1º Lugar): '%s'", primeiroMaisVendido.titulo);
}

Livro* buscaISBN(HeapMax* vLivro, int ISBN){
    //Livro* buscaLivro;

    for(int i=0;i<(vLivro->tamanho);i++){
        if(vLivro->livros[i].isbn==ISBN){
            printf("Livro encontrado: %s", vLivro->livros[i].titulo);
            return &vLivro->livros[i];
        }
    }
    perror("Livro não encontrado\n");
    return NULL;

}

// Atualiza a heap depois da venda
void updateHeap(HeapMax* heap, int isbn, int qtd){
    if(buscaISBN(heap, isbn)==NULL || isbn<=0 || qtd<=0){
        perror("Venda não realizada\n");
        return;
    }

    Livro* vendaLivro=buscaISBN(heap, isbn);
    int indexVendaLivro=0;


    // procedimento de busca de indice na heap
    for(int j=0; j<heap->tamanho; j++){
        if(heap->livros[j].isbn==isbn) indexVendaLivro=j;
    }

    int vendaAnt=heap->livros[indexVendaLivro].vendas;
   
    heap->livros[indexVendaLivro].estoque-=qtd;
    heap->livros[indexVendaLivro].vendas+=qtd;

    //bool vendaAlt=heap->livros[indexVendaLivro].vendas>vendaAnt;
    bool subir=true; 

    while(subir && indexVendaLivro>0){
        //rotina 1 - atualização de prioridade
        int indexPai=pai(indexVendaLivro); // começa tomando o nó como o pai
        bool comp_venda=heap->livros[indexPai].vendas<heap->livros[indexVendaLivro].vendas;

        if(comp_venda){
            trocar(&heap->livros[indexVendaLivro], 
                &heap->livros[indexPai]);
            indexVendaLivro=indexPai;
        }
        else{
            //heapify(heap, indexVendaLivro);
            subir=false;
        }
    }
}