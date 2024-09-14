#  * Escribe un programa que se encargue de comprobar si un número es o no primo.
#  * Hecho esto, imprime los números primos entre 1 y 100.

def EsPrimo(numero_argumento = 1):
    numero_argumento = int(numero_argumento)
    pivote = 1
    for i in range (1,numero_argumento):
        pivote = pivote * i
    return ((pivote + 1) % numero_argumento) == 0

for i in range (1,101):
    if EsPrimo(i):
        print(i, end=", ")
    else:
        continue
print("\n")