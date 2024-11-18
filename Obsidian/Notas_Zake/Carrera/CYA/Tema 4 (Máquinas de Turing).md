## Conceptos básicos
#### Definición
Una Máquina de Turing es una tupla que contiene los siguientes elementos:
+ Q : Conjunto de estados.
+ Σ : Alfabeto de entrada.
+ Γ : Alfabeto de cinta.
+ q0 : Estado inicial
+ ␢ : Símbolo blanco ($), es el que diferencia Γ de Σ.
+ F : Conjunto de estados de aceptación.
+ δ : Función de transición

#### Funcionamiento
La MT tiene un cabezal de lectura y escritura, por cada símbolo que lee escribe otro y ejecuta un movimiento que puede ser izquierda, derecha o quedarse quieto.
La cinta son infinitos símbolos $, en esta se escribe la cadena que se desea analizar.
Una cadena es aceptada si la MT se queda parada estando en un estado de aceptación.
Una máquina se queda parada si para una determinada situación no tiene una transición definida.

#### Conceptos
Se define como computación a la secuencia de movimientos que conducen a la máquina desde su estado de arranque hasta una parada.

Un lenguaje es aceptado por una MT es aquel que contiene cadenas que son producidas por esa MT.

Una función de cadena es computable si desde el estado inicial, con 0 o más transiciones puedo alcanzarla.

#### Diferencias entre las MT y los AF.
Un AF solo puede leer su entrada, leer hacia la derecha y no es capaz de determinar si una cadena es aceptada o no hasta que no acabe de leerla, pues no puede quedarse parada en un estado de aceptación.

#### Ejemplo de Máquina de Turing
![[Pasted image 20241108102323.png]]

#### Combinación
Si dos máquina de Turing diferentes en estados y con los mismos alfabetos se pueden combinar haciendo que la combinación se comporte como M1 hasta que llegue a F1, entonces comenzará a comportarse como M2 y la cadena solo será aceptada cuando llegue a F2.

#### MT multi-pista
Tiene una única cinta con $n$ pistas y en cada iteración lee y escribe $n$ símbolos.
![[Pasted image 20241108103958.png]]
#### MT multi-cinta
Tiene varias cintas, cada una con su cabezal de lectura y escritura, hace un cambio de estado en función del actual y el contenido de todas las cintas, escribe en cada una de ellas y mueve de manera independiente cada una de sus cintas.
![[Pasted image 20241108104327.png]]

#### MT multidimensional
La combinación de múltiples cintas multipista.

#### MT no determinista
Para un estado y símbolo existen finitos movimientos a realizar.

#### Modificaciones
Todas las variantes introducidas tienen la misma capacidad de computo que la Máquina de Turing original.
Si la original puede hacer algo, sus variantes también pueden.

#### MT universal
Le das como entrada una máquina M y una cadena w esta actuará como M con w. Para representar M se sigue el siguiente convenio:
![[Pasted image 20241108111201.png]]

Se implementa de la siguiente manera:
![[Pasted image 20241108112040.png]]
![[Pasted image 20241108112049.png]]

## Lenguajes aceptatos por una MT
#### Definición
Un lenguaje es recursivamente enumerable si existe una MT que acepta todas sus cadenas.

Es recursivo si la MT se para con toda cadena del lenguaje aceptando, si no es del lenguaje, para y rechaza. Los lenguajes recursivos son un subconjuntos de los recursivamente enumerables.
#### MT a partir de un DFA
Se puede construir una MT M' ≡ (Q′, Σ′, Γ, ␢, q′ 0, F ′, δ′) de tal manera el lenguaje reconocido por dicha MT es el mismo que el que reconoce el DFA. Dicha maquina tiene la forma:
+ Q′ = Q ∪ {q′} (q′ /∈ Q) 
+ Σ′ = Σ 
+ Γ = Σ ∪ {␢} 
+ F′ = {q′} 
+ δ′(q, a) = (δ(q, a), a, R) ∀q ∈ Q, ∀a ∈ Σ 
+ δ′(q, ␢) = (q′, ␢, S) ∀q ∈ F

