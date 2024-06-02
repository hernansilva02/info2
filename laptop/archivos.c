#include <stdio.h>
 //
 //FILE *fp = fopen(const char *, const char *); //fopen toma como argumento el archivo a abrir y como 2 argumento el modo
 //
 //
 ///*fopen("archivo","w, r, a")
 // *
 // *MODOS: w,r y a
 // *"w" es write, dentro de el hay 2 submodos: "wt" de "write text" y "wb" de "write binary"
 // *"r" es read, lo mismo, existe "rt" y "rb"
 //*/
 //
 //
 ////exclusion de error
 //int main(void) {
 //    if((fp=fopen("ejemplo.txt", "wt")) == NULL) {
 //        printf("No se pudo abrir el archivo\n");
 //        return 1;
 //    }
 //}

 //cree varios registros de la sig struct:
 //    int id;
 //    char *nombre[60];
 //    int n[5];
 //
 //una vez cargados los alumnos se pide imprimir listado de los que aprobaron
 //dddaadddddddddddddddddasdsadsadasdsadsadasdsadsadsadsadsadsadsadsadsadsadsaasddsaasddsadsa
 //se tiene un archivo de organizacion secuencial con la siguiente estructura:
 
typedef struct{
    char nombre[30];
    int legajo;
    char regular; //"s" de si o "n" de no
} alumno_t;

//Se pide recorrer el archivo e imprimir el pantalla todos los que no son regulares y cuyo legajo tenga el bit 3 en 1
//hacer una segunda funcion que reciba como param un numero de legajo y lo imprima en pantalla

void mostrarNoRegulares(void);
 
