#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "EDA.h"
int verifEliminacion(NODO n);
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
//Requiere que le mandes un nodo inicializado donde corresponde
NODO *busquedaElemento(LISTA *lista, char *nombre, NODO *recorrer){
    NODO *coincidencia = NULL;
    recorrer = (recorrer == NULL)? lista->h:recorrer;
    printf("Dep: llego aqui");
    if(!estaVacia(lista) && lista != NULL && nombre != NULL){ //valores invalidos
        while (recorrer != NULL && coincidencia==NULL){
            if(strcmp(recorrer->nombre, nombre)==0){
                coincidencia = recorrer;
            }
            recorrer = recorrer->sig;
        }
    }
    return coincidencia;
}

void borrarElemento(LISTA *lista, char *nombre, NODO *control){
    NODO *almacena, *q;
    control = (control == NULL)? lista->h:control;
    if(lista != NULL && nombre != NULL){
        if(!estaVacia(lista)){
            almacena=busquedaElemento(lista, nombre, control);
            if(almacena!=NULL){
                if(verifEliminacion(*(almacena))){
                    if(almacena==lista->h){
                        borrarInicio(lista);
                    } else {
                        q = almacena->ant;
                        q->sig = almacena->sig;
                        if(almacena->sig != NULL)
                            almacena->sig->ant = q;
                        free(almacena);
                    }
                } else {
                    printf("Abortando eliminacion ...\n");
                }
            } else {
                printf("No existe dicho nombre en la lista\n");
            }
        }
        
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