#include <stdio.h>
#include <stdlib.h>
void lee(int *n);
void suma(int *n1, int *n2, int *res);
void resta(int n1, int *n2, int *res);
void lee(int *n){
    char c; int verif;
    do{
        printf("Ingresa un numero entero: ");
        fflush(stdin);
        verif=scanf("%d", n);
        if(verif==0){
            while((c=getchar()) != '\n' && c != EOF);
            printf("Se esperaba un entero, intenta de nuevo - ");
        }
    }while(verif==0);
}
void suma(int *n1, int *n2, int *res){
    *res = *n1 + *n2;
}
void resta(int n1, int *n2, int *res){
    *res = n1 - *n2;
}
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