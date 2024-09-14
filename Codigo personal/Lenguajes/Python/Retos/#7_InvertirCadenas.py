#  * Crea un programa que invierta el orden de una cadena de texto
#  * sin usar funciones propias del lenguaje que lo hagan de forma automática.
#  * - Si le pasamos "Hola mundo" nos retornaría "odnum aloH"

cadena = input("introduzca la cadena que desea invertir: ")
cadena_invertida = ""
longitud = len(cadena)
cadena_invertida
for i in range(1,longitud + 1):
    cadena_invertida = cadena_invertida + cadena[longitud - i]
print ("La cadena invertida es: ", cadena_invertida)