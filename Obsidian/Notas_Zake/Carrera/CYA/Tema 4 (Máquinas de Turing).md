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

#### Lenguajes regulares e independientes del contexto
#### Lenguajes recursivos
#### Lenguajes recursivamente enumerables
