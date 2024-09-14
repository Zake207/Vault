"""
 * Crea una función que calcule y retorne cuántos días hay entre dos cadenas
 * de texto que representen fechas.
 * - Una cadena de texto que representa una fecha tiene el formato "dd/MM/yyyy".
 * - La función recibirá dos String y retornará un Int.
 * - La diferencia en días será absoluta (no importa el orden de las fechas).
 * - Si una de las dos cadenas de texto no representa una fecha correcta se
 *   lanzará una excepción.    
"""

# LA SIGUIENTE RESOLUCIÓN DEL EJERCICIO ES PROVICIONAL DEBIDO A LO SIGUIENTE:
# - LOS MESES NO SE RESUELVEN DE MANERA CORRECTA
# - NO SE COMPRUEBA SI LAS FECHAS SON CORRECTAS
# - NO SE COMPRUEBAN SI LOS AÑOS SON BISIESTOS


def DaysAmount(date_1, date_2) -> int :
    years = abs(int(date_1[6:10]) - int(date_2[6:10]))
    months = abs(int(date_1[3:5]) - int(date_2[3:5]))
    days = abs(int(date_1[0:2]) - int(date_2[0:2]))
    days += months * 30 + years * 365
    return days
    
date1 : str = input("Introduzca la primera fecha: ")
date2 : str = input("Ahora introduzca la segunda: ")
print("Los días que hay entre las fechas dadas son: ", DaysAmount(date1,date2), " (Aproximadamente)")