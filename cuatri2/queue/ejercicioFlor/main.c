/*
/Escribe un programa que gestione una pila dinámica de libros en una biblioteca. Cada libro tiene los siguientes datos:

Título (string)
Autor (string)
Año de publicación (entero)
ISBN (entero)
El programa debe permitir al usuario realizar las siguientes operaciones:

Añadir un libro a la pila: Solicita los datos del libro al usuario y agrégalo a la pila.
Listar los libros: Muestra en pantalla todos los libros que están en la pila.
Guardar en archivo: Guarda todos los libros de la pila en un archivo llamado libros.dat, de organización secuencial, pero solo 
si el año de publicación es posterior a 2000.
Eliminar el último libro añadido: Elimina el último libro que fue añadido a la pila.
Salir: Termina el programa.
Requisitos adicionales:

Usa una estructura de datos para representar la información de cada libro.
Usa una pila implementada con memoria dinámica (estructura enlazada).
Asegúrate de liberar toda la memoria reservada al finalizar el programa./
*/
#include <stdio.h>
#include <stdlib.h>

#define AÑADIR 1
#define PRINT_LIB 2
#define SAVE 3
#define DELETE 4
#define READ 5

typedef struct libro_t {
    char titulo[20];
    char autor[21];
    int año;
    int ISBN;
}libro_t;

typedef struct nodo_t {
    libro_t libro;
    struct nodo_t* previo;
}nodo_t;

//elimino el '\n' sobrante de stdin
void flushline(void) {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    int seguir, op;
    nodo_t* top = NULL;
    nodo_t* nodoNuevo = NULL;
    nodo_t* temp = NULL;
    libro_t libroNuevo;
    libro_t libroLectura;

    FILE* fp;

    do {
        printf("Seleccionar Alguna opcion\n1)Añadir Libro\n2)Printear libros\n3)Guardar en archivo\n4)Eliminar primer libro de la pila\n5)Leer el archivo\n0)Salir del ejercicio\n");
        scanf(" %d", &op);
        flushline();
        switch (op) {
            case AÑADIR:
                system("clear");
                do {
                    printf("Ingresar titulo: ");
                    fgets(libroNuevo.titulo, sizeof(libroNuevo.titulo), stdin);
                    flushline();

                    printf("\nIngresar autor: ");
                    fgets(libroNuevo.autor, sizeof(libroNuevo.autor), stdin);
                    flushline();

                    printf("\nIngresar año del libro: ");
                    scanf("%d", &libroNuevo.año);
                    flushline();

                    printf("\nIngresar ISBN del libro: ");
                    scanf("%d", &libroNuevo.ISBN);
                    flushline();

                    nodoNuevo = malloc(sizeof(nodo_t));
                    nodoNuevo->libro = libroNuevo;
                    nodoNuevo->previo = top;
                    top = nodoNuevo;

                    printf("\nDesea seguir ingresando libros? 1--Si 2--No\n");
                    scanf("%d", &seguir);
                    flushline();
                }while (seguir == 1);
                break;

            case PRINT_LIB:
                system("clear");
                temp = top;
                if (temp == NULL) {
                    printf("No hay pila para printear\n");
                    break;
                }
                while (temp != NULL) {
                    printf("\n\nTitulo: %s\nAutor: %s\nAño de publicación: %d\nISBN: %d\n", temp->libro.titulo, temp->libro.autor,temp->libro.año,temp->libro.ISBN);
                    temp = temp->previo;
                } 
                break;

            case SAVE:
                temp = top;
                system("clear");
                if (top == NULL) {
                    printf("No hay pila para escribir en el archivo\n");
                    break;
                }
                fp = fopen("libros.dat", "wb+");
                if (fp == NULL) {
                    printf("No se pudo abrir el archivo\n");
                    return 1;
                }
                while (temp != NULL) {
                    if (temp->libro.año > 2000) {
                        if (fwrite(&temp->libro, sizeof(libro_t), 1, fp) != 1) {
                            printf("Error escribiendo el archivo\n");
                        }
                    }
                    temp = temp->previo;
                } 
                fclose(fp);
                temp = NULL;
                printf("\nLibros escritos en la base de datos\n");
                break;

            case DELETE:
                system("clear");
                if (top == NULL) {
                    printf("No hay pila para eliminar el primer item\n");
                    break;
                }
                temp = top;
                top = top->previo;
                free(temp);
                printf("\nPrimer item eliminado\n");
                break;

            case READ:
                system("clear");
                fp = fopen("libros.dat", "rb+");
                if (fp == NULL) {
                    printf("No se pudo abrir el archivo\n");
                    return 1;
                }
                while ((fread(&libroLectura, sizeof(libro_t), 1, fp)) == 1) { //Sin lectura anticipada, fread devuelve el nro. que se le pasa como parametro
                    printf("Titulo: %s\nAutor: %s\nAño de publicación: %d\nISBN: %d\n", libroLectura.titulo, libroLectura.autor,libroLectura.año,libroLectura.ISBN);
                }
                break;
        }
    }while (op != 0);

    //hago un free de toda la lista
    if (top == NULL) {
        printf("No hay pila para liberar\n");
        return 0;
    }    temp = top;
    while (temp != NULL) {
        top = top->previo;
        free(temp);
        temp = top;
    }
    return 0;
}
