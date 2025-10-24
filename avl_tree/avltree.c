#include "avl.h"

int main(){
  No* raiz = NULL;

  raiz = inserir_no(raiz, 10);
  raiz = inserir_no(raiz, 20);
  raiz = inserir_no(raiz, 30);
  raiz = inserir_no(raiz, 40);
  raiz = inserir_no(raiz, 50);
  raiz = inserir_no(raiz, 25);

  printf("Árvore AVL em ordem: ");
  imprimir_em_ordem(raiz);
  printf("\n");

  raiz = remover_no(raiz, 40);

  printf("Árvore AVL após remoção: ");
  imprimir_em_ordem(raiz);
  printf("\n");

  return 0;
}