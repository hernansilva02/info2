#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct {
    long clave; //Clave o Id del registro
    char d[30]; // Descripcion
    unsigned char tipo; //Tipo de datos como entero sin signo
    char b; //'A':Alta 'B':Baja
} d;

typedef struct nodo_t{
    d valor;
    struct nodo_t* previo;
} nodo_t;
#endif
