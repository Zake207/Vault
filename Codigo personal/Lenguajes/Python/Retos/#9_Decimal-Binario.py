#  * Crea un programa se encargue de transformar un número
#  * decimal a binario sin utilizar funciones propias del lenguaje que lo hagan directamente.

entero : int = input("Introduza un número para transformarlo en binario: ")
pivote = 0
resultado = ""
while entero != 0:
    pivote = int(entero) % 2
    entero = int(entero) / 2
    resultado = str(pivote) + resultado
print ("El número pasado equivale a ", resultado, " en binario.")