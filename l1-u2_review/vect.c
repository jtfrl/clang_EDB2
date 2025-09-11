/*q. 3 - Lista de Exercıcios - Revisão de C para EDB2 */
#include <stdio.h>

void readVal(int* v){
    int n=0;

    for(int i=0; i<5;i++){
         printf("Insira os valores do vetor na posição %d \n", (i+1));
         scanf("%d", &n);
         printf("\n");
         v[i]=n;
    }
}

int sumVect(int vint[]){
    int soma=0;
    for(int j=0; j<5; j++){
        soma=soma+vint[j];
    }
    printf("Soma dos valores do vetor: %d \n", soma);

    return soma;
}

int main(){
    int vInt[5]={};

    readVal(vInt);
    sumVect(vInt);

    return 0;
}