[[CyA - Tema 8 - Divide-and-Conquer.pdf|PDF]]
___
## Definición
Subdivide el problema inicial en partes pequeñas que aborda por separado, tras esto combina todas las soluciones para resolver el problema principal.
*Ad hoc* es un subalgoritmo básico dado un problema arbitrario.
### Análisis
#### Ejemplo
![[Pasted image 20241129111816.png]]

Hay que ser cuidadoso a la hora de llamar un subalgoritmo en vez de usar recursividad.
La descomposición y recomposición debe ser suficientemente eficiente.
Los subproblemas deben ser aproximadamente del mismo tamaño, dividiendo el tamaño n del problema entre una constante d para obtener p subproblemas.
Este enfoque permite un análisis casi automático del problema.

Dado $f(n) = Θ(n^k)$ el tiempo de un algoritmo DyV para descomponer y recomponer problemas de tamaño n.
El tiempo para cada iteración es $T(n) = p · T(n / d) + n^k$ donde:
+ n: tamaño del problema en cada iteración (salvo caso base).
+ p: número de subproblemas en que se subdivide el problema.
+ d: factor de reducción de los subproblemas.
+ k: exponente que define la tasa de crecimiento Θ(nk) de la descomposición y recomposición.

![[Pasted image 20241129112942.png]]
### Búsqueda binaria
