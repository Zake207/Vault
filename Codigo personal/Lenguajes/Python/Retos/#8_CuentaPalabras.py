#  * Crea un programa que cuente cuantas veces se repite cada palabra
#  * y que muestre el recuento final de todas ellas.
#  * - Los signos de puntuación no forman parte de la palabra.
#  * - Una palabra es la misma aunque aparezca en mayúsculas y minúsculas.
#  * - No se pueden utilizar funciones propias del lenguaje que
#  *   lo resuelvan automáticamente.

my_str = input("Introduca una cadena de texto:\n")
my_str = my_str.lower()
additional_str = ''
my_list = list()
my_set = set()
for i in my_str :
    if i in 'abcdefghijklmnñopqrstuvwxyz' : 
        additional_str = additional_str + i 

    elif i == ' ':
        my_list.append(additional_str)
        my_set.add(additional_str)
        additional_str = ''
my_list.append(additional_str)
my_set.add(additional_str)
for i in my_set :
    times = my_list.count(i)
    print(f"{i} aparece {times} veces.")

""" 
============================================================================

SOLUCIÓN 1:

cadena = []
print("Introduzca la cadena principal: ")
while True:
    pivote = input()
    if pivote == '_FIN_':
        break
    cadena.append(pivote)
print(cadena)

palabra = input("Ahora introduzca la palabra a contar: ")
contador = 0
for i in cadena:
    if i.lower() == palabra.lower():
        contador = contador + 1
print("La palabra aparece", contador, "veces.")

============================================================================
"""