## Definición
El Análisis de algoritmos estima el consumo de recursos de un algoritmo. 
+ Se debe distinguir entre el problemas y los casos. 
+ El algoritmo tiene que funcionar para todos los casos.
+ Encontrar un caso en el que este no funcione, demuestra que el algoritmo no funciona.
+ Se tiene que establecer el dominio de definición, que son los casos que deben considerarse.
## Enfoques
Hay dos enfoques para determinar la eficiencia:
+ **Empírico** Donde se programan diferentes soluciones y se observan resultados $\rightarrow$ inviable
+ **Teórico** Donde se determinan los recursos necesarios, programando solo el que menos requiera $\rightarrow$ Factible

Este último no depende del ordenador usado, el lenguaje o el programador.
## Recursos
Los recursos considerados son el **Espacio** y el **Tiempo**. La **eficiencia** viene dada por los tiempos de ejecución. El **tamaño** viene dado por el número de elementos que lo componen (n).
## Eficiencia
Para un problema *P* hay un algoritmo *A* que requiere un tiempo de orden *T(n)* que resuelve los n casos en menos de *T(n)* pasos. Existe una constante *c* tal que: $$T(n)\ pasos = c·T(n)\ segundos$$
Existen ciertos órdenes que se dan con frecuencia:
● Constante: T(n) = k (con k constante) 
● Logarítmico: T(n) = log(n) 
● Lineal: T(n) = n 
● Cuadrático: T(n) = n^2 
● Polinómico: T(n) = n^k (con k constante) 
● Exponencial: T(n) = k^n (con k constante)

Hay que tener en cuenta que si la complejidad es 100n pese a que al ser lineal es mejor que la cuadrática, esto no se da hasta cierto punto:
![[Pasted image 20241119200544.png]]

#### Ejemplo

Viendo el siguiente ejemplo:
![[Pasted image 20241119200634.png]]

El **mejor** caso sería encontrarlo en el primer elemento (i = 1), el cual no es representativo del comportamiento de un algoritmo.
El **peor** caso sería encontrarlo en el último elemento (i = n), el cual debe ser usado cuando el tiempo de respuesta sea crítico (en tiempo real).
El **promedio** sería encontrarlo sobre i = n/2, si se conoce la distribución de entrada se usará esta.

Una medida del comportamiento de un algoritmo es la operación elemental, aquella cuyo tiempo de ejecución no depende de valores particulares(operaciones aritméticas, lógicas, de comparación, etc ...).

La eficiencia debe ser encontrada debido a que la elección de una complejidad mayor empeora el rendimiento del algoritmo
Véase el siguiente ejemplo:
![[Pasted image 20241119201506.png]]
![[Pasted image 20241119201517.png]]
