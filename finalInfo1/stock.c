#include <stdio.h>
#include <string.h>

int main(void) {
    int stock[60][5];
    int articulo, cantidad, sucursal, validar, indice = 0;
    int seguir, suma = 0;
    char descripciones[60][50], descripcion[50];

    //inicializo las variables a 0
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 5; j++) {
            stock[i][j] = 0;
        }
    }

    memset(descripciones, 0, sizeof(descripciones));


    printf("Bienvenido al admin de stock\n");
    do {
        do {
            printf("Ingresar artículo: \n");
            scanf("%d", &articulo);
        }while (articulo < 1 || articulo > 60);


        printf("Ingresar cantidad: ");
        printf("\n");
        scanf("%d", &cantidad);

        do {
            printf("el valor en descripciones es: %s\n", descripciones[articulo - 1]);
            if (descripciones[articulo - 1][0] == 0) {
                printf("Ingresar una descripcion del articulo\n");
                scanf("%s", descripcion);
                validar = 0;

                for (int i = 0; i < 60; i++) {
                    if (!strcmp(descripcion, descripciones[i])) {
                        printf("La descripción %s ya fue añadida\n", descripcion);
                        validar = 1; 
                    }  
                }
            }
        }while (validar == 1);

        printf("Ingresar sucursal: \n");
        scanf("%d", &sucursal);

        switch (sucursal) {
            case 1: 
                stock[articulo - 1][sucursal - 1] = cantidad;
                indice += 1;
                stock[articulo - 1][4] = indice;
                strcpy(descripciones[articulo - 1], descripcion);
                break;
            case 2:
                stock[articulo - 1][sucursal - 1] = cantidad;
                indice += 1;
                stock[articulo - 1][4] = indice;
                strcpy(descripciones[articulo - 1], descripcion);
                break;
            case 3:
                stock[articulo - 1][sucursal - 1] = cantidad;
                strcpy(descripciones[articulo - 1], descripcion);
                break;
            default:
                printf("Sucursal ingresada invalida\n");
                break;
        }
        suma = 0;

        for (int i = 0; i < 3; i++) {
            suma += stock[articulo - 1][i];
        }

        stock[articulo - 1][3] = suma;

        printf("Desea seguir ingresando fichas? 1-Si 2-No\n");
        scanf("%d", &seguir);

    }while (seguir == 1);
    
    //Ordenamiento
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60 - 1 - i; j++) {
            if (stock[j][3] > stock[j + 1][3]) {
                for (int k = 0; k < 4; k++) {
                     int temp = stock[j + 1][k];
                     stock[j + 1][k] = stock[j][k];
                     stock[j][k] = temp;
                }
                char tempDesc[50];
                strcpy(tempDesc, descripciones[j + 1]);
                strcpy(descripciones[j + 1], descripciones[j]);
                strcpy(descripciones[j], tempDesc);
            } 
        }
    }

    printf("en el 0 y 0 esta: %d\n", stock[0][0]);
    printf("la suma en esa fila es: %d\n", stock[0][3]);

    //Impresion ordenada
    printf("Artículo   Sucursal1   Sucursal2   Sucursal3   Total\n");
    for (int j = 0; j < 60; j++) {
        if(stock[j][3] != 0) {
            printf("%-15s   %-15d   %-15d   %-15d   %-15d\n", descripciones[j], stock[j][0], stock[j][1], stock[j][2], stock[j][3]);
        }
    }
}
