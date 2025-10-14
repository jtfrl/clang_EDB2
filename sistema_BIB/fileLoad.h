#ifndef FILE_LOAD
#define FILE_LOAD

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


#define MAX_CAT 1000
#define MAX_CAT_NAME 15


typedef struct{
    char **cat; // array de strings
    int count;
    int cap; // capacidade
}CatVector;

bool checkOpenFile(FILE* arqCsv);
FILE* openFile(const char *fileAdd);
void readFile(FILE* dataCsv);
void closeFile(FILE* f);
void initCatVector(CatVector* v, int cap_inicial);
CatVector* criaVtCat();
void addCat(CatVector* v, const char* nome_cat);
void liberaCat(CatVector* v);
CatVector* leCSV_Cat(const char* file, int indexCol);

#endif //FILE_LOAD