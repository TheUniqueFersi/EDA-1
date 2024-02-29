#include <stdio.h>
#include "essentials.h"
/*4. hacer un programa que lea dos arreglos (va y vb) , 
el programa debe determinar si la secuencia de números del arreglo vb 
se encuentra en alguna parte del arreglo va, en tal caso debe indicar a 
partir de qué posición se encuentra.*/
void impresionCoincidente(int va[], int vb[], int MaxA, int MaxB, int inicioCoincidencia){
    int k, m;
    m=0;
    printf("|-va-|-vb-|\n");
    for(k=0; k<MaxA; k=k+1){
        if(va[k]!=0){
            printf("|[%d]|", va[k]);
            if(k==inicioCoincidencia){
                printf("[%d]", vb[m]);
                m=m+1;
                if(m<MaxB)
                    inicioCoincidencia++;
            }
            printf("\n");
        }
    }
}
void buscarSecuenciaVBenVA(int va[], int vb[], int iMaxA, int iMaxB){
    int coincidencias, k, m, inicioCoincidencia;
    coincidencias=0; m=0; k=0;
    while(k<iMaxA && coincidencias!=iMaxB){
            inicioCoincidencia=k;
            coincidencias=0;
            while(m<iMaxB && coincidencias!=-1){
                if(va[k+m]!=vb[m])
                    coincidencias=-1;
                else
                    coincidencias++;
                m=m+1;
            }
            k=k+1;
            m=0;
        }
        if(coincidencias == iMaxB){
            printf("\n==> La secuencia del arreglo vb esta dentro de va a partir del indice [%d], (Elemento %d)\n", inicioCoincidencia, inicioCoincidencia+1);
            impresionCoincidente(va, vb, iMaxA, iMaxB, inicioCoincidencia);
        }
        else 
            printf("La secuancia del arreglo vb no esta en el arreglo va\n"); // --TODO: imprime ambos arreglos de manera estetica
}
int main (void){
    int va[MAXI], vb[MAXI], iMaxA, iMaxB;
    desplegarMenu(1, "L PROGRAMA 4: =BUSQUEDA DE ELEMENTO EN LISTA=", "Identifica si el numero proporcionado esta o no en el arreglo, si esta, indica en que indices\n\n--------");
    llenarArregloInt(va, &iMaxA, "Ingresa un numero entero para el arreglo \"va\": ", "Se esperaba un entero, ingresa de nuevo - ");
    printf("\n-------------\n\n");
    llenarArregloInt(vb, &iMaxB, "Ingrese un numero entero para el arreglo \"vb\": ", "Se esperaba un entero, ingresa de nuevo - ");
    if(iMaxB>iMaxA)
        printf("El arreglo vb es mas grande que el va, por ende, no puede estar contenido en va.\n Intenta de nuevo.\n");
    else if (!(iMaxA>0) || !(iMaxB>0))
        printf("%s, intenta de nuevo.\n", (iMaxA<=0)? ((iMaxB<=0)? "Ambos arreglos estan vacios":"El arreglo \"va\" esta vacio") :"El arreglo \"vb\" esta vacio");
    else{
        buscarSecuenciaVBenVA(va, vb, iMaxA, iMaxB);
    }
    desplegarMenu(2, '\0', "ESTE PROGRAMA HA TERMINADO");
    return 0;
}

