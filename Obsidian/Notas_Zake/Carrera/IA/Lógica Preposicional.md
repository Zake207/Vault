# Parte I
La lógica propocicional es declarativa, composicional, permite información parcial/disyuntiva/negada. Además es independiente del contexto y tiene un poder expresivo muy limitado. No es lo mismo que la lógica de predicados.

Por otro lado la lógica de predicados(de primer orden) tiene:
+ Objetos: nombres o sentencia
+ Relaciones: verbos que relacionan los objetos
+ Funciones: relaciones que dada la entrada, se obtiene un solo valor.

![[Pasted image 20241029105721.png]]

## Sintáxis
+ Termino: Expresión lógica referida a un objeto. $$Padre(Juan)$$
+ **Sentencias atómicas:** Símbolo de predicado seguido de una lista de términos. $$Hermano(Ricardo,Juan)$$$$Casado(Padre(Ricardo),Madre(Juan))$$
+ **Sentencias compuestas:** Sentencias que utiliza las conectivas lógicas. $$Rey(Ricardo)\&(¬Hermano(Pepe,Juan))$$
+ **Cuantificador universal:** Construye enunciados para todos los objetos del universo.$$\forall x | Rey(x) \Longrightarrow Persona(x)$$ Suele usarse el implica con este cuantificador
+ **Cuantificador existencial:** Construye enunciados para algún objeto del universo sin nombrarlo $$\exists x\ Corona(x) \land SobreCabeza(x,Juan)$$Suele usarse un $a n d$ con este cuantificador
+ **Cuantificadores anidados:** Construcciones más complejas $$∀x ∀y Hermano(x, y ) ⇒ Camarada(x, y )$$$$∀x, y Camarada(x, y ) ⇒ Camarada(y , x)$$
$$∀x ∃y Ama(x, y )$$$$∃y ∀x Ama(x, y )$$
+ **Relación entre el cuantificador existencial y universal:**
$$∀x ¬Gusta(x, Espinacas) ≡ ¬∃x Gusta(x, Espinacas)$$
$$∀x Gusta(x, Chocolate) ≡ ¬∃x ¬Gusta(x, Chocolate)$$
+ **Leyes de Morgan:**
	+ ∀x ¬P ≡ ¬∃x P 
	+ ¬P ∧ ¬Q ≡ ¬(P ∨ Q)
	+ ¬∀x P ≡ ∃x ¬P 
	+ ¬(P ∧ Q) ≡ ¬P ∨ ¬Q)
	+ ∀x P ≡ ¬∃x ¬P 
	+ P ∧Q ≡ ¬(¬P ∨ ¬Q)
	+ ∃x P ≡ ¬∀x ¬P 
	+ P ∨Q ≡ ¬(¬P ∧ ¬Q)
+ **Igualdad:** Se puede usar el símbolo de igualdad para construir enunciados describiendo que dos términos se refieren al mismo objeto.

## Inferencia
Hay que tratar de llevar las sentencias a lógica propocicional para poder trabajar.
### Especificación universal
Al detectar un $\forall x$ en una sentencia se puede eliminar directamente pues no hay que hacer esa serie de sustituciones. También se puede sustituir por todos los elementos que puede tomar la variable $x$.
![[Pasted image 20241112122313.png]]

+ Puede ser aplicada múltiples veces.
+ La nueva base de conocimiento será equivalente.
### Especificación existencial
Se debe usar una Constante de Skolem. Hay que proceder como en el siguiente ejemplo.
![[Pasted image 20241112122443.png]]

+ Sólo se puede aplicar una vez
+ No es equivalente a la anterior pero se puede demostrar que es **equivalente inferencialmente**.
### Reducción
Aplicando lo anterior a la siguiente base de conocimiento tenemos la siguiente BC proporsicionalizada.
![[Pasted image 20241114192835.png]]

Una sentencia base es implicada por la nueva solo si es implicada por la original. Por lo que se podría optar por proporsicionalizar la BC y la petición.

Esto acarrea un problema y es que se pueden dar situaciones infinitas como: $$Padre(Padre(Padre(Juan)))$$
Se puede hacer un número indefinido de veces (n): Crear la BC con profundidad n y ver si la sentencia es implicada por esta, si no lo fuera nunca entraría en un bucle infinito.
#### Teoremas (POSIBLE PREGUNTA DE EXÁMEN):
![[Pasted image 20241114193452.png]]
![[Pasted image 20241114193500.png]]
#### Problemas con proporsicionalización
Genera muchas sentencias inútiles que no son relevantes.
### Unificación
**PREGUNTAS DE EXÁMEN**
Se busca encontrar un θ tal que Rey(x) y Codicioso(x) sean iguales a Rey(Juan) y Codicioso(y) en este caso θ = {x/Juan, y/Juan}.
Ejemplo:
![[Pasted image 20241114194429.png]]
La ultima sentencia falla pues se esta asumiendo que Juan es OJ lo cual es falso. Para evitarlo se puede estandarizar las variables ($Conoce(z_{17}, OJ)$)
![[Pasted image 20241114194651.png]]
### Modus Ponens Generalizado(MPG)
![[Pasted image 20241114194732.png]]

