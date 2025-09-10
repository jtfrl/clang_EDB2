/*q. 3 - Lista de Exercıcios - Revisão de C para EDB2 */
#include <stdio.h>

void readVal(int* vint[]){
    int v=0;

    for(int i=0; i<5;i++){
         printf("Insira os valores do vetor na posição %d \n", (i+1));
         scanf("%d", v);
         vint[i]=v;
    }

    //return vint[];

}

int sumVect(int* vint[]){

    int soma=0;

    return soma;
}

int main(){
    int vInt[5]={};



    return 0;
}