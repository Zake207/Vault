[[CyA - Tema 8 - Divide-and-Conquer.pdf|PDF]]
___
## Definición
Subdivide el problema inicial en partes pequeñas que aborda por separado, tras esto combina todas las soluciones para resolver el problema principal.
*Ad hoc* es un subalgoritmo básico dado un problema arbitrario.
### Análisis
![[Pasted image 20241129111816.png]]

Hay que ser cuidadoso a la hora de llamar un sub-algoritmo en vez de usar recursividad.
La descomposición y recomposición debe ser suficientemente eficiente.
Los subproblemas deben ser aproximadamente del mismo tamaño, dividiendo el tamaño n del problema entre una constante d para obtener p sub-problemas.
Este enfoque permite un análisis casi automático del problema.

Dado $f(n) = Θ(n^k)$ el tiempo de un algoritmo DyV para descomponer y recomponer problemas de tamaño n.
El tiempo para cada iteración es $T(n) = p · T(n / d) + n^k$ donde:
+ n: tamaño del problema en cada iteración (salvo caso base).
+ p: número de subproblemas en que se subdivide el problema.
+ d: factor de reducción de los subproblemas.
+ k: exponente que define la tasa de crecimiento Θ(nk) de la descomposición y recomposición.

![[Pasted image 20241129112942.png]]
## Búsqueda binaria
Se usa para encontrar un elemento en un conjunto ordenado, en este caso se divide a la mitad del tamaño original, su complejidad es de $\Theta(log (n))$, a continuación se muestra una versión recursiva.
![[Pasted image 20241210181343.png]]
![[Pasted image 20241210181401.png]]

### Análisis del algoritmo
Usando el Teorema Maestro:
+ Al subdividirse en cada iteración en un subproblema, p = 1
+ El tamaño de ese sub-problema es la mitad del problema de la iteracióna anterior, d = 2
+ Al descomponer como recomponer los problemas vemos una complejidad constante: f(n) = Θ(1) = Θ(n0), por tanto k = 0
+ Obtenemos que $T(n) = T(n/2) + n^{0}$
+ Como $p = 1$ y $d^k = 2^0 = 1$ su complejidad es de orden $\Theta(\log n)$ 

## Ordenación MergeSort
Dado el problema de ordenar un array de elementos de forma ascendente, el algoritmo trata de descomponer el array en dos parte de igual tamaño sucesivamente, ordenando los subarrays y fusionando ordenadamente las soluciones obtenidas.

Se puede usar la técnica del centinela asignando a la posición n+1 con valor infinito.
![[Pasted image 20241210184114.png]]
![[Pasted image 20241210184145.png]]

### Análisis del algoritmo
Teniendo en los casos no triviales que:
+ p = 2
+ d = 2
+ k = 1 debido a que el procedimiento fusionar tiene complejidad de n

Usando el **Algoritmo Maestro** tenemos que $T(n) = \Theta(n^k\log n) = \Theta (n\log n)$

#### Caso alternativo
![[Pasted image 20241210185952.png]]
