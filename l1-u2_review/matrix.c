/*q. 4 - Lista de Exerc ́ıcios - Revisão de C para EDB2 */
#include <stdio.h>

void readVal(int mint[][3]){ //a última das dimensões deve ser indicada
    int n=0; 

    for(int k=0; k<3; k++){
        for(int j=0; j<3; j++){
            printf("Insira o valor da posição (%d,%d): ", (k+1), (j+1));
            scanf("%d", &n);
            printf("\n");
            mint[k][j]=n;
        }
    }

}

int suMatrix(int mint[][3]){
    int soma=0;
    for(int i=0; i<3; i++){
        soma=soma+(mint[i][i]);
    }

    printf("Soma dos valores da diagonal: %d\n", soma);

    return soma;
}

int main(){
    int mInt[3][3]={};

    readVal(mInt);
    suMatrix(mInt);


    return 0;
}