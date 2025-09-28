#ifndef ARVN
#define ARVN

#include <iostream>
#include <string>


//arvn é nó; ArvN é uma árvore composta de nós desse struct

struct arvn{
    std::string info;
    arvn* head;
    arvn* prox;

    arvn(std::string i): info(i), prox(nullptr), head(nullptr){}
};

class ArvN{
    arvn* head;
    
    public:
    ArvN(){};
    ArvN(std::string info): head(nullptr){}

    void ins(ArvN a, std::string l);
    void print(arvn* a);
    bool inArv(arvn* a, std::string l);

};


void ArvN::ins(ArvN a, std::string l){
    arvn* nova_arv=new arvn(l); //sub-árvore

    if(head==nullptr){
        head=nova_arv;
    }else{
        arvn* temp=head;
        while(temp->prox!=nullptr){
            temp=temp->prox;
        }
        temp->prox=nova_arv;
    }

}

void ArvN::print(arvn* a){
    arvn* temp=a->head;
    if(a==nullptr) return;
    std::cout<<"<"<<a->info;
    /*
    for(temp=a->head;temp->info!=nullptr;temp=a->prox){
        print(temp);
    }
        */

    while(temp!=nullptr){
        print(temp);
    }
     printf(">");  
}

bool ArvN::inArv(arvn* a, std::string l){
    arvn* temp;
    if(a->info==l) return true;
    else{
        for(temp=a->head;temp!=nullptr;temp=temp->prox){
        if(inArv(temp,l)) return true;
        }
        return false;
    }


}



#endif //ARVN