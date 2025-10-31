#ifndef FLOAD
#define FLOAD

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

typedef struct{
    char **w; // array de strings: palavras
    int count;
    int cap; // capacidade
}Word;

bool checkOpenFile(FILE* arqTxt);
FILE* openFile(const char *fileAdd);
void readFile(FILE* aTxt);
void closeFile(FILE* f);

// inicialização e leitura de arquivo
void initWord(Word* v, int cap_inicial);
Word* criaWord();
void addWord(Word* v, const char* word); // adiciona palavras em 'Word'
void liberaWord(Word* v);
Word* leTXT(const char* file, int indexCol);
Word* loadWordsFromFile(const char* filename);



#endif //FLOAD