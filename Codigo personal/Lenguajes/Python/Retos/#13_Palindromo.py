"""
 * Escribe una función que reciba un texto y retorne verdadero o
 * falso (Boolean) según sean o no palíndromos.
 * Un Palíndromo es una palabra o expresión que es igual si se lee
 * de izquierda a derecha que de derecha a izquierda.
 * NO se tienen en cuenta los espacios, signos de puntuación y tildes.
 * Ejemplo: Ana lleva al oso la avellana.
"""

text : str = input("Introduzca una cadena para comprobar si es un palíndromo --> ")
text = text.lower()
text = text.replace(" ", "")
reversed_text = text[::-1]

print(text)
print(reversed_text)

if (text == reversed_text) :
    print("Es palíndromo")
else :
    print("No es palíndormo")

