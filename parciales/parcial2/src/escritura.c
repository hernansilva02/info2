/*
        {
            long id;
            char categoria[90]; 
            int tipo;
            char marca; // Marca 'A': Alta  'B': Baja)
        }
*/

#include "../libs/estruct.h"
#include "../libs/escritura.h"
#include <string.h>
#include <stdio.h>

long escritura(long* id) {
    productos a; 
    int option = 0;
    int c;
    FILE* fp;

    fp = fopen("datos.dat", "rb+");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo para la escritura\n");
        return 1;
    }

    printf("Archivo abierto\n");

    system("clear");
    while((c = getchar()) != '\n' && c != EOF); //limpia stdin

    do {
        memset(&a, 0, sizeof(productos));

        printf("Ingresar categoria\n");
        fgets(a.categoria, sizeof(a.categoria), stdin);

        if (strlen(a.categoria) > 0 && a.categoria[strlen(a.categoria) - 1] == '\n') {
            a.categoria[strlen(a.categoria) - 1] = '\0';
        }


        printf("Ingresar estado\n");
        scanf(" %u", &a.estado);

        while((c = getchar()) != '\n' && c != EOF); //limpia stdin

        printf("Ingresar valor\n");
        scanf(" %f", &a.valor);

        while((c = getchar()) != '\n' && c != EOF); //limpia stdin
        
        a.id = *id;

        fwrite(&a, sizeof(productos), 1, fp);

        (*id)++;

        printf("Desea seguir ingresando productos? 1-Si 2-No\n");
        scanf("%d", &option);

        while((c = getchar()) != '\n' && c != EOF); //limpia stdin
    } while (option == 1);

    fclose(fp);

    return *id;
}

