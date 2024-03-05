#include <stdio.h>
//#include "essentials.h"

int leerEntero(char * mensajeEntrada, char * mensajeError){
    int verif, entrada;
    char c;
    do{
        printf("%s", mensajeEntrada);
        fflush(stdin);
        verif=scanf("%d", &entrada);
        if(verif==0){
            while((c=getchar()) != '\n' && c != EOF);
            printf("%s", mensajeError);
        }
    }while(verif==0);
    return entrada;
}