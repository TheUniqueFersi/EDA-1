#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#define LARGOM 50
#define MAXSTRING 50
struct Equipo {
    char nombre[30];
    int pts;
};
typedef struct Equipo Equipo;
struct Nodo {
    Equipo info;
    struct Nodo *sig;
};
struct Nodo* nuevoNodo(Equipo info);

//

void desplegarSeparador(char c);
//
Equipo leerEquipo();
void bufferflush();
int leerEntero(char *mensaje, char *mensajeError);

void rem1SaltoLinea(char * cadena);
int strlenEDA(char * s);
int leerCadena(char *destino, int max, int remover, char *mensajeError);

#endif