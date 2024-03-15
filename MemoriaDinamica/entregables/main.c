#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
int main(void){
    int *op1, *op2, res;
    op1 = malloc(sizeof(int));
    op2 = malloc(sizeof(int));
    lee(op1);
    lee(op2);
    printf("Dados los 2 numeros proporcionados, se calcula la:\n---SUMA---\n");
    suma(op1, op2, &res);
    printf("%d + %d = %d\n---RESTA---\n", *op1, *op2, res);
    resta(*op1, op2, &res);
    printf("%d - %d = %d\n", *op1, *op2, res);
    free(op1);
    free(op2);
    return 0;
}