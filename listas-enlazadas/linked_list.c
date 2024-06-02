#include <stdlib.h>
#include <stdio.h>

typedef struct nodo{
    int valor;
    struct nodo *next;
}nodo;

nodo crear_nodo(int valor) {
    nodo n;
    n.valor = valor;
    n.next = NULL;
    return n;
}

void imprimir_lista(nodo *head) {
    while (head != NULL) {
        printf("%d-", head->valor);
        head = head->next;
    }
    printf("\n");
}

int main(void) {

    nodo *head;

    nodo tmp = crear_nodo(8);
    *head = tmp;
    tmp = crear_nodo(32);
    head->next = &tmp;

    imprimir_lista(head);
}
