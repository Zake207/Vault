[[CyA - Tema 9 - DP.pdf|PDF]]
___
## Definición
Cuando en programación dinámica se generan sub-problemas solapados, el hecho de resolverlos de una sola vez y evitar tener que calcular dos veces el mismo resultado los vuelve más eficientes.

La **Programación dinámica** es una técnica ascendente que comienza desde problemas sencillos y combinando sus solución obtiene la solución al problema original.

## Problema: Coeficiente Binomial.
Véase el siguiente problema:
![[Pasted image 20241216103131.png]]

Con este algoritmo muchos de los resultados se vuelven a calcular, al usar una tabla de resultados intermedios se optimiza el algoritmo.
![[Pasted image 20241216103928.png]]
![[Pasted image 20241216103953.png]]


El tiempo y espacio necesarios para rellenar toda la tabla es de orden $\Theta(n²)$, sin embargo se requiere rellenar toda la tabla, sirve tener un vector de tamaño k, de esta forma el algoritmo requiere un tiempo $\Theta(n·k)$ y $\Theta(k)$.

![[Pasted image 20241216104812.png]]
![[Pasted image 20241216104845.png]]

## Problema: Devolver cambio
En ciertos escenarios un algoritmo voraz no permite encontrar la solución óptima a este problema.

Suponemos un sistema monetario *M*, con *m* tipos de monedas, cada una con un valor *v*. Se debe devolver una cantidad *n* que sea el cambio con el menor número de monedas posible.

Se prepara una tabla con una fila por cada valor de moneda y una columna por cada cantidad desde 0 hasta *n*.
Opera de la siguiente manera:
+ Se inicializa C\[i, 0] = 0
+ Si se añaden una moneda el número de estas es 1 más el número de monedas necesario para cubrir el valor anterior menos el valor de la moneda añadida.**C\[i, j] = 1 + C\[i, j - vi]**
+ Si no se añaden **C\[i, j] = C\[i - 1, j]**

De esas dos decisiones se escoge el mínimo de las dos.
![[Pasted image 20241216125213.png]]
![[Pasted image 20241216125223.png]]
![[Pasted image 20241216125234.png]]

Pero de ahí, la cantidad n, especifíca el número de monedas a escoger, cuales hay que coger se calcula de la haciendo un recorrido dentro de la matriz, desde C\[m,n] hasta C\[-,0]:
+ Si C\[i, j] = C\[i-1,j] (con i > 1) pasamos a C\[i-1, j].
+ En otro caso se pasa a C\[i,j-v]
+ Al llegar a C\[i,0] se ha finalizado el pago.

![[Pasted image 20241216130256.png]]
![[Pasted image 20241216130356.png]]

La complejidad de este algoritmo es de $\Theta(m·n)$
