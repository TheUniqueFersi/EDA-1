#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "nodo.h"
struct Lista *nuevaLista(){
    struct Lista *nueva;
    nueva = malloc(sizeof(struct Lista));
    if(nueva==NULL){
        printf("No hay memoria suficiente para crear una lista \n");
        exit(0);
    }
    nueva->h = NULL;
    nueva->t = NULL;
    return nueva;
}
int listaEstaVacia(struct Lista *lista){
    return lista->h==NULL;
}
    
void agregarFinal(struct Nodo *nodo, struct Lista *lista){
    //struct Nodo *ultimo;
    if(listaEstaVacia(lista)){
        lista->h = nodo;
        lista->t = nodo;
    } else {
        //ultimo = lista->t;
        //ultimo->sig = nodo;
        lista->t->sig = nodo;
        lista->t = nodo;
    }
}
void iterar(struct Lista *lista, void iterador(struct Nodo *nodo)){
    struct Nodo *nodo;
    nodo = lista->h;
    while(nodo!=NULL){
        iterador(nodo);
        nodo = nodo->sig;
    }
}