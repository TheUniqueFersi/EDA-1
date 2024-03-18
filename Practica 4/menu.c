#include <stdio.h>
#define LARGO 25
void dLineaHoriz(char caracter){
    int k;
    for(k=0; k<LARGO; k++)
        putchar(caracter);
}