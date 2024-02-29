#include <stdio.h>
#include "essentials.h"
int main (void){
    int listaNum[MAXI], indice, valorBusqueda, indiceCoincidencia;
    desplegarMenu(1, "L PROGRAMA 3: =BUSQUEDA DE ELEMENTO EN LISTA=", "Identifica si el numero proporcionado esta o no en el arreglo, si esta, indica en que indices");
    llenarArregloInt(listaNum, &indice, "Ingresa un numero entero para llenar el arreglo: ", "Se esperaba un entero, intenta de nuevo - ");
    if(indice>0){        
        while((valorBusqueda=leerEntero("Ingresa un numero que quieras buscar en la lista previamente creada: ", "Se esperaba un entero, intenta de nuevo - "))>0){
            indiceCoincidencia=0;
            if((busquedaElemento(listaNum, valorBusqueda, &indiceCoincidencia, indice, "Este elemento SI se encuentra en la lista previamente dada\nLas coincidencias son:\n"))<0)
                printf("Este elemento NO se encuentra en el arreglo previamente dado\n");
            else
                indiceCoincidencia--;
                while(indiceCoincidencia<indice){
                    if((busquedaElemento(listaNum, valorBusqueda, &indiceCoincidencia, indice, "\0"))>=0)
                        printf("El elemento se encuentra en el indice: [%d] = %d (Elemento %d)\n", indiceCoincidencia-1, valorBusqueda, indiceCoincidencia);
                }
        }
    } else {
        printf("El arreglo esta vacio, vuelve a intentarlo\n");
    }
    desplegarMenu(2, '\0', "ESTE PROGRAMA HA TERMINADO");
    return 0;
}
