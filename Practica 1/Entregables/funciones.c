//Contiene las funciones SUMA, RESTA, MULTIPLICACION Y EL INCREMENTO (4 funciones)}
#include <stdio.h>
float suma(float x, float y){    
    printf("\n---Tus números han sido SUMADOS---\n");
    return x+y;
}
void resta(float * resultado, float x, float y){
    printf("\n---Tus números han sido RESTADOS---\n");
    *resultado = x-y;
}
void multiplicacion(float * primerFactor, float * segundoFactor, float * producto){
    printf("\n---Tus números han sido MULTIPLICADOS---\n");
    *producto = (*primerFactor)*(*segundoFactor);
}
void incremento(float * numero){
    printf("\n---Tu número ha sido INCREMENTADO---\n");
    *numero = *numero + 1;
}
float leer(float * primerNumero) {
    float segundoNumero;
    int datoCorrecto;
    char c;
    do{
        printf("Ingresa el valor de X: ");
        fflush(stdin); //No me funciona
        datoCorrecto = scanf("%f", primerNumero);
        if(datoCorrecto!=1){
            while((c = getchar()) != '\n' && c != EOF);
            printf("Dato invalido, ingresa un numero real: ");
        }
            
    }while(datoCorrecto!=1);
    do{
        printf("Ingresa el valor de Y: ");
        fflush(stdin); //No me funciona
        datoCorrecto = scanf("%f", &segundoNumero);
        if(datoCorrecto!=1){
            while((c = getchar()) != '\n' && c != EOF);
            printf("Dato invalido, ingresa un numero real: ");
        }
    }while(datoCorrecto!=1);
    printf("=== Ahora X = %f, y Y = %f ===\n", *primerNumero, segundoNumero);
    return segundoNumero;
}