#include "trie.h"

No *criar_no(){
  No *novo_no = (No *)malloc(sizeof(No));  // reserva espaço na memória para  tipo No
  
  if(novo_no){
    // o novo nó, se houver, recebe false
    // para realizar a inserção da palavra
    novo_no->fim_da_palavra = false; 

    // cada um dos filhos do nó será null 
    // (espaço reservados aos caracteres) que vão vir de 'inserir'
    for(int i = 0; i < ALFABETO; i++){
      novo_no->filhos[i] = NULL;
    }
  }
  return novo_no;
}


void inserir(No *raiz, const char *palavra){
  No *atual = raiz;
  
  for(int i = 0; palavra[i] != '\0'; i++){
    // cada letra na ASCII tem seu valor subtraido de 97
    // isso agiliza a busca
    int indice = palavra[i] - 'a';

    if(atual->filhos[indice] == NULL)
      atual->filhos[indice] = criar_no();

    atual = atual->filhos[indice]; 
    // cada filho é atualizado com o caractere correspondente
    // aqui é usado a string (vetor de caracteres)
  }
  
  atual->fim_da_palavra = true; // encerrado o laço, o fim da palavra é atingido
}

bool buscar(No *raiz, const char *palavra){
  No *atual = raiz;
  
  for(int i = 0; palavra[i] != '\0'; i++){
    int indice = palavra[i] - 'a'; 

    if(atual->filhos[indice] == NULL)
      return false;

    atual = atual->filhos[indice];
  }
  
  return atual->fim_da_palavra;
}

void liberar_trie(No *raiz){
  if(raiz == NULL)
    return;

  for(int i = 0; i < ALFABETO; i++)
   // liberação de memória dinâmica (espaço reservado para o tipo 'No')
        liberar_trie(raiz->filhos[i]);

  free(raiz);
}
