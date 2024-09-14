#  * Crea una única función (importante que sólo sea una) que sea capaz
#  * de calcular y retornar el área de un polígono.
#  * - La función recibirá por parámetro sólo UN polígono a la vez.
#  * - Los polígonos soportados serán Triángulo, Cuadrado y Rectángulo.
#  * - Imprime el cálculo del área de un polígono de cada tipo.

def CalculadoraDeArea(tipo_de_poligono):
    if tipo_de_poligono == 'triangulo':
        altura = input("Introduzca la altura: ")
        base = input("Ahora el ancho de la base: ")
        area = ((float(base) * float(altura)) / 2)
        return area
    elif (tipo_de_poligono == 'cuadrado') | (tipo_de_poligono == 'rectangulo'):
        altura = input("Introduzca la altura: ")
        base = input("Ahora el ancho de la base: ")
        area = float(base) * float(altura)
        return area
    else:
        print("Diculpe, el tipo de polígono es desconocido")
        return -1
    
poligono = input('Introduzca el tipo de polígono para calcular su area: ')
area = CalculadoraDeArea(poligono)
if area != -1:
    print("El area del ", poligono, " es de ", area, " metros cuadrados. ")
