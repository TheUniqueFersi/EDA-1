//--- Funciones hechas a lo largo de las prácticas previas y añadidos de la actual ---
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "EDA.h"
#include "pI-torneo.h"
//=== Previas ===

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

int ctoi(char caracter){
    return caracter - 48;
}

//PROTO - FUNCION
int sfirstC(char *cadena, char car, int longitud) //String First Coincidence
{
    int coincidencia, k;
    for(k=0, coincidencia=0;k<longitud;k++){
        if(cadena[k]==car){
            coincidencia=k;
            k=longitud;
        }
    }
    return (coincidencia==0)? -1: coincidencia;
}

//NUEVA

int leerCadena(char *destino, int max, int remover, char *mensajeError){
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
    return overflow;
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



//DEPRECATED
int stoi(char * cadena){//stringToInt
    int longitud, k, numeroEntero, maxIntPosible, iInicioNumero;
    int ciclos, ciclosN, p=0;
    longitud=strlenEDA(cadena);
    k=0;
    numeroEntero=0;
    iInicioNumero=0;
    maxIntPosible = ((int)pow(2,8*sizeof(int)));//Hal alguna forma de saber si una compu no utiliza 8 bits?
    if(longitud == 1 && *cadena == '0')
        numeroEntero = 0;
    else if((longitud>0 && isANumber(cadena)!=0)){
        if(isANumber(cadena)==-1){
            iInicioNumero = 1;
        }
        do{
            ciclos = 0;
            ciclosN = (ctoi(cadena[longitud-1]))*10;
            if(p!=0){
                do{
                    numeroEntero = numeroEntero + ((int)pow(10, p-1));
                    ciclos++;
                }while(ciclos<ciclosN && numeroEntero>0);
            } else {
                do{
                    numeroEntero = numeroEntero + 1;
                    ciclos+=10;
                }while(ciclos<ciclosN && numeroEntero>0);
            }
            p++;
            longitud--;
        }while(longitud!=iInicioNumero && numeroEntero>0);
        if(numeroEntero<0)
            numeroEntero = maxIntPosible;
        else
            if(isANumber(cadena)==-1)
                numeroEntero*=-1;
    }
    return numeroEntero;
} 
//2147483647 -> numero maximo

// printf("%d %d\n", isANumber("0"), stoi("0"));
//     printf("%d %d\n", isANumber("-1"), stoi("-1"));
//     printf("%d %d\n", isANumber("10"), stoi("10"));
//     printf("%d %d\n", isANumber("100"), stoi("100"));
//     printf("%d %d\n", isANumber("10000"), stoi("12943"));
//     printf("%d %d\n", isANumber("10001"), stoi("100001"));
//     printf("%d %d\n", isANumber("a"), stoi("a"));
//     printf("%d %d\n", isANumber("1"), stoi("1"));
//     printf("%d %d\n", isANumber("12222222222222222"), stoi("12222222222222"));
//     printf("%d %d\n", isANumber("hoa211kw"), stoi("hoa211k"));
//     printf("%d %d\n", isANumber("-12fff"), stoi("-12fff"));
//     printf("%d %d\n", isANumber("00f"), stoi("00f"));
//     printf("%d %d\n", isANumber("lol"), stoi("alol"));
