#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "EDA.h"

LISTA *crearLista(){
    LISTA *l;
    l=malloc(sizeof(LISTA));
    if(l==NULL){
        printf("Ya no hay memoria");
    }
    l->h = NULL;
    l->t = NULL;
    return l;
}

void imprimeLista(LISTA *l){
    if(l->h==NULL){
        printf("La lista esta vacia\n");
    } else {
        NODO *q;
        q = l->h;
        while(q != NULL){
            imprimeNodo(*q);
            q=q->sig;
        }
    }
}
void imprimeListaInversa(LISTA *l){
    if(l->t==NULL){
        printf("La lista esta vacia\n");
    } else {
        NODO *q;
        q = l->t;
        while(q != NULL){
            imprimeNodo(*q);
            q=q->ant;
        }
    }
}
void borrarInicio(LISTA *l){
    NODO *nod;
    if(l != NULL){
        if(!estaVacia(l)){
            //solo tiene uno
            if(l->t == l->h){
                free(l->h);
                l->h = l->t = NULL;
            } else { //tiene mas de uno
                nod = l->h;
                free(nod);
                l->h = l->h->sig;
            }
        } else {
            printf("La lista esta vacia");
        }
    } else {
        printf("Argumentos inválidos");
    }
}

int estaVacia(LISTA *l){
    int retorno = 0;
    if(l != NULL){
        retorno = (l->h!=NULL)? true:false;
    } else {
        printf("Argumentos inválidos");
    }
    return retorno;
}