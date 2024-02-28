#include <stdio.h>
#include "essentials.h"
/*4. hacer un programa que lea dos arreglos (va y vb) , 
el programa debe determinar si la secuencia de números del arreglo vb 
se encuentra en alguna parte del arreglo va, en tal caso debe indicar a 
partir de qué posición se encuentra.*/

int main (void){
    int va[MAXI], vb[MAXI], iMaxA, iMaxB, iCoincidenciaA=0, iCoincidenciaB=0, inicioCoincidencia, coincidencias;
    desplegarMenu(1, "L PROGRAMA 3: =BUSQUEDA DE ELEMENTO EN LISTA=", "Identifica si el numero proporcionado esta o no en el arreglo, si esta, indica en que indices");
    llenarArregloInt(va, &iMaxA);
    llenarArregloInt(vb, &iMaxB);
    if(iMaxB>iMaxA)
        printf("El arreglo vb es mas grande que el va, por ende, no puede estar contenido en va.\n Intenta de nuevo.\n");
    else if (!(iMaxA>0) || !(iMaxB>0))
        printf("%s, intenta de nuevo.\n", (iMaxA<=0)? ((iMaxB<=0)? "Ambos arreglos estan vacios":"El arreglo \"va\" esta vacio") :"El arreglo \"vb\" esta vacio");
    else{
        while(iCoincidenciaA<iMaxA && coincidencias!=iMaxB){
            if(busquedaElemento(va, vb[0], &iCoincidenciaA, iMaxA, "\0")>=0){
                inicioCoincidencia=iCoincidenciaA-1;
                coincidencias=1;
                while(busquedaElemento(va, vb[coincidencias], &iCoincidenciaA, iMaxA, "\0")>=0 && coincidencias!=iMaxB)
                    coincidencias++;                    
                //printf("DP: %d\n", coincidencias);
            }
        }
        if(coincidencias == iMaxB)
            printf("La secuencia del arreglo vb esta dentro de va a partir del indice %d\n", inicioCoincidencia);
        else 
            printf("La secuancia del arreglo vb no esta en el arreglo va\n"); // --TODO: imprime ambos arreglos de manera estetica
    }
    desplegarMenu(2, '\0', "ESTE PROGRAMA HA TERMINADO");
    return 0;
}

