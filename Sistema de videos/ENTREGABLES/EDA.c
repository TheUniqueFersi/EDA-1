#include <stdio.h>
#include <stdlib.h>
#include "EDA.h"

int *push_int(int *arr, int n){
    char cadenaError[60];
    int *temp;
    temp = realloc(arr, sizeof(int)*((*arr)+2)); //1 por ser arregl
    sprintf(cadenaError, "!! ERR: Error en realloc al redimensionarlo a %d\n\n", (*temp)+2);
    if(!verifAlloc(arr, cadenaError)){
        (*temp)++;
        temp[*temp] = n;
    }
    return temp;
}
int verifAlloc(int *arr, char* cadena){
    if(arr == NULL)
        printf("%s", cadena);
    return arr==NULL;
}
void imprimir_Elem_pseudo_cola(int *pseudo, char *cadena){
    int k;
    printf("%s", cadena);
    for(k=1; k<=*pseudo; k++)
        printf("%d ", pseudo[k]);
    printf("\n");
}

void bufferflush(){
    char c;
    while((c=getchar()) != '\n' && c != EOF);
}
int leerEntero(char * mensajeEntrada, char * mensajeError){
    int verif, entrada;
    do{
        printf("%s", mensajeEntrada);
        fflush(stdin);
        verif=scanf("%d", &entrada);
        if(verif==0){
            bufferflush();
            printf("%s", mensajeError);
        }
    }while(verif==0);
    return entrada;
}
void leerString(char *cadena, char *mensaje){
    printf("%s", mensaje);
    bufferflush();
    //fgets(cadena, MAXstring, stdin);
    scanf("%[^\n]",cadena);
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