#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "nodo.h"
#include "lista.h"

NODO *nuevoNodo(char *nombre){
    NODO *n;
    //Verificacion de cadena
    if((nombre==NULL)|| nombre[0]=='\0'){
        return NULL;
    }
    n = malloc(sizeof(NODO));
    if(n==NULL){
        printf("Se acabo la memoria\n");
        exit(1);//WTF
    }
    strcat(n->nombre, nombre);
    n->ant = n->sig = NULL;
//    strcat
    //strcpy
    return n;
}
void imprimeNodo(NODO n){
    printf("%s\n", n.nombre);
}
void agregarNodoFinal(LISTA *lista, NODO *n){
    NODO *q;
    if(lista != NULL && n != NULL){
        if(estaVacia(lista)){
            lista->h = n;
            lista->t=lista->h;
        } else {        
            q = lista->t;
            q->sig = n;
            lista->t = n;
        }
    } else {
        printf("Datos incorrectos");
    }
}