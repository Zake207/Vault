[[20241011_CyA-Transparencias-T2.pdf|PDF]]
___
No existe ningún método para especificar todos los lenguajes sobre un alfabeto.
## Lenguajes regulares
El conjunto de leguajes regulares se define como:
![[Pasted image 20240926174843.png]]
## Expresiones regulares
Son mecanismos formales que permiten especificar lenguajes regulares.
![[Pasted image 20240926175039.png]]
![[Pasted image 20240926175231.png]]
Sea r una expresion regular, su lenguaje será L(r).
Los operadores tienen la siguiente jerarquía:
1. $*$ == 0 o más repeticiones
2. . == Concatenación
3. | == Disyunción
Para representar lenguajes con estos operadores se pueden usar paréntesis.
Estas expresiones regulares, aunque no sean iguales en forma pueden servir para representar los mismos lenguajes.
![[Pasted image 20240926175647.png]]
![[Pasted image 20240926180103.png]]
**ES ACONSEJABLE DEMOSTRARLAS**
Existen otro operadores además de los ya nombrados.
![[Pasted image 20240928223455.png]]
![[Pasted image 20240928223524.png]]
Algunos ejemplos son
![[Pasted image 20240928223635.png]]
## Autómatas finitos
Los diagramas de transición están formados por nodos (estados) que apuntan a otros nodos mediante aristas dirigidas, a estas se les llama transcisiones y se etiquetan con símbolos del alfabeto.

Siempre se comienza por un estado inicial y se puede acabar en uno o varios estados de aceptación.
![[Pasted image 20240928224530.png]]
#### Autómata finito
Para cada estado y simbolo de entrada se puede calcular el siguiente estado. Pueden ser determinista o No determinista.
Consta de los siguientes elementos:
+ Un alfabeto de entrada Σ
+ Una colección finita de estados Q
+ Un estado inicial $s$
+ Una colección $F$ de estados finales
+ Una función δ : Q × Σ → Q.
Ejemplo:
![[Pasted image 20240928225011.png]]
La función del DFA debe estar definida para cada estado/entrada

Para representarlo se siguen los siguientes pasos:
1. Se dibuja un nodo para cada estado
2. Se dibujan los arcos pertinentes y después se marca con una flecha el estado de arranque y con doble trazo los estados finales

Los estados finales son aquellos de los cuales no se puede salir sea cual sea la entrada y además no son estados de aceptación. Suelen ser omitidos

La función se puede extender sobre las cadenas formadas por símbolos del alfabeto.
![[Pasted image 20240928230315.png]]

#### Leguaje aceptado por un DFA
Sea M un DFA definido por (Q, Σ, δ, q0, F)
L(M) es el lenguaje aceptado por el DFA. Este es el conjunto de todas las cadenas aceptadas por el DFA. Si dos DFA reconocen el mismo lenguaje se dice que son equivalentes

## Minimizar DFA
Dos estados son equivalentes si:
![[Pasted image 20241006202155.png]]
Son distinguibles si:
![[Pasted image 20241006202226.png]]

Un DFA es mínimo si todos los pares de estados son distinguibles.
![[Pasted image 20241006202433.png]]

El algoritmo de minimizar DFA comienza con dos conjuntos: El de los estados de aceptación y de estados de no aceptación.
A partir de ahi se itera con todos los símbolos del conjunto para cada partición. 
+ Si con todos los símbolos los elementos de cada partición iteran dentro de la misma partición, el conjunto se conserva.
+ Si hubiera un símbolo que provoque que los estados de una partición transiten a estados de otra partición se divide el conjunto.
+ Cuando no se pueda dividir de nuevo se tendrán todas las particiones de nodos diferentes, cada una contiene nodos de comportamiento equivalente. 
+ Basta con quedarnos con uno y redirigir las entradas de los eliminados a este.
## NFA
Es un autómata que para un estado se pueden hacer cero, una o mas de una transiciones con dicho símbolo.
Estos contienen los siguientes elementos:
![[Pasted image 20241006203507.png]]

