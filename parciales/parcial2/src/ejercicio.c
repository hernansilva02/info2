#include "../libs/estruct.h"
#include <stdio.h>
#include <string.h>

int ejercicio(long id) {
    productos b; 
    char nuevaCat[90];
    char* ptr;
    int idCont = 0;

    memset(nuevaCat, 0, sizeof(nuevaCat));

    FILE* fp = fopen("datos.dat", "rb+");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo para el cambio a mayusculas\n");
        return 1;
    }

    while ((fread(&b, sizeof(productos), 1, fp)) == 1 && b.id != id);

    if (!feof(fp)) {
        printf("No existe ese ID");
        return 0;
    }
    
    ptr = b.categoria;

    memset(b.categoria, 0, sizeof(b.categoria));

    while (*ptr != '\0') {
        if (*ptr == ' ' || (*ptr >= 'A' && *ptr <= 'Z')) {
            *ptr = *ptr; 
            ptr++; 
        } else {
            *ptr += 32;
            ptr++; 
        }
    }

    strcpy(b.categoria, ptr);

    if ((b.estado & (1 << 2)) != 0) {
        fwrite(&b, sizeof(productos), 1, fp);
        rewind(fp);
        fread(&b, sizeof(productos), 1, fp);
        while (!feof(fp)) {
            fread(&b, sizeof(productos), 1, fp);
            idCont++; 
        }
    }
    return idCont++;
}

