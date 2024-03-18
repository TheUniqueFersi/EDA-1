#include <stdio.h>
#include <stdlib.h>
#include "EDA.h"
#define MAXs 50
struct Equipo {
    char nombre [10];
    int pts;
    int juegosGanados;
    int juegosEmpatados;
    int juegosPerdidos;
};
struct Equipo leer (char texto[]);
void imprime(struct Equipo e);

int main(void) {
    struct Equipo local, visitante;
    local = leer("Equipo local");
    visitante = leer("Equipo visitante");
    imprime(local);
    imprime (visitante);
    return 0;
}
struct Equipo leer (char texto []){
    struct Equipo e;
    printf("\n%s\n\n", texto);
    printf("Nombre? ");
    //fflush(stdin); //Al no ser estándar, se propone la siguiente linea
    //gets(e.nombre);
    fgets(e.nombre, MAXs, stdin);
    
    printf("Puntaje? ");
    scanf("%d", &e.pts);
    bufferflush();
    return e;
}

void imprime (struct Equipo e){
    printf("\n\n\n%-10s tiene %03d pts\n", e.nombre, e.pts);
}