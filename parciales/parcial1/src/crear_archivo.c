#include <stdio.h>
#include "../libs/crear_archivo.h"

void crear_archivo() {
    FILE* fp = fopen("datos.dat", "wb");
    if (fp == NULL) {
        printf("No se pudo crear el archivo\n");
        return;
    }
    return;
}
