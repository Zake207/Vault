[[Tema 7_Variables_Aleatorias_Discretas.pdf|PDF]]
[[HOJA5.pdf|PROBLEMAS]]
___
# Distribuciones de probabilidad discreta
## Distribución uniforme discreta
Se dice de una variable aleatoria que todos los elementos tienen la misma probabilidad.$$P(X=x_{i}) = f_{X}(x_{i})=\frac{1}{n}$$
**Ejemplo:**
*Sea el terminal de un número de lotería. Este puede valer cualquier de los números del 0 al 9, y todos tienen igual probabilidad 0.1. Entonces:*

X Es Terminal de un número de lotería” es Uniforme Discreta.
Suponiendo que tome los valores de $a$ hasta $b$ tenemos:
+ $\mu_{X} = E[X] = \frac{a+b}{2}$
+ $\sigma²_{X} = \frac{(b - a + 1)² -1}{12}$

## Distribución de Bernouilli
En un experimento aleatorio con solo dos resultados excluyentes se les llama prueba de Bernouilli:
+ A con probabilidad p
+ !A con probabilidad 1-p

La variable toma el valor 1 cuanto ocurre A y 0 cuando ocurre !A.

**Ejemplo:** *Extraer una pieza de un lote de 100, donde hay 15 defectuosas. X= Salir defectuosa.* En este caso p = 0.15
+ $\mu_{X} = p$
+ $\sigma²_{X} = pq$
+ X = Be(p)
## Distribución Binomial
Experimento en el que se hacen n pruebas de Bernouilli.
+ Dichas pruebas son independientes
+ La probabilidad de éxito p permanece constante

**Ejemplo:** *Se lanza 10 veces una moneda. Los posibles resultados de cada lanzamiento son: 
+ *cara que suponemos éxito con P(cara) = 1/2 
+ *cruz que suponemos como fracaso con P(cruz) = 1/2 
Cada lanzamiento es una Prueba de Bernouilli. Además, se puede apreciar: 
1. *Si sale cara en el 3º lanzamiento no influye en el 5º lanzamiento. 
2. *La probabilidad de obtener cara es la misma en todos los lanzamientos.*

Una variable descrita como Binomial cuenta el número de éxitos con prob. p en n pruebas de Bernouilli. Es **reproductiva respecto al parámetro n** y su función de probabilidad es:
![[Pasted image 20241129165541.png]]
+ $\mu_{X} = E[X]= np$
+ $\sigma²_{X} =V(X) = npq$
+ X = Bi(n,p)

Para resolver problemas se hace uso de la tabla:
![[Pasted image 20241129170114.png]]
**Ejemplo** *Buscar las probabilidades en la tabla
+ *P(Bi(5,0.1) = 1) = 0.3280 
+ *P(Bi(7,0.5) = 3) = 0.2734

Si p > 0.5 ocurre lo siguiente
![[Pasted image 20241129170858.png]]
**Ejemplo** *Buscar la siguiente probabilidad en la tabla
+ *P(Bi(10,0.8)=7) = P(Bi(10,0.2) = 3) = 0.2013

## Distribución de Poisson
Se puede definir como una Binomial con la n grande y la p pequeña. 
+ p = $\lambda$ / n
+ $\lambda$ = nº medio de ocurrencias
Un proceso de Poisson es un conteo de ocurrencias en intervalos pequeños tales que:
+ La probabilidad de más de una ocurrencia en un subintervalo sea 0.
+ La probabilidad de ocurrencia en un intervalo es la misma en todos y proporcional a su longitud.
+ El conteo de ocurrencias es independiente del subintervalo.

Su función de probabilidad es:
![[Pasted image 20241129173039.png]]
**Ejemplos**
1. *Nº de emisiones de partículas radioactivas durante un intervalo de tiempo de un material radioactivo
2. *Nº de errores de una secretaria al mecanografiar una página

+ $\mu_{X} = E[X]= \lambda$
+ $\sigma²_{X} = \lambda$
+ X = Po($\lambda$)

Relación Binomial-Poisson: Se puede aproximar una Poisson cuando
+ n > 50
+ p < 0.1

ó
+ np < 5

## Distribución Geométrica
Dada una serie de pruebas de Bernouilli independientes y con la misma probabilidad de éxito p. La distribución geométrica mide el número de pruebas realizadas hasta el primer éxito.
Función de probabilidad:
![[Pasted image 20241129175543.png]]

**Ejemplo** *La probabilidad de recibir de forma errónea un bit enviado por un canal de transmisión digital es 0.1. Supuesto que las transmisiones son independientes. 

*Sea X = nº de bits transmitidos hasta que se presenta el primero error.

*¿Cuál es la probabilidad de se transmitan 4 bits de forma correcta? 

*Solución: P(X=5) = 0.94 x 0.1= 0.066*

+ $\mu_{X} = E[X]= \frac{1}{p}$
+ $\sigma²_{X} = V(x) = \frac{1-p}{p²}$
+ X = Ge(p)

En el caso de que se quiera contar el número de fracasos hasta el primer éxito cambia lo siguiente:
![[Pasted image 20241129180933.png]]

## Distribución Binomial Negativa
Dada una serie de pruebas de Bernouilli independientes y con la misma probabilidad de éxito p.
La distribución cuenta el número de fracasos hasta el n-ésimo éxito.
Su función de probabilidad:
![[Pasted image 20241129181313.png]]

+ $\mu_{X} = E[X]= \frac{n(1-p)}{p}$
+ $\sigma²_{X} = V(x) = \frac{n(1-p)}{p²}$
+ X = BiN(n,p)

## Distribución hipergeométrica
Dado un conjunto con N objetos que contiene
+ k objetos clasificados como éxito, k $\leq$ N
+ N-k objetos clasificados como fracaso

Al elegir una muestra de tamaño n (n $\leq$ N) al azar y sin reemplazo la distribución mide el número de éxitos en la muestra.
Su función de probabilidad:
![[Pasted image 20241129181855.png]]

Dado que p = k/N
+ $\mu_{X} = E[X]= np$
+ $\sigma²_{X} = V(x) = np(1-p)\frac{N-n}{N-1}$
+ X = Hi(N,n,k)

**Ejemplo** *Un lote de piezas contienen 100 de un proveedor local y 200 de un proveedor exterior. Si se eligen 4 piezas al azar y sin reemplazo. ¿Cuál es la probabilidad de que todas procedan del proveedor local?*

*Sea X “nº de piezas de las 4 elegidas que son del proveedor local”*

![[Pasted image 20241129182202.png]]
