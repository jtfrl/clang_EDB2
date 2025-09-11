/*q. 7 - Lista de Exercıcios - Revisão de C para EDB2 */
#include <stdio.h>

struct Pessoa{
    char nome[50];
    int idade;
    float altura;
};

void insPessoa(struct Pessoa *p){
    printf("Insira o nome: \n");
    scanf("%s", p->nome);
    // '->' acesso de membros de um ponteiro para um 'struct'

    printf("Insira a idade: \n");
    scanf("%d", &p->idade);

    printf("Insira a altura: \n");
    scanf("%f", &p->altura);

}

void showData(struct Pessoa *p){
    printf("\n NOME: %s ", p->nome);
    printf("\n NOME: %i ", p->idade);
    printf("\n NOME: %.2f \n\n", p->altura);
}

int main(){
    struct Pessoa p;

    insPessoa(&p);
    showData(&p);


    return 0;
}