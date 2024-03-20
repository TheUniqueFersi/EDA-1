#include "video.h"
#define MAXARR 10

struct ListaVideos {
    struct Video arreglo[MAXARR];
    int nVideos;
};

void imprimeLista(struct ListaVideos *lista);
void agregarVideo(struct ListaVideos *lista, struct Video v);
void borrarVideo(struct ListaVideos *lista, char *nombre);

int *buscarVideo(struct ListaVideos *lista, char *nombre);

int verifEliminacion(int k);