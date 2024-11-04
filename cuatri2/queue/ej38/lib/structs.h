#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct {
    char nombre[15];
    char apellido[15];
    int edad;
    char telefono[15];
    char mail[30];
}persona_t;

typedef struct node_t {
    persona_t persona;
    struct node_t* next;
}node_t;
#endif
