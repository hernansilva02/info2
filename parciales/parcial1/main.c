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

#include "libs/escritura.h"
#include "libs/leer_archivo.h"
#include "libs/crear_archivo.h"
#include "libs/ejercicio.h"
#include "libs/leer_bajas.h"
#include <stdio.h>

int main() {
    int op = 0;
    long id = 0;
    long nuevo_id = 0;

    system("clear");

    do {
        printf("Elija una opción\n");
        printf("1-Crear Archivo\n");
        printf("2-Realizar ejercicio\n");
        printf("3-Mostrar los datos\n");
        printf("4-Leer las bajas\n");
        printf("5-Salir\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                crear_archivo();
                id = escritura(&id);
                break;
            case 2:
                printf("Seleccionar id: ");
                scanf("%ld", &nuevo_id);
                ejercicio(nuevo_id); 
                break;
            case 3:
                leer_archivo();
                break;
            case 4:
                leer_bajas();
                break;
        }
    }while (op != 5);
}
