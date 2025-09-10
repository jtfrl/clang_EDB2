/*q. 2 - Lista de Exerc ́ıcios - Revisão de C para EDB2 */
#include <stdio.h>

void trocaRVal(int* a, int* b){

    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int x=0;
    int y=0;
    scanf("%d", &x);
    scanf("%d", &y);

    printf("Valores antes da troca: %d | %d \n", x,y);
    trocaRVal(&x,&y); //endereço de memória sempre deve ser indicado
    printf("Valores depois da troca: %d | %d \n", x,y);
 
  
    return 0;

}