## Introducción
Un **experimento aleatorio** es un fenómeno observable en el que interviene el azar, la **probabilidad** surge al tratar de medir o cuantificar la posibilidad de que ocurra un determinado experimento aleatorio.

Todos los posibles resultados que se pueden obtener se recopilan en el **espacio muestral**. Un subconjunto de posibles resultados se le conoce como **suceso**, pudiendo ser estos simples o compuestos.
Existen operaciones básicas entre estos:
![[Pasted image 20241118121403.png]]

También cumplen una serie de propiedades:
![[Pasted image 20241118121439.png]]

Dado un suceso A, tiene una frecuencia absoluta $n_A$ y una frecuencia relativa $f_A$.
## Probabilidad
La P(A) es la probabilidad de que ocurra el suceso A: 
+ Es un número entre 0 y 1
+ La suma de todos los sucesos debe ser 1
+ La probabilidad de la unión de dos sucesos es igual a la suma de sus probabilidades siempre que la intersección de estos sea nula.

Si la suma de las probabilidades de todos los sucesos no es 1, entonces no se trata de una probabilidad.

Un espacio probabilístico es equiprobable si todos los sucesos tienen igual probabilidad. Para calcular probabilidades en estos casos se aplica la regla de Laplace.
![[Pasted image 20241118123120.png]]

La probabilidad de la unión de dos sucesos se calcula de la siguiente manera: $$P(A∪B)=P(A)+P(B)−P(A∩B)$$
### Probabilidad condicionada
La probabilidad de que ocurra el suceso A sabiendo que a ocurrido el suceso B se mide de la siguiente forma:
![[Pasted image 20241118123547.png]]

La probabilidad de la intersección de dos sucesos dependientes se define con la fórmula $P(A \cap B) = P(A/B)·P(B) = P(B/A)·P(A)$ 
**Ejemplo** *Una urna con 3 bolas rojas y 2 blancas. Se extrae al azar tres bolas y se pide calcular la probabilidad de que sean las tres rojas.*
$P(B1 \cap B2 \cap B3 ) = P(B1 ) P(B2 / B1 )·P(B3 / B2 \cap B1 )$


Esto no ocurre si dos sucesos son independientes, dándose las siguientes propiedades
+ P(A) = P(A/B) y P(B) = P(B/A)
+ P(A $\cap$ B $\cap$ C) = P(A) · P(B) · P(C)

### Representación en árbol
Los árboles solo se pueden usar para sucesos dependientes
![[Pasted image 20241118124818.png]]

Para calcular probabilidades en un árbol se usa el **Teorema de la Probabilidad Total**: P(B) = Ai P(B/Ai) siendo Ai el suceso anterior a B

El **Teorema de Bayes** permite calcular la probabilidad de que sabiendo que ha ocurrido B, haya ocurrido A: $$P(A /B) = \frac{P(A) · P(B/A)}{P(B)}$$
## Combinatoria
### Combinaciones de n elementos tomados de m en m
Dado n elementos se quiere averiguar el nº de grupos distintos de m elementos que se pueden formar, sin repetir elementos
No se cuenta el orden.
![[Pasted image 20241118130455.png]]
### Variaciones de n elementos tomados de m en m
Dados n elementos, se quiere averiguar el número de grupos diferentes que se pueden formar sin repetir elementos y con órdenes diferentes

![[Pasted image 20241118130546.png]]
### Permutaciones de n elementos
Dados n elementos se quiere saber de cuantas formas se pueden ordenar
![[Pasted image 20241118130612.png]]
### Variaciones con repetición de n elementos tomados de m en m
Dados n elementos, se quiere averiguar el número de grupos diferentes que se pueden formar repitiendo elementos
![[Pasted image 20241118130813.png]]
### Permutaciones con repetición
ordenaciones distintas que se pueden hacer con m elementos en los que en cada ordenación cada elemento puede aparecer repetido n veces.
![[Pasted image 20241118131635.png]]

### Combinaciones con repetición de n elementos tomados de m en m
Dados n elementos, se quiere averiguar el número de grupos de m elementos que se pueden formar. Los elementos se pueden repetir y dos grupos son diferentes si están formados por diferentes elementos.
![[Pasted image 20241118131612.png]]