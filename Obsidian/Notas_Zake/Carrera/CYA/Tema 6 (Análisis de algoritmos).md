[[CyA - Tema 6 - Análisis de Algoritmos .pdf|PDF]]
___
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

## Análisis asintótico
Tratar de estimar matemáticamente la cantidad de recursos que necesita el algoritmo en función del tamaño de la entrada.
### Cotas superiores: O
Indica la mayor tasa de crecimiento. 
T(n) pertenece al conjunto O(f(n)) si existen dos constantes positivas tal que: $$|T(n)| ≤ c·|f(n)|, ∀n ≥ k$$
Lo cual indica que el algoritmo siempre se va a ejecutar en menos de c*|f(n)| pasos.
De todas las cotas superiores se selecciona la menor.
![[Pasted image 20241125134643.png]]
![[Pasted image 20241125140801.png]]
### Cotas inferiores: $\Omega$ 
Indica la menor tasa de crecimiento.
T(n) pertenece al conjunto $\Omega$(f(n)) si existen dos constantes positivas tal que: $$|T(n)| ≥ c·|f(n)|, ∀n ≥ k$$
En este caso se selecciona la mayor de las cotas inferiores.
![[Pasted image 20241125141359.png]]
![[Pasted image 20241125141409.png]]
### Notación $\Theta$
Se dice que un algoritmo es de este orden si esta en los dos anteriores. Es decir, si f(n) = Ө(g(n)), entonces g(n) = Ө(f(n))
![[Pasted image 20241125143211.png]]
 De esta manera se dice que dada una entrada de datos, el algoritmo tiene una cota superior e inferior iguales.
 Si no coinciden o no se pude calcular alguna faltan datos sobre el problema.

### Reglas de simplificación
#### Transitividad
Si *f(n) ∈ O(g(n))* y *g(n) ∈ O(h(n))*, entonces *f(n) ∈ O(h(n))*.
#### Eliminación de constantes
Si *f(n) ∈ O(t·g(n)), t > 0*, entonces *f(n) ∈ O(g(n))*.
#### Instrucciones secuenciales
Si f*1 (n) ∈ O(g1 (n)) y f2 (n) ∈ O(g2 (n))*, entonces:
	*f1 (n) + f2 (n) ∈ O(max(g1 (n), g2 (n)))*
#### Bucles
Si *f1 (n) ∈ O(g1 (n)) y f2 (n) ∈ O(g2 (n))*, entonces.
	*f1 (n) · f2 (n) ∈ O(g1 (n) · g2 (n))*
### Análisis
Se realiza de dentro hacia fuera:
1. Se determina el tiempo requerido por las instrucciones individuales.
2. Se combinan estos tiempos con las estructuras de control.

+ Sean $A_1$ y $A_2$ dos fragmentos secuenciales de un algoritmo (pudiendo ser instrucciones individuales o procedimientos complicados). 

+ Sean $T_1(n)$ y $T_2(n)$ los órdenes de tiempo (tasas de crecimiento) de los dos fragmentos anteriores. 

+ La regla de composición secuencial dice que el tiempo necesario para calcular “$A_1 ; A_2$ ” es simplemente $T_1(n) + T_2(n) ∈ O(max(T_1(n), T_2(n)))$.
### Bucles "for"
Bucles del tipo
```c++
for (int i = 0; i < n; ++i) {
	std::cout << i << std::endl;
}
```
 Suponemos que el bloque de código del interior del bucle es de orden O(m). El número de pasos del bucle es de orden O(n). Usando la tercera regla de simplificación se obtiene que el tiempo total será O(m·n).

### Bucles "while"
La técnica de análisis trata de hallar una función de la variables cuyo valor se decremente en cada pasada del bucle.
Véase el siguiente ejemplo del algoritmo de búsqueda binaria.
![[Pasted image 20241125150814.png]]

+ Denotaremos $m_k = d_k - i_k$ al nº de elementos de A a analizar en cada iteración k. Al principio, $m_0 = n$ (todos).
+ El peor caso es que la última iteración t quede solo un elemento.
+ Para una posición k la posición analizada será $p = (i_k + d_k ) / 2$, para el cual hay dos opciones:
![[Pasted image 20241125152251.png]]
![[Pasted image 20241125152324.png]]

Por lo que se puede asumir que el peor caso es $m_{k+1} < m_{k} / 2$. Teniendo en cuenta lo siguiente se puede asumir que el tamaño del problema en cada iteración es de $n / 2^k$.

Por tanto en el número t de iteraciones tenemos:
![[Pasted image 20241125152823.png]]

Estos bucles se pueden simular bucles "for".
![[Pasted image 20241125153032.png]]

### Cotas de espacio.
Las técnicas usadas para calcular los requerimientos en espacio de un algoritmo son similares.
![[Pasted image 20241125153533.png]]

El principio ESPACIO vs TIEMPO se ejemplifica con la siguiente imagen:
![[Pasted image 20241125153941.png]]

Para reducir las necesidades de espacio se puede usar el empaquetado, pero desempaquetar requiere de tiempo. Por lo que se mejoran las capacidades de espacio pero empeora las del tiempo.
De manera análoga se pude pre-guardar ciertos resultados para acelerar la velocidad del algoritmo a costa del uso de más espacio.
