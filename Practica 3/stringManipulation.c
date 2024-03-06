/* --[ Estas funciones se asemejan a string.h, pero lo hacemos a la antigua ]--*/
#include <stdio.h>
#include <math.h>
//#include "stringManipulation.h"

int strlenMX(char * s){//Es lo mismo que 'char s[]'
    int n;
    n=0;
    while(s[n]!=0 && s[n]!='\n')
        n=n+1;    
    return n;
}

void stringToUpper(char * sLower){
    int n;
    n=0;
    if(strlenMX(sLower)>0)
        while(sLower[n]!=0){            
            if(sLower[n]>='a' && sLower[n]<='z')
                sLower[n]=sLower[n]-32;            
            n++;
        }    
}

void stringToUpperOrLower(char * cadena, int caso){ //caso>=1
    int limiteIzq, limiteDer, diferencia, n;
    limiteIzq = (caso>=1)? 'a':'A';
    limiteDer = (caso>=1)? 'z':'Z';
    diferencia = (caso>=1)? 32:-32;
    n=0;
    if(strlenMX(cadena)>0){
        while(cadena[n]!=0){//mismo que decir '\0'
            if(cadena[n]>=limiteIzq && cadena[n]<=limiteDer)
                cadena[n]=cadena[n]-diferencia;
            n++;
        }
    } else
        printf("Tu cadena esta vacia\n");
}

int isANumber(char * cadena){
    int esUnNumero, k=1;
    esUnNumero = (cadena[0]=='-')? -1:1;
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

int stoi(char * cadena){//stringToInt
    int longitud, k, numeroEntero, maxIntPosible, iInicioNumero;
    longitud=strlenMX(cadena);
    k=0;
    numeroEntero=0;
    iInicioNumero=0;
    // printf("long: %d\n", longitud);
    // printf("%d\n", (int)pow(2,8*sizeof(int)));
    maxIntPosible = ((int)pow(2,8*sizeof(int)));//Hal alguna forma de saber si una compu no utiliza 8 bits?
    printf("MAX: %d\n", maxIntPosible);
    //maxIntPosible/=2;
    //printf("%d\n", maxIntPosible);
    int ciclos, ciclosN, p=0;
    if(longitud>0 && isANumber(cadena)!=0){
        //printf("%f\n", pow(10, (longitud-1)));
        if(isANumber(cadena)==-1){
            iInicioNumero = 1;
        }            
        do{
            ciclos = 0;
            ciclosN = (ctoi(cadena[longitud-1]))*10;
            printf("ciclosN: %d\n", ciclosN);
            if(p!=0){
                do{
                    printf("DEP: valor de sumas%d\n", (int)pow(10, p-1));
                    numeroEntero = numeroEntero + ((int)pow(10, p-1));
                    ciclos++;
                }while(ciclos<ciclosN && numeroEntero>0);
            } else {
                do{
                    printf("DEP: valor de sumas%d\n", (int)pow(10, p-1));
                    numeroEntero = numeroEntero + 1;
                    ciclos+=10;
                }while(ciclos<ciclosN && numeroEntero>0);
            } 
            
            printf("LOL: %d\n", numeroEntero);
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

