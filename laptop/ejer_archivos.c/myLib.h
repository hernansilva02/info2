#include <stdio.h>

typedef struct {
    char nombre[30];
    int legajo;
    char regular; //"S" para si o "N" para no
} alumons_t;

void mostrarNtoRegulares(void);
void mostrar_alumno(int);
