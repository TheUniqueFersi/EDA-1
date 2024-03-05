#include <stdio.h>
//#include "essentials.h"
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