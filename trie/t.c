#include "trie.h"
#include "fload.h"

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
  
  No *raiz2 = criar_no();


  // Leitura das palavras do arquivo
  Word* plv=loadWordsFromFile("JCMN.txt");
  if(!plv){
    fprintf(stderr, "Não foi possível ler as palavras.\n");
    return 1;
  }

  for (int i=0; i<200; i++){
    inserir(raiz2, plv->w[i]);
  }
  printf("\nTrie carregada com o arquivo\n");

  if(buscar(raiz2, "tela"))
    printf("Palavra tela encontrada no arquivo!\n");
  else
    printf("Palavra não encontrada.\n");

  liberaWord(plv);
  liberar_trie(raiz);
  liberar_trie(raiz2);

  return 0;
}