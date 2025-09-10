/*q. 1 - Lista de Exerc ́ıcios - Revisão de C para EDB2 */
#include <stdio.h>

void trocaVal(int a, int b){
    int val1=0;
    int val2=0;
    val1=a;
    val2=b;
    a=val2;
    b=val1;

    printf("variável 1: %d\n",a);
    printf("variável 2: %d\n",b);
}

int main(){
    int x=0;
    int y=0;
    scanf("%d", &x);
    scanf("%d", &y);

    printf("Valores antes da troca: %d | %d \n", x,y);
    
    printf("Valores depois da troca: \n");
    trocaVal(x,y);
  
    return 0;
}