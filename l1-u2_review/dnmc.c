/*q. 6 - Lista de Exercıcios - Revisão de C para EDB2 */
#include <stdio.h>
#include <stdlib.h>

void readVal(int* v){
    int n=0;

    for(int i=0; i<5;i++){
         printf("Insira os valores do vetor na posição %d \n", (i+1));
         scanf("%d", &n);
         printf("\n");
         v[i]=n;
    }

}



int somaVal(int v[]){
    int s=0;

    for(int i=0; i<5; i++){
        s=s+v[i];
    }

     printf("Soma dos valores do vetor: %d \n", s);

    return s;
}

int main(){

    //int val=0;
    int *mVal=malloc(sizeof(int[5]));

    readVal(mVal);
    somaVal(mVal);
    free(mVal);
    return 0;
}