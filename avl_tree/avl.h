#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  int dado;
  struct No* esquerdo;
  struct No* direito;
  int altura;
}No;

int obter_altura(No* no);
int balanco(No* no); // calcula o fator de balanceamento
No* criar_no(int dado);

 // um nó é tomado como eixo; maior vai a direita
 // equilibrando a árbore
No* rotacao_direita(No* y);

// função análoga
No* rotacao_esquerda(No* x);
No* inserir_no(No* no, int dado);

No* menor_valorNo(No* no);
No* remover_no(No* raiz, int dado);

void imprimir_em_ordem(No* raiz);

