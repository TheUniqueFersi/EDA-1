#include <stdio.h>
#define MAXI 50
void desplegarMenu(char * nombre, char * explicacion){
    //Bienvenida
    printf("+---|| BIENVENID@ A%S  ||---+\n", nombre); //Como hacer 
    printf("Este programa %s", explicacion);
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
            printf("Se esperaba un número entero, ingresa nuevamente por favor: ");
        }
    }while(verif==0);
    return entrada;
}

void llenarArregloInt(int arr[], int * nElem){
    int n;
    n=0;
    while (n<MAXI && arr[*nElem] > 0){
        arr[n] = leerEntero("Ingresa un numero entero: ");
        if(arr[*nElem]>0)
            *nElem++;
    }
    if(n>=MAXI)
        printf("------// Has alcanzado el limite de valores para el arreglo\n");
}
int busquedaElemento(int v[], int elemento, int * indice){

    
}