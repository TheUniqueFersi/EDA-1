#include "nodo.h"

typedef struct {
    NODO *h, *t;
} LISTA;

LISTA *crearLista();
void imprimeLista(LISTA *l);
void imprimeListaInversa(LISTA *l);
int estaVacia(LISTA *l);
void borrarInicio(LISTA *l);
void agregarNodoFinal(LISTA *l, NODO *n);