"""
 * Crea un programa que comprueba si los paréntesis, llaves y corchetes
 * de una expresión están equilibrados.
 * - Equilibrado significa que estos delimitadores se abren y cieran
 *   en orden y de forma correcta.
 * - Paréntesis, llaves y corchetes son igual de prioritarios.
 *   No hay uno más importante que otro.
 * - Expresión balanceada: { [ a * ( c + d ) ] - 5 }
 * - Expresión no balanceada: { a * ( c + d ) ] - 5 }
"""

expression = input("Introduzca una expresion aritmética: ")
is_balanced = True
qeue = []
for i in expression:
    if (i == "(") | (i == "[") | (i == "{") :
        qeue.insert(0,i)
    match i :
        case ")":
            if len(qeue) != 0:
                if qeue[0] == "(" :
                    qeue.pop(0)
                else :
                    is_balanced = False
            else :
                is_balanced = False
        case "]":
            if len(qeue) != 0:
                if qeue[0] == "[" :
                    qeue.pop(0)
                else :
                    is_balanced = False
            else :
                is_balanced = False
        case "}":
            if len(qeue) != 0:
                if qeue[0] == "{" :
                    qeue.pop(0)
                else :
                    is_balanced = False
            else :
                is_balanced = False
        
        
if is_balanced :
    print("Está balanceada")
else :
    print("No está balanceada")