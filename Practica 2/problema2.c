#include <stdio.h>
#include "essentials.h"

lectura (int v[], int * n){
    *n = 0;

}

/*
    lea mientras verifica que no esten repetidos

    pregunte numero que desea buscar

    le diga si es enumero esta o no, si esta entonces le dice en que posicion esta

    La busqueda se repite hasta que el usuario introduzca un valor menor o igual a cero

*/

void llenarArregloNoRepetido(int v[], int * indice){
    int indiceFalso = 0, *ptrFalso = &indiceFalso;
    *indice = 0;
    do{
        do{
            *ptrFalso = 0;
            v[*indice] = leerEntero("Ingresa un numero entero, cuida que sea repetido: ");
        }while(busquedaElemento(v, v[*indice], &indiceFalso, *indice, "Este numero ya se ha ingresado previamente, ingresa uno diferente: ")>0);
        *indice=*indice+1;
    }while(*indice<MAXI && v[*indice-1] > 0);
    if(*indice>=MAXI)
        printf("------// Has alcanzado el limite de valores para un arreglo\n");
    *indice=*indice-1;
}


int main (void){
    int listaNoRepetidos[MAXI], indice, maxIndiceValido, valorBusqueda;
    desplegarMenu(1, "L PROBLEMA 2: =BUSQUEDA DE ELEMENTO EN LISTA NO REPETIDA=", "Identifica si el numero proporcionado esta o no en el arreglo, si esta, indica en que indice");
    llenarArregloNoRepetido(listaNoRepetidos, &indice);
    if(indice>0){
        
        
        while()//para repetir numero que busque
    } else {
        printf("El arreglo es muy pequeño, vuelve a intentarlo\n");
    }
    return 0;
}