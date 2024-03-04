//-----> Manipulación de cadenas {29-02-2024}
#include <stdio.h>
//#include <string.h>
#include "stringManipulation.h"
#define MAX 3

int main (){
    char cadena[MAX];
    
    
    printf("Ingresa una cadena que quieras transformar a MAYUSCULAS: ");

    fgets(cadena, MAX, stdin);//Corta en el MAX-ésimo y reemplaza dicho caracter por \0 si es que la cadena es mas grande
    printf("%s\n", cadena);

    stringToUpper(cadena);
    printf("La cadena convertida es: %s", cadena);


    return 0;
}