#  * Escribe un programa que imprima los 50 primeros números de la sucesión
#  * de Fibonacci empezando en 0.
#  * - La serie Fibonacci se compone por una sucesión de números en
#  *   la que el siguiente siempre es la suma de los dos anteriores.
#  *   0, 1, 1, 2, 3, 5, 8, 13...

primer = 0
segundo = 1
tercero = 0
print(primer, "\n", segundo)
for i in range (0,51): 
    tercero = primer + segundo
    primer = segundo
    segundo = tercero
    print(tercero)