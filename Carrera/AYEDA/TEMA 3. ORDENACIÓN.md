## Introducción.
Los algoritmos de ordenación se pueden clasificar en cuadráticos, logarítmicos y otros. Estos últimos consisten en algoritmos mejorados.
## Algoritmos cuadráticos.
#### Por inserción.
Se divide la secuencia en dos partes: La primera con los i elementos que ya están ordenados y la segunda que no esta ordenada son los n-i siguientes numeros. En cada iteración Se toma el elemento de la posición j y se inserta en la posición adecuada entre los i primeros números.
![[Pasted image 20240510233633.png]]
![[Pasted image 20240326161848.png]]
Hay que realizar ese bucle por cada elemento de la secuencia partiendo desde el segundo, es decir, en la secuencia 44 34 23 92 se empieza a operar desde el 34.
También se puede hacer mediante el uso de un centinela:
![[Pasted image 20240326162339.png]]

#### Bin-sort
BinSort es un método en el que se calcula la posición de j comparando el elemento con la mitad de la secuencia ordenada y acotando la posición de j.
![[Pasted image 20240326163025.png]]
Sin embargo este método es de una complejidad mayor y se debería usar un árbol binario de búsqueda.
#### Por Selección.
Parte de la misma división de la secuencia expuesta en el caso anterior pero en este caso no se asume la ordenación del primer elemento.
El la primera iteración se selecciona el menor de toda la secuencia y se intercambia con el primero y a partir de ahí se intercambia el menor de la secuencia no ordenada con el primero de dicha secuencia.
El código es similar al de ordenación por inserción.  
Donde la función de selección tiene el siguiente código
![[Pasted image 20240326164217.png]]
La última parte se puede sustituir por un swap
#### Por Intercambio.
En este tipo de algoritmos se recorre la secuencia intercambiando pares de elementos no ordenados desde el final hasta el principio, haciendo lo que se conoce como pasada.
Existen dos métodos
###### Método de la burbuja.
Siguiendo el criterio anterior se puede observar como los elementos menores se van colocando en posiciones superiores. El elemento que asciende se considera elemento burbuja y este cambia cuando se topa con uno que es inferior en clave a él. El método acaba cuando no se modifica la secuencia en una pasada.
![[Pasted image 20240326165938.png]]
###### Método de la sacudida.
Acelera el método de la burbuja al hacer pasadas tanto descendentes como ascendentes y estas pueden empezar por el segundo y penúltimo elemento.
![[Pasted image 20240326170202.png]]
## Algoritmos logarítmicos.
#### HeapSort
Es una optimización del método de selección donde los elementos no ordenados se introducen en un montículo. Es más fácil representar esto con un árbol de padres e hijos donde los hijos del elemento i son 2i y 2i+1 siempre que estén en el montón, el padre del elemento i es i/2 siempre que no sea nulo.
Basándose en esto:
+ Los elementos más allá de la mitad del montón no tienen hijos.
+ Si n es par los hijos de n/2 solo es uno, el último.
+ Si es impar sus hijos serán el penúltimo y el último.
+ El único elemento sin padre es el primero.
________________________________________________________________________
El algoritmo de Floyd para HeapSort sigue las siguientes reglas:
+ Se asume que la mitad final está ordenada.
+ Se completa el montón añadiendo a la derecha los demás elementos y bajándolos.
+ El Heap o montón está ordenado si se cumple: 
	+ ningún elemento tiene mayor clave que su padre. 
	+ ningún elemento tiene menor clave que alguno de sus dos hijos.
+ Un elemento mal colocado se recoloca, bajándolo o subiéndolo recursivamente mientras haga falta:
	- Se baja intercambiándolo recursivamente con su hijo mayor.
	+ Se sube intercambiándolo recursivamente con su padre.
+ Para eliminar el primer elemento del montón ordenado, se intercambia con el último elemento; y, si queda mal colocado, se baja mientras haga falta.
+ Para ordenar los elementos de una secuencia por el método de ordenación por selección con el uso de un heap:
	- **En una primera fase**: se ordena la secuencia como un montón incorporando al montón los elementos uno a uno, bajándolo si hace falta.
	- **En la segunda fase**: se va seleccionando iterativamente el elemento de mayor clave, que será siempre el que está en la raíz o primera posición, para  eliminarlo y bajar mientras haga falta el que ocupa su lugar.
El algoritmo implementado:

![[Pasted image 20240326192512.png]]
![[Pasted image 20240326192555.png]]
*(Revisar el código de la practica, ese es el correcto)*

#### QuickSort
Usa un pivote para descomponer la secuencia.
Recorre la secuencia desde sus extremos en ambos sentidos
El ascendente se para en el elemento que sea mayor o igual que el pivote y de manera homóloga con el descendente. Al parar se intercambian y se continúa hasta que se encuentren. Haciendo esto se divide la secuencia en dos subsecuencias de los menores y mayores que el pivote.

Al cruzarse, la división de los subconjuntos se el corte se hace en medio de los elementos.
Si ambos coinciden se hace detrás del elemento en el que coinciden

El pivote suele ser el elemento central.
Una vez dividida se realiza el mismo método de manera recursiva sobre los dos subconjuntos.
![[Pasted image 20240326193945.png]]

#### MergeSort
Se descompone la secuencia a ordenar en dos, se ordenan y luego se mezclan ordenadamente. La división se realiza por la posición media y la mezcla se realiza seleccionando los elementos de menor clave de las subsecuencias.
![[Pasted image 20240326195238.png]]
![[Pasted image 20240326195304.png]]
![[Pasted image 20240326195328.png]]

## Otros algoritmos.
#### ShellSort.
Consiste en ordenar por inserción los elementos de la secuencia que están a una distancia X, rebajando X hasta llegar a 1
Ejemplo visual:
![[Pasted image 20240326201025.png]]
Se recomienda que los incrementos de X no sean múltiplos y que no tengan divisores comunes.
En este caso se aplica la ordenación por inserción pero aquí se hace con el elemento que esté X posiciones más adelante.
La mejor reducción de los incrementos es calcular X basándose en:
					X = E((5X-1)/11)

![[Pasted image 20240510163852.png]]

#### RadixSort.
Este método consiste en ir ordenando los números según sus dígitos desde el último hasta el primero usando cubetas desde el 0 hasta el 9 para su ordenación
#### TimSort.
Está pensado para actuar con grandes cantidades de datos.
Se hacen pasadas en las que se identifican subsecuencias de elementos ordenados ya sean crecientes o decrecientes, si es decreciente se invierte. Aquellas rachas que no tengan el tamaño mínimo se las amplia mediante el método de inserción. Las rachas ordenadas se almacenan en una pila de rachas para luego mezclarse ordenadamente, aumentando la eficacia de la mezcla si las rachas son de tamaño similar
