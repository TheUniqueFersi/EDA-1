#include <stdio.h>
#include "funciones.h"
#define MAX 30

int main(){
    int num[MAX], n, pares;
    leer(num, &n);
    pares = cuenta(num, n);
    resultado(pares, num, n);
    return 0;
}