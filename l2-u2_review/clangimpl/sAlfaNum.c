#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char l;
    struct No* next;
} No;

typedef struct {
    No* inicio;
} RandomLetter; //nome dado para uso na função a seguir

// Função para criar uma nova lista
RandomLetter createRandomLetter() {
    RandomLetter rl;
    rl.inicio = NULL;
    return rl;
}

// Função para inserir letra na lista
void ins(RandomLetter* rl, char ltr) {
    No* novo_n = (No*)malloc(sizeof(No)); 
  // uso de memória dinâmica para uso de ponteiros
  // indo para um novo 'No' criado a cada letra
    novo_n->l = ltr;
    novo_n->next = NULL;

    if (rl->inicio == NULL) {
        rl->inicio = novo_n;
    } else {
        No* temp = rl->inicio;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = novo_n;
    }
}

void display(RandomLetter* rl) {
    No* temp = rl->inicio;
    while (temp != NULL) {
        printf("%c -> ", temp->l);
        temp = temp->next;
    }
    printf("NULL\n");
}

char* countletter(RandomLetter* listPal) {
    if (listPal->inicio == NULL) {
        return strdup("FAIL");
    }

    // Aloca memória para a string resultante
    char* countingLetter = (char*)malloc(1024); 
    countingLetter[0] = '\0'; // inicia string vazia

    No* temp = listPal->inicio;
    char atChar = temp->l;
    int n = 1;

    temp = temp->next;

    while (temp != NULL) {
        if (temp->l == atChar) {
            n++;
        } else {
            // adiciona letra e número à string
            char buffer[32];
            snprintf(buffer, sizeof(buffer), "%c%d", atChar, n);
            strcat(countingLetter, buffer);

            atChar = temp->l;
            n = 1;
        }
        temp = temp->next;
    }

    // adiciona o último caractere
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%c%d", atChar, n);
    strcat(countingLetter, buffer);

    return countingLetter;
}

// Função para liberar a memória da lista
// acompanha o uso de 'malloc'
void freeList(RandomLetter* rl) {
    No* current = rl->inicio;
    while (current != NULL) {
        No* temp = current;
        current = current->next;
        free(temp);
    }
    rl->inicio = NULL;
}

int main() {
    RandomLetter list = createRandomLetter();
    char pal[100];

    printf("Insira o conjunto de letras:\n");
    scanf("%s", pal);

    for (int i = 0; pal[i] != '\0'; i++) {
        ins(&list, pal[i]);
    }

    display(&list);

    char* res = countletter(&list);

    printf("\nCódigo com base na lista ligada: %s\n", res);

    // Libera memória
    free(res);
    freeList(&list);

    return 0;
}
