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
void agregarNodoFinal(LISTA *l, NODO *n){
    NODO *q;
    if(l != NULL && n != NULL){
        if(l->t==NULL){
            //NODO *nNodo = nuevoNodo(leerCadena());
            l->h = n;
            l->t=l->h;
        } else {        
            q = l->t;
            q->sig = n;
            l->t = n;
        }
    } else {
        printf("Datos incorrectos");
    }
}