#include <stdio.h>
#include <stdlib.h>
int main(void){
    // Se reserva memoria para un entero
    int *direccion_numero = malloc(sizeof(int));

    //Se verifica si la asignacion de memoria fue exitosa
    if(direccion_numero == NULL){
        printf("Error: No se pudo asignar memoria. \n");
        return 1; //O:
    }
    //Asigna un valor al entero
    *direccion_numero = 16;

    //Direccion del apuntador
    printf("La direccion de la variable direccion_numero es: %p\n", &direccion_numero);
    //Direccion que guarda el apuntador
    printf("El contenido de la variable (que es un apuntador) direccion_numero es: %p\n", direccion_numero);
    //Se muestra el valor del entero
    printf("El numero que almacena direccion_numero es: %d\n", *direccion_numero);

    // Se libera la memoria asignada por malloc(), pues ya no la usaremos y es buena práctica liberarla
    free(direccion_numero);

    return 0;
}