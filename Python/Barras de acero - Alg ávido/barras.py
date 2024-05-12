# Puede haber varias tablas de la misma
# EJEMPLO DE TABLA
tabla = [[4, 500, 800],
         [10, 450, 700],
         [3, 400, 900],
         [15, 300, 750],
         [7, 600, 950]]

# ---------------------------------------------------
# Funciones de llenado de tabla: ... 1)
# Función para llenar la tabla 
def leerEntero(cabecera="un número entero"): # No acepta enteros 0 ni flotantes ni enteros negativos
    var = ""
    n = 0
    while type(var) != int:
        #print(f"iteracion {n}",bandera_positiva)
        n+=1
        var = input(f"Ingresa {cabecera}: ")
        try:
            var = int(var)
        except ValueError:
            print("Esto no es un entero positivo, intenta de nuevo.")
        #print(f"iteracion {n}",bandera_positiva)
    return var
# ---
ind = {"tramo": 0, "PROD": 1, "VENTA": 2, "RENT": 3, "CPMETRO": 4}
def llenarTabla():
    tabla = []
    solicitudes = ['el tramo del corte', 
                   'su precio de producción',
                   'su precio de venta']
    bandera = False
    while bandera != True:
        print(f"la tabla es: {tabla}")
        protolista = crearFila(solicitudes)
        if type(protolista) == list:
            tabla.append(protolista)
        else:
            if len(tabla) >= 3:
                bandera = True
                print("Has indicado la finalización del llenado de la tabla")
            else:
                print("Debes ingresar al menos 3 valores a comparar (3 filas)")
    return tabla
        
def crearFila(solicitud):
    fila = []
    bandera = True
    retorno = fila
    i = 0
    while i<3 and bandera != False: 
        valorvalido = False
        while valorvalido == False:
            valor = leerEntero(solicitud[i])
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
    print(retorno)
    return retorno

#tabla = llenarTabla()
# ---------------------------------------------------
# Funciones de Ordenado de datos ... 2)

print(F"La tabla final es: {tabla}")
def ordenarMejorCaso(tablaOrig):
    for fila in tablaOrig:
        fila.append(fila[2]-fila[1])
        fila.append(fila[3]/fila[0])
    return sorted(tabla, key=lambda x: x[4], reverse=True)

tablaOrdenada = ordenarMejorCaso(tabla)
print(tablaOrdenada)
# ---------------------------------------------------
# Funciones de resolución respecto a barras ... 3)
resultado = {"rentabilidad": 0}
valido = False
while valido != True:
    barra = leerEntero("el tamaño de una barra")
    if barra <=0:
        print("Ingresa un valor de barra válido")
    else:
        valido = True
print(barra)
#for caso in tablaOrdenada:


  
# indicador = ""
# barra = 40
# dicc = {"hola": "s"}
# print(f"{dicc['hola']}")
# for n in range (5):
#     print(f"{tabla[n]}, {type(tabla[n])}")