#include <stdio.h>
#include <stdlib.h>
/** #include <malloc.h> */

int main()
{
    int i,*p,t;
    long c=0;

    printf("Ingrese el tama%co del vector:",164);
    scanf("%d",&t);

    p=(int*) malloc(sizeof(int)*t);
    if(!p)
    {
      printf("No hay memoria disponible\n");
      getchar();
      return 0;
    }

    for(i=0;i<t;i++)
        p[i]=i+t;

    for(i=0;i<t;i++)
        printf("%4d ",p[i]);

   free(p);
   getchar();

   /** Parte 2 forzar  a agotar la memoria dinámica */

   while(p) /** Este códogo deja reservada la memoria dinámica en cada ciclo de manera que no puede liberarse*/
   {
    c++;
    p=(int*) malloc(sizeof(int)*t);
    printf(".-");
   }
    printf("\n Pude reservar %ld bytes %ld veces",sizeof(int)*t,c);
    printf("\n Total de bytes reservados:%ld",sizeof(int)*t*c);

    printf("\n");
    getchar();
    return 0;
}
