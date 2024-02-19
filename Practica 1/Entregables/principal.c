#include <stdio.h>
#include "funciones.h"
#include "menu.h"
int main() {
    int opcion;
    float x,y,z;
    x=0.0; y=0.0;

    do{
        opcion = menu();
        switch(opcion){
            case 1: //suma
                z = suma(x,y);
                printf("%f + %f = %f\n", x, y, z);
                break;
            case 2: //resta
                resta(&z, x,y);
                printf("%f - %f = %f\n", x, y, z);
                break;
            case 3: //multiplicación
                multiplicacion(&x, &y, &z);
                printf("%f * %f = %f\n", x, y, z);
                break;
            case 4: //incremento de x
                incremento(&x);
                printf("%f\n", x);
                break;
            case 5: //Leer X y Y
                y = leer(&x);
        }
    } while (opcion != 0);
    return 0;
}
