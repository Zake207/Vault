Los agentes están formados por una base de conocimientos, esta es un conjunto de sentencias, además se usa un motor de inferencia que en base a estos conocimientos permite aumentar la base de conocimientos, aprendiendo
![[Pasted image 20241111190540.png]]

## Mundo Wumpus
Consiste en una cueva formada por habitaciones contiguas, en la cueva habita el wumpus, una bestia que puede acabar con los moradores de la mazmorra, las habitaciones pueden tener hoyos que atrapen a todo merodeador de la cueva menos al wumpus, escondido en la mazmorra hay una pila de tesoro. el wumpus puede ser asenados por la flecha del explorador.
+ +1000 pts por recoger el tesoro.
+ -1000 pts por caer en un hoyo o ser comido por el wumpus.
+ -1 por cada habitacion visitada
+ -10 si se usa la flecha
El entorno es una matriz 4x4 donde cada casilla es una habitación, el jugador empieza en la \[1, 1] (siendo esta la esquina inferior izquierda).
El jugador puede avanzar, girar, disparar y agarrar. Este cuenta con una serie de sensores:
+ El jugador detecta hedor si se encuentra en la casilla del wumpus o adyacentes (en cruceta).
+ Percibirá brisa si esta en una casilla adyacente a un hoyo.
+ Verá un brillo en la casilla donde está el tesoro.
+ Sentirá un golpe si intenta atravesar un muro
+ Escuchará un grito cuando el wumpus muera, esté donde esté.
![[Pasted image 20241111194059.png]]
![[Pasted image 20241111194151.png]]


La base de conocimiento se compone de sentencias expresadas en la sintaxis, con una semántica dada.
Las sentencias pueden implicar otras, si y solo si, para cada modelo donde una lo es, la otra también.
![[Pasted image 20241111195112.png]]

## Propociciones
Una proposición es una frase declarativa que puede ser falsa o verdadera. Pueden ser atómicas, es decir, indivisibles y cada uno de estos puede ser representado con símbolos.
### Sintáxis
Aquellas que sean complejas estarán formadas por sentencias atómicas unidas por los conectores lógicos ¬(not), $\land$(and), $\lor$(or), $\implies$(implica) y $\iff$(). 
### Semántica
Define como determinar el valor de una sentencia dada, como ejemplo: m = {P = falso, Q = falso, R = verdadero}
estableciendo el valor de las secuencias atómicas y después el de las construcciones más complejas.
+ En las atómicas, es verdadero en todos los modelos o falso en todos los modelos.
+ En las complejas el valor se resume en las tablas de verdad para las sentencias complejas

Como ejemplo:
![[Pasted image 20241111225948.png]]

La base de conocimiento se puede representar como una única sentencia de operaciones $and$
### Inferencia
El objetivo de esta es decidir si para alguna $a$ $BC \implies a$ 
por ejemplo, saber si en la casilla \[1 2] hay un hoyo. si BC y a tienen n símbolos la complejidad temporal será de O($2^n$) y la espacial O(n).
El algoritmo enumera los modelos y comprueba si $a$ es verdadera en cada modelo donde $a$ es cierta.

Dos sentencias son equivalentes si tiene los mismos valores de verdad  en el mismo conjunto de modelos. Esto posibilita varias propiedades:
![[Pasted image 20241112003136.png]]

Las sentencias son válidas si es verdadera en todos los modelos, son llamada tautologías.
![[Pasted image 20241112003431.png]]

Es satisfacible si es veradera para algún modelo. si $a$ es veradera para el modelo $m$ decimos que $m$ satisface $a$.

$a$ es válida o satisfacible si $¬a$ es insatifacible o inválida.

![[Pasted image 20241112003804.png]]
Esto se prueba por reducción a lo absurdo.

### Razonamiento
#### Modus Ponens
Se se observa α ⇒ β y α, se infiere β.
#### Modus Tollens
Si se observa α ⇒ β y ¬β, se infiere ¬β.
#### Eliminación ∧ : 
De una conjunción se puede inferir cualquiera de sus conjuntores.
α ∧ β
α
#### Silogismo hipotético:
α ⇒ β, β ⇒ γ
α ⇒ γ
#### Silogismo disyuntivo:
α ∨ β, ¬α
β
#### Ley de casos:
α ⇒ β, ¬α ⇒ β
β
#### Ejemplo:
![[Pasted image 20241112004455.png]]Se quiere demostrar $¬H_{1,2}$
![[Pasted image 20241112004532.png]]![[Pasted image 20241112004553.png]]![[Pasted image 20241112004615.png]]
![[Pasted image 20241112004631.png]]![[Pasted image 20241112004659.png]]

#### Forma normal conjuntiva
Una sentencia formada de disyunciones de literales.
Un ejemplo puede ser:
![[Pasted image 20241112004840.png]]Los procedimientos por inferencia trabajan con el principio de contradicción, para demostrar A implica B se demuestra A y ¬B es insatisfacible.
![[Pasted image 20241112005019.png]]![[Pasted image 20241112005033.png]]
