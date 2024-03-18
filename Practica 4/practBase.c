#include <stdio.h>
#include <stdlib.h>
#include "EDA.h"
#include "menu.h"
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


void registrarPartido(struct Equipo *loc, struct Equipo *vis){
    int entrada;
    do{
        printf("Quien gano el encuentro? (1): Local\t(2): Visitante\t(3): Empataron\n");
        entrada = leerEntero("Ingresa una opcion: ", NULL);
        if(entrada < 1 && entrada > 3)
            printf("Opcion invalida\n");
    }while(entrada < 1 && entrada > 3);
    if(entrada == 1){ 
        loc->pts+=2;
        loc->juegosGanados++;
        vis->juegosPerdidos++;
    } else if(entrada == 2){
        vis->pts+=3;
        vis->juegosGanados++;
        loc->juegosPerdidos++;
    } else if(entrada == 3){
        loc->pts++;
        vis->pts++;
        loc->juegosEmpatados++;
        vis->juegosEmpatados++;
    }
}
float efectividad(struct Equipo e){
    float efectividad;
    efectividad = ((e.juegosGanados+e.juegosEmpatados+e.juegosPerdidos)==0)? 0.0:(float)(e.juegosGanados+e.juegosEmpatados)/(e.juegosGanados+e.juegosEmpatados+e.juegosPerdidos) * 100;
    return efectividad;
}
int main(void) {
    int entrada;
    struct Equipo local, visitante;
    local = leer("Equipo local");
    visitante = leer("Equipo visitante");    
    dLineaHoriz('-');
    //Quien gano?
    //
    do{
        printf("\n(0) Salir\n(1) Registrar partido\n(2) Solo imprimir equipos\n");
        entrada = leerEntero("Ingresa una opcion: ", NULL);
        switch (entrada){
            case 0:
                printf("Saliendo del programa ...\n");
            case 1:
                registrarPartido(&local, &visitante);
            case 2:
                dLineaHoriz('-');
                imprime(local);
                imprime (visitante);
                dLineaHoriz('-');
                break;
            default:
                printf("Opcion invalida\n");
        }
    }while(entrada != 0);
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
    rem1SaltoLinea(e.nombre);

    //Lectura de partidas:
    e.juegosGanados = leerEntero("Partidas ganadas: ", "-- Se esperaba un entero, intenta de nuevo\n");
    e.juegosPerdidos = leerEntero("Partidas perdidas: ", "-- Se esperaba un entero, intenta de nuevo\n");
    e.juegosEmpatados = leerEntero("Partidas empatadas: ", "-- Se esperaba un entero, intenta de nuevo\n");
    bufferflush();
    return e;
}

void imprime (struct Equipo e){
    printf("\n\n%-10s tiene %03d pts\n", e.nombre, e.pts);
    // --TODO Hacer en formato tabla
    printf("Juegos Ganados: %d\n", e.juegosGanados);
    printf("Juegos perdidos: %d\n", e.juegosPerdidos);
    printf("Juegos empatados: %d\n", e.juegosEmpatados);

    printf("Efectividad del equipo: %.2f%\n", efectividad(e));
}