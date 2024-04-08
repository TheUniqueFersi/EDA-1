//#include "nodo.h"
struct nodo{
    char * nombre;
    struct nodo *ant, *sig;
};
typedef struct nodo NODO;
NODO *nuevoNodo(char *nombre);
void imprimeNodo(NODO n);