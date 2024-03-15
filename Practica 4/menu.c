#include <stdio.h>
#include "lista.h"

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
            printf("Opcion invalida o error en la entrada");
        } else
            bandera = 1;
    } while (bandera == 0);
    return opcion;
}

void ejecutaMenu() {
    int opcion;
    struct Video v;
    struct ListaVideos misVideos;
    misVideos.nVideos = 0;
    do {
        opcion = eligeOpcion();
        switch (opcion) {
            case 1: imprimeLista(&misVideos);
                    break;
            case 2: v = leer();
                    agregarVideo(&misVideos,v);
                    break;
            case 3: printf("Opcion: %d\n",opcion);
                    break;
            case 4: printf("Opcion: %d\n",opcion);
                    break;
            case 5: printf("Gracias por usar este sistema\n");
                    break;
        }
    } while (opcion!=5);
}

