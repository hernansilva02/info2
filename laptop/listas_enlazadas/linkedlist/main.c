#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int valor;
    struct nodo* next;
} nodo;


nodo* crear_nodo(int valor) {
    nodo* temp = malloc(sizeof(nodo));
    temp->valor = valor;
    temp->next = NULL;
    return temp;
}

void imprimir_lista(nodo* head) {
    while (head != NULL) {
        printf("%d - ", head->valor);
        head = head->next;
    }
    printf("\n");
}

int main(void) {
    nodo* head;
    nodo* tail;
    
    for (int i = 0; i < 25; i++) {
        nodo* tmp = crear_nodo(i);
        if (head == NULL) {
            head = &tmp;
        } else {
            head->next = &tmp;
        }
    }
    imprimir_lista(head);
}
