"""
 * Crea una función que analice una matriz 3x3 compuesta por "X" y "O"
 * y retorne lo siguiente:
 * - "X" si han ganado las "X"
 * - "O" si han ganado los "O"
 * - "Empate" si ha habido un empate
 * - "Nulo" si la proporción de "X", de "O", o de la matriz no es correcta.
 * Nota: La matriz puede no estar totalmente cubierta.
 * Se podría representar con un vacío "", por ejemplo.
"""

def ThreeInLine(matrix) -> str :
    # Compruebo el número de valores
    result = "Not defined"
    amount_of_X = matrix[0].count("X") + matrix[1].count("X") + matrix[2].count("X")
    amount_of_O = matrix[0].count("O") + matrix[1].count("O") + matrix[2].count("O")
    if amount_of_O != amount_of_X or amount_of_O + amount_of_X == 9:
        result = "Null"
        return result
    # Compruebo filas y columnas
    winner_X = False
    winner_O = False
    line = ""
    column = ""
    for row in range(0,3) :
        for columns in range (0,3) :
            line += matrix[row][columns]
            column += matrix[columns][row]
        if line == "XXX" :
            winner_X = True
        elif line == "OOO" :
            winner_O = True
        if column == "XXX" :
            winner_X = True
        elif column == "OOO" :
            winner_O = True
        line = ""
        column = ""
    # Compruebo las diagonales
    diagonal = matrix[0][0] + matrix[1][1] + matrix[2][2]
    if diagonal == "XXX" :
        winner_X = True
    elif diagonal == "OOO" :
        winner_O = True
    diagonal = matrix[0][2] + matrix[1][1] + matrix[2][0]
    # Determino el ganador
    if winner_O and winner_X :
        result = "Empate"
    elif winner_X :
        result = "X"
    elif winner_O :
        result = "O"
    return result
    

my_matrix = [["O", "O", "O"],
             ["X", "X", "X"],
             [" ", "", " "]]
try :
    result = ThreeInLine(my_matrix)
except Exception as error_name:
    print(f"/// ERROR DETECTADO A CONTINUACIÓN ///\n{error_name}")
else:
    print(f"El resultado de la evaluación es: {result}")
finally:
    print("/// PROGRAMA FINALIZADO ///")


