/*
1) Exite un archivo de organización secuencial, llamado temperatura.dat, con la siguiente estructura:

long timestamp;
char descripcion[90];
float temperatura;
float temperatura_alarma;
int tipo;

Se sabe que cuando los bits 5 y 7 del campo tipo están en 1 indican que el sensor es de tipo creciente, es decir que la temperatura no debe superar la temperatura de alarma. Por otro lado, si los bits 4 y 6 están en uno el sensor es decreciente, osea que la temperatura no debe ser inferior a la de alarma.

Se pide, realizar una función, que reciba el tipo (C o D) y el nombre del archivo de salida, recorra el archivo y se la use para crear los archivos de creciente.dat y decreciente.dat que contenga la misma estructura del archivo original agregandole el campo de alarma char estado; //A - Alarnado, N - Normal. En caso de error la función deberá devolver 1, caso contrario 0.

NO SE PUEDEN USAR VARIABLE GLOBALES.

2) Teoricos

A. Explicar, que son los parametros de una función. ¿Como funciona el pasaje por valor? ¿Como funciona el pasaje por referencia?
B. Que implica un error cuando abrimos un archivo en modo "R".
*/

typedef struct datos_t{
    long timestamp;
    char descripcion[90];
    float temperatura;
    float temperatura_alarma;
    int tipo;
} datos_t;

int funcion(int tipo, char* archivo) {

}

#include <stdio.h>
#include <string.h>

int main() {
    datos_t dato, lectura;
    int op = 0;
    char* D = "decreciente.dat";
    char* C = "creciente.dat";
    long timestamp = 0;

    FILE* fp = fopen("temperatura.dat", "ab+");

    if (fp == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    do {
        printf("Ingresar timestamp: ");
        scanf("%ld", &dato.timestamp);
        printf("\nIngresar descripcion: ");
        fgets(dato.descripcion, sizeof(dato.descripcion), stdin);

        if (dato.descripcion[strlen(dato.descripcion) - 1] == '\n') {
            dato.descripcion[strlen(dato.descripcion) - 1] = '\0';
        }

        printf("\nIngresar temperatura: ");
        scanf("%f", &dato.temperatura);

        printf("\nIngresar la temperatura para la alarma: ");
        scanf("%f", &dato.temperatura_alarma);

        printf("\nIngresar tipo: ");
        scanf("%d", &dato.tipo);

        dato.timestamp = timestamp;

        printf("\n");

        fwrite(&dato, sizeof(datos_t), 1, fp);

        printf("Desea seguir cargando datos? 1--Si 2--No\n");

        scanf("%d", &op);
    } while(op != 2);

    while ((fread(&lectura, sizeof(datos_t), 1, fp) == 1)) {
        if ((dato.tipo & (1 << 4)) != 0 && (dato.tipo & (1 << 6)) != 0) {
            funcion(dato.tipo, C);
        } else if ((dato.tipo & (1 << 3)) != 0 && (dato.tipo & (1 << 5)) != 0) {
            funcion(dato.tipo, D);
        }
    }




}
