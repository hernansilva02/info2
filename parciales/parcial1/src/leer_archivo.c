#include <stdio.h>
#include "../libs/leer_archivo.h"
#include "../libs/piezas.h"

void leer_archivo(void) {
    piezas b;
    FILE* fp;
    
    fp = fopen("datos.dat", "rb+");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo");
        return;
    }

    system("clear");

    while ((fread(&b, sizeof(piezas), 1, fp)) == 1) {
        printf("id: %ld\n", b.id);
        printf("Descripcion: %s\n", b.descripcion);
        printf("Estado: %c\n", b.marca);
        printf("tipo: %d\n", b.tipo);
        printf("\n");
    }

    if (!feof(fp)) {
        printf("Error al leer archivo\n");
    }

    fclose(fp);
    printf("Lectura terminada\n");
}
