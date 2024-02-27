#include <stdio.h>
#include "essentials.h"
void desplegarMenu(int seccion, char * nombre, char * explicacion){
    switch (seccion)
    {
        case 1: //Bienvenida
            printf("\n\n+---|| BIENVENID@ A%s ||---+\n", nombre); //Como hacer 
            printf("Este programa %s\n", explicacion);
            break;
        case 2: //Terminacion
            printf("+---|| %s ||---+", explicacion);
        
    default:
        break;
    }        
}
int leerEntero(char * indicacionEntrada){
    int verif, entrada;
    char c;
    do{
        printf("%s", indicacionEntrada);
        fflush(stdin);
        verif=scanf("%d", &entrada);
        if(verif==0){
            while((c=getchar()) != '\n' && c != EOF);
            printf("Se esperaba un numero entero, ingresa nuevamente por favor: ");
        }
    }while(verif==0);
    return entrada;
}
void llenarArregloInt(int arr[], int * nElem){
    *nElem=0;
    do{
        arr[*nElem] = leerEntero("Ingresa un numero entero: ");
        *nElem=*nElem+1;
    }while(*nElem<MAXI && arr[*nElem-1] > 0);
    if(*nElem>=MAXI)
        printf("------// Has alcanzado el limite de valores para el arreglo\n");    
    *nElem=*nElem-1;
}
int busquedaElemento(int v[], int elemento, int * indice, int elementosEnArreglo, char * mensajeCoincidencia){
    int coincidencia=-1;
    while (*indice < elementosEnArreglo && coincidencia<0){
    if(v[*indice] == elemento){
        coincidencia = *indice;
        printf("%s", mensajeCoincidencia);
    }
    *indice=*indice+1;
    }
    return coincidencia;
}