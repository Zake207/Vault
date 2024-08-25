""" 
* Escribe una función que calcule si un número dado es un número de Armstrong
* (o también llamado narcisista).
* Si no conoces qué es un número de Armstrong, debes buscar información
* al respecto.
"""

def IsAmstrong(number) -> bool :
    cifras = len(number)
    aux_number = 0
    for i in number :
        aux_number += int(i)**cifras
    if aux_number == int(number) :
        return True
    else :
        return False 
    
        
number : str = input("Introduzca un número para comprobar si es narcisista: ")
if IsAmstrong(number) :
    print("El numero es narcisista")
else : 
    print("El número no es narcisista")