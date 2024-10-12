#include <stdio.h>

typedef struct{

    long timestamp;
    char descripcion[90];
    float temperatura;
    float temperatura_alarma;
    int tipo;           //160 creciente 80 decreciente

} registro;

int main(){
FILE* fp;
registro data;
int op=1;
long timestamp;

if((fp=fopen("temperatura.dat","ab+"))==NULL) printf("archivo inexisitente");

do
{
    printf("\ningrese la descripcion: ");           //me da una posicion de memoria, &me da el valor
    scanf("%s", data.descripcion);
    printf("\ningrese la temperatura: ");
    scanf("%f",&data.temperatura);
    printf("\ningrese la alarma: ");
    scanf("%f",&data.temperatura_alarma);
    printf("\ningrese el tipo: ");
    scanf("%d",&data.tipo);

    data.timestamp = timestamp;

    fwrite(&data, sizeof(registro), 1, fp);

    printf("desea seguir cargando temperaturasn\n 1)si\t2)no\n");
    scanf("%d",&op);
    timestamp++;

} while (op!=2);
}
