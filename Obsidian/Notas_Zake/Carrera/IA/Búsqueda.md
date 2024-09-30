Un agente formula el problema, busca una solución y la ejecuta.

Al agente comienza problema con un estado inicial, se usa una función sucesor para llegar al siguiente estado.

El test objetivo si un estado es el final. Además se requiere una función de coste que establezca el coste de ir de un estado a otro.

Como resultado, para un problema tenemos un grafo que representa los diferentes estados del problema y las funciones sucesoras y de coste enlazadas a cada nodo.

+ Búsqueda no informada: solo usa la definición del problema
+ Búsqueda informada: Usa información adicional
![[Pasted image 20240918111856.png]]

Al formalizar el problema se genera un grafo, al resolverlo se genera un árbol.
Cada nodo debe conocer:
+ Estado
+ Nodo padre
+ Costo desde el inicio hasta el nodo
+ Profundidad del nodo en el árbol
+ La acción aplicada al padre para llegar al 
La eficiencia del algoritmo será mayor si generamos y/o inspeccionamos menos nodos.
## Búsquedas no informadas
Un problema viene dado por
+ Estado inicial
+ Operador
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
#### B. en anchura/amplitud
A raiz del primer nodo genero sus sucesores, nivel por nivel, compruebo cada nodo, si es el estado meta: fin, si no: genero sus sucesores.
+ Es completo si el factor de ramificación es finito
+ Es óptima si la función de coste es monótona no decreciente(todas las acciones tienen el mismo coste)
+ Complejidad del espacio: En el peor de los casos se generan todos los hijos de un nivel menos el del último que es el estado base ($b^d$ + b($b^d$ - 1)) ocurre de igual forma con la complejidad en el tiempo 
  O(b^(d+1)).
Generamos los nodos cuando estén en ramas diferentes para evitar ciclos.

#### B. primero en profundidad
Expande el árbol por el nodo más profundo disponible
+ Es completo siempre que m sea finito.
+ No es óptima
+ Una vez un nodo a sido expandido se puede quitar de memoria
+ complejidad en tiempo O($b^m$) %%Hay una errata en las diapos, es así%%
+ complejidad en espacio O(bm)
#### B. profundidad limitada
Se hace una búsqueda en profundidad de forma iterativa que aumenta poco a poco la profundidad