#ifndef ARVN
#define ARVN

#include <iostream>
#include <string>


//arvn é nó; ArvN é uma árvore composta de nós desse struct

class ArvN{
    std::string info;
    ArvN* head;
    ArvN* prox;
    
    public:
    ArvN(){};
    ArvN(std::string info): info(info), head(nullptr), prox(nullptr){}

    void ins(ArvN* sa);
    void printree(ArvN* a);
    bool inArv(ArvN* a, std::string l);

};


void ArvN::ins(ArvN* sa){
    sa->prox=this->head;
    this->head=sa;
}
    

void ArvN::printree(ArvN* a){
    if(a==nullptr) return;
    
    std::cout<<"<"<<a->info;
     ArvN* temp=a->head;
    while(temp!=nullptr){
        printree(temp);
        temp=temp->prox; //vai ao próximo nó
    }
     printf(">");  
}

bool ArvN::inArv(ArvN* a, std::string l){
    ArvN* temp;
    if(a->info==l) return true;
    else{
        for(temp=a->head;temp!=nullptr;temp=temp->prox){
        if(inArv(temp,l)) return true;
        }
        return false;
    }


}



#endif //ARVN