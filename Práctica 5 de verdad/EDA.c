#include <stdio.h>
#include <ctype.h>
#include "EDA.h"
#include "lista.h"
//MENUS
void dLineaHoriz(char caracter){
    int k;
    for(k=0; k<LARGO; k++)
        putchar(caracter);
    printf("\n");
}
//FUNCIONALIDADES:
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
// stringManipulation.h
//Devuelve la longitud de la cadena sin contemplar el salto de linea
int strlenEDA(char * s){//Es lo mismo que 'char s[]'
    int n;
    n=0;
    while(s[n]!=0 && s[n]!='\n')
        n=n+1;    
    return n;
}
int isANumber(char * cadena){
    int esUnNumero, k;
    esUnNumero = (cadena[0]=='-')? -1:1;
    k = (cadena[0]=='-')? 1:0;
    while(cadena[k]!='\0' && cadena[k]!='\n'){
        if(!(cadena[k] >= '0' && cadena[k] <= '9'))
            esUnNumero = 0;
        k++;
    }
    return esUnNumero;
}
void rem1SaltoLinea(char * cadena){
    int k, tamanio;
    k=0;
    while(cadena[k] != 0){
        k++;
        if(cadena[k]=='\n')
            cadena[k] = '\0';
    }
}

char *leerCadena(char *destino, int max, int remover, char *mensajeError){
    int overflow, nCaracter;
    char *mnsjError = (mensajeError == NULL)? "Ingrese de nuevo (la cadena no puede estar vacia): ": mensajeError;
    do{
        nCaracter = 0;
        do{
            destino[nCaracter] = getchar();
            nCaracter++;
        } while(destino[nCaracter-1]!='\n' && nCaracter < (max-1));
        destino[nCaracter] = 0;
        if(nCaracter>=(max-1)){
            if(destino[nCaracter-1]!='\n'){
                bufferflush();
                overflow = true;
            }
        } else 
            overflow = false;
        if(remover == true)
            rem1SaltoLinea(destino);
        if(strlenEDA(destino) == 0)
            printf("%s", mnsjError);
    } while(strlenEDA(destino) == 0);
    //return overflow;
    return destino;
}
int verifEliminacion(NODO nodo){
   char entrada;
   do{
      printf("Seguro que quieres elminar el elemento \"%s\" de la lista? (Y/N)", nodo.nombre);
      bufferflush();
      entrada = getchar();
      entrada = tolower(entrada);
      if(entrada != 'y' && entrada != 'n')
         printf("Ingresa solo ya sea (y) o (n)\n");
   }while(entrada != 'y' && entrada != 'n');
   return entrada=='y';
}