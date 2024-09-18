# Parte 1.
## Definiciones
Proposición -> sentencia la cual puede ser verdadera o falsa.
Función -> Expresión que se transforma en proposición al sustituir las variables

Para una función existe un conjunto de verdad. El cual puede ser 
+ Función -> b(x) = el natural x es tal que x > 10
+ Conjunto -> B = \{ x∈\N : x > 10} = \{ x∈\N : b(x)}
Al estar definido por una propiedad se dice que se define por una comprensión

## Operaciones.
#### Negación.
Niega la proposición y por tanto altera el conjunto, con el ejemplo anterior:
+ Función -> ¬b(x) = el natural x es tal que x <= 10
+ Conjunto -> ¬B = \{ x∈\N : x <= 10} = \{ x∈\N : ¬b(x)}
#### Conjunción
Una conjunción es verdadera solo si ambas proposiciones lo son.
![[Pasted image 20240918144723.png]]
![[Pasted image 20240918144741.png]]
#### Disyunción
+ Inclusiva: p *o* q
	Es verdad si una o varias de las proposiciones lo es.
	![[Pasted image 20240918144723.png]]
	![[Pasted image 20240918145241.png]]
+ Exclusiva: p ∇ q
	Es verdad solo si una de las proposiciones lo es.
	(p o q) ^ ¬(p ^ q) <=> p ∇ q
	![[Pasted image 20240918145739.png]]
#### Condicional
p -> q
si p entonces q <=> a (¬p) o q
![[Pasted image 20240918150443.png]]
Si para todo x∈U, a(x) -> b(x), por ende A⊆B si y solo si A\´∪B = U
Para esta implicación se puede definir la recíproca (q -> p), la contraria (¬p -> ¬q) y la contra recíproca (¬q -> ¬p).
![[Pasted image 20240918151256.png]]
La conjunción de una implicación con su recíproco provoca el bicondicional p <-> q el cual tiene el siguiente comportamiento.
![[Pasted image 20240918151615.png]]

Se dice que una equivalencia lógica significa que al hacer la bicondicional, en su columna siempre sale verdadero, por ende, la bicondicional es tautología
#### Equivalencias de conjuntos.
+ Ley de Morgan
![[Pasted image 20240918152321.png]]
![[Pasted image 20240918152712.png]]
___
+ Ley distributiva
![[Pasted image 20240918152453.png]]
![[Pasted image 20240918152653.png]]
# Parte 2.
## Tautologías
Permiten probar la validez de razonamientos. Es cierta para todos los valores de verdad de sus variables.
Ejemplo.
![[Pasted image 20240918154838.png]]
Al ser la ultima columna todo V significa que p->q ^ q implica q.

## Cuantificadores.
#### Universal
(∀x∈U) \[a(x)\] para todo x perteneciente a U, a(x) se cumple. Por ende su conjunto de verdad es A = U
#### Existencial.
(∃x∈U) \[a(x)\] Existe un x en U que cumple a(x)
#### Negación.
La negación de cuantificadores conlleva las siguientes equivalencias.
![[Pasted image 20240918161049.png]]

![[Pasted image 20240918161103.png]]

![[Pasted image 20240918161446.png]]

![[Pasted image 20240918161540.png]]
## Orden de los cuantificadores
Existe un elemento neutro.
![[Pasted image 20240918162943.png]]
Existe un inverso.
![[Pasted image 20240918162952.png]]
Otro ejemplo.
![[Pasted image 20240918163338.png]]

## Equivalencias
![[Pasted image 20240918163639.png]]

![[Pasted image 20240918163652.png]]

![[Pasted image 20240918163702.png]]

![[Pasted image 20240918163717.png]]
