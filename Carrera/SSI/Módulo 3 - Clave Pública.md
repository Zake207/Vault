# Criptografía Elíptica
## Calcular puntos de la curva
![[Pasted image 20250407121923.png]]
destacar que en los cuadrados, de la mitad hacia abajo no hay que calcularlas puesto que si nos fijamos son un espejo

Las recomendadas por el NIST son 80 112 128 192 256

La operacion básica de este cifrado es sumar los puntos obtenidos de la curva eliptica

## Sumar los puntos de la curva
![[Pasted image 20250407122950.png]]
Se usan las siguientes formulas para facilitar
![[Pasted image 20250407123031.png]]

### Ejemplo
![[Pasted image 20250407124209.png]]
Es muy raro tenerlo mal y que de un punto, si no te da un punto tras la operación esta mal
Si el lambda no da un entero se tiene que calcular el inverso modular del denominador con el el algoritmo de Euclides Extendido

## Codificar el mensaje
Es necesario codificar el mensaje como punto de la curva para poder operar.
M = tamaño del conjunto de mensajes

![[Pasted image 20250407125702.png]]
![[Pasted image 20250407125840.png]]
![[Pasted image 20250407130002.png]]

## Problema del Logaritmo Discreto Elíptico
Diffie-Hellman eliptico
Gammal Eliptico

