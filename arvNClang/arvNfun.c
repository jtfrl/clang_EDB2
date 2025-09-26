#include "arvN.h"

       
// typedef struct arvvar ArvVar;

//construtor
ArvVar *arvv_cria(char c){
    ArvVar *a = (ArvVar *) malloc(sizeof(ArvVar));
    a->info = c;
    a->head = NULL;
    a->prox = NULL;
    return a;
}

void arvv_insere(ArvVar *a, ArvVar *sa){
    sa->prox=a->head;
    a->head=sa;
}


 void arvv_imprime(ArvVar *a){
    ArvVar *p;
    //int count=0;
    
    //printf("<%c\n", a->info);
        printf("<%c", a->info);

    for(p=a->head; p!=NULL; p=p->prox){
        arvv_imprime(p);  // Imprime cada subárvore filha.
        //count++; //tentativa de pular linha
    }
    printf(">");


}


bool arvv_pertence(ArvVar *a, char c) {
        ArvVar *p;
        if(a->info == c)
            return true;
            else{
                for(p=a->head; p!=NULL; p=p->prox){
                    if(arvv_pertence(p,c)){
                    return true;
                    }
                return false;
        }
}
}

void arvv_libera(ArvVar *a) {
        ArvVar *p = a->head; //auxiliar
            while(p != NULL){
                 ArvVar *t = p->prox; //2o. auxiliar
                arvv_libera(p);
                p = t;
            }
            free(a);
}

