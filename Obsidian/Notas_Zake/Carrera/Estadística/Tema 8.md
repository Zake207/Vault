[[Tema 8_Variables_Aleatorias_Continuas.pdf|PDF]]
___
## Distribución Uniforme Continua
Posee la siguiente función de densidad: $$f_{X}(x) = \frac{1}{b-a}\ \ \ \ a \leq x \leq b$$
+ X = U(a,b)
+ $\mu_{X} = \frac{a+b}{2}$ 
+ $\sigma²_{X} =\frac{(b-a)²}{12}$

Gráficamente:
![[Pasted image 20241202190256.png]]

Su distribución es
![[Pasted image 20241202190638.png]]
## Distribución Normal
Aparece naturalmente en distribuciones de pesos, puntuaciones de examen, distancia de frenado, etc...

Su función de densidad es: $$f_{X}(x) = \frac{1}{\sigma\ ·\ \sqrt{2\pi}}\ ·\ e^{-\frac{(x-\mu)²}{2\sigma²}}$$
![[Pasted image 20241202191847.png]]

+ X = N($\mu$,$\sigma²$)
+ $\mu_{X} = E[X] = \mu$
+ $\sigma²_{X} = V(X) = \sigma²$

Gráficamente se representa con una campana de Gauss, el máximo se da cuando x = $\mu$ y vale $\frac{1}{\sigma\ ·\ \sqrt{2\pi}}$

Propiedades:
![[Pasted image 20241202192338.png]]

Una N(0,1) es la normal estándar y se denota por Z = $\frac{X-\mu}{\sigma}$
Su función de densidad no es más que las sustitución de las variables correspondientes:
![[Pasted image 20241202193136.png]]

### Cálculo de probabilidades
Se usan tablas que muestran las probabilidades de la cola superior.

Se denotan los siguientes casos:
#### 1. $P(Z \geq z_{\alpha} = \alpha)$
![[Pasted image 20241202193805.png]]

En el caso de que z no esté en la tabla se debe interpolar de la siguiente manera:
![[Pasted image 20241202193921.png]]

#### 2. $P(Z \leq z_{\alpha})\ \ \forall z_{\alpha} > 0$
En este caso equivale a hacer $1-P(Z\geq z)$
![[Pasted image 20241202194449.png]]

#### 3. $P(Z \leq z)\ \ \forall z<0$
En este caso equivale a hacer $P(Z\geq -z)$
**Ejemplo** *P(Z ≤ -0.71) = P(Z ≥ 0.71) = 0.2389*

#### 4. $P(Z \geq z)\ \ \forall z<0$
En este caso equivale a hacer $1 - P(Z\geq -z)$
![[Pasted image 20241202195048.png]]

#### 5. $P(a \leq Z \leq b)$
Equivale a hacer $P(Z \geq a) - P(Z>b)$
#### 6. $P(|Z - a| ≤ b)$ 
$P(a-b \leq Z \leq a+b)$
#### 7. $P(|Z - a| \geq b)$
$P(Z ≤ a-b) + P(Z ≥ a+b)$
### Búsqueda de un $z_{\alpha}$ dado $\alpha$
#### 1. $P(Z ≥ a) = α\ \ \ \ \forallα < 0.5$
![[Pasted image 20241202200016.png]]

#### 2. $P(Z \leq a) = α\ \ \ \ \forallα < 0.5$
Equivale a $P(Z ≥ -a) = \alpha$
![[Pasted image 20241202200228.png]]

#### 3. $P(Z \leq a) = α\ \ \ \ \forallα > 0.5$
Equivale a $P(Z\geq a) = 1-\alpha$
**Ejemplo** *P(Z ≤ a) = 0.6554 $\implies$ P(Z > a) = 1- 0.6554 = 0.3446 y a = 0.4*
#### 4. $P(Z ≥ a) = α\ \ \ \forall \alpha \geq 0.5$
Se aplica $P(Z < a) = 1 - α$ y después el caso 2.
![[Pasted image 20241202201549.png]]

#### 5. $P(Z \geq a) = \alpha$  || $\alpha$ no está en las tablas
Se debe interpolar como el siguiente caso:
**Ejemplo:** *P(Z ≥ a) = 0.152. Si se busca en la tabla se tiene: P(Z ≥ 1.03) = 0.1515 y P(Z ≥ 1.02) = 0.1539*
![[Pasted image 20241202201801.png]]

### Relación Binomial-Normal
Se puede aproximar una variable Binomial a una Normal siempre que np > 5 y nq > 5, de esta forma se obtiene una $N(np, \sqrt{ npq })$ siendo $Z =\frac{X-np}{\sqrt{ npq }}$

