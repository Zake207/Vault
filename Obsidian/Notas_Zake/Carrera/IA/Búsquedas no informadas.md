Una búsqueda no informada no usa otra información que no sea la del problema.

Cada nodo debe conocer:
+ Estado
+ Nodo padre
+ Costo desde el inicio hasta el nodo
+ Profundidad del nodo en el árbol
+ La acción aplicada al padre para llegar al 
La eficiencia del algoritmo será mayor si generamos y/o inspeccionamos menos nodos.

Un problema viene dado por
+ Estado inicial
+ Operador (función sucesor)
+ Prueba de meta
+ Función de costo
El rendimiento viene dado por
+ Completitud
+ Optimización
+ Complejidad en tiempo
+ Complejidad en espacio
La complejidad viene dada por:
+ ramificación (b)
+ profundidad de la solución óptima (d) 
+ profundidad máx. de la información (m)

___
#### B. en anchura/amplitud
A raíz del primer nodo genero sus sucesores, nivel por nivel, compruebo cada nodo, si es el estado meta: fin, si no: genero sus sucesores.
+ Es completo si el factor de ramificación es finito.
+ Es óptima si la función de coste es monótona no decreciente.
+ Complejidad del espacio: $O(b^{(d+1)}$
+ Complejidad del tiempo: $O(b^{(d+1)}$

Generamos los nodos cuando estén en ramas diferentes para evitar ciclos.

Se puede hacer una modificación para que en vez de expandir por el nodo más superficial se expanda por el nodo con camino de menor coste.
___
#### B. primero en profundidad
Expande el árbol por el nodo más profundo disponible, una vez un nodo a sido expandido se puede quitar de memoria.
+ Es completo siempre que m sea finito.
+ No es óptima
+ Complejidad en tiempo O($b^m$)
+ Complejidad en espacio O(bm)
___
#### B. profundidad limitada
Se hace una búsqueda en profundidad de forma iterativa que aumenta poco a poco la profundidad.
+ Es completa
+ Es óptima
+ Complejidad en tiempo: $O(b^d)$
+ Complejidad en espacio: $O(bd)$
___
![[Pasted image 20241026171731.png]]
