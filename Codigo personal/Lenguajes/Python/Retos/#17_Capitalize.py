"""
 * Crea una función que reciba un String de cualquier tipo y se encargue de
 * poner en mayúscula la primera letra de cada palabra.
 * - No se pueden utilizar operaciones del lenguaje que
 *   lo resuelvan directamente.
"""

def Capitalize(string_to_capitalize) :
    capitalized_string = ""
    is_first_letter = True
    for character in string_to_capitalize:
        if (character in "abcdefghijklmnñopqrstuvwxyz") and is_first_letter:
            capitalized_string += chr(ord(character) - 32)
            is_first_letter = False
        elif character == " " : 
            is_first_letter = True
            capitalized_string += character
        else :
            capitalized_string += character
    print(f"La cadena de texto introducida se modificó a la siguiente:\n {capitalized_string}")
            
my_string = input("Introduzca una cadena de texto: ")
Capitalize(my_string)

