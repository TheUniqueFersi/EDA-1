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

def leerEnteroParaTabla(cabecera, excepcion="-1"): # No acepta enteros 0 ni flotantes ni enteros negativos
    var = ""
    bandera_positiva = False
    while type(var) != int and bandera_positiva == False:
        var = input(f"Ingresa {cabecera}")
        if(var != excepcion):
            try: 
                var = int(var)
                if var > 0:
                    bandera_positiva = True
                elif var == 0:
                    print("Ingresa un número mayor a cero\n")
                else:
                    print("El número proporcionado no puede ser negativo\n")
            except ValueError:
                print("Esto no es un entero positivo, intenta de nuevo.")
        else:
            var = -1
    return var
# ---
ind = {"tramo": 0, "PROD": 1, "VENTA": 2, "RENT": 3, "CPMETRO": 4}
tabla = []
def llenarTabla():
    tabla = []
    solicitud = ['el tramo del corte', 
                   'su precio de producción',
                   'su percio de venta']
    valor = ""
    while bandera != False:
        fila = []
        bandera = False
        for i in range(3):
            valor = leerEnteroParaTabla(solicitud[i])
            if valor == -1:
                bandera = True

        if()

# ---------------------------------------------------
# Funciones de Ordenado de datos ... 2)
crearTabla()

# ---------------------------------------------------
# Funciones de resolución respecto a barras ... 3)
    
    llenarFila()

  
# indicador = ""
# barra = 40
# dicc = {"hola": "s"}
# print(f"{dicc['hola']}")
# for n in range (5):
#     print(f"{tabla[n]}, {type(tabla[n])}")
