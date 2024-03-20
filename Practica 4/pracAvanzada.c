#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EDA.h"
#include "menu.h"
#include "pI-torneo.h"

int entradaEquipoExistente(char * cadena, char *mensaje){
    int entrada;
    do{
        printf("%s", mensaje);
        fgets(cadena, MAXs, stdin);

        
        //Si brinda el nombre

        // if(!isANumber(cadena1))
        // Codigo para retornar el indice del video con ese nombre (primer coincidencia)
        // entrada = ()
        
        //entrada = (!isANumber(cadena1))? retorno:stoi(cadena1);
            //entrada = stoi(cadena);
        entrada = atoi(cadena);
        printf("DEP : stoi %d", entrada);
        if(!(entrada>=1 && entrada<=NEQUIPOS))
            printf("Ese equipo no existe, ingresa (1-10) o su nombre - \n");
    }while(!(entrada>=1 && entrada<=NEQUIPOS));
    return entrada-1;
}
void actualizarPromediosTorneo(struct Torneo *t){
    float promPTS=0, promJG=0, promJP=0, promJE=0;
    int k;
    for(k=0; k < NEQUIPOS; k++){
        promPTS += t->equipos[k].pts;
        promJG += t->equipos[k].juegosGanados;
        promJP += t->equipos[k].juegosPerdidos;
        promJE += t->equipos[k].juegosEmpatados;
    }
    t->promPTS = promPTS / NEQUIPOS;
    t->promJG = promJG / NEQUIPOS;
    t->promJP = promJP / NEQUIPOS;
    t->promJE = promJE / NEQUIPOS;
}
void registrarPartido(struct Torneo *torneo){
    int indE1, indE2, entrada;
    char cadena1[MAXs], cadena2[MAXs];
    indE1 = entradaEquipoExistente(cadena1, "Ingresa algun equipo (numero): ");
    do{
        indE2 = entradaEquipoExistente(cadena2, "Ingresa el equipo contra el que va a enfrentarse (numero): ");
        if(indE1 == indE2)
            printf("Un equipo no puede enfrentarse a si mismo, proporcione otro\n");
    }
    while(indE2 == indE1);
    do{
        printf("Quien gano el encuentro? (1): %s\t(2): %s\t(3): Empataron\n", torneo->equipos[indE1].nombre, torneo->equipos[indE2].nombre);
        entrada = leerEntero("Ingresa una opcion: ", NULL);
        if(!(entrada >= 1 && entrada <= 3))
            printf("Opcion invalida\n");
    }while(!(entrada >= 1 && entrada <= 3));
    if(entrada == 1){ 
        torneo->equipos[indE1].pts += (torneo->equipos[indE1].locOVis == 1)? 2:3;
        torneo->equipos[indE1].juegosGanados++;
        torneo->equipos[indE2].juegosPerdidos++;

        // loc->pts+=2;
        // loc->juegosGanados++;
        // vis->juegosPerdidos++;
    } else if(entrada == 2){
        torneo->equipos[indE2].pts += (torneo->equipos[indE2].locOVis == 1)? 2:3;
        torneo->equipos[indE2].juegosGanados++;
        torneo->equipos[indE1].juegosPerdidos++;
        // vis->pts+=3;
        // vis->juegosGanados++;
        // loc->juegosPerdidos++;
    } else if(entrada == 3){
        torneo->equipos[indE1].pts ++;
        torneo->equipos[indE2].pts++;
        torneo->equipos[indE1].juegosEmpatados ++;
        torneo->equipos[indE2].juegosEmpatados ++;
        // loc->pts++;
        // vis->pts++;
        // loc->juegosEmpatados++;
        // vis->juegosEmpatados++;
    }
    actualizarPromediosTorneo(torneo);
}

void leerEquipos(struct Equipo e[], int nEquipos){
    int k;
    char sIngresoEquipo[30];
    for(k=0; k<nEquipos; k++){
        sprintf(sIngresoEquipo, "Equipo %d", k+1);
        e[k] = leer(sIngresoEquipo);
    }
}

int main(void) {
    int entrada;
    // struct Equipo local, visitante;
    // local = leer("Equipo local");
    // visitante = leer("Equipo visitante");    
    struct Torneo torneo;
    leerEquipos(torneo.equipos, NEQUIPOS);
    actualizarPromediosTorneo(&torneo);

    dLineaHoriz('-');
    do{
        printf("\n(0) Salir\n(1) Registrar partido\n(2) Solo imprimir equipos\n");
        entrada = leerEntero("Ingresa una opcion: ", NULL);
        bufferflush();
        switch (entrada){
            case 0:
                printf("Saliendo del programa ...\n");
                break;
            case 1:
                registrarPartido(&torneo);
            case 2:
                dLineaHoriz('-');
                imprimirEquipos(&torneo);
                dLineaHoriz('-');
                break;
            default:
                printf("Opcion invalida\n");
        }
    }while(entrada != 0);
    return 0;
}


// void imprime (struct Equipo e){
//     printf("\n%-10s tiene %03d pts\n", e.nombre, e.pts);
//     // --TODO Hacer en formato tabla
//     printf("Juegos Ganados: %d\n", e.juegosGanados);
//     printf("Juegos perdidos: %d\n", e.juegosPerdidos);
//     printf("Juegos empatados: %d\n", e.juegosEmpatados);

//     printf("Efectividad del equipo: %.2f%%\n", efectividad(e));
// }