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

Para eliminar símbolos y producciones inútiles se siguen dos etapas.
+ Etapa 1: Eliminar no terminales que no deriven en una cadena de Σ* y las producciones en las que aparezca.
	![[Pasted image 20241018183535.png]]
+ Etapa 2: Eliminar no terminales los cuales sean inaccesibles.
	![[Pasted image 20241018184118.png]]

![[Pasted image 20241018184617.png]]

Una modificación es vacía si es de la forma A → ε.
