Juegos en donde haya dos jugadores (MAX y MIN)
+ Ambos jugadores toman las decisiones optimas
+ Esta compuesto por una serie de problemas de búsqueda

El funcionamiento es el siguiente:
+ Se alternan para mover hasta acabar, el primero en mover es MAX
+ Al final se le dan puntos al ganador y penalizan al perdedor.
El juego esta compuesto por:
+ Estado inicial(incluye la posición y el jugador que mueve)
+ Función sucesor(devuelve una lista movimiento-estado que indica los movimientos legales y su estado consecuente)
+ Test terminal(determina cuando se termina el juego)
+ Función de utilidad(la valor a los estados terminales)
El árbol de juegos se forma con el estado inicial y los movimientos legales.

En un juego de dos jugadores MIN responde a la jugada de MAX, por ende, este debe responder a los movimientos de MIN de la mejor forma posible.
![[Pasted image 20241008221756.png]]

El valor minimax de un nodo es la utilidad (de MAX) de estar en el estado correspondiente, en un estado terminal es su utilidad.
![[Pasted image 20241008222501.png]]

