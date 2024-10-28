Juegos en donde haya dos jugadores (MAX y MIN):
+ Ambos jugadores toman las decisiones optimas.
+ Esta compuesto por una serie de problemas de búsqueda.
+ MAX mueve primero.

El funcionamiento es el siguiente:
+ Se alternan para mover hasta acabar, el primero en mover es MAX
+ Al final se le dan puntos al ganador y penalizan al perdedor.
El juego esta compuesto por:
+ **Estado inicial**(incluye la posición y el jugador que mueve)
+ **Función sucesor**(devuelve una lista movimiento-estado que indica los movimientos legales y su estado consecuente)
+ **Test terminal**(determina cuando se termina el juego)
+ **Función de utilidad**(da valor a los estados terminales)
El árbol de juegos se forma con el estado inicial y los movimientos legales.

En un juego de dos jugadores MIN responde a la jugada de MAX, por ende, este debe responder a los movimientos de MIN de la mejor forma posible.
![[Pasted image 20241008221756.png]]

El valor minimax de un nodo es la utilidad (de MAX) de estar en el estado correspondiente, en un estado terminal es su utilidad.
![[Pasted image 20241008222501.png]]

+ Complejidad en tiempo: $O(b^m)$ para b(movimientos por turno) y m(profundidad máxima del árbol)
+ Complejidad en espacio: $O(bm)$ si el algoritmo genera todos los nodos a la vez, o bien $O(m)$ si los generase de uno en uno.

Se puede realizar una poda para reducir el número de nodos que se visitan, este utiliza dos parámetros:
+ alfa: El mejor valor que se ha encontrado para MAX
+ beta: El mejor valor encontrado para MIN
La eficacia de la poda depende de el orden en el que se examinen a los sucesores, si el orden es perfecto (examinando siempre primero a los que son posiblemente los mejores) el algoritmo visitará $O(b^{m/2})$ nodos.

Para evitar recorrer toda la profundidad del árbol se puede parar hasta cierto punto y establecer los nodos de dicho nivel como terminales, estableciendo su valor con una heurística, el cálculo de la misma no debe llevar mucho tiempo. 

Cada valor esperado de los nodos en los que se decide parar se escoge en base a categorías (como el número de piezas y su tipo en ajedrez) y la proporción de los estados que llevan al triunfo en base a esta. También se suele asignar un valor numérico a las características de los escenarios. 



