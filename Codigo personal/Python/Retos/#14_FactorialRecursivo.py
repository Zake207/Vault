""" 
* Escribe una función que calcule y retorne el factorial de un número dado
* de forma recursiva.
 """
 
def Factorial(number) -> int :
    if (number != 1) :
        return number * Factorial(number - 1)
    else :
        return number

print(Factorial(10))