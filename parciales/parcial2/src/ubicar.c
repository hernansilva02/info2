#include <stdio.h>
#include "../libs/ubicar.h"
#include "../libs/estruct.h"

long ubicar(long id) {
    productos a;
    FILE* fp = fopen("datos.dat", "rb+");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return -1;
    }

    while ((fread(&a, sizeof(productos), 1, fp)) == 1) {
        if (a.id == id) {
            printf("Se encontro el producto\n");
            fclose(fp);
            return id;
        } 
    }

    if (!feof(fp)) {
        printf("No se encontro el producto\n");
    }

    fclose(fp);
    return 0;
}


