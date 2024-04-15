//#ifndef NODO_H_INCLUDED
//#define NODO_H_INCLUDED

#include "nodo.h"
struct Lista{
    struct Nodo *h;
    struct Nodo *t;
};

struct Lista *nuevaLista();
int listaEstaVacia (struct Lista *lista);
void agregarFinal(struct Nodo *nodo, struct Lista *lista);
struct Nodo *retirarInicio (struct Lista *lista);
void iterar(struct Lista *lista, void iterador(struct Nodo *nodo));
//#endif