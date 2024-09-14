""" 
 * Crea una función que reciba días, horas, minutos y segundos (como enteros)
 * y retorne su resultado en milisegundos.
"""

def TimeConversor(days, hours, minutes, seconds) -> float :
    return (86440000 * float(days)) + (3600000 * float(hours)) + (60000 * float(minutes)) + (1000 * float(seconds))

print("Por favor introduzca dias, horas, minutos y segundos para transformarlos en milisegundos")
days : int = input("Días: ")
hours : int = input("Horas: ")
minutes : int = input("Minutos: ")
seconds : int = input("Segundos: ")
miliseconds = TimeConversor(days, hours, minutes, seconds)
print(f"Los datos introducidos equivalen a {miliseconds} milisegundos")