La única diferencia se ubica en la función de transición, la cual ahora produce una partición de los estados del autómata, o lo que es lo mismo, para un símbolo de entrada, la función devuelve un conjunto de estados.
![[Pasted image 20241006203738.png]]

Las tablas de transición son ahora de la siguiente forma.
![[Pasted image 20241006203823.png]]
La función de transición funciona ahora con conjuntos de estados.
![[Pasted image 20241006203955.png]]
#### ε − transicion
Es una transición que no consume símbolos de la entrada.
Por tanto se puede decir que un estado (q0) con una ε − transicion a otro estado (q1) implica que al estar en q0 también se está en q1, si de este hubiera una ε − transicion a q2, estando en q0 se estaría tambien en q1 y q2

Para obtener todos los estados accesibles desde un estado sin consumir símbolo de la entrada se hace la ε − clausura.
![[Pasted image 20241006205308.png]]
Por lo tanto la función de transición se define ahora como:
![[Pasted image 20241006205232.png]]
![[Pasted image 20241006205524.png]]

Un ejemplo de esta nueva función sería:
![[Pasted image 20241006205558.png]]

La definición y equivalencia de los NFA y los lenguajes reconocidos no varía de la de un DFA o un NFA.

Un DFA es un caso particular de NFA, dado un NFA es posible definir un DFA.
Se utiliza el siguiente algoritmo para pasar de un NFA M ≡ (Q, Σ, δ, q0, F) a un DFA M′ ≡ (Q′, Σ, δ′, q′0, F′).
![[Pasted image 20241006210004.png]]

#### Ejemplo
![[Pasted image 20241006210103.png]]
![[Pasted image 20241006210131.png]]![[Pasted image 20241006210148.png]]
![[Pasted image 20241006210207.png]]

## Autómatas y Expresiones
Si hay dos expresiones regulares y dos autómatas que reconocen cada una de ellas.
![[Pasted image 20241008180359.png]]
![[Pasted image 20241008180434.png]]

La construcción de Thompson sobre una expresion regular (R) permite hacer la disyuncion, concatenación y asterisco.
Tienen las siguientes características:
+ Tiene a lo sumo el doble de estados que de símbolos que en R
+ Tiene un único estado de aceptación el cual no tiene transiciones salientes
+ Cada estado tiene a lo sumo dos transiciones salientes.

#### Teorema de Kleene
Si tengo un autómata finito M existe una expresión regular R tal que: L(M) = L(R).
Un lenguaje es regular si existe un autómata finito que lo acepta.

Cualquier lenguaje finito es regular porque: se puede representar como la disyunción de REVISAR!!!

#### Lema del Bombeo
![[Pasted image 20241008182728.png]]

Para demostrarlo:
+ L es regular, por ende existe un DFA mínimo M(Q, Σ, δ, q0, F) tal que L(M) = L.
+ Sea n = |Q| el numero de estados.
+ Sea z ∈ L tal que |z| = m >= n
+ El DFA acepta z, por tanto pasa por m + 1
+ Esto implica que algún nodo se repite
	![[Pasted image 20241008200329.png]]
+ Comprobamos que δ(q$_i$, v) = q$_i$ = q$_j$
+ Por ende: z′ = a1 a2...ai aj+1...am ∈ L
![[Pasted image 20241008200757.png]]

Si un lenguaje es regular se cumple el lema del bombeo.
Si no lo cumple no es regular.
Para demostrar que L no cumple el Lema del Bombeo:
+ Identificar el lenguaje L que se pretende demostrar que no es regular
+ Se elige una cadena z que cumpla z ∈ L y también |z| ≥ n. Al desconocer n la cadena debe ser en función de n.
+ Dividimos la cadena en z = uvw tal que 1 <= |uv| <= n
+ Basta con demostrar que, para cualquier n, se puede encontrar una cadena z y que, para cualquier forma de descomponer z = uvw existe un i tal que uv$^i$w !∈ L
![[Pasted image 20241008201342.png]]