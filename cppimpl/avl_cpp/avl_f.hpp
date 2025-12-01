#ifndef AVL_F
#define AVL_F

#include <iostream>

class Avl{
    int n;
    Avl* esq;
    Avl* dir;
    int altura;
    
    public:
    Avl(){};

    // evitamos cópias temporárias no construtor padrão com '&'
    Avl(int n): n(n), esq(nullptr), dir(nullptr), altura(0){}

    int obter_altura(Avl* no_avl);
    int balanco(Avl* no_avl); // calcula o fator de balanceamento

    // um nó é tomado como eixo; maior vai a direita
    // equilibrando a árbore
    Avl* rotacao_direita(Avl* y);
    Avl* rot_dir_esq(Avl* y);

    // função análoga
    Avl* rotacao_esquerda(Avl* x);
    Avl* rot_esq_dir(Avl* x);

    // inserção e remoção de palavras  
    Avl* inserir_p(Avl* no, int n);
    Avl* remover_p(Avl* raiz, int n);

    Avl* menor_valorNo(Avl* no);

    void print_avl(Avl* raiz);
};


#endif //AVL_F