## Introducción
La estadística bidimensional se realiza sobre dos caracteres de una muestra de individuos de forma simultánea. Estas pueden ser discretas o continuas.

La frecuencia absoluta de una variable $x_i y_j$ se le denota por el numero de individuos que presentan $x_i y_j$.
De igual forma la frecuencia relativa es la frecuencia absoluta entre el tamaño muestral.

Los datos de estas variables se representan de la siguiente manera.
![[Pasted image 20241006180723.png]]
## Representaciones gráficas
Diagrama de frecuencias: Representación tridimensional de la tabla.
![[Pasted image 20241006180855.png]]

Diagrama de dispersión: Cada par viene dado por unos punto.
![[Pasted image 20241006180950.png]]

## Distribuciones marginales.
La frecuencia marginal de uno de los dos valores consiste en contar el número de veces que aparece un determinado valor de una de las variables sin considerar la otra.
![[Pasted image 20241006181217.png]]
![[Pasted image 20241006181242.png]]

A partir de estas se puede calcular las frecuencias relativas.
Sabiendo esto se pueden construir las Tablas Contingencia.
![[Pasted image 20241006181358.png]]

### Media y varianza
Además se pueden calcular otros valores marginales en base a una de estas variables.
![[Pasted image 20241006181504.png]]

### Frecuencias condicionadas.
Ocurre de igual forma con la Y.
La frecuencia relativa condicionada de una variable, pongamos Y sobre X (Y/X), define las veces que aparecen los valores de la variable Y, fijado un valor de la variable X.
![[Pasted image 20241006182106.png]]
![[Pasted image 20241006182233.png]]

### Media y varianza condicionada.
![[Pasted image 20241006182401.png]]

De manera aclaratoria se podría ver como hacer la media o varianza, fijado un valor para la Y, de todos los valores que toma la X en dicho valor.

## Momentos Bidimensionales.
![[Pasted image 20241006182709.png]]

### Covarianza
De estos momentos podemos observar un caso particular en los momentos centrales o respecto de la media. Si fuera el caso de $m_1$$_1$ estaría coincidiendo con la covarianza.

La cual tiene la siguiente formula.
![[Pasted image 20241006183103.png]]
Según su comportamiento podemos observar diferentes características de las variables:
+ Si es negativa: Las variables varían en sentidos opuestos.
+ Si es positiva: Las variables varían en el mismo sentido.

## Dependencia de variables.
+ Funcional: Existe una expresión matemática que las relacione
+ Estadística: No existe.
+ Independencia: X es independiente de Y si las distribuciones de X condicionadas a Y coinciden.
	![[Pasted image 20241006183940.png]]
## Regresión
Consiste en ajustar una curva de función conocida a una la nube de puntos para predecir el comportamiento de dichas variables.
Si la coincidiera una recta estamos hablando de Regresión Lineal.

La Recta de regresión de Y sobre X es: y = ax + b
Para estimar a y b se trata de minimizar la distancia de los puntos a la recta. (EL PROCEDIMIENTO ESTA EN LAS DIAPOS)

Tras dicho proceso nos queda:
![[Pasted image 20241006184817.png]]
Quedando como recta de regresión:
![[Pasted image 20241006184916.png]]

Esto ocurre de la misma forma si la recta fuera de X sobre Y.

### Coeficientes de regresión
![[Pasted image 20241006185142.png]]

### Varianza residual
Si hay dudas mirar este [video](https://www.youtube.com/watch?v=dNEsmaWbRHs)
![[Pasted image 20241006190506.png]]

La raíz cuadrada de esta es el Error típico.

De esta podemos sacar lo siguiente.
![[Pasted image 20241006191013.png]]


También sirve para calcular el coeficiente de Determinación.
![[Pasted image 20241006191209.png]]
## Correlación
![[Pasted image 20241006191338.png]]
![[Pasted image 20241006191348.png]]