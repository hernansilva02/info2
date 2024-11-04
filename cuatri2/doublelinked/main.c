#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int valor;
    struct node_t* next;
    struct node_t* prev;
}node_t;

void prepend(node_t** head, int valor) {
    node_t* nuevoNodo = malloc(sizeof(node_t));
    nuevoNodo->valor = valor;
    nuevoNodo->prev = NULL;

    if (nuevoNodo == NULL) {
        printf("No se pudo crear espacio en memoria para el nodo de prepend\n");
        return;
    }

    if (*head == NULL) {
        *head = nuevoNodo;
        return;
    }
    
    nuevoNodo->next = *head;
    (*head)->prev = nuevoNodo;
    *head = nuevoNodo;

}

void insertAt(node_t** head, int idx, int valor) {
    node_t* nuevoNodo = malloc(sizeof(node_t));
    nuevoNodo->valor = valor;

    if (idx == 0) {
        prepend(head, valor);
        return;
    }
    
    node_t* temp = *head;
    for (int i = 0; temp && i < idx; i++) {
        temp = temp->next;
    }

    nuevoNodo->next = temp;
    nuevoNodo->prev = temp->prev;
    temp->prev->next = nuevoNodo;
    temp->prev = nuevoNodo;
}

void removeNode(node_t** head, node_t** tail, int valor) {
    node_t* temp = *head;
    while (temp->valor != valor && temp != NULL) {
        temp = temp->next; 
    }

    if (temp == NULL) {
        printf("No hay nodo con ese valor para eliminar\n");
        return;
    }

    if (temp->prev == NULL) {
        *head = (*head)->next;
        free(temp);
        return;
    }

    if (temp->next == NULL) {
        *tail = temp->prev;
        free(temp);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    return;
}

void removeAt(node_t** head, node_t** tail, int idx) {
    node_t* temp = *head;

    for (int i = 0; i < idx; i++) {
        if (temp == NULL) {
            printf("No hay nada en la posicion %d", idx);
            return;
        }
        temp = temp->next;    
    }

    if (temp->prev == NULL) {
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    if (temp->next == NULL) {
        *tail = (*tail)->prev;
        free(temp);
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void append(node_t** tail, node_t** head, int valor) {
    node_t* nuevoNodo = malloc(sizeof(node_t));
    nuevoNodo->valor = valor;
    nuevoNodo->next = NULL;

    if (*tail == NULL) {
        *tail = *head = nuevoNodo;
        return;
    }

    (*tail)->next = nuevoNodo;
    nuevoNodo->prev = *tail;
    *tail = nuevoNodo;
}

void getAt(node_t** head, int idx) {
    node_t* temp = *head;
    for (int i = 0; temp && i < idx; i++) {
        temp = temp->next;
    }

    printf("El valor del nodo en el indice %d es: %d", idx, temp->valor);
    return;
}

void printList(node_t** head) {
    node_t* temp = *head;

    while (temp != NULL) {
        printf("El valor es: %d\n", temp->valor);
        temp = temp->next;
    }
}


int main(void) {
    node_t* tail = NULL;
    node_t* head = NULL;

    append(&tail, &head, 3);
    append(&tail, &head, 9);
    append(&tail, &head, 12);
    append(&tail, &head, 30);

    printf("la lista hecha hasta ahora solo con los append es: \n");
    printList(&head);

    insertAt(&head, 2, 10);
    printf("la lista con el elemento insertado en la pos 2 es: \n");
    printList(&head);

    printf("la lista con el prepend queda: \n");
    prepend(&head, 1);
    printList(&head);
    printf("\n\n------------------------------------------");

    printf("La lista con el elemento insertado al principio es: \n");
    insertAt(&head, 0, 100);
    printList(&head);

    printf("\n\n------------------------------------------La lista con el elemento 12 borrado es:\n");
    removeAt(&head, &tail, 5);
    printList(&head);
}
