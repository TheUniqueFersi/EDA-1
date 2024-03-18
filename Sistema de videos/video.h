#include "EDA.h"
struct Fecha {
    int dia, mes, anio;
};

struct Video {
    char nombre[MAXstring];
    float duracion;
    struct Fecha fecha;
    char calidad[10];
    int n_rep;
};

// prototipos
void imprime(struct Video v);
struct Video leer(void);
char *strFecha(char cadena[], struct Fecha f);