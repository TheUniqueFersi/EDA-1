/* --[ Estas funciones se asemejan a string.h, pero lo hacemos a la antigua ]--*/
#include <stdio.h>
#include <math.h>
#include "stringManipulation.h"

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
    int ciclos, ciclosN, p=0;
    longitud=strlenMX(cadena);
    k=0;
    numeroEntero=0;
    iInicioNumero=0;
    maxIntPosible = ((int)pow(2,8*sizeof(int)));//Hal alguna forma de saber si una compu no utiliza 8 bits?
    if(longitud>0 && isANumber(cadena)!=0){
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

void stringsConcat(char * s1, char * s2, char * sr){
    int size1, size2, k;
    size1 = strlenMX(s1);
    size2 = strlenMX(s2);
    k=0;
    while(k<size1){
        sr[k] = s1[k];
        k++;
    }
    while(k<size1+size2){
        sr[k] = s2[k-size1];
        k++;
    }
    sr[k] = '\0';
}