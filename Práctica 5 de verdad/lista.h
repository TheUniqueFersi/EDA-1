#include "nodo.h"

typedef struct {
    NODO *h, *t;
} LISTA;

LISTA *crearLista();
void imprimeLista(LISTA *l);
void imprimeListaInversa(LISTA *l);
NODO *busquedaElemento(LISTA *lista, char *nombre, NODO *recorrer);
int estaVacia(LISTA *l);
void borrarInicio(LISTA *l);
void borrarElemento(LISTA *lista, char *nombre, NODO *control);
void agregarNodoFinal(LISTA *l, NODO *n);