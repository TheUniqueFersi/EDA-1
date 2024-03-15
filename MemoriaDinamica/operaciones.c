#include <stdio.h>
#include "operaciones.h"
void lee(int *n){
    char c; int verif;
    do{
        printf("Ingresa un numero entero: ");
        fflush(stdin);
        verif=scanf("%d", n);
        if(verif==0){
            while((c=getchar()) != '\n' && c != EOF);
            printf("Se esperaba un entero, intenta de nuevo - ");
        }
    }while(verif==0);
}
void suma(int *n1, int *n2, int *res){
    *res = *n1 + *n2;
}
void resta(int n1, int *n2, int *res){
    *res = n1 - *n2;
}