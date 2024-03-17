#include "lista.h"

void imprimeLista(struct ListaVideos *lista) {
   int k;
   if ((*lista).nVideos == 0){
      printf("No hay videos registrados");
      return;
   }
   for (k=0;k<(*lista).nVideos; k++) {
      printf("Video: %s\n",(*lista).arreglo[k].nombre);
   }

}

void agregarVideo(struct ListaVideos *lista, struct Video v) {
   int nx;
   nx = (*lista).nVideos;
   (*lista).arreglo[nx] = v;
   (*lista).nVideos += 1;
}

void borrarVideo(struct ListaVideos *lista, char *nombre) {


}
