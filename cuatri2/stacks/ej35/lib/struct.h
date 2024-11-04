#ifndef LIB_H
#define LIB_H
typedef struct {
    char nombre[10];
    char apellido[10];
    int edad;
    char telefono[10];
    char mail[25];
} persona_t;

typedef struct node_t{
    persona_t x;
    struct node_t* previo;
}node_t;

#endif
