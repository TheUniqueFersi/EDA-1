//-----> Manipulación de cadenas {29-02-2024}
#include <stdio.h>
#include "menus.h"
#include "essentials.h"
#include "stringManipulation.h"
#define MAX 50
int main(void){
    char cadena[MAX];
    int largoMenu, opcionMenu;
    char opciones[] = "+ 0) SALIR\n+ 1) Convertir cadena a mayusculas\n+ 2) Convertir cadena numerica en numero ('atoi' casero)\n+ 3) Unir dos cadenas en una tercera\n";
    desplegar(1, "PRACTICA 3 - EDA I", "\0", &largoMenu);
    char cadena1[MAX], cadena2[MAX], cadena3[MAX*2];
    
    do{
        desplegar(0, 0, 0, &largoMenu);//SEPARADOR
        desplegar(2, opciones, "\0", NULL);
        desplegar(0, 0, 0, &largoMenu);//SEPARADOR
        opcionMenu=leerEntero("Ingresa una opcion: ", "Se esperaba un numero entero, intenta de nuevo - ");
        switch (opcionMenu)
        {
            case 1:
                printf("Has entrado a la opcion \"1) CONVERTIR CADENA A MAYUCULAS\"\n");
                printf("Ingresa una cadena que quieras transformar a MAYUSCULAS: ");
                bufferflush();
                fgets(cadena, MAX, stdin);//Corta en el MAX-ésimo y reemplaza dicho caracter por \0 si es que la cadena es mas grande (por ende no se desborda la memoria)
                //--TODO: MENSAJE CADENA SE EXECEDE DE LA LONGITUD MAXIMA
                //printf("%s\n", cadena);
                stringToUpper(cadena); //reemplazar por la otra funcion pro?
                printf("La cadena convertida es: %s\n", cadena);
                break;
            case 2:
                printf("Has entrado a la opcion \"2) CONVERTIR CADENA NUMERICA A NUMERO (atoi CASERO)\"\n");
                bufferflush();
                do{
                    printf("Ingresa una cadena numerica: ");
                    fgets(cadena, MAX, stdin);//Corta en el MAX-ésimo y reemplaza dicho caracter por \0 si es que la cadena es mas grande (por ende no se desborda la memoria)
                    if(isANumber(cadena)==0){
                        printf("Esto no es una cadena numerica, solo se acepta un numero sin signo (positivo), o con '-' al principio indicando que es negativo.\nEj. \"123\" o \"-123\"\n");
                    }
                }while(isANumber(cadena)==0);                
                printf("La cadena en numero es: %d\n Se demuestra dividiendo el mismo entre 2: %d\n", stoi(cadena), stoi(cadena)/2);
                break;
            case 3: 
                printf("Has entrado a la opcion \"3) UNIR DOS CADENAS EN UNA TERCERA\"\n");
                bufferflush();
                printf("Ingresa la primer cadena: ");
                fgets(cadena1, MAX, stdin);
                //bufferflush();
                printf("Ingresa la segunda cadena: ");
                fgets(cadena2, MAX, stdin);
                stringsConcat(cadena1, cadena2, cadena3);
                printf("La cadena concatenada es: %s\n", cadena3);
                break;
            case 0: 
                printf("SALIENDO DEL PROGRAMA...\n");
            default:
                printf("*** Opcion invalida, por favor ingresa una opcion del programa\n");
        }
        if(opcionMenu>0 && opcionMenu<4)
            printf("Subprograma %d ha terminado.\n", opcionMenu);
        desplegar(0, 0, 0, &largoMenu);//SEPARADOR
    } while(opcionMenu!=0);
    desplegar(3, 0, 0, NULL);
    return 0;
}