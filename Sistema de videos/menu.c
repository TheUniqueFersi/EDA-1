#include <stdio.h>
#include "lista.h"
#include "EDA.h"

#define LARGO 50
void dibujaSeparador(char c){
    int k;
    printf("\n");
    for(k=0; k<LARGO; k++)
        putchar(c);
    printf("\n\n");
}

void menu() {
    printf("(1) Mostrar la lista\n");
    printf("(2) Agregar un video\n");
    printf("(3) Borrar un video\n");
    printf("(4) Buscar un video\n");
    printf("(5) Terminar\n");
}

int eligeOpcion() {
    int res, opcion, bandera;
    bandera = 0;
    do {
        menu();
        res = scanf("%d",&opcion);
        if (res!=1 || opcion<0 || opcion >5) {
            while (getchar()!='\n'); // limpia el buffer de teclado
            printf("Opcion invalida o error en la entrada\n");
        } else
            bandera = 1;
    } while (bandera == 0);
    return opcion;
}

void ejecutaMenu() {
    int opcion, *manejarResultadosBusqueda, k;
    char nombreVideo[MAXstring];
    struct Video v;
    struct ListaVideos misVideos;
    misVideos.nVideos = 0;
    
    do {
        opcion = eligeOpcion();
        dibujaSeparador('-');
        switch (opcion) {
            case 1: //printf("DEP: %d\n", misVideos.nVideos);
                    imprimeLista(&misVideos);
                    break;
            case 2: v = leer();
                    agregarVideo(&misVideos, v);                    
                    break;
            case 3: //printf("Opcion: %d\n",opcion);
                    if(misVideos.nVideos!=0){
                        leerString(nombreVideo, "Ingresa el titulo del video que quieres borrar: ");
                        borrarVideo(&misVideos, nombreVideo);
                    } else {
                        printf("No hay videos que borrar\n");
                    }
                    
                    break;
            case 4: //printf("Opcion: %d\n",opcion);
                    if(misVideos.nVideos!=0){
                        leerString(nombreVideo, "Ingresa el titulo del video que quieres buscar: ");
                        manejarResultadosBusqueda = buscarVideo(&misVideos, nombreVideo);
                        if(manejarResultadosBusqueda != NULL && *manejarResultadosBusqueda!=0){
                            if(*manejarResultadosBusqueda == 1){
                                imprime(misVideos.arreglo[manejarResultadosBusqueda[1]]);
                            } else {
                                printf("Videos con el nombre: %s\n\n", nombreVideo);
                                for(k=1; k<=*manejarResultadosBusqueda; k++)
                                    imprime(misVideos.arreglo[manejarResultadosBusqueda[k]]);
                                    //printf("%d ", manejarResultadosBusqueda[k]);
                                //imprimir_Elem_pseudo_cola(manejarResultadosBusqueda, "Elementos con coincidencia de titulo: ");
                            }
                        } else if(manejarResultadosBusqueda == NULL)
                            printf("!! ERR: Hubo un error en memoria\n");
                        else if(*manejarResultadosBusqueda == 0)
                            printf("No hay algun video con ese nombre\n");
                    } else {
                        printf("No hay videos que buscar \n");
                    }
                    
                    break;
            case 5: printf("Gracias por usar este sistema\n");
                    break;
        }
        dibujaSeparador('-');
    } while (opcion!=5);
}