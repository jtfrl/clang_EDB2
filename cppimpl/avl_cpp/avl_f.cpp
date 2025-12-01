#include "avl_f.hpp"

int Avl::obter_altura(Avl* no_avl){
    if(no_avl==nullptr) return -1;
    else return no_avl->altura;
}


int Avl::balanco(Avl* no){
    if(no==nullptr) return 0;
    else return obter_altura(no->esq) - obter_altura(no->dir);
}


Avl* Avl::rotacao_direita(Avl* y){
    Avl* x=y->esq;
    Avl* z=x->dir;

    x->dir=y; // torna-se raiz: y
    y->esq=z; // z antes era raiz, agora será um nó a esq

    if(obter_altura(y->esq)>obter_altura(y->dir))
        y->altura=1+obter_altura(y->esq);
    else
        y->altura=1+obter_altura(y->dir);

    
    if(obter_altura(x->esq)>obter_altura(x->dir))
        x->altura=1+obter_altura(x->esq);
    else
        x->altura=1+obter_altura(x->dir);

    return x;

}

Avl* Avl::rotacao_esquerda(Avl* x){
     Avl* y=x->dir;
     Avl* z=y->esq;

     y->esq=x;
     x->dir=z;

    if(obter_altura(x->esq)>obter_altura(x->dir))
        x->altura=1+obter_altura(x->esq);
    else
        x->altura=1+obter_altura(x->dir);
    if(obter_altura(y->esq)>obter_altura(y->dir))
        y->altura=1+obter_altura(y->esq);
    else
        y->altura=1+obter_altura(y->dir);

    return y;
}

Avl* Avl::rot_esq_dir(Avl* y){
    y->dir=rotacao_direita(y->dir);
    return rotacao_esquerda(y);
}

Avl* Avl::rot_dir_esq(Avl* x){
    x->esq=rotacao_esquerda(x->esq);
    return rotacao_direita(x);
}
