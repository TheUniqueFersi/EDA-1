#include "video.h"

struct ListaVideos {
    struct Video arreglo[100];
    int nVideos;
};

void imprimeLista(struct ListaVideos *lista);
void agregarVideo(struct ListaVideos *lista, struct Video v);
void borrarVideo(struct ListaVideos *lista, char *nombre);

