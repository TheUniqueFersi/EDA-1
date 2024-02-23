#include <stdio.h>
#define MAX 20

int leer(int arr[], int *n){
    int verif;
    *n = 0;
    do{
        printf("Ingresa un numero: ");
        fflush(stdin);
        verif = scanf("%d", &arr[*n]);
        if(verif!=0)
            *n=*n+1;
    }while(arr[*n-1]>0);
    *n=*n-1;
}
int cuenta(int arr[], int m){
    int k, cta;
    cta = 0;
    for(k=0; k<m; k=k+1)
        if(arr[k]>10 && arr[k]<100)
            cta++;
    return cta;
}
void imprimirResultado(int numVal, int arr[], int m){
    printf("\t=== RESULTADOS ===\nHay %d numeros que están en el rango de (10,100)\nLos numeros son: ", numVal);
    for(m=m-1; m>=0; m=m-1)
        if(arr[m]>10 && arr[m]<100)
            printf("%d\t", arr[m]);

}
int main (void){
    int num[MAX], n, numerosValidos;//n -> loc arreglos
    leer(num, &n);
    numerosValidos = cuenta(num, n);
    imprimirResultado(numerosValidos, num, n);
/*
    fflush(stdin);
    getchar();
    */
    return 0;
}