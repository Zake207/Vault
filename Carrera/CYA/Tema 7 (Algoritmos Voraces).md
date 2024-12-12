[[CyA - Tema 7 - Greedy.pdf|PDF]]
___
Toman decisiones en base a la información disponible en cada momento sin considerar las repercusiones futuras. Suelen ser eficientes y se usan para resolver problemas de optimización.
![[Pasted image 20241126180806.png]]

El algoritmo es el siguiente:
![[Pasted image 20241126180929.png]]

+ Este algoritmo es óptimo si se dispone de una cantidad ilimitada de cada moneda y los valores correctos de las monedas.
+ En otro caso puede no funcionar o no encontrar el valor óptimo. 
+ Es voraz porque en cada paso selecciona la mayor moneda posible sin cambiar de opinión.
+ La complejidad: siendo m=|M| tenemos O(n\*m) 

Otra versión puede ser la siguiente:
![[Pasted image 20241126181843.png]]

Con esta versión su complejidad se reduce a O(m).

## Características generales
Disponen de 3 conjuntos:
+ Candidatos viables.
+ Candidatos seleccionados.
+ Candidatos rechazados.

También tienen 4 funciones:
+ Determinar si un conjunto de candidatos es una solución.
+ Determinar si un conjunto de candidatos es factible.
+ Función de selección (selecciona de los candidatos actuales el mejor de los no seleccionados ni rechazados).
+ Función objetivo (mide el valor de la solución).

Siguen el siguiente esquema general:
![[Pasted image 20241126182717.png]]

Si lo aplicamos al problema de cambio de monedas:
![[Pasted image 20241126183038.png]]

## El problema de la mochila
+ Tenemos n objetos, cada uno tiene un peso p y un valor v.
+ La mochila soporta un peso P.
+ Se pretende maximizar el valor total de los objetos respetando la limitación del peso.
+ Se permite incluir fracciones de los objetos. $\forall x, 0 \leq x \leq 1$ por lo que cada objeto tiene un valor x\*v y peso x\*p

![[Pasted image 20241126183928.png]]


Existen múltiples opciones para la función de selección, la óptima es seleccionarlo en base a su valor por unidad de peso, seleccionando el mayor.

![[Pasted image 20241126184121.png]]

Cuyo algoritmo es el siguiente:
![[Pasted image 20241126184246.png]]
Faltan parar en caso de que no queden objetos por meter o no haya solución.
### Análisis del algoritmo.
Depende de si los elementos están o no ordenados:
+ En caso de estarlo $\implies$ O(n)
+ En caso de que no $\implies$ O(n * *complejidad del algoritmo de ordenación*).