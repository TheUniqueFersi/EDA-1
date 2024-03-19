#include <stdio.h>
#include "EDA.h"
#include "pI-torneo.h"

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

    do{
        e.locOVis = leerEntero("Ingresa '1' si el equipo es local, '2' si es visitante: ", NULL);
        if(e.locOVis != 1 && e.locOVis != 2)
            printf("Opcion invalida\n");
    }while(e.locOVis != 1 && e.locOVis != 2);
    bufferflush();


    return e;
}
float efectividad(struct Equipo e){
    float efectividad;
    efectividad = ((e.juegosGanados+e.juegosEmpatados+e.juegosPerdidos)==0)? 0.0:(float)(e.juegosGanados+e.juegosEmpatados)/(e.juegosGanados+e.juegosEmpatados+e.juegosPerdidos) * 100;
    return efectividad;
}

//TABLA EQUIPOS:
void encabezado(){
    printf("\n\n+----+-----+----------------------+-----+-----+-----+-----+--------+\n");
    printf("| %2s | %3s | %-20s | %3s | %3s | %3s | %3s | %6s |\n", "N.", "l/v", "EQUIPO", "PTS", "JG", "JP", "JE", "%Efec");
    printf("+----+-----+----------------------+-----+-----+-----+-----+--------+\n");
}
void imprime(struct Equipo e, int n){
    printf("| %02d | %3s | %-20s | %3d | %3d | %3d | %3d | %03.2f%% |\n", n+1, (e.locOVis==1)? "loc":"vis", e.nombre, e.pts, e.juegosGanados, e.juegosPerdidos, e.juegosEmpatados, efectividad(e));
    printf("+----+-----+----------------------+-----+-----+-----+-----+--------+\n");
}
void imprimirEquipos(struct Torneo *t){
    int k;
    struct Equipo *eMP;
    struct Equipo *emP;
    //Depliegue encabezado
    encabezado();
    for (k=0; k<NEQUIPOS; k++){
        imprime(t->equipos[k], k);
    }
    //IMPRIME PROMEDIOS GENERALES
    printf("| %31s |% 3.1f |% 3.1f |% 3.1f |% 3.1f |        |\n", "PROMEDIOS", t->promPTS, t->promJG, t->promJP, t->promJE);
    printf("+----+-----+----------------------+-----+-----+-----+-----+--------+\n");
    eMP = &(t->equipos[0]);
    emP = &(t->equipos[0]);
    for (k=0; k<NEQUIPOS; k++){
        if(t->equipos[k].pts>eMP->pts)
            eMP = &(t->equipos[k]);
        if(t->equipos[k].pts<emP->pts)
            emP = &(t->equipos[k]);
    }    
    //Equipo mayor puntaje / menor puntaje
    printf("| %30s  | %30s |\n", "Equipo con mayor puntaje", "Equipo con menor puntaje");
    printf("| %30s  | %30s |\n", eMP->nombre, emP->nombre);
    printf("+----+-----+----------------------+-----+-----+-----+-----+--------+\n");

}