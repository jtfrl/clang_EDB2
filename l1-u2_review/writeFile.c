/*q. 10 - Lista de Exercıcios - Revisão de C para EDB2 */

#include <stdio.h>
#include <stdlib.h>


int verOpenFile(FILE* a){
    int isok=EXIT_FAILURE;
    if(!a){
        perror("Abertura do arquivo falhou\n");
        return isok;
    }
}


int main(){
    const char* fname="/workspaces/EDB2_imd0039-res/l1-u2_revClang/dados_2.txt";
 
     FILE* filWr=fopen(fname, "w+");

     verOpenFile(filWr);

     fputs("DADOS: \n NOME: Alberto \nIDADE: 35 \nALTURA: 1.65\n\n", filWr);
     rewind(filWr);


    /*##### FLUXO PARA IMPRMIR O ARQUIVO ####*/ 
    int c; //usado para percorrer o arquivo

    while((c=fgetc(filWr))!=EOF) putchar(c);


    if(ferror(filWr))
        puts("\nErro de I/O na leitura\n");
    else if(feof(filWr)){
        puts("\nFim do arquivo atingido com sucesso!");
    }

    fclose(filWr);
    //remove(filWr);

    return 0;

}
