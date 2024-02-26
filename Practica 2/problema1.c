#include <stdio.h>
#include "essentials.c"

void imprimirResultado(int numVal, int arr[], int m){
    int k;
    printf("\t==RESULTADOS==\nDel arreglo proporcionado, hay %d elemento%c que esta%c en el rango de (%d-%d)\n", numVal, (numVal==1)? '\0':'s', (numVal==1)? '\0':'n', 10, 100);
    if(numVal>0){
        for(k=0; k<m; k=k+1)
            if(arr[k]>10 && arr[k]<100)
                printf("arr[%d]: %d\n", k, arr[k]);
    }

}
void buscarRangoInt(int v[], int izquierda, int derecha, int indiceMax, int * contadorVerdaderos){
    int k;
    for(k=0;k<indiceMax;k=k+1){
        if(v[k]>izquierda && v[k]<derecha)
            *contadorVerdaderos=*contadorVerdaderos+1;
    }
}
int main (void){
    int num[MAXI], indice, nNumerosValidos=0;
    desplegarMenu(1, "L PROBLEMA 1: =NUMEROS (10,100)=", "Identifica los numeros que se encuentran en el rango de (10-100) de un arreglo dado");
    llenarArregloInt(num, &indice);
    if(indice>0){
        buscarRangoInt(num, 10, 100, indice, &nNumerosValidos);
        imprimirResultado(nNumerosValidos, num, indice);
    } else {
        printf("El arreglo es muy pequeño, vuelve a intentar\n");
    }
    return 0;
}