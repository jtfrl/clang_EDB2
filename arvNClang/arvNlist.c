#include "arvN.h"

int main(){
    ArvVar *a1 = arvv_cria('a');
    ArvVar *a2 = arvv_cria('a');
    ArvVar *a3 = arvv_cria('x');

    ArvVar *b = arvv_cria('b');
    ArvVar *c = arvv_cria('c');
    ArvVar *d = arvv_cria('d');
    ArvVar *e = arvv_cria('e');
    ArvVar *f = arvv_cria('f');
    ArvVar *g = arvv_cria('g');
    ArvVar *h = arvv_cria('h');
    ArvVar *i = arvv_cria('i');
    ArvVar *j = arvv_cria('j');


    /*# item (a)*/
    //esq.
    arvv_insere(c, d);
    arvv_insere(b, e);
    arvv_insere(b, c);
   
    //direita
    arvv_insere(i, j);
    arvv_insere(g, i);
    arvv_insere(g, h);
    
    //raiz
     arvv_insere(a1, g);
        arvv_insere(a1, f);
            arvv_insere(a1, b);
           
    arvv_imprime(a1);
    printf("\n");


    //-----------------
    ArvVar *b2 = arvv_cria('b');
    ArvVar *c2 = arvv_cria('c');
    ArvVar *d2 = arvv_cria('d');
    ArvVar *e2 = arvv_cria('e');
    ArvVar *f2 = arvv_cria('f');
    ArvVar *g2 = arvv_cria('g');
    ArvVar *h2 = arvv_cria('h');

    /*# item (b)*/
    //esq.
    arvv_insere(b2, d2);
    arvv_insere(b2,c2);

    //direita
    arvv_insere(e2,f2);
    arvv_insere(f2,g2);

    arvv_insere(a2,h2);
    arvv_insere(a2,e2);
    arvv_insere(a2,b2);

    arvv_imprime(a2);
    printf("\n");

    //-----------------
    /*# item (c)*/
    ArvVar *y=arvv_cria('y');
    ArvVar *z=arvv_cria('z');
    ArvVar *w=arvv_cria('w');
    ArvVar *p=arvv_cria('p');
    ArvVar *q=arvv_cria('q');
    ArvVar *s=arvv_cria('s');
    ArvVar *r=arvv_cria('r');

    arvv_insere(w, q);
    arvv_insere(w, p);

    arvv_insere(y, w);
    arvv_insere(y,z);

    arvv_insere(r,s);

    arvv_insere(a3,r);
    arvv_insere(a3, y);
    
    arvv_imprime(a3);
    printf("\n");

    return 0;
}