# Búsqueda secuencial
Se le aplica a cualquier secuencia, sin importar si están ordenados o no. 
Disminuye su eficiencia al tener muchos elementos en la secuencia.
Aumenta su eficiencia si los elementos están ordenados.
![[Pasted image 20240501110329.png]]

+ Búsqueda interna: Los elementos a buscar están en memoria
+ Búsqueda externa: Los elementos a buscar están en dispositivos externos al ordenador.


+ Búsqueda primaria: El algoritmo se detiene al encontrar la primera coincidencia.
+ Búsqueda secundaria: No se detiene hasta no encontrar todas las coincidencias.


La búsqueda lineal recorre todos los elementos sucesivamente hasta dar con los resultados. En promedio se hacen (n+1)/2 comparaciones O(n).

Lo ideal para este método sería tener ordenada la secuencia de más frecuente a menos.
+ Movimiento al frente: Coloca en primer lugar cada elemento buscado. (Lista enlazada)
+ Transposición: Intercambia el elemento buscado con el anterior. (Array)
![[Pasted image 20240501110354.png]]
# Búsqueda binaria
Utiliza una clave para buscar el elemento en la lista.
Se suele mirar la mitad que corresponda y se va acotando la zona de búsqueda dependiendo del valor que se encuentre (si es mayor o menor). Reduciendo constantemente a la mitad el tamaño de la secuencia donde se busca.
![[Pasted image 20240501110244.png]]

Se puede mejorar si salimos del bucle al ver que uno de los extremos o el centro, coincide con el valor buscado.
![[Pasted image 20240501110543.png]]
La complejidad de este método es O($log_2$ $n$)

# Tablas hash
El hashing consiste en convertir una clave dada en una dirección. Los registros se almacenan en base a unas claves.

Para ello se usa una Función de Dispersión. Dado una clave K se le aplica la función h y se obtiene una dirección D.
+ $h(K) = D$
Existirán valores que se traducirán a una misma dirección (sinónimos), si estos se aparecen se produce una colisión. Se deben evitar y saber tratar en caso de que aparezcan. Las funciones de dispersión uniformes consiguen esto.
___
## Funciones
### ==Truncamiento==
Se ignora una parte de la clave y se usa la restante como índice.
Un ejemplo es seleccionar dígitos específicos del elemento. Esto no es uniforme pero sí es rápido.
Se puede, por ejemplo, filtrar según las 3 últimas cifras del elemento.
### ==Módulo==
+ $h(K) = K mod(t)$  
siendo $t$ el tamaño de la tabla

Para aumentar la eficiencia de este método se consigue si el tamaño de tabla usado es un número primo.

Si el espacio de direcciones es de la forma 1,2,...,t hay que usar: $h(k) = 1 + (k – 1) mod(t)$
### ==Suma==
Se suman los dígitos del elemento y se trabaja con el valor obtenido, aplicando la operación de módulo por ejemplo.

En el caso de que los valores almacenados sean cadenas de caracteres se pueden usar los valores ASCII de los caracteres para obtener su cantidad numérica.
### ==Plegado==
Puede ser por desplazamiento o por fronteras.
En una tabla de tamaño 1000 sería:
![[Pasted image 20240501121051.png]]
### ==Centro del cuadrado==
Consiste en elevar al cuadrado el elemento y coger unas cifras fijas del interior de este.
![[Pasted image 20240501121640.png]]
### ==Números pseudo-aleatorios==
Se usan número generados aleatoriamente a partir de una semilla.
Suele escogerse `srand(time(NULL))` para fijar la semilla.
luego se obtiene el número `n = mínimo + rand() / máximo`

La clave participa en la asignación del valor de la semilla usando su valor numérico.

**La semilla debería ser impar**


___
## Paradoja de von Mises.
En un grupo de 23 persona exite un 50% de probabilidades de que al menos 2 tengan la misma fecha de nacimiento, si fueran 50 aumenta a un 97% y con 75 es de 99,97%.

Ahora basta con sustituir el personas por celdas, siendo la tabla de tamaño 365 y ahora en vez de probabilidad de nacer el mismo día tenemos las probabilidades de que se encuentren en la misma celda.
___
## Implementación
Consiste en una tabla de pares que guarda elementos con clave y dato.

Se produce una colisión si aparecen dos claves distintas que son sinónimos.

Cada celda puede almacenar un único registro, un número fijo de ellos o una cantidad arbitraria.

+ Si tiene dispersión abierta cada celda crece a medida que se le incluyen entradas. No produce desbordamiento.
+ Si tiene dispersión cerrada la celda tiene un tamaño máximo por lo que hay que manejas el desbordamiento.

En caso de desbordamiento hay que buscar otra celda con espacio. Se debe realizar una exploración.
### Búsqueda
Se empieza por la dirección correspondiente. Si dicha celda está vacía y no se encuentra el valor, se detiene la búsqueda. Por otro lado, si la celda esta llena se deben explorar las siguientes celdas empleando la función de exploración empleada siempre que estas estén llenas y no contengan el elemento. Si en algún momento encuentra una celda con espacio pero sin la clave se detiene la búsqueda.

### Inserción
Primero se debe buscar el elemento para determinar que este se puede insertar, tras esto se inserta en su celda correspondiente, en caso de estar llena se debe aplicar la técnica de exploración para encontrar una celda disponible.
### Eliminación
Eliminar elementos puede dar pie a confuciones pues si al insertar A nos encontramos con que hay que hacer 3 exploraciones, si una de las celdas que estaban llenas se les elimina un elemento, a la hora de buscar A se detendría antes de encontrarla. 

Se pueden marcar las celdas de las que se han eliminado elementos.
+ 0 para celda vacía
+ -1 para celda anteriormente ocupada.
La presencia de celdas de este último tipo contamina la tabla. Al llegar a un grado de contaminación alto se debe reorganizar la tabla.
### Exploración
La siguiente posición a la hora de operar viene dada por la formula genérica: $d = (h(K) + g_i(K) * mod(t))$

+ Lineal: explora las posiciones posteriores provoca clustering
		$d = (h(K) + i) * mod(t)$ para i€\[0,t\] siendo $t$ el tamaño de la tabla.
+ Cuadrática: Evita el clustering pero provoca clustering secundario.
		$g_i(K) = i²$
+ Permutación: Consiste en generar a partir de la clave una permutación $p(K)$ por numeros pseudo-aleatorios.
+ Disperción doble: Por este método se usa otra función de dispersión para obtener las direcciones.
		$d = h(K) + i * f(K) mod(t)$ para i = 0, 1, 2, ...

Para este último método se requiere que la tabla tenga de tamaño un número primo.

+ Redispersión: Usa una familia de funciones de exploración en donde para cada iteración se usa una función de dispersión diferente.
## Eficiencia

Densidad = (Direcciones Usadas) / (Direcciones Posibles)
Factor = (Registros almacenados) / (Registros Almacenables)

