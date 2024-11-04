#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct nodo_t {
    char componente[30];
    struct nodo_t* next;
}nodo_t;

#endif
