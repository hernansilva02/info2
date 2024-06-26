/*
       Existe un archivo llamado "datos.dat" de tipo binario cuya organización es secuencial con la siguiente estructura:
        {
            long id;
            char descripcion[90]; 
            int tipo;
            char marca; // Marca 'A': Alta  'B': Baja)
        }
        
        Se pide: Realizar una función que pase como parámetro el id de la pieza, si el registro esta marcado como ‘A’ deberá modificar
        la descripción por "Registro Procesado", marcarlo como ‘B’ en el archivo y retornar el registro. Si esta marcado como 'B' 
        utilizando punteros cambiar la descripción las ‘a’ y ‘o’ por ‘e’, retornando el registro y grabándolo en el archivo "baja.dat".
        No usar variables globales.

    A. Explicar: que relación hay entre un puntero y un vector en lenguaje c 
    B. Que es una clave primaria compuesta. 
 */

#include "../libs/ejercicio.h"
#include "../libs/piezas.h"
#include <stdio.h>
#include <string.h>

void ejercicio(long id) {
    system("clear");
    piezas c;
    memset(&c, -1, sizeof(piezas));
    FILE* fp = fopen("datos.dat", "rb+");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return;
    }

    while (c.id != id && !feof(fp)) {
        if(feof(fp)) {
            printf("No se encontro el id solicitado");
            return;
        }
        fread(&c, sizeof(piezas), 1, fp);
    }
    if (c.marca == 'A') {
        c.marca = 'B';
        char nueva_desc[] = {"Registro procesado"};
        printf("ID: %ld\n", c.id);
        printf("Descripcion: %s\n", c.descripcion);
        printf("Estado: %c\n", c.marca);
        printf("Tipo: %d\n", c.tipo);
        strcpy(c.descripcion, nueva_desc);
        fseek(fp, -1, SEEK_SET);
        fwrite(&c, sizeof(piezas), 1, fp);
    } else if (c.marca == 'B') {
        char* letra = c.descripcion;
        FILE* new_fp = fopen("baja.dat", "ab+");
        if (new_fp == NULL) {
            printf("No se puedo abrir/crear el archivo\n");
            return;
        }
        for (int i = 0; i < strlen(c.descripcion); i++) {
            if (*letra == 'a' || *letra == 'o' || *letra == 'A' || *letra == 'O') {
                *letra = 'e';
            }
            letra++;
        }

        printf("ID: %ld\n", c.id);
        printf("Descripcion: %s\n", c.descripcion);
        printf("Estado: %c\n", c.marca);
        printf("Tipo: %d\n\n", c.tipo);
        printf("\n\n");

        fwrite(&c, sizeof(piezas), 1, new_fp);
        fclose(new_fp);
    }
    fclose(fp);
    return;
}
