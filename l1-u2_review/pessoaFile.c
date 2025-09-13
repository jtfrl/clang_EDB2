/*q. 9 - Lista de Exercıcios - Revisão de C para EDB2 */
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
    const char* fname="/workspaces/EDB2_imd0039-res/l1-u2_revClang/dados_1.txt";

    FILE* abrir=fopen(fname, "w+");

    verOpenFile(abrir);

    int c; //usado para percorrer o arquivo

    while((c=fgetc(abrir))!=EOF) putchar(c);

    //verifica se houve erro na leitura
    if(ferror(abrir))
        puts("ERRO DE I/O NA LEITURA");
    else if(feof(abrir)){
        puts("\nFim do arquivo atingido com sucesso!");
 
    }

    fclose(abrir);
    remove(fname); //arquivo removido depois da leitura

    return 0;

}
