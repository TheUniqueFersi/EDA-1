#include <stdio.h>
void imprimirResultado(int arr[], int izquierda, int derecha, int indiceMax, int numVal){
    int k;
    printf("\n\n\t==RESULTADOS==\nDel arreglo proporcionado, hay %d elemento%c que esta%c en el rango de (%d-%d)\n", numVal, (numVal==1)? '\0':'s', (numVal==1)? '\0':'n', 10, 100);
    if(numVal>0){
        for(k=0; k<indiceMax; k=k+1)
            if(arr[k]>izquierda && arr[k]<derecha)
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