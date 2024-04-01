#include <stdio.h>
#include <stdlib.h>
#include "nodo.h"
#define true 1
#define false 0

struct Nodo* nuevoNodo(Equipo info){
    struct Nodo *nodo;
    nodo = malloc(sizeof(struct Nodo));
    if(nodo == NULL){
        printf("Memoria insuficiente para asignar \n");
        exit(0);
    }
    nodo->sig==NULL;
    nodo->info = info;
    return nodo;
}
Equipo leerEquipo(){
    Equipo e;
    char *mensajeFormateado;
    printf("Ingresa un nombre para tu equipo: ");
    //fgets(e.nombre, MAXSTRING, stdin);
    //bufferflush();
    leerCadena(e.nombre, MAXSTRING, 1, NULL);
    sprintf(mensajeFormateado, "Ingresa el puntaje de %s ", e.nombre);
    e.pts = leerEntero(mensajeFormateado, NULL);
    return e;
}
void bufferflush(){
    char c;
    while((c=getchar()) != '\0' && c != EOF);
}
int leerEntero(char *mensaje, char *mensajeError){
    int lectura, bandera;
    char *mensajeE = (mensajeError==NULL)? "Se esperaba un entero":mensajeError;
    do{
        printf("%s", mensaje);
        bandera = scanf("%d", &lectura);
        if(bandera == 0){
            printf("%s", mensajeE);
            bufferflush();
        }
    }while(bandera == 0);
    return lectura;
}
void rem1SaltoLinea(char * cadena){
    int k, tamanio;
    k=0;
    while(cadena[k] != 0){
        k++;
        if(cadena[k]=='\n')
            cadena[k] = '\0';
    }
}
int strlenEDA(char * s){//Es lo mismo que 'char s[]'
    int n;
    n=0;
    while(s[n]!=0 && s[n]!='\n')
        n=n+1;    
    return n;
}


int leerCadena(char *destino, int max, int remover, char *mensajeError){
    int overflow, nCaracter;
    char *mnsjError = (mensajeError == NULL)? "Ingrese de nuevo (la cadena no puede estar vacia): ": mensajeError;
    do{
        nCaracter = 0;
        do{
            destino[nCaracter] = getchar();
            nCaracter++;
        } while(destino[nCaracter-1]!='\n' && nCaracter < (max-1));
        destino[nCaracter] = 0;
        if(nCaracter>=(max-1)){
            bufferflush();
            overflow = true;
        } else 
            overflow = false;
        if(remover == true)
            rem1SaltoLinea(destino);
        if(strlenEDA(destino) == 0)
            printf("%s", mnsjError);
    } while(strlenEDA(destino) == 0);
    return overflow;
}