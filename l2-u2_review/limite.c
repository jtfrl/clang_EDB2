/*q. 1 - Lista de Exercıcios 2 - Revisão de C para EDB2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool isVogal(char p){
    bool check=false;
  
    if(p=='A' || p=='E' || p=='I' ||
    p=='O' || p=='U'){
        check=true;
    }

    return check;
}

char* upperChar(char pal[]){
    int tam=strlen(pal);
    for(int k=0;k<tam;k++) pal[k]=toupper(pal[k]);
    return pal;
}

int countC(char pal[], char l){
    int tam=0;
    int count=0;

    //converte para maisculo
    upperChar(pal);
    l=toupper(l);
    tam=strlen(pal);

    if(*pal=='\0') return 0; 

    char at=pal[count];

    // 'pal+1' abaixo permite avançar com base 
    // no índice de cada posição das letras da string

    if(!isVogal(at) && at>l && at>='A' && at<='Z') return 1+countC(pal+1, l);

    return count+countC(pal+1,l);
}

/*
f alternativa de conversão para caixa alta 
void convertCase(char* p[]){
    char convert_pal[50];
    int i=0;
    while(p[i]!='\0'){ //até o último caractere
        p[i]=p[i]-32;
        i++;
    }
}
*/

int main(){
    char c;
    char palavra[100];

    scanf("%c", &c);//toma a letra limite 
    getchar(); //consome nova linha

    fgets(palavra, 100, stdin);
    palavra[strcspn(palavra, "\n")]='\0'; //consome nova linha para palavra
    
    int valorCnst=countC(palavra, c);
    char novo_c=toupper(c);
    printf("\nSão %d consoantes depois do caractere '%c'", valorCnst, novo_c);
    printf("\n\n");

    return 0;
}