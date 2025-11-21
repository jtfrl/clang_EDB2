#ifndef JOGO_h
#define JOGO_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
// FUNCIONAMENTO PARA AMBOS OS SOs:
#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(seconds) Sleep(seconds * 1000)
#else
    #include <unistd.h>
    #define SLEEP(seconds) sleep(seconds)
#endif

#include "trie.h"
#include "avl.h"

char **lerTabuleiro(int *n, char* nome_arq);
void carregarPalavras(TrieNode *raiz, char* nome_arq);
void buscarAPartirDe(int x, int y, char **tab, int n, TrieNode *trie, No **raizAVL);
void buscarPalavras(char **tab, int n,TrieNode *trie, No **raizAVL);
void imprimirResultados(No *raizAVL);

// mostra os pontos ""...""
void dot_load(int s, int op);
#endif //JOGO_h