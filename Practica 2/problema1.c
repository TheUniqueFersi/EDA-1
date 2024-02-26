#include <stdio.h>
#include "essentials.c"

void imprimirResultado(int numVal, int arr[], int m){
    printf("\t=== RESULTADOS ===\nHay %d numeros que están en el rango de (10,100)\nLos numeros son: ", numVal);
    for(m=m-1; m>=0; m=m-1)
        if(arr[m]>10 && arr[m]<100)
            printf("%d\t", arr[m]);

}
int main (void){
    int num[MAXI], n, numerosValidos;//n -> loc arreglos
    leer(num, &n);
    numerosValidos = cuenta(num, n);
    imprimirResultado(numerosValidos, num, n);

    return 0;
}