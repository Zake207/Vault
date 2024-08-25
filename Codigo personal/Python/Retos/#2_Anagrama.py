#  * Escribe una función que reciba dos palabras (String) y retorne
#  * verdadero o falso (Bool) según sean o no anagramas.
#  * - Un Anagrama consiste en formar una palabra reordenando TODAS
#  *   las letras de otra palabra inicial.
#  * - NO hace falta comprobar que ambas palabras existan.
#  * - Dos palabras exactamente iguales no son anagrama.

import string

def Anagrama(palabra1, palabra2):
    return sorted(palabra1.lower()) == sorted(palabra2.lower())

print("Introduzca a continuación dos palabras para comprobar que son anagramas")
palabra1 = input()
palabra2 = input()
if Anagrama(palabra1, palabra2):
    print ("Las palabras son anagramas")
else:
    print("Las palabras no son anagramas")