Actúa de la misma manera que el DFA, analizando la entrada de izquierda a derecha, la acepta si al llegar al final ve un blanco y se encuentra en un estado de aceptación.
#### Lenguajes regulares e independientes del contexto
Si $L\subseteq \Sigma^*$ es un lenguaje regular, entonces L es recursivo.
De la misma forma ocurre con los lenguajes independientes del contexto.
#### Lenguajes recursivos
##### Intersección
**Los lenguajes recursivos son cerrados para la intersección**, puesto que dadas dos Máquina de Turing, $M_{1}$ y $M_{2}$ que reconocen $L_{1}$ y $L_{2}$ respectivamente y paran ante cualquier cadena, dada una cadena pararán en un estado de aceptación o no. 
Por tanto se crea una Máquina de Turing con dos cintas, colocando en la primera la cadena y en la segunda se hará una copia de la misma.
M emulará a la primera máquina, si rechaza la cadena esa cadena no pertenece a la intersección, si la acepta, pasará a comportarse como la segunda maquina en la segunda cinta, si la acepta pertenece a la intersección.
M para ante cualquier cadena de entrada, por tanto es recursivo.
![[Pasted image 20241115162909.png]]
##### Unión
**Los lenguajes recursivos son cerrados para la unión**, se puede demostrar de manera similar al anterior.
![[Pasted image 20241115164017.png]]
##### Complementario
**Los lenguajes recursivos son cerrados para la complementación**.
Si L es recursivo existe una Máquina que acepta L y para ante cualquier entrada.
Se puede construir una M' que pare en un estado de no aceptación cuando la cadena sea del lenguaje y pare en uno de aceptación cuando no lo es, para cualquier cadena, esta máquina nueva se para, por lo que el complementario de L es recursivo también.
![[Pasted image 20241115165436.png]]
#### Lenguajes recursivamente enumerables
##### Unión
**Los lenguajes recursivamente enumerables son cerrados para la unión**
![[Pasted image 20241115171615.png]]
##### Complementación
**Los lenguajes recursivamente enumerables no son cerrados para el complementario**.
+ Dado un alfabeto Σ
+ Σ* es numerable de la forma {w1, w2, w3, w4, ...}
+ Las MT se pueden numerar {MT1, MT2, MT3, ...}
+ Dado L = {wi ∈ Σ∗ | wi es aceptada por Mi}
+ L es recursivamente enumerable, mientras que su complementario no.

Primero hay que desmostrar que es recursivamente enumerable.
![[Pasted image 20241115170702.png]]

Luego hay que desmostrar que su complementario no lo es.
![[Pasted image 20241115171012.png]]

Pese a esto se puede afirmar que si **L y su complementario son recursivamente enumerables, L es recursivo**.
![[Pasted image 20241115171757.png]]
##### Propiedades
Dado un lenguaje y su complementario se pueden deducir las siguientes posibilidades:
+ Los dos son recursivos
+ Ninguno es recursivamente enumerable
+ Un es recursivamente enumerable pero no recursivo y el otro no es recursivamente enumerable.
### Gramáticas no restringida
Son gramáticas de la forma $\alpha \rightarrow \beta$ siendo los dos simbolos secuencias de símbolos terminales y no terminales.

Esto implica que cualquier gramática regular o independiente del contexto es una no restringida.
##### Teorema
Si G es una gramática no restringida entonces el lenguaje generado por la gramática es recursivamente enumerable.

##### Teorema
Dado un lenguaje L $\subseteq \Sigma$* es recursivamente enumerable si y solo si es generado por una gramática no restringida.

### Gramáticas sensibles al contexto
Son gramáticas de la forma $\alpha \rightarrow \beta$ donde |$\alpha$| $\leq$ |$\beta$| 
##### Teorema
Los lenguajes sensibles al contexto contienen a los independientes al contexto
##### Teorema
Si L es sensible al contexto entonces L es recursivo, pero no todo lenguaje recursivo es sensible al contexto.
![[Pasted image 20241115173601.png]]
## Resolubilidad
Una MT puede simular un computador, puesto que este último no es más que una tripleta de Procesador, Memoria y DispositivosIO. Estas se pueden simular con una MT de la forma:
![[Pasted image 20241115174151.png]]
### Tesis 
Toda función efectivamente computable es Turing-computable.
Esto implica:
+ Cualquier algoritmo implementado por humanos u ordenadores puede ser implementado por una máquina de Turing.
+ Esto no es matemáticamente demostrable.

#### Algoritmo
Una secuencia de instrucciones simples para llevar a cabo alguna tarea.
+ Debe tener un número finito de instrucciones exactas y representadas por un número finito de símbolos.
+ Debe producir el resultado deseado en un número finito de pasos al ejecutarse sin error.
+ Puede ser ejecutado por un humano a lápiz y papel.

Dado un lenguaje recursivo, existe un algoritmo que determine si una cadena pertenece a este, sin embargo si el lenguaje es recursivamente enumerable pero no recursivo no existe ningún algortimo.
![[Pasted image 20241115175539.png]]

**El problema de la parada es un problema irresoluble**:
Sea M una MT arbitraria con un alfabeto de entrada $\Sigma$, dada una cadena perteneciente al cierre de Kleene del alfabeto *¿Parará M ante cualquier w?*
Una isntancia del problema es $Π_{HP}$ < M, w >
La solución debe ser una MT que ante cualquier codificación de una instancia del problema responda SI o NO de forma correcta.
+ Dado un alfabeto, su cierre de Kleene es enumerable
+ También se sabe que las MT pueden ser descritas como binarios, por tanto también son enumerables
+ Consideramos $L = \{w_{i} ∈ Σ^∗ | w_{i}\ no\ es\ aceptada\ por\ M_{i}\}$ que es el complementario al lenguaje diagonal tenemos que demostrar que este lenguaje no es recursivamente enumerable.
![[Pasted image 20241115184211.png]]

Ahora queda demostrar con reducción a lo absurdo que es irresoluble, suponiendo lo contrario, que es soluble
![[Pasted image 20241115184513.png]]
![[Pasted image 20241115184524.png]]

