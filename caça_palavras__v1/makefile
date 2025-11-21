all: main

main: main.o jogo.o avl.o trie.o
	gcc -g -Wall -o main main.o jogo.o avl.o trie.o

main.o: main.c jogo.h avl.h trie.h
	gcc -c main.c

jogo.o: jogo.c avl.h trie.h
	gcc -c jogo.c

trie.o: trie.c trie.h
	gcc -c trie.c

avl.o: avl.c avl.h
	gcc -c avl.c

test: all
	./main

clean:
	rm -f main *.o