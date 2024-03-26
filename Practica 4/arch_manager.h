#include <stdio.h>
#define LECT_BIN "rb"
#define LECT_BIN_PLUS "rb+"
#define LECT_A_BIN_PLUS "ab+"
#define DEPUR 1 //definir en 0 si se requiere que los mensajes de depuracion se desactiven
#define RUTA_ARCHIVO "./equipos.dat"
int contadorBytesArch(char *ruta);
FILE *manejarAperturaArchivo(char *ruta, char *t_apertura);
int select(char *ruta, void *registro_en_codigo, size_t tam_elem, size_t num_elem);
int update(char *ruta, void *registro_en_codigo, size_t tam_elem, size_t num_elem);
void depVerifEscCorrecta();
//Al no tener la posibilidad de eliminar registros, no se preocupa, por ahora, de idear una manera 
// de conocer cuales registros son visibles (no basura) y cuales no; todos son visibles porque siempre son 10 equipos