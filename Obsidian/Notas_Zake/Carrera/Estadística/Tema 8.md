[[Tema 8_Variables_Aleatorias_Continuas.pdf|PDF]]
[[HOJA6.pdf|PROBLEMAS]]
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
Dada una variable de Poisson X = Po($\lambda$) 