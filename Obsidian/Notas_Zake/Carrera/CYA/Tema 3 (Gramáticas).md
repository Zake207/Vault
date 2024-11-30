[[20241025_CyA-Transparencias-T3.pdf|PDF]]
___
## Gramáticas regulares
Una gramática regular es una tupla G = (Σ, N, S, P )
+ Σ : alfabeto
+ N : conjunto de símbolos no terminales
+ S es un no terminal llamado símbolo inicial (start) o de arranque
+ P : es un conjunto de reglas de sustitución denominadas producciones, tales que (caben dos alternativas):
	+ O bien todas las producciones son lineales por la derecha, por lo que es una gramática lineal por la derecha:
			A → uB|v (A, B ∈ N y u, v ∈ Σ∗)
 + O todas las producciones son lineales por la izquierda, por lo que es una gramática lineal por la izquierda:
			A → Bu|v (A, B ∈ N y u, v ∈ Σ∗)

El lenguaje generado por una gramática se denota como L(G)

Dado un DFA M y su lenguaje L(M) existe una gramática regular G tal que L(G) = L(M), G sera de la forma G ≡ (Σ′, N, S, P ) donde:
+ Σ′ = Alfabeto del DFA
+ N = Q
+ S = s
+ P = {q → ap | δ(q, a) = p} ∪ {q → ε | q ∈ F }
![[Pasted image 20241018164730.png]]

También se puede afirmar que existe un NFA M de la forma M ≡ (Q, Σ′, δ, q0, F ) tal que L(M) = L(G), siendo G una gramática de la forma G ≡ (V, Σ, S, P ). Dicho NFA tendrá la forma siguiente: Σ′ = Σ, Q = V ∪ {f }, F = {f }, q0 = S.
![[Pasted image 20241018165717.png]]![[Pasted image 20241018170053.png]]
![[Pasted image 20241018170104.png]]
![[Pasted image 20241018170114.png]]
![[Pasted image 20241018170150.png]]
## Gramática independiente del contexto
Es una gramática con la siguiente forma G = (V, Σ, S, P )
en donde:
+ V es el conjunto de símbolos no terminales (V̸ = ∅)
+ Σ es el conjunto de símbolos terminales o alfabeto de la gramática (V ∩ Σ = ∅)
+ S es un no terminal que se llama símbolo de arranque o axioma de la gramática (S ∈ V )
+ P es un conjunto de reglas de producción:
	+ P = {A → α | A ∈ V, α ∈ (V ∪ Σ)∗}
	+ P ⊆ V × (V ∪ Σ)∗
	+ P != ∅

Se sigue el siguiente convenio:
+ Símbolos terminales: Minúsculas del principio del alfabeto latino.
+ Símbolos no terminales: Mayúsculas del principio alfabeto latino.
+ Símbolos gramaticales: Mayúsculas del final del alfabeto latino.
+ Cadenas: Minúsculas del final de alfabeto latino.
+ Cadenas de símbolos gramaticales: Letras griegas.

La derivación consiste en en sustituir los símbolos no terminales según las reglas de producción.

+ Ejemplo:

![[Pasted image 20241018172705.png]]
![[Pasted image 20241018172804.png]]

Por tanto se puede dar la siguiente definición:
![[Pasted image 20241018173213.png]]
Este lenguaje será independiente del contexto.

La Clasificación de Chomsky
![[Pasted image 20241018174351.png]]
## Árboles de análisis sintáctico (AAS)
+ El nodo raiz es el símbolo de arranque de la gramática.
+ Los nodos internos son símbolos no terminales
+ Los nodos hoja son símbolos terminales o con épsilon.
![[Pasted image 20241018175405.png]]

La derivación canónica se define como la sucesiva sustitución de los símbolos no terminales que estén más a la derecha o más a la izquierda, si no se sigue alguno de los dos órdenes, la sustitución no será canónica.


Una gramática es ambigua si existe alguna cadena para la cual hay más de un AAS.
## Simplificación de gramáticas
Un símbolo X ∈ (Σ ∪ V) si existe una derivación que resulte un una cadena.
![[Pasted image 20241018182555.png]]

### Símbolos inútiles
Para eliminar símbolos y producciones inútiles se siguen dos etapas.
+ Etapa 1: Eliminar no terminales que no deriven en una cadena de Σ* y las producciones en las que aparezca.
![[Pasted image 20241018183535.png]]
+ Etapa 2: Eliminar no terminales los cuales sean inaccesibles.
![[Pasted image 20241018184118.png]]

![[Pasted image 20241018184617.png]]

