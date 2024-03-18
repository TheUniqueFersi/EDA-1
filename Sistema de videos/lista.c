#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "lista.h"

#include "EDA.h"

void imprimeLista(struct ListaVideos *lista) {
   int k;
   if ((*lista).nVideos == 0){
      printf("No hay videos registrados\n\n");
      return;
   }
   for (k=0;k<(*lista).nVideos; k++) {
      //printf("Video: %s\n",(*lista).arreglo[k].nombre);
      imprime(lista->arreglo[k]);
   }

}

void agregarVideo(struct ListaVideos *lista, struct Video v) {
   int nx;
   nx = (*lista).nVideos;
   (*lista).arreglo[nx] = v;
   (*lista).nVideos += 1;
}

int *buscarVideo(struct ListaVideos *lista, char *nombre) {
   int *pseudo_cola, k, boolCoincidencia;
   boolCoincidencia = 0;
   pseudo_cola = (int *)malloc(sizeof(int));
   //printf("DEP 0: %p\n", pseudo_cola);
   if(!(verifAlloc(pseudo_cola, "!! ERR: Error en malloc inicial\n\n"))){
      *pseudo_cola = 0;
      //printf("DEP 1: %d\n", *pseudo_cola);
      for(k=0; k<lista->nVideos; k++){
         if(strcmp(lista->arreglo[k].nombre, nombre)==0){
            //printf("DEP lsita.c: %d\n\n", *pseudo_cola);
            pseudo_cola = push_int(pseudo_cola, k);
            boolCoincidencia=1;
         }
      }
   }
   if(boolCoincidencia!=1)
      *pseudo_cola = 0;
   //printf("DEP: %d\n\n\n", *pseudo_cola);
   return pseudo_cola;
}

void borrarVideo(struct ListaVideos *lista, char *nombre) {
   int *resBusq, idVideo, indiceBusqueda, k;
   if(lista->nVideos==0){
      printf("No hay videos que borrar\n");
   } else {
      resBusq = buscarVideo(lista, nombre);
      if(resBusq != NULL && *resBusq!=0){
         if(*resBusq > 1){
               imprimir_Elem_pseudo_cola(resBusq, "Estos son los indices de elementos dentro del arreglo de videos que tienen ese mismo nombre. Cual quieres borrar? (Indica uno de los indices proporcionados): ");
         }
         do{
            indiceBusqueda = 0;
            idVideo = leerEntero("Ingresa algun indice de los videos con coincidencia de titulo: ", "Se esperaba un entero, intenta de nuevo - ");
            if(busquedaElemento(&resBusq[1], idVideo, &indiceBusqueda, *resBusq, "\0")==-1){
               printf("El elemento proporcionado no es uno de los indices proporcionado en la lista.\nSe proporciona de nuevo:\n\t");
               imprimir_Elem_pseudo_cola(resBusq, "Indices de videos con el mismo nombre: \n");
               idVideo = -1;
            }
         } while (idVideo == -1);
         if (verifEliminacion(idVideo)){//Si el usuario verifica con (y)es si eliminación
            //recorrer elementos
            for(k=idVideo; k<(lista->nVideos-1); k++)
               lista->arreglo[k] = lista->arreglo[k+1];
            lista->nVideos--;
         }
      } else if(resBusq == NULL)
         printf("!! ERR: Hubo un error en memoria\n");
      else if(resBusq == 0)
         printf("No hay algun video con ese nombre\n");
   }  
}
int verifEliminacion(int k){
   char entrada;
   do{
      printf("Seguro que quieres elminar el elemento %d de la lista de videos? (Y/N)", k);
      bufferflush();
      entrada = getchar();
      entrada = tolower(entrada);
      if(entrada != 'y' && entrada != 'n')
         printf("Ingresa solo ya sea (y) o (n)\n");
   }while(entrada != 'y' && entrada != 'n');
   return entrada=='y';
}