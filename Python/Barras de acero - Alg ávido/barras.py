# Puede haber varias tablas de la misma
# EJEMPLO DE TABLA
tabla = [[4, 500, 800],
         [10, 450, 700],
         [3, 400, 900],
         [15, 300, 750],
         [7, 600, 950]]
#ind = {"tramo": 0, "PROD": 1, "VENTA": 2, "RENT": 3, "CPMETRO": 4}
# ---------------------------------------------------
# Funciones de llenado de tabla: ... 1)
def leerEntero(cabecera="un número entero"):
    var = ""
    while type(var) != int:
        var = input(f"Ingresa {cabecera}: ")
        try:
            var = int(var)
        except ValueError:
            print("Esto no es un entero positivo, intenta de nuevo.")
    return var

def imprimirTabla(tabla):
    encabezado = "|Tramo| Precio PROD | Precio Venta |"
    print("-"*len(encabezado), f"\n{encabezado}")
    for i in tabla:
        string = f"| {i[0]} | {i[1]} | {i[2]} |"
        print("-"*len(string), f"\n{string}")
def llenarTabla():
    tabla = []
    solicitudes = ['el tramo del corte', 
                   'su precio de producción',
                   'su precio de venta']
    print("Llena la tabla de acuerdo a lo solicitado, son 3 datos por fila")
    bandera = False
    while bandera != True:
        protolista = crearFila(solicitudes, len(tabla)+1)
        if type(protolista) == list:
            tabla.append(protolista)
            imprimirTabla(tabla)
        else:
            if len(tabla) >= 3:
                bandera = True
                print("Has indicado la finalización del llenado de la tabla")
            else:
                print("!! ---> Debes ingresar al menos 3 valores a comparar (3 filas)")
    return tabla
def crearFila(solicitud, iteracion):
    fila = []
    bandera = True
    retorno = fila
    i = 0
    separador(' ')
    print("(Para salir del modo de llenado de tabla digita '-1' y presiona enter)")
    while i<3 and bandera != False: 
        valorvalido = False
        while valorvalido == False:
            valor = leerEntero(f"{solicitud[i]} (fila {iteracion})")
            if valor > 0 or valor == -1:
                valorvalido = True
            elif valor == 0:
                print("Ingresa un número mayor a cero\n")
            else:
                print("El número proporcionado no puede ser negativo\n")
        bandera = True if valor != -1 else False
        if bandera != False:
            fila.append(valor)
            i+=1
        else:
            retorno = -1
    return retorno

# ---------------------------------------------------
# Funciones de Ordenado de datos ... 2)
def ordenarMejorCaso(tablaOrig):
    for fila in tablaOrig:
        fila.append(fila[2]-fila[1])
        fila.append(fila[3]/fila[0])
    return sorted(tabla, key=lambda x: x[4], reverse=True)
# ---------------------------------------------------
# Funciones de resolución respecto a barras ... 3)
def separador(char):
    print(char*50)
def obtenerCortes(corteRestante, tabla, resultados):
    corte = 0
    pila = []
    while corteRestante != 0 and corte != len(tabla):
        posiblesCortes = int(corteRestante/tabla[corte][0])
        if posiblesCortes == 0:
            if len(pila) > 0:
                ultimoCorte = pila.pop()
                resultados[ultimoCorte] -= 1
                resultados["rentabilidad"] -= tabla[corte-1][3]
                corteRestante+=ultimoCorte
            else: 
                corte+=1
        else: 
            for i in range(posiblesCortes):
                corteRestante -= tabla[corte][0]
                pila.append(tabla[corte][0])
                resultados[tabla[corte][0]] = resultados[tabla[corte][0]]+1 if resultados.get(tabla[corte][0]) else 1
                resultados["rentabilidad"] += tabla[corte][3]
            corte+=1    
    return -1 if corteRestante!=0 else 0
def solicitarCorte(resultado, tablaOrdenada):
    resultado = {"rentabilidad": 0}
    barra = 0
    while barra <=0 :
        barra = leerEntero("el tamaño de una barra")
        if barra <=0:
            print("Ingresa un valor de barra válido")
    if obtenerCortes(barra, tablaOrdenada, resultado) == 0:
        print(f"--> Para cortar una barra de {barra}[m] y tener la mejor rentabilidad, se debe cortar de la siguiente forma:")
        for i in range(len(tablaOrdenada)):
            corte = resultado.get(tablaOrdenada[i][0])
            if corte:
                print("{} corte{} de {}[m]".format(corte, 
                                                's' if corte > 1 else '', 
                                                tablaOrdenada[i][0]))
        print(f"Con una rentabilidad de ${resultado["rentabilidad"]}")
    else: print("¡¡¡ No hay solución para la barra proporcionada !!!")
print("="*25)
print("Bienvenido a este programa donde aseguras la mayor rentabilidad de una barra dados unos cortes indivisibles")
separador("-")
bucle = ""
resultado = {}
tabla = llenarTabla()
print(F"La tabla final es: {tabla}")
tablaOrdenada = ordenarMejorCaso(tabla)
print("La tabla ordenada es: {}".format(tablaOrdenada))
solicitarCorte(resultado, tablaOrdenada)
while bucle.lower() != "no":
    print("\n")
    separador('-')
    bucle = input("¿Deseas calcular otra rentabilidad? (Si/No): ")
    if(bucle.lower() == "no"):
        print("¡Gracias por usar este programa!\n---Elaborado por: López Morales Fernando Samuel---")
        separador('=')
    elif bucle.lower() == "si": 
        solicitarCorte(resultado, tablaOrdenada)
    else:
        print("Opción no válida, ingrese de nuevo")