#include "fload.h"

bool checkOpenFile(FILE* arqTXT){
    if(!arqTXT){
        perror("Abertura de arquivo falhou!");
        return false;
    }
    return true;
}

FILE* openFile(const char *fileAdd){
    FILE* abrir=fopen(fileAdd, "r");
    if(!checkOpenFile(abrir)) return NULL; // checa o .csv
    return abrir;
}

void readFile(FILE* aTxt){
    if(!aTxt) return;
    int c; 

    while((c=fgetc(aTxt))!=EOF) putchar(c);

    if(ferror(aTxt)) puts("ERRO DE LEITURA");
    // se não há erro, leitura concluída com sucesso
}

void closeFile(FILE* f){
    if(f) fclose(f);
}

// ##### INICIALIZAÇÃO DO STRUCT COM AS PALAVRAS #####pragma endregion

void initWord(Word *v, int cap_inicial){
    v->w=(char**)malloc(sizeof(char*)*cap_inicial);
    v->count=0;
    v->cap=cap_inicial;
}

Word* criaWord(){
    Word* v=(Word*)malloc(sizeof(Word)); 
    if(!v) return NULL;

    initWord(v, 100);

    return v;
}

void addWord(Word* v, const char* word){
    if(v->count>=v->cap){
        v->cap*=2; // atualização de tamanho para utilizar alocação abaixo
        v->w=(char**)realloc(v->w, sizeof(char*)*v->cap);
    }
    // aloca espaço para os caracteres da string + 1 (\0)
    v->w[v->count]=(char*)malloc(strlen(word)+1); 
    strcpy(v->w[v->count], word);// cada palavra é colocada
    v->count++;
}

void liberaWord(Word* v){
    if(!v) return;

    for (int i=0; i<v->count; i++) free(v->w[i]);
    free(v->w);
    free(v);
}


// *** LEITURA DAS PALAVRAS NO .TXT ***
// aqui pontuação e números são tratados como delimitadores
Word* loadWordsFromFile(const char* filename){

    char wordBuffer[MAX_LEN];
    int char_index=0;
    int c;

    Word* palavras=criaWord();
    if(!palavras) return NULL;

    FILE* arq=openFile(filename);
    if(!arq){
        liberaWord(palavras);
        return NULL;
    }

    // leitura caractare a caractere
    while((c=fgetc(arq))!=EOF){
        if(isalpha(c)){ // se alfabético...
            if(char_index<MAX_LEN-1){
                wordBuffer[char_index++]=tolower(c);
                // é adcionado
            }
            
        } // cadeia de truncamento (palavras com mais de 100 caracteres)
        else if(char_index>0){
            wordBuffer[char_index]='\0'; // finalizamos a string
            addWord(palavras, wordBuffer);
            char_index=0; // reiniciamos o index
        }

    }

    // adiciona a última palavra
    // caso o arquivo não tenha quebra de linha
    if(char_index>0){
        wordBuffer[char_index]='\0';
        addWord(palavras, wordBuffer);
    }

    closeFile(arq);
    return palavras;

}
