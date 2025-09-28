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


	ins(c, d);
	ins(b, e);
	ins(b, c);
	
	ins(i, j);
	ins(g, i);
	ins(g, h);
	
	ins(a1, g);
	ins(a1, f);
	ins(a1, b);
	
	print(a1);
	std::cout<<std::endl;
	
	return 0;
}
