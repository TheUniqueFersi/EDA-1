# Clase {29-02-2024}
La función:

`fflush();`
NO ES ESTANDAR DE ENTRADAA!!!!! :OOO
Solo de salida


``` C
    scanf("%[^\n]s", cadena); 
```
Lo que hace esta función es que recibe la entrada hasta que encuentre un salto de línea ?


Buffer 
Escritura que se va guardando en buffer


Funciones para entrada de datos:
```C
//---Prueba para la entrada de maximos valores:
    fgets(cadena, MAX, stdin);//Corta en el MAX-ésimo y reemplaza dicho caracter por \0 si es que la cadena es mas grande
    printf("%s\n", cadena);

    scanf("%3s", cadena);//Corta en el MAX-ésimo, pero reemplaza añade el \0 uno después, por ende se estaría desbordando
    printf("%s\n", cadena);
    //gets(cadena); NOOOOOOOOOOOOO porque se desborda
```



# PROBLEMAS

## TOUPPER

## LEER UNA CADENA DE CARACTERES DEL TECLADO
Debe contener solamente numeros
Transforme la cadena a un numero entero
char[] "76984" -> int 76984

## Unir cadenas (strcat)
`strcatMX(char fte1[], fte2[], res[]);`
Dos cadenas de caracteres

