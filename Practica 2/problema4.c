#include <stdio.h>
#include "essentials.h"
#include "funciones4.h"
int main (void){
    int va[MAXI], vb[MAXI], iMaxA, iMaxB;
    desplegarMenu(1, "L PROGRAMA 4: =BUSQUEDA DE SECUENCIA EN ARREGLO=", "Busca la coincidencia de la secuencia de un arreglo dentro del otro\n\n--------");
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