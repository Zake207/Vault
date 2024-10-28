Usa conocimientos adicionales al mero planteamiento del problema.
Se usa una función f(n) de evaluación, en la cual se usa h(n) como estimador de cuanto queda para llegar al final, es conocida como función heurística, esta debe ser menor o igual al valor real y es cero para el nodo objetivo.

La función g(n) es la función que calcula lo que se tarda en ir del origen hasta el nodo actual, se usa con h(n).

#### Búsqueda Voraz el primero mejor
Consiste en escoger de los nodos hijos los que tienen menor coste asumiendo que conducirá al destino
+ Es completa solo si el espacio de estado es finito y se evitan ciclo.
+ No es óptima
+ Complejidad en espacio: $O(b^m)$
+ Complejidad en tiempo: $O(b^m)$

#### Búsqueda A*
Para el algoritmo cuando se selecciona el nodo final para inspeccionar, mientras escoge el que tiene un valor f(n) = h(n) + g(n) más pequeño.

Una función heurística es admisible si nunca sobreestima el costo de llegar al destino desde n.
+ Es Completa
+ Es óptima si h(n) es admisible
Una heurística puede ser admisible si se relaja el problema, alterando las reglas para que esta pueda serlo. Además de esto la solución del problema relajado no será mayor a la solución del problema original.