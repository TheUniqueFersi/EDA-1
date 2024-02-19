#include <stdio.h>
void desplegarMenu(int verifPrimeraVez){ //Muestra el menu
//Se podria modificar el archivo "principal.c" para poder sabercomunicar entre funciones si el usuario ha ingresado por primera vez
    if(verifPrimeraVez == 1)
        printf("\n===> BIENVENIDO A LA CALCULADORA INTELIGENTE DE LA FI <===\n***Si ingresaste por primera vez recuerda actualizar los valores de X y Y con la opcion 5***\n");
    printf("\n0.- SALIR Y TERMINAR PROGRAMA\n1.- SUMA\n2.- RESTA\n3.- MULTIPLICACION\n4.- INCREMENTO (sumarle 1)\n5.- INGRESAR LOS VALORES DE X y Y\n");
}
//Si se quisiera que se imprimiera el valor de X y Y para saber cuando actualizar ambos valores, se sugiere modificar los parámetros de
//la función menu(); para que pueda recibir las direcciones de X y Y en memoria: int menu(float *, float *);
int menu(){//Debe Llamar a despliega menu y pide valor
    int valorIngreso, n; char c;
    desplegarMenu(1);
    do{
        printf("Digita alguna de las anteriores opciones de acuerdo a lo que quieras hacer: \n");
        fflush(stdin); //No me funcionó
        n = scanf("%d", &valorIngreso);        //Guarda el valor de retorno de scanf para asegurar una entrada de datos exitosa
        if(n != 1 || (valorIngreso < 0 || valorIngreso > 5)){
            while((c = getchar()) != '\n' && c != EOF);
            printf("***Valor invalido, por favor ingresa solo alguna de las opciones del menu: (1-5)***\n");
            desplegarMenu(0);
        }
    }while((valorIngreso < 0 || valorIngreso > 5)||n!=1);
    return valorIngreso;
}