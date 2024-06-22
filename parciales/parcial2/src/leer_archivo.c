#include <stdio.h>
#include "../libs/leer_archivo.h"
#include "../libs/estruct.h"

void leer_archivo(void) {
    productos b;
    FILE* fp;
    
    fp = fopen("datos.dat", "rb+");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }

    system("clear");

    while ((fread(&b, sizeof(productos), 1, fp)) == 1) {
        printf("id: %ld\n", b.id);
        printf("Categoria: %s\n", b.categoria);
        printf("Estado: %u\n", b.estado);
        printf("valor: %f\n", b.valor);
        printf("\n");
    }

    if (!feof(fp)) {
        printf("Error al leer archivo\n");
    }

    fclose(fp);
    printf("Lectura terminada\n");
}

