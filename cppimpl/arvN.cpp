#include "arvN.hpp"

int main(){
	ArvN a1("a");
	ArvN a2("a");
	ArvN a3("x");
	
	ArvN b("b");
	ArvN c("c");
	ArvN d("d");
	ArvN e("e");
	ArvN f("f");
	ArvN g("g");
	ArvN h("h");
	ArvN i("i");
	ArvN j("j");
	
		c.ins(&d);
		b.ins(&e);
		b.ins(&c);
		
		i.ins(&j);
		g.ins(&i);
		g.ins(&h);
		
		a1.ins(&g);
		a1.ins(&f);
		a1.ins(&b); //usa o endereço de memória do no
	
	a1.printree(&a1);
	std::cout<<std::endl;
	
	return 0;
}
