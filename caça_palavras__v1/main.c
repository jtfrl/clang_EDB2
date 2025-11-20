#include "avl.h"
#include "trie.h"
#include "jogo.h"
#include <stdbool.h>

int main(){
    printf("#..*#..*#..*#..* CAÇA PALAVRAS *..#*..#*..#*..#\n\n");

    bool rnn=true;
    char op[10];
    int _op=0;

    // variáveis de AVL, trie, e de arquivos
    //TrieNode *trie = NULL;
    char **tab = NULL;
    int n = 0;  // dimensões l x l do quadro de palavras do tabuleiro
    No *raizAVL = NULL;
    char t_arq[100] = ""; // tabuleiro
    char w_arq[100] = ""; // palavras


    // controle de arquivos: tem como objetivo ver se todos os arquivos carrgaram
    bool tab_carr=false;
    bool p_carr=false;



    while(rnn){
          printf("\n\n Selecione uma opção do menu a seguir: \n");
            printf("[1] Indicar arquivo do tabuleiro;\n");
            printf("[2] Executar busca & mostrar palavras;\n[3] Sair\n\n");

            fgets(op, sizeof(op), stdin);
            _op=atoi(op);

            bool uOpt=false;

            if(_op<1||_op>3) perror("Selecione um número válido\n");
            uOpt=true;
        
           
            bool t=false;

            /*
            if (!tab){
                perror("Não foi possível abrir o tabuleiro");
                return 1; // Erro ao ler tabuleiro
                t=true;
            }
                */
            TrieNode *trie = criarNoTrie();
            //carregarPalavras(trie);

            if(uOpt){
            carregarPalavras(trie);
             
                switch(_op){

                    case 1:{
                        printf("Indique o arquivo do tabuleiro: ");                   
                        fgets(t_arq, sizeof(t_arq), stdin);
                        t_arq[strcspn(t_arq, "\n")]=0;

                        dot_load(3);

                        printf("Indique o número da dimensão do tabuleiro: ");
                        char dim[10];
                        fgets(dim, sizeof(dim), stdin);
                        n=atoi(dim);
                                    
                        dot_load(3);
                        tab = lerTabuleiro(&n, t_arq);

                        if(tab) tab_carr=true;

                        break;
                    }

                    case 2:{
                        if(!tab_carr){
                            perror("Caregamento do tabuleiro falhou. Tente novamente com a op. 1\n");
                            break;
                        }

                        dot_load(3);
                         // Buscar palavras no tabuleiro e armazenar em AVL:
                        raizAVL = NULL;
                        buscarPalavras(tab, n, trie, &raizAVL);

                        imprimirResultados(raizAVL);

                        p_carr=true;

                        break;

                    }
                    case 3:{
                        rnn=false;
                        printf("Saindo do programa");
                        for (int i=0; i<3; i++){
                            printf(".");
                            fflush(stdout);
                            sleep(1);
                        }
                        printf("\n\n");
                        break;

                    }
                    default:{
                        break;
                    }
                      
                }

               
            }
    liberarTrie(trie);

    }

   
    if(raizAVL){     
        del_arv(raizAVL);
        raizAVL=NULL;
    }
    if(tab){
    for (int i = 0; i < n; i++) free(tab[i]);
    free(tab);
    tab=NULL;
    }


    return 0;
}