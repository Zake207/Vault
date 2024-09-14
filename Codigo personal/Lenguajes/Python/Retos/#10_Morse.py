#  * Crea un programa que sea capaz de transformar texto natural a código
#  * morse y viceversa.
#  * - Debe detectar automáticamente de qué tipo se trata y realizar
#  *   la conversión.
#  * - En morse se soporta raya "—", punto ".", un espacio " " entre letras
#  *   o símbolos y dos espacios entre palabras "  ".
#  * - El alfabeto morse soportado será el mostrado en
#  *   https://es.wikipedia.org/wiki/Código_morse.

#REVISAR SI SE PUEDE SOLUCIONAR CON UN DICCIONARIO

string_original = input("Introduzca una cadena de caracteres para transformarla en su versión: ")
string_original = string_original.lower()
string_resultado = ""
for i in range(0,len(string_original)):
    match string_original[i]:
        case "a":
            string_resultado = string_resultado + "._ "
        case "b":
            string_resultado = string_resultado + "_... "
        case "c":
            string_resultado = string_resultado + "_._. "
        case "d":
            string_resultado = string_resultado + "_.. "
        case "e":
            string_resultado = string_resultado + ". "
        case "f":
            string_resultado = string_resultado + ".._. "
        case "g":
            string_resultado = string_resultado + "__. "
        case "h":
            string_resultado = string_resultado + ".... "
        case "i":
            string_resultado = string_resultado + ".. "
        case "j":
            string_resultado = string_resultado + ".___ "
        case "k":
            string_resultado = string_resultado + "_._ "
        case "l":
            string_resultado = string_resultado + "._.. "
        case "m":
            string_resultado = string_resultado + "__ "
        case "n":
            string_resultado = string_resultado + "_. "
        case "ñ":
            string_resultado = string_resultado + "__.__ "
        case "o":
            string_resultado = string_resultado + "___ "
        case "p":
            string_resultado = string_resultado + ".__. "
        case "q":
            string_resultado = string_resultado + "__._ "
        case "r":
            string_resultado = string_resultado + "._. "
        case "s":
            string_resultado = string_resultado + "... "
        case "t":
            string_resultado = string_resultado + "_ "
        case "u":
            string_resultado = string_resultado + ".._ "
        case "v":
            string_resultado = string_resultado + "..._ "
        case "w":
            string_resultado = string_resultado + ".__ "
        case "x":
            string_resultado = string_resultado + "_.._ "
        case "y":
            string_resultado = string_resultado + "_.__ "
        case "z":
            string_resultado = string_resultado + "__.. "
        case "1":
            string_resultado = string_resultado + ".____ "
        case "2":
            string_resultado = string_resultado + "..___ "
        case "3":
            string_resultado = string_resultado + "...__ "
        case "4":
            string_resultado = string_resultado + "...._ "
        case "5":
            string_resultado = string_resultado + "..... "
        case "6":
            string_resultado = string_resultado + "_.... "
        case "7":
            string_resultado = string_resultado + "__... "
        case "8":
            string_resultado = string_resultado + "___.. "
        case "9":
            string_resultado = string_resultado + "____. "
        case "0":
            string_resultado = string_resultado + "_____ "
        case "'":
            string_resultado = string_resultado + "._.._. "
        case ".":
            string_resultado = string_resultado + "._._._ "
        case ",":
            string_resultado = string_resultado + "__..__ "
        case "?":
            string_resultado = string_resultado + "..__.. "
        case "/":
            string_resultado = string_resultado + "_.._."
        case " ":
            string_resultado = string_resultado + "  "
print(string_resultado)