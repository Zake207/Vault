"""
 * Crea una función que evalúe si un/a atleta ha superado correctamente una
 * carrera de obstáculos.
 * - La función recibirá dos parámetros:
 *      - Un array que sólo puede contener String con las palabras
 *        "run" o "jump"
 *      - Un String que represente la pista y sólo puede contener "_" (suelo)
 *        o "|" (valla)
 * - La función imprimirá cómo ha finalizado la carrera:
 *      - Si el/a atleta hace "run" en "_" (suelo) y "jump" en "|" (valla)
 *        será correcto y no variará el símbolo de esa parte de la pista.
 *      - Si hace "jump" en "_" (suelo), se variará la pista por "x".
 *      - Si hace "run" en "|" (valla), se variará la pista por "/".
 * - La función retornará un Boolean que indique si ha superado la carrera.
 * Para ello tiene que realizar la opción correcta en cada tramo de la pista.
"""

def race_analiser(runner_str, field_str) -> bool:
    success = True
    race_str = ""
    if (len(runner_str) != len(field_str)) :
        print("The strings passed are not the same lenght.")
        return False
    print ("Evaluating the string passed by parameter...")
    for element in range(0, len(field_str)) :
        match runner_str[element] :
            case "r" :
                if (field_str[element] == "_") :
                    race_str += "_"
                elif (field_str[element] == "|") :
                    race_str += "/"
                    success = False
                else :
                    race_str += "?"
                    success = False
            case "j" :
                if (field_str[element] == "_") :
                    race_str += "x"
                    success = False
                elif (field_str[element] == "|") :
                    race_str += "|"
                else :
                    race_str += "?"
                    success = False
            case _:
                race_str += "!"
                success = False
    print(race_str)
    return success
        
runner = "rjmmrjrj"
field = "_||_|_ab"

print (f"The runner string: {runner}")
print(f"The field string:  {field}")
if race_analiser(runner, field) :
    print("Race was a success")
else :
    print("Race was a fiasco")