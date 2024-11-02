#include <stdio.h>
#include <stdlib.h>


struct d
{
  int id;
  char d[20];
  float med;
  int b;
};

void muestaRegistros(void);

int main()
{
  int c;
  int d;
  int t,i;
  struct d *p;
  FILE *fp;
  FILE *fp2;

  muestaRegistros();

  printf("\nCuantos registros: llevo a memoria?:");
  scanf("%d",&c);
  printf("\nDesde que registros: ");
  scanf("%d",&d);

  /**genero el espacio*/

  p=(struct d*)malloc(sizeof(struct d)*c);
  if(p==NULL)
  {
     printf("\nNo hay memoria disponible.");
     getchar();
     return 1;
  }

 fp=fopen ("data.dat","rb");
 fp2 = fopen("listado.txt", "at");
   /** posiciono el puntero */
 fseek(fp,(1L)*(d-1)*sizeof(struct d),0);
 t=fread(p,sizeof(struct d),c,fp);
 printf(" se lleyeron %3d registro(s)",t);
  for(i=0; i<t; i++)
  {
   printf("\n %04d %-20s %10.2f",p[i].id,p[i].d,p[i].med);
   fprintf(fp2, "\n %04d %-20s %10.2f",p[i].id,p[i].d,p[i].med);
  }

  getchar();
  return 0;
}


void muestaRegistros(void)
{
 struct d bf;
 FILE *fp;
 fp=fopen ("data.dat","rb");
 if (fp == NULL) {
    printf("No se pudo abrir el archivo\n");
 }
 fread(&bf,sizeof(struct d),1,fp);
 while(!feof(fp))
 {
    printf("\n %4d - %-20s %10.2f",bf.id,bf.d,bf.med);
    fread(&bf,sizeof(struct d),1,fp);
 }

fclose(fp);
}

