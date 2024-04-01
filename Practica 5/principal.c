#include <stdio.h>
#include "nodo.h"
#include "lista.h"
void imprimir(struct Nodo *n){
    printf("[%p] %s %d %p\n", n, n->info.nombre, n->info.pts, n->sig);
}
void incrementa(struct Nodo *nodo){
    nodo->info.pts+=1000;
}
int main(void){
    struct Lista *miLista = nuevaLista();
    struct Nodo *nodo;
    int k;
    printf("Bienvenido a este sistema\n");
    //Solicita equipos
    for(k=0; k<5; k++){
        agregarFinal(nuevoNodo(leerEquipo()), miLista);
    }
    //recorre todos los nodos

    // nodo = miLista->h;
    // while(nodo!=NULL){
        
    //     nodo = nodo->sig;
    // }
    iterar(miLista, imprimir);
    iterar(miLista, incrementa);
    

    
    return 0;
}