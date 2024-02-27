#include <stdio.h>
#include "funciones1.h"
#include "essentials.h"
int main (void){
    int num[MAXI], indice, nNumerosValidos=0;
    desplegarMenu(1, "L PROBLEMA 1: =NUMEROS (10,100)=", "Identifica los numeros que se encuentran en el rango de (10-100) de un arreglo dado");
    llenarArregloInt(num, &indice);
    if(indice>0){
        buscarRangoInt(num, 10, 100, indice, &nNumerosValidos);
        imprimirResultado(num, 10, 100, indice, nNumerosValidos);
    } else {
        printf("El arreglo es muy pequeño, vuelve a intentar\n");
    }
    return 0;
}