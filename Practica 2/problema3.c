#include <stdio.h>
#include "essentials.h"

/*
3. hacer un programa que lea una lista de números (posiblemente repetidos). 
Luego pregunte al usuario que numero desea buscar, 
y le diga al usuario si ese numero está o no en la lista, 
si está entonces le dice en las posiciones en donde el numero está dentro del arreglo. 
Esta búsqueda se repite hasta que el usuario introduzca un valor menor o igual a cero.
*/

int main (void){
    int listaNum[MAXI], indice, valorBusqueda, indiceCoincidencia;
    desplegarMenu(1, "L PROGRAMA 3: =BUSQUEDA DE ELEMENTO EN LISTA=", "Identifica si el numero proporcionado esta o no en el arreglo, si esta, indica en que indices");
    llenarArregloInt(listaNum, &indice);
    if(indice>0){        
        while((valorBusqueda=leerEntero("Ingresa un numero que quieras buscar en la lista previamente creada: "))>0){
            indiceCoincidencia=0;
            if((busquedaElemento(listaNum, valorBusqueda, &indiceCoincidencia, indice, "Este elemento SI se encuentra en la lista previamente dada\nLas coincidencias son:\n"))<0)
                printf("Este elemento NO se encuentra en el arreglo previamente dado\n");
            else
                printf("Dep: %d %d\t", indice, indiceCoincidencia);
                indiceCoincidencia--;
                printf("Dep: %d %d\n", indice, indiceCoincidencia);
                while(indiceCoincidencia<indice){
                    if((busquedaElemento(listaNum, valorBusqueda, &indiceCoincidencia, indice, "\0"))>=0)
                        printf("El elemento se encuentra en el indice: [%d] = %d\n", indiceCoincidencia-1, valorBusqueda);
                }
        }
    } else {
        printf("El arreglo es muy pequeño, vuelve a intentarlo\n");
    }
    desplegarMenu(2, '\0', "ESTE PROGRAMA HA TERMINADO");
    return 0;
}
