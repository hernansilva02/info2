#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int valor;
    struct node_t* next;
    struct node_t* prev;
} node_t;

int main(void){
    node_t* arrayList = malloc(10 * sizeof(node_t));

    arrayList[10].valor = 10;
}
