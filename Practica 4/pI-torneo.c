#include <stdio.h>
#include "EDA.h"
#include "pI-torneo.h"

struct Equipo leer (char texto []){
    struct Equipo e;
    printf("\n%s\n\n", texto);
    printf("Nombre? ");
    //fflush(stdin); //Al no ser estándar, se propone la siguiente linea
    //gets(e.nombre);


    //fgets(e.nombre, MAXs, stdin);
    leerCadena(e.nombre, MAXs, true);
    
    printf("Puntaje? ");
    
    scanf("%d", &e.pts);
    e.pts = leerEntero("Ingresa un puntaje", DEFAULT);

    //Lectura de partidas:
    e.juegosGanados = leerEntero("Partidas ganadas: ", DEFAULT);
    e.juegosPerdidos = leerEntero("Partidas perdidas: ", DEFAULT);
    e.juegosEmpatados = leerEntero("Partidas empatadas: ", DEFAULT);

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
void imprimirEquipos(struct Torneo *t, int tipo_imp){
    int ciclos, k;
    struct Equipo *eMP;
    struct Equipo *emP;
    struct Torneo tTemp;
    struct Equipo temp;
    tTemp = *t;

    //Depliegue encabezado
    encabezado();

    //Impresión equipos IMP_NORM
    if(tipo_imp == IMP_NORMAL){
        for (k=0; k<NEQUIPOS; k++)
            imprime(t->equipos[k], k);
    } else { //Ímpresión equipos IMP_ORD
        //Ordenamiento Burbuja invertida
        for(ciclos = 1; ciclos < NEQUIPOS; ciclos++){
            for(k=0; k<NEQUIPOS-1; k++){ //En menos 1 como maximo, por la notacion de arreglo que admite hasta el indice [n-1]
                if(tTemp.equipos[k].pts < tTemp.equipos[k+1].pts){
                    intercambioPosEquipos(&tTemp, &temp, k);
                } else if(tTemp.equipos[k].pts == tTemp.equipos[k+1].pts){
                    if(tTemp.equipos[k].juegosPerdidos > tTemp.equipos[k+1].juegosPerdidos)
                        intercambioPosEquipos(&tTemp, &temp, k);
                    else if(tTemp.equipos[k].juegosPerdidos == tTemp.equipos[k+1].juegosPerdidos)
                        if(tTemp.equipos[k].juegosGanados < tTemp.equipos[k+1].juegosGanados)
                            intercambioPosEquipos(&tTemp, &temp, k);
                }
            }
        }
        for (k=0; k<NEQUIPOS; k++)
            imprime(tTemp.equipos[k], k);
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
void intercambioPosEquipos(struct Torneo *t, struct Equipo *temp, int k){
    *temp = t->equipos[k];
    t->equipos[k] = t->equipos[k+1];
    t->equipos[k+1] = *temp;
}