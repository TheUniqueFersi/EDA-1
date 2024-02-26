#include <stdio.h>
#include "essentials.c"

void imprimirResultado(int numVal, int arr[], int m){
    
    for(m=m-1; m>=0; m=m-1)
        if(arr[m]>10 && arr[m]<100)
            printf("%d\t", arr[m]);

}
void buscarRangoInt(int v[], int izquierda, int derecha, int indiceMax, int * contadorVerdaderos){
    for(indiceMax=indiceMax-1;indiceMax>0;indiceMax=indiceMax-1){
        if(v[indiceMax]>izquierda && v[indiceMax]<derecha){
            *contadorVerdaderos++;
        }
            
    }
    printf("\t==RESULTADOS==\nDel arreglo proporcionado, hay %d elemento%c que esta%c en el rango de (%d-%d)\n", *contadorVerdaderos, (*contadorVerdaderos==1)? '\0':'s', (*contadorVerdaderos==1)? '\0':'n', 10, 100);
}
int main (void){
    int num[MAXI], indice, nNumerosValidos=0;
    desplegarMenu("L PROBLEMA 1: =NUMEROS (10,100)=", "Identifica los numeros que se encuentran en el rango de (10-100) de un arreglo dado");
    llenarArregloInt(num, &indice);
    if(indice>0){
        buscarRangoInt(num, 10, 100, indice, &nNumerosValidos);
        imprimirResultado(num, &nNumerosValidos);

    } else {
        printf("****El arreglo es muy pequeño, vuelve a intentar****\n");
    }

    return 0;
}