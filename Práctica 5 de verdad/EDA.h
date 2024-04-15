
#define true 1
#define false 0
#define LARGO 25
#define MAX_LONG_STRING 200
#define MAX_STRING 50
#define DEFAULT ((void *)0)
//DISEÑO DE MENU:
void dLineaHoriz(char caracter);

//FUNCIONALIDADES:
void bufferflush();
int leerEntero(char * mensajeEntrada, char * mensajeError);

int strlenEDA(char * s);
int isANumber(char *cadena);

void rem1SaltoLinea(char * cadena);
char *leerCadena(char *destino, int max, int remover, char *mensajeError);