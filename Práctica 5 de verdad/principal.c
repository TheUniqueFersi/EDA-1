#include <stdio.h>
#include "EDA.h"
#include "lista.h"
//#include "nodo.h"
//#include "nodo.h"
char *opcionesMenu(){
    char *opciones = "0)Salir.\n1)Agregar nombre\n2)Imprimir elementos de la lista\n3)Imprimir elementos de la lista de manera inversa\n4)Borrar Elemento\n";
    return opciones;
}

int main(void){
    int control;
    char mensaje [MAX_LONG_STRING], cadena[MAX_STRING];
    NODO *nodo;
    LISTA *lista = crearLista();
    sprintf(mensaje, "Ingrese una de las siguiente opciones:\n%s", opcionesMenu());
    printf("Bienvenido a este ejercicio de Listas Doblemente Ligadas\n");
    dLineaHoriz('-');
    do{    
        dLineaHoriz('-');
        control = leerEntero(mensaje, NULL);
        switch (control)
        {
            case 0:
                printf("Gracias por usar el programa, vuelva pronto!\nSaliendo del programa...\n");
                break;
            case 1:
                do{
                    leerCadena(cadena, MAX_STRING, true, DEFAULT);
                    if(busquedaElemento(lista, cadena, NULL)!=NULL)
                        printf("Ingresa otro nombre, ese ya se encuentra presente en la lista\n");
                }while(busquedaElemento(lista, cadena, NULL)!=NULL);
                nodo = nuevoNodo(cadena);
                agregarNodoFinal(lista, nodo);
                break;
            case 2:
                imprimeLista(lista);
                break;
            case 3:
                imprimeListaInversa(lista);
                break;
            case 4:
                nodo = lista->h;
                leerCadena(cadena, MAX_STRING, true, DEFAULT);
                borrarElemento(lista, cadena, nodo);
                break;
            default:
                printf("Opcion invalida, ingresa una opcion valida\n");
        }
    } while(control != 0);
    
    return 0;
}

