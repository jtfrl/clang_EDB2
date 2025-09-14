//q.2 - LISTA 2 - Revisão (EDB2)

#include <iostream>
#include <vector>
#include <string>

struct No{
    char l; //cada uma das letras
    No* next;

    No(char letra): l(letra), next(nullptr){}
    // nullptr: 
    // ponteiro nulo para as implementações de ligação entre nos
};

class RandomLetter{
    //std::vector<char> s;
    No* inicio;

    public:
    RandomLetter(): inicio(nullptr){}

    void ins(char ltr);
    void display();
    std::string countletter(RandomLetter lisPal);

};

void RandomLetter::ins(char ltr){
    No* novo_n=new No(ltr);
    if(inicio==nullptr){
        inicio=novo_n;
    }else{
        No* temp=inicio;
        while(temp->next!=nullptr){
            temp=temp->next; //em java 'No temp=temp.next;'
        }
        temp->next=novo_n;
    }
}

void RandomLetter::display() {
    No* temp = inicio;
    while (temp != nullptr) {
        std::cout<<temp->l<<" -> ";
        temp = temp->next;
    }
    std::cout<<"nullptr"<<std::endl; // fim da lista
}


std::string RandomLetter::countletter(RandomLetter listPal){
    std::string countingLetter="";
    if(listPal.inicio==nullptr)  return "FAIL";

        No* temp=listPal.inicio;
        char atChar=temp->l;
        int n=1;

        temp=temp->next;

        while(temp!=nullptr){
            if(temp->l==atChar){ // '->' é acesso de ponteiro de atributo
                n++; // soma a quantidade de repetições
            }
                else{
                // quando a contagem finaliza
                // adiciona os caracteres
                countingLetter+=atChar;
                countingLetter+=std::to_string(n);
                
                // move para a nova letra
                    atChar=temp->l;
                    n=1;
                }
                 temp=temp->next;
        }

        // finalização: adiciona os últimos caracteres
        countingLetter+=atChar;
        countingLetter+=std::to_string(n);

    return countingLetter;
}

int main(){

    RandomLetter list;
    std::string pal;

    std::cout<<"Insira o conjunto de letras: "<<std::endl;
    std::cin>>pal;
    std::cout<<std::endl;

    for(char l:pal){
        list.ins(l);
    }

    list.display();
    std::cout<<std::endl;
    std::string res=list.countletter(list);

    std::cout<<"\nCódigo com base na lista ligada: "<<res<<std::endl;

    return 0;
}
