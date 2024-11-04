#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int valor;
    struct node_t* next;
}node_t;

void enqueue(int valor, node_t** tail, node_t** head) {
    node_t* nuevoNodo = malloc(sizeof(node_t));
    if (nuevoNodo == NULL) {
        printf("hubo un error al asignar nuevo espacio de memoria\n");
        return;
    }
    nuevoNodo->valor = valor;
    nuevoNodo->next = NULL;
    if (*tail == NULL) {
        *tail = *head = nuevoNodo; 
    }
}

void deque(node_t** head) {
    if (*head == NULL) {
        printf("No hay ninguna fila para hacer un deque\n");
        return;
    } 
    node_t* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void peek(node_t* head) {
    printf("el primer valor de la fila es: %d\n", head->valor);
}

void printQue(node_t* head) {
    while (head != NULL) {
        printf("%d\n", head->valor);
        head = head->next;
    }
    return;
}

int main(void) {
    node_t* head = NULL;
    node_t* tail = NULL;
    enqueue(2, &tail, &head);
    enqueue(3, &tail, &head);
    enqueue(5, &tail, &head);
    enqueue(29, &tail, &head);
    enqueue(55, &tail, &head);
    printQue(head);
    printf("Ahora vamos a dequear\n");
    deque(&head);
    deque(&head);
    printQue(head);
}