Todas las variables deben estar universalmente especificadas. hay que mostrar lo siguiente:
![[Pasted image 20241114194925.png]]

Para esto tenemos el siguiente lema:
![[Pasted image 20241114194948.png]]
### Ejemplo de base de concocimiento
![[Pasted image 20241114195009.png]]
![[Pasted image 20241114195230.png]]
![[Pasted image 20241114195304.png]]

### Encadenamiento hacia delante
#### Algoritmo
![[Pasted image 20241114195320.png]]
Comienza por lo hechos conocidos, elproceso dispara todas las reglas cuyas premisas se satisfacen, añade sus conclusiones al conjuntos de hechos conocidos.

Se repite hasta que la petición es respondida o hasta que no puede añadir más hechos.
#### Ejemplo
![[Pasted image 20241114195550.png]]
![[Pasted image 20241114195608.png]]
![[Pasted image 20241114195625.png]]
![[Pasted image 20241114195643.png]]

#### Propiedades
+ Es sólido, pues cada inferencia es una aplicación del Modus Ponens Generalizado, que ya es sólido.
+ Es completo para las BC de cláusulas positivas.
+ Las BC DAtalog(no tienen símbolos de función) tienen una k como aridad máxima, p el número de predicados, y n el número de símbolos de constante. **No puede haber más de $p·n^k$ hechos base** por tanto el algoritmo debe encontrar un punto fijo
+ Las cláusulas que tienen símbolos de función pueden generar hechos nuevos infinitamente.
#### Eficiencia
Tiene tres fuentes de complejidad.
1. El bucle encargado del emparejamiento de patrones.
2. La comprobación de las nuevas reglas.
3. La generación de hechos irrelevantes.
### Emparejamiento
Es importante el orden de los conjuntores por lo siguiente:
![[Pasted image 20241114200750.png]]

Se debe ver cada conjuntor como una restricción sobre las variables que contiene.
![[Pasted image 20241114200922.png]]
Aqui colorable se infiere si y solo si PSR(Problema de Satisfacción de Restricciones) tiene solución.

Por lo que el encadenamiento hacia delante es visto como un problema de emparejamiento NP-duro. Sin embargo:
+ La complejidad de los datos es polinómica
+ Se debería considerar sibclases de reglas para las que el encadenamiento sea eficiente
+ Eliminar los intentos de emparejamiento de reglas redundantes.

El el último apartado quiere decir que:
*Cada hecho nuevo inferido en una iteración t debe ser derivado de al menos un hecho nuevo inferido en la iteración t − 1.* 
# Parte II
### Encadenamiento hacia detrás
![[Pasted image 20241119105039.png]]
### Composición, COMPÓN
El algoritmo usa composición de sustituciones.
![[Pasted image 20241119150653.png]]
### Ejemplo
![[Pasted image 20241119150714.png]]
![[Pasted image 20241119150746.png]]
![[Pasted image 20241119150807.png]]
![[Pasted image 20241119150920.png]]
![[Pasted image 20241119150936.png]]
![[Pasted image 20241119150951.png]]
![[Pasted image 20241119151005.png]]
### Propiedades
+ Es un algoritmo de búsqueda en profundidad
+ Es incompleto
+ Ineficiente
+ Muy usado

### Resolución
Kurt Gödel demostró en 1930 el primer teorema de completitud, por lo que para una sentencia implicada existe una demostración finita.

Un año más tarde demostró el teorema de incompletitud, demostrando que un sistema lógico que incluye un principio de inducción es necesariamente incompleto. 
### Forma Normal Conjuntiva
Es necesario seguir una serie de pasos para lograr llegar a un problema en FNC:
1. Incluir el contrario de lo que se desea demostrar en la BC (incluir ¬P)
2. Obtener una conjunción de disyunciones
	+ Eliminar los $\implies$ distribuyendo y anidando las negaciones
	+ Eliminar cuantificadores $\exists$ y $\forall$:
		+ $\forall$ Se eliminan a secas
		+ $\exists$ Se sustituyen por constantes de Skolen
		+ $\forall x \ \exists y$ se hace la sustitución {$y/F(x)$}
Una vez hecho eso se aplica la inferencia hasta llegar a un resultado.

El ejemplo anteriormente resuelto equivale a lo siguiente
![[Pasted image 20241119151216.png]]
![[Pasted image 20241119151239.png]]
