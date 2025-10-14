#include "abbSys.h"
#include "heap.h"
#include "fileLoad.h"

int main(){
    printf("\n\n######### BIB - SISTEMA DE GESTÃO & VENDAS DE LIVROS #########\n\n");
     // Carregamento do arquivo .csv é automático, já que 
    // ele é o arquivo principal do programa
    FILE* csv_file=openFile("arqs_csv/categorias.csv");
    readFile(csv_file); //executa a leitura
    bool rnn=true; //controla o laço do menu
    char op[10];
    int _op=0;

    if(checkOpenFile(csv_file)){ //controle por precaução
        // leitura e alimentação de CatVector com as categorias do .csv
        CatVector* catCSVfile=leCSV_Cat("arqs_csv/categorias.csv", 1);
        HeapMax* heapCategoria=NULL;

        while(rnn){
            printf("\n\n Selecione uma opção do menu a seguir: \n");
            printf("[1] Listar categorias e selecionar;\n[2] Mostrar o livro mais vendido da categoria;\n");
            printf("[3] Mostrar os mais vendidos;\n[4] Registrar venda; \n[5] Sair\n\n");

            fgets(op, sizeof(op), stdin);

            _op=atoi(op);

            bool uOpt=false;


            if(_op<1||_op>5) perror("Selecione um número válido\n");
            uOpt=true;
            
            if(uOpt){
                char* catSelect=NULL;
                switch(_op){
                    case 1:{
                        //if(catSelect) free(catSelect); // -- liberação (memória dinâmica em processaCat)

                        catSelect=processarCat("arqs_csv/categorias.csv", 1);
                        if(catSelect!=NULL){
                            heapCategoria=processaLivro(catSelect, 6);
                        }else{
                            perror("Categoria não selecionada corretamente. Tente novamente\n");
                        }
                        break;
                    }
                    case 2:{
                        if(!heapCategoria){
                            printf("Não foram carregadas categorias\n.");
                            break;
                        }
                        mostraPrimeiroMaisVendido(heapCategoria);
                        break;
                    }
                    case 3:{ 
                        if(!heapCategoria){
                            printf("Não foram carregadas categorias\n.");
                            break; 
                        }

                        int num=0;
                        printf("Indique o número de livros: \n");
                        scanf("%d", &num);
                        while(getchar()!='\n'); //limpa o buffer de caracteres
                        imprimirTopN(heapCategoria, num);
                        
                        break;
                    }
                    case 4:{
                        if(!heapCategoria){
                            printf("Não foram carregadas categorias\n.");
                            break;
                        }
                        char val[10];
                        int _val=0; // Código do ISBN informado
                        printf("\nInsira ISBN do livro para a venda\n");
                        fgets(val, sizeof(val), stdin);
                        _val=atoi(val);

                        Livro* livrovendido=buscaISBN(heapCategoria, _val);

                        if(livrovendido){
                            char qtd[10];
                            int _qtd=0;
                            printf("\n\nInsira a quantidade de livros desejada\n");
                            fgets(qtd, sizeof(qtd), stdin);

                            _qtd=atoi(qtd);
                            updateHeap(heapCategoria, _val, _qtd);

                            printf("\n\nLivro vendido! \n\n| TÍTULO: %s |\t AUTOR: %s ", 
                                livrovendido->titulo, livrovendido->autor);
                        }
                        break;
                    }
                    case 5:{
                        rnn=false;
                        printf("Saindo do programa...\n");
                        break;
                    }
                    default:{
                        break;
                    }
                }
            }
        }
        liberaCat(catCSVfile);
        if(heapCategoria) liberarHeap(heapCategoria);
        closeFile(csv_file);
    }
    return 0;
}