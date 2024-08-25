"""
 * Crea una función que reciba dos cadenas como parámetro (str1, str2)
 * e imprima otras dos cadenas como salida (out1, out2).
 * - out1 contendrá todos los caracteres presentes en la str1 pero NO
 *   estén presentes en str2.
 * - out2 contendrá todos los caracteres presentes en la str2 pero NO
 *   estén presentes en str1.
"""

def Eliminar_caracteres(str1, str2) :
    print("Función 'Eliminar_caracteres' ha sido llamada")
    additional_str : str = ''
    for i in str1 :
        if not (i in str2) :
            additional_str = additional_str + i  
    print(additional_str)
    additional_str = '' 
    for i in str2 :
        if not (i in str1) :
            additional_str = additional_str + i  
    print(additional_str)  
    


str1 = input("Introduzca la primera cadena de caracteres: ")
str1 = str(str1).lower()
str2 = input("Ahora introduzca la segunad cadena de caracteres: ")
str2 = str(str2).lower()
Eliminar_caracteres(str1, str2)



"""
FORMA DE HACERLO CON SETS
===================================================
    set_of_str1 = set()
    for i in str1 :
        set_of_str1.add(i)
    set_of_str2 = set()
    for i in str2 : 
        set_of_str2.add(i)
    print(set_of_str1.difference(set_of_str2))
    print(set_of_str2.difference(set_of_str1))
===================================================


FORMA DE ELIMINARLOS EN TIEMPO DE EJECUCIÓN  --> NO ES MÍA
============================================================
    print(str1.join([x for x in str1 if x not in str2]))
    print(str2.join([x for x in str2 if x not in str1]))
============================================================
"""