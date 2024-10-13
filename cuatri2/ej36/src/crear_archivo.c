#include "../lib/crear_archivo.h"
#include <stdio.h>

void crear_archivo(char* nombre) {
    FILE* fp = fopen(nombre, "wb");
    if (fp == NULL) {
        printf("No se pudo crear el archivo\n");
        return;
    }
}
