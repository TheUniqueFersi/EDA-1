#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *arr, n_elementos, k;
    n_elementos = 5;
    
    // Asignación de memoria para un arreglo de 5 enteros
    arr = (int*)malloc(n_elementos * sizeof(int));
    if (arr == NULL) {
        printf("La asignación de memoria ha fallado\n");
        return 1;
    }
    
    // Se llena el arreglo con valores
    for (k = 0; k < n_elementos; k++)
        arr[k] = k;
    
    printf("Valores originales del array:\n");
    for (int i = 0; i < n_elementos; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Se redimensiona el arreglo de 5 a 10 elementos
    arr = (int*)realloc(arr, 10 * sizeof(int));
    if (arr == NULL) {
        printf("La reasignación de memoria ha fallado\n");
        return 1;
    }
    
    // Imprimir los valores del array redimensionado
    printf("Se pueden ingresar 5 valores nuevos:\n");
    for (int i = 0; i < 10; i++){
        arr[i] = i;
        printf("%d ", arr[i]);
    }
        
    printf("\n");
    
    // Se libera la memoria asignada
    free(arr);
    
    return 0;
}
