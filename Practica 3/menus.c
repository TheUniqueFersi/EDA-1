#include <stdio.h>
//#include "menus.h"

//#include "stringManipulation.h"
#include "stringManipulation.c"

#define mitadMenu 20

void desplegar(int menu, char * cadena1, char* cadena2, int * largoMenu){
    int k;
    char limite = '=', separador = '-';
    
    switch(menu){
        case 1://PARTE PRINCIPAL MENU
            *largoMenu = 0;
            printf("+");
            for(k=0; k<mitadMenu*2; k++){
                if(k==mitadMenu)
                    printf("[%s]", cadena1);
                printf("%c", limite);
                *largoMenu=*largoMenu+1;
            }
            *largoMenu=*largoMenu+strlenMX(cadena1)+4;
            printf("DEP: %i", *largoMenu);
            printf("+\n+ -> BIENVENID@%s!+\n", cadena2);
            break;
        case 2://Opciones
            printf("+---INDICACIONES---\n%s", cadena1);
            break;
        case 3://FINAL
            printf("+----- ESTE PROGRAMA HA TERMINADO -----+\n");
            printf("<---- Elaborado por Lopez Morales (Fer)nando (Sa)muel ---->\n");
            break;
        default: //Separador
            printf("+");
            for(k=0; k<*largoMenu-2; k=k+1)
                printf("%c", separador);
            printf("+\n");
    }
}