#define true 1
#define false 0
#define DEFAULT ((void *)0)
void bufferflush();
int leerEntero(char * mensajeEntrada, char * mensajeError);

int strlenEDA(char * s);
int isANumber(char *cadena);
int ctoi (char caracter);
int stoi(char *cadena);

//PROTOFUNCION
int sfirstC(char * cadena, char car, int longitud);

int leerCadena(char *destino, int max, int remover, char *mensajeError);
void rem1SaltoLinea(char * cadena);