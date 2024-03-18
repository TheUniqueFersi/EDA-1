//--- Funciones hechas a lo largo de las prácticas previas y añadidos de la actual ---
#include <stdio.h>
#include <string.h>
//Previas
void bufferflush(){
    char c;
    while((c=getchar()) != '\n' && c != EOF);
}
int leerEntero(char * mensajeEntrada, char * mensajeError){
    int verif, entrada;
    char *mensajeDefault = "Se esperaba un entero, intente de nuevo - ";
    if(mensajeError == NULL)
        mensajeError = mensajeDefault;
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
//Nuevas (Esta práctica)
void rem1SaltoLinea(char * cadena){
    int k, tamanio;
    k=0;
    while(cadena[k] != 0){
        k++;
        if(cadena[k]=='\n')
            cadena[k] = '\0';
    }
}