#include <stdio.h>
#include "pI-torneo.h"
#include "arch_manager.h"
int contadorBytesArch(char *ruta){
    FILE *archi = manejarAperturaArchivo(ruta, LECT_A_BIN_PLUS);
    int retorno = (archi==NULL)? -1 : 0, n_bytes;
    if(archi != NULL){
        fseek(archi, 0, SEEK_END);
        n_bytes = ftell(archi);
        //printf("Numero de bytes de %s: %i\n",ruta, n_bytes);
        rewind(archi);
        fclose(archi);
        retorno = n_bytes;
    }
    return retorno;
}
FILE *manejarAperturaArchivo(char *ruta, char *t_apertura){
    FILE *arch = fopen(ruta, t_apertura);
    if(arch == NULL && DEPUR == 1)
        printf("-!- ERROR: No se pudo abrir %s -|-\n", ruta);
    return arch;
}
int select(char *ruta, void *registro_en_codigo, size_t tam_elem, size_t num_elem){
    FILE *arch = manejarAperturaArchivo(ruta, LECT_BIN);
    if(arch!=NULL){
        rewind(arch);
        fread(registro_en_codigo, tam_elem, num_elem, arch);
        fclose(arch);
    }
    return (arch == NULL)? -1:contadorBytesArch(ruta);
}
int update(char *ruta, void *registro_en_codigo, size_t tam_elem, size_t num_elem){
    FILE *arch = manejarAperturaArchivo(ruta, LECT_BIN_PLUS);
    if(arch != NULL){
        rewind(arch);
        fwrite(registro_en_codigo, tam_elem, num_elem, arch);
        fclose(arch);
    }
    return (arch == NULL)? -1:contadorBytesArch(ruta);
}
// -- DEPURACION:
void depVerifEscCorrecta(){
    struct Torneo t;
    select(RUTA_ARCHIVO, &t, sizeof(struct Torneo), 1);
    imprimirEquipos(&t, IMP_NORMAL);
}
//Al no tener la posibilidad de eliminar registros, no se preocupa, por ahora, de idear una manera 
// de conocer cuales registros son visibles (no basura) y cuales no; todos son visibles porque siempre son 10 equipos