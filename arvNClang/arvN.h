
#ifndef ARVN
#define ARVN

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct arvvar{
         char info;
         struct arvvar *head;
         struct arvvar *prox;
 }ArvVar;
       
// typedef struct arvvar ArvVar;

//construtor
ArvVar *arvv_cria(char c);

void arvv_insere(ArvVar *a, ArvVar *sa);
void arvv_imprime(ArvVar *a);
bool arvv_pertence(ArvVar *a, char c);

//libera pelo uso de malloc
void arvv_liber(ArvVar *a);











#endif //ARVN