#include <stdio.h>
#include "video.h"

void imprime(struct Video v) {
    char unaFecha[20];
    printf("===[%s]===\n",v.nombre);
    printf("Duracion: %0.2f\n",v.duracion);
    printf("Fecha: %s\n",strFecha(unaFecha,v.fecha));
    printf("Calidad: %s\n",v.calidad);
    printf("%d veces visto\n",v.n_rep);
    printf("----------------------------\n\n");
}

char *strFecha(char cadena[], struct Fecha f) {
    sprintf(cadena,"%02d/%02d/%04d",f.dia,f.mes,f.anio);
    return cadena;
}

struct Video leer(void) {
    struct Video v;
    printf("Nombre del video? ");
    getchar();
    scanf("%[^\n]",v.nombre);
    printf("Duracion? ");
    scanf("%f",&(v.duracion));
    printf("Dia mes y anio? ");
    scanf("%d %d %d", &(v.fecha.dia) , &(v.fecha.mes), &(v.fecha.anio));
    getchar();
    printf("Calidad? ");
    scanf("%[^\n]",v.calidad);
    printf("numero de veces visitado? ");
    scanf("%d",&(v.n_rep));
    return v;
}