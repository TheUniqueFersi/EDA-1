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
# Funcion para ingresar un entero solamente Wii

def leerEnteroParaTabla(cabecera): # No acepta enteros 0 ni flotantes ni enteros negativos
    var = ""
    bandera_positiva = False
    n = 0
    while type(var) != int or bandera_positiva == False:
        print(f"iteracion {n}",bandera_positiva)
        n+=1
        var = input(f"Ingresa {cabecera}: ")
        try:
            var = int(var)
            if var > 0 or var == -1:
                bandera_positiva = True
            elif var == 0:
                print("Ingresa un número mayor a cero\n")
            else:
                print("El número proporcionado no puede ser negativo\n")
        except ValueError:
            print("Esto no es un entero positivo, intenta de nuevo.")
        print(f"iteracion {n}",bandera_positiva)
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
        
def crearFila(solicitud):
    fila = []
    bandera = True
    retorno = fila
    i = 0
    while i<3 and bandera != False: 
        valor = leerEnteroParaTabla(solicitud[i])
        bandera = True if valor != -1 else False
        if bandera != False:
            fila.append(valor)
            i+=1
        else:
            retorno = -1
    print(retorno)
    return retorno

llenarTabla()
# ---------------------------------------------------
# Funciones de Ordenado de datos ... 2)


# ---------------------------------------------------
# Funciones de resolución respecto a barras ... 3)
    
    

  
# indicador = ""
# barra = 40
# dicc = {"hola": "s"}
# print(f"{dicc['hola']}")
# for n in range (5):
#     print(f"{tabla[n]}, {type(tabla[n])}")
