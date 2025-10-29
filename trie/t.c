#include "trie.h"

int main(void){
  No *raiz = criar_no();

  const char *palavras1[] = {"casa","carro","casaco","cadeira","sapato"};
  const char *palavras2[] = {"casa","carro","casaco","cadeira","sapato","casco","nuvem","prato"};

  for(int i=0; i<5; i++)
   inserir(raiz, palavras1[i]);
  
  for(int i=0; i<8; i++)
    if(buscar(raiz, palavras2[i]))
      printf("A palavra %s está na Trie.\n", palavras2[i]);
    else
      printf("A palavra %s não está na Trie.\n", palavras2[i]);
    
  liberar_trie(raiz);

  return 0;
}