### Producciones vacías
Una producción es vacía si es de la forma A → ε.
Para eliminarlas se sigue el siguiente algoritmo, eliminando todas las producciones vacías y teniendo en cuenta que si el estado inicial produce la cadena vacía es que esta puede ser generada por la gramática y por tanto es parte del lenguaje.
1. Primero se calcula el conjunto de variables vacías.
![[Pasted image 20241110185901.png]]
2. Después se eliminan las producciones vacías, donde quiera que se vea un no terminal que tubo la cadena vacía se deben crear dos producciones, una en la que no este el símbolo y otra en la que sí.
![[Pasted image 20241110185917.png]]

Un ejemplo puede ser el siguiente.
![[Pasted image 20241110190010.png]]

### Producciones unitarias
Una producción es unitarias si es de la forma A $\implies$ B
El algoritmo a seguir para eliminarlas es el siguiente.
![[Pasted image 20241110190402.png]]

![[Pasted image 20241110190419.png]]

### Forma normal de Chomsky
Para tener una gramática en forma normal de Chomsky primero se debe higienizar la gramática para poder operar con ella, siguiente los pasos anteriores en este orden:
+ Eliminar símbolos inútiles.
+ Eliminar producciones vacías.
+ Eliminar producciones unitarias.
+ Eliminar símbolos inútiles.

Tras esto hay que destacar el concepto de recursividad el cual consiste en que una gramática es recursiva si tiene derivaciones de la forma 
$A\implies^+aAb$ donde o bien alfa o beta pueden ser cadenas vacías.

Una gramática está en forma normal de Chomsky si todas sus producciones son de la forma:
+ A → BC 
+ A → a 
+ S → ε

![[Pasted image 20241110191127.png]]

![[Pasted image 20241110191140.png]]

#### Propiedades
Los AAS generados sobre una cadena generada por una gramática en forma normal de Chomsky siempre será un árbol binario.

El camino más largo desde la raíz hasta las hojas tiene m+2 nodos y en el nivel m hay a lo sumo 2$^m$ nodos padre.

$2^m$ es la longitud más larga de la cadena derivada.

Si la longitud de la cadena es mayor a $2^m$ entonces el camino más largo desde la raíz a las hojas a de tener m + 2 nodos.

## Lema del bombeo

Sea L un lenguaje independiente del contexto el cual es generado por una gramática y no contiene la cadena vacía existe un entero $k \in N$ para el cual, teniendo una cadena del lenguaje $z$ cuya longitud es mayor que k tenemos lo siguiente:
![[Pasted image 20241111150029.png]]
![[Pasted image 20241111150408.png]]

![[Pasted image 20241111150427.png]]

## Lenguaje vacío
Hay un algoritmo para determinar si un lenguaje independiente del contexto es vacío. Si en la primera parte del proceso de eliminación de símbolos inútiles se elimina $S$ este lenguaje será vacío.

## Lenguaje finito o infinito
El lenguaje generado por una gramática es finito o infinito se debe hacer lo siguiente, se escribe esta en forma normal de Chomsky. Se debe construir un grafo dirigido para todos los símbolos no terminales, cada producción que produzca un no terminal es un arco, si no hay ciclos se dice que el lenguaje es finito.
![[Pasted image 20241111152425.png]]

## Analisis sintático
Permite determinar si una cadena es parte del lenguaje o no.
#### Lema
Dada una cadena del alfabeto $x$ para cualquier estado no terminal y cualquier subcadena de $x$ se puede determinar si $A \implies ^* \ \ w$
Sea n la longitud de la cadena y $w_{ij}$ la subcadena que comienza en la posicion i y tiene longitud j.
Hay que demostrar que el lema se cumple para cualquier $w_{ij}$
![[Pasted image 20241111165303.png]]

Si se particulariza este lema para el estado inicial el lema indica que es posible determinar si $S \implies^*  w_{1n} = x$ 
determinando que x pertenece al lenguaje.

Con el algoritmo de Cocke Younger Kasami se puede derterminar la pertenencia de una cadena al lenguaje generado por una gramática en forma normal de Chomsky.
![[Pasted image 20241111170129.png]]

![[Pasted image 20241111171539.png]]
![[Pasted image 20241111171601.png]]

## Propiedades
### Unión
Los lenguajes independientes del contexto son cerrados para la unión.
![[Pasted image 20241111172153.png]]
![[Pasted image 20241111172214.png]]
### Concatenación
Los lenguajes independientes del contexto son cerrados para la concatenación.
![[Pasted image 20241111172618.png]]
Se demuestra de una manera similar a la de la unión
### Cierre de Kleene
Los lenguajes independientes del contexto son cerrados para el cierre de Kleene.
![[Pasted image 20241111172913.png]]

### Intersección
Los lenguajes independientes del contexto **no son cerrados para la intersección**.
![[Pasted image 20241111173029.png]]
### Complementación
Los lenguajes independientes del contexto **no son cerrados para la complementación**.
Puesto que para serlo deberían ser cerrados para la intersección y cumplir la siguiente propiedad, cosa que no sucede.
![[Pasted image 20241111173233.png]]
