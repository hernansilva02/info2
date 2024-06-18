/*
        {
            long id;
            char descripcion[90]; 
            int tipo;
            char marca; // Marca 'A': Alta  'B': Baja)
        }
*/

#include "../libs/piezas.h"
#include "../libs/escritura.h"
#include <stdio.h>

long escritura(long* id) {
    piezas a; 
    int option = 0;
    int c;
    FILE* fp;

    fp = fopen("datos.dat", "rb+");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo para la escritura\n");
        return 1;
    }

    do {
        while((c = getchar()) != '\n' && c != EOF); //limpia stdin

        printf("Ingresar descripcion\n");
        fgets(a.descripcion, sizeof(a.descripcion), stdin);

        printf("Ingresar estado\n");
        scanf(" %c", &a.marca);

        printf("Ingresar tipo\n");
        scanf(" %d", &a.tipo);

        while((c = getchar()) != '\n' && c != EOF); //limpia stdin
        
        a.id = *id;

        fwrite(&a, sizeof(piezas), 1, fp);

        (*id)++;

        printf("Desea seguir ingresando productos? 1-Si 2-No\n");
        scanf("%d", &option);
    } while (option == 1);

    fclose(fp);

    return *id;
}

