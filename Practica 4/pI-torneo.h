#define MAXs 10
#define NEQUIPOS 2
struct Equipo {
    char nombre [MAXs];
    int pts;
    int juegosGanados;
    int juegosEmpatados;
    int juegosPerdidos;
    int locOVis; //local -> 1; visitante -> 2
};
struct Torneo {
    struct Equipo equipos[NEQUIPOS];
    float promPTS;
    float promJG;
    float promJP;
    float promJE;
};
struct Equipo leer (char texto[]);

float efectividad(struct Equipo e);

void encabezado();
void imprime(struct Equipo e, int n);
void imprimirEquipos(struct Torneo *t);
