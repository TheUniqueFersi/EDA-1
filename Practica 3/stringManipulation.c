/* --[ Estas funciones se asemejan a string.h, pero lo hacemos a la antigua ]--*/
#include <stdio.h>
#include "stringManipulation.h"

int strlenMX(char * s){//Es lo mismo que 'char s[]'
    int n;
    n=0;
    while(s[n]!=0)
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