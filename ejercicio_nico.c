 /*1- Definir una estructura para los componentes electrónicos:
 
 Cada componente debe tener las siguientes propiedades:
 id (un identificador único, tipo int)
 nombre (nombre del componente, tipo char[50])
 tipo (tipo del componente, tipo char[30], por ejemplo, "Resistor", "Capacitor", etc.)
 cantidad (cantidad disponible en el inventario, tipo int)
 Implementar las siguientes funciones:
 
 2- Agregar Componente: Función para agregar un nuevo componente al inventario.
 Mostrar Inventario: Función para mostrar todos los componentes en el inventario.
 Buscar Componente por ID: Función para buscar un componente por su id y mostrar sus detalles.
 Menú Interactivo:
 
 3- Implementar un menú interactivo para que el usuario pueda seleccionar las operaciones de agregar componente, mostrar inventario y buscar componente por ID.
*/
 #include <stdio.h>

 typedef char *string;

 typedef struct {
     int id;
     char nombre[50];
     char tipo[30];
     int cantidad;
 } Componente;

 void mostrar_inventario(Componente inventario[100]);
 void buscar_componente(int componente, Componente inventario[100]);

 int main(void) {
     Componente inventario[100];
     int numero;
     int input;
        
     for (int i = 0; i < 100; i++) {
         inventario[i].id = -1;
     }

     do {
         printf("Bienvenido a la gestión de inventario\n");
         do {
             printf("Buscar Componente por ID (3)\n" 
                    "Mostrar inventario de componentes actual(2)\n" 
                    "Agregar un nuevo componente al inventario (1)\n");
             scanf(" %d", &numero);
         } while(numero < 1 || numero > 3);

         if (numero == 1) {
             int idbusq;
             printf("Ingresar Id a buscar: ");
             scanf(" %d", &idbusq);
             printf("\n");
             buscar_componente(idbusq, inventario);
         }
         else if (numero == 2) {
             mostrar_inventario(inventario);
         }
         else if (numero == 3) {
             Componente nuevo;
             printf("Ingresar nuevo id: ");
             scanf("%d", &nuevo.id);

             printf("Ingresar nuevo Nombre: ");
             scanf(" %s", nuevo.nombre);

             printf("Ingresar nuevo Tipo: ");
             scanf(" %s", nuevo.tipo);

             printf("Ingresar nueva Cantidad: ");
             scanf(" %d", &nuevo.cantidad);

              for (int i = 0; i < 100; i++) {
                  if (inventario[i].id == -1) {
                      inventario[i] = nuevo;
                      break;
                  }
              }
         }
         printf("\n¿Desea salir del administrador? Para hacer esto presionar el numero 1 en su teclado\n");
        scanf(" %d", &input);
     } while (input != 1);
 }

 void mostrar_inventario(Componente inventario[100]) {
     if (inventario[0].id == -1) {
         printf ("No se encuentra ningun componente en el inventario\n");
         return;
     }
     for (int i = 0; inventario[i].id != -1; i++) {
         printf("Componente %d\n"
                "ID: %d\n"
                "Nombre: %s\n"
                "Tipo: %s\n"
                "Cantidad: %d\n", i, inventario[i].id, inventario[i].nombre, inventario[i].tipo, inventario[i].cantidad);
         printf("\n");
     }
     return;
 }

void buscar_componente(int componente, Componente inventario[100]) {
     if (inventario[0].id == -1) {
         printf ("No se encuentra ningun componente en el inventario\n");
         return;
     }
     for (int i = 0; inventario[i].id != -1; i++) {
        if (inventario[i].id == componente) {
            printf("Id: %d\n"
                   "Nombre: %s\n"
                   "Tipo: %s\n"
                   "Cantidad: %d\n", inventario[i].id, inventario[i].nombre, inventario[i].tipo, inventario[i].cantidad);
        } 
        else {
            printf("No se encontró un componente con ese Id");
        }
     }
     return;
 }