Se deben aplicar los factores de corrección pertinentes.
![[Pasted image 20241202202426.png]]

![[Pasted image 20241202202445.png]]

### Relación Poisson-Normal
Dada una variable de Poisson X = Po($\lambda$) donde $\lambda > 5$ se puede aproximar a $$Z = \frac{X - \lambda}{\sqrt{ \lambda }}$$
que a su vez se aproxima a una N(0,1).

**Ejemplo** *Supóngase que el nº de partículas de asbesto en un centímetro cuadrado de polvo tiene un distribución Po(1000). Si se analiza un cm2 de polvo ¿Cuál es la probabilidad de encontrar menos de 950 partículas?*

![[Pasted image 20241203113833.png]]

## Distribución Exponencial
Se dice que una variable aleatoria X que mide el tiempo entre dos ocurrencias sucesivas de un proceso de Poisson de media $\theta > 0$ sigue una distribución Exponencial de parámetro $\theta$.

Su función de densidad es $\theta e^{-\theta x}$ para x > 0.
+ $E[X] = \frac{1}{\theta}$
+ $V(X) =\frac{1}{\theta^2}$

**Propiedad de amnesia:** La probabilidad de que una componente funcione mas de a+b unidades de tiempo sabiendo que lleva funcionando a unidades equivale a calcular la probabilidad de otra variable que dure más de b unidades de tiempo.
$$P(X \geq a+b\ \ /\ \ X\geq a) = P(X \geq b)$$

## Distribución Gamma
Dada una variable X con la siguiente función de densidad:
![[Pasted image 20241203115328.png]]

Se dice que la variable sigue una distribución Gamma con parámetros a y p con las siguientes propiedades:
+ a > 0 (1/a, parámetro de escala)
+ p > 0 (parámetro de forma)
+ $\Gamma(p) = {\int_{0}^{\infty}  \,x^{p-1}e^{-x} dx}$
+ $E[X] = \frac{p}{a}$
+ $V(X) = \frac{p}{a^{2}}$

![[Pasted image 20241203120508.png]]

Sean $X_1, ...,X_{n}$ n variables aleatorias e independientes entre sí y cada una distribuida como una $\Gamma(a, 1)$ tenemos:
![[Pasted image 20241203121358.png]]

Si tenemos una variable X que sigue una distribución $\Gamma(a,p)$ y una constante c, $c·X = \Gamma(a/c\ ,\ \ p)$
## Distribución Beta
![[Pasted image 20241203123022.png]]

## Distribución Weibull
![[Pasted image 20241203123049.png]]

## Distribución Chi-Cuadrado
Sea X = N(0,1) se define $Y = X^2$ que sigue una distribución Chi-Cuadrado con 1 grado de libertad cuya función de densidad es:
![[Pasted image 20241203123548.png]]

Si existieran n variables X aleatorias que se distribuyen con N(0,1) se dice que siguen una distribución Chi-Cuadrado con n grados de libertad $\chi_{n}^2$
![[Pasted image 20241203123924.png]]

+ $\mu = n$
+ $\sigma^2 = 2n$

![[Pasted image 20241203124057.png]]
![[Pasted image 20241203124110.png]]

Además se tiene que la suma de dos variables que sigan esta distribución con diferentes grados de libertad, la suma de las dos variables da como resultado una variable Chi-Cuadrado que tiene como grados de libertad la suma de los anteriores.

## Distribución t de Student
Dada dos variables aleatorias Z (que siguen una N(0,1)) e Y (que sigue una $\chi_{n}^2$) se define la variable $$t_{n} = \frac{Z}{\sqrt{ \frac{Y}{n} }}$$
Es una t de Student con n grados de libertad.
+ $E[X] = 0$
+ $V(X) = \frac{n}{n-2}$

![[Pasted image 20241203125314.png]]

![[Pasted image 20241203125328.png]]
## Dsitribución F de Fisher-Snedecor
Dada dos variables aleatorias que siguen una distribución Chi-Cuadrado se define:
![[Pasted image 20241203125707.png]]

+ $E[X] = \frac{n_{1}}{n_{1}-2}$
+ $V(X) = \frac{2n_{1}^2 (2 + n_{1} + n_{2})}{n_{2}(n_{1} - 2)^2 ·(n_{1}-4)}$

Que es una distribución F de Fisher Snedecor con n1 y n2 grados de libertad.
![[Pasted image 20241203125752.png]]

Para calcular probabilidades se usa la tabla que solo muestra las $\alpha$ < 0.5 si $\alpha$ > 0 se usa lo siguiente:
![[Pasted image 20241203130245.png]]