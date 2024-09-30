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