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
+ La acción aplicada al padre para llegar al nodo