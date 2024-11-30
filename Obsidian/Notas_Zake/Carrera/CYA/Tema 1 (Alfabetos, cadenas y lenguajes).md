[[20240917_CyA-Transparencias-T1.pdf|PDF]]
___
## Definiciones.
### Alfabetos
Un conjunto no vacío y finito de símbolos, se representan como **Σ**
Si **σ** esta en Σ es entonces un símbolo del alfabeto
![[Pasted image 20240918091854.png]]
### Una cadena
Es una secuencia finita de símbolos del alfabeto. Estas cadenas carecen de significado (123 no es ciento veintitrés, es uno dos tres).
Cada símbolo de un alfabeto es una cadena sobre dicho alfabeto.
![[Pasted image 20240918091925.png]]

La longitud se denota por |ω|
+ Dos cadenas de diferente longitud siempre serán diferentes
+ Dos cadenas de igual longitud pero diferente orden en sus elementos siempre serán diferentes
+ Existe una cadena vacía la cual se representa como **ε**, |**ε**| = 0. Dicha cadena es una cadena sobre cualquier alfabeto.
### Lenguaje
Un lenguaje formal es un conjunto de cadenas sobre un lenguaje.
![[Pasted image 20240918092533.png]]
+ Todo alfabeto es un lenguaje con cadenas de un único símbolo
+ Los lenguajes pueden ser infinitos
+ A mayor cardinal, mayor dificultad de determinar sus cadenas
+ El lenguaje vacío tiene cardinal 0 mientras que un lenguaje con la cadena vacía tiene cardinal 1. Por ende, son diferentes
	![[Pasted image 20240918094510.png]]
+ Siendo **Σ** un lenguaje y **ω** una cadena sobre dicho lenguaje y existe un lenguaje sobre este lenguaje y contiene algunas cadenas del mismo incluyendo ω entonces: ω pertenece al lenguaje.

Un lenguaje universal es el lenguaje compuesto por todas las posibles cadenas del alfabeto. Se denota como **Σ**\*, este es infinito pues no hay alfabeto vacío.
![[Pasted image 20240918095024.png]]

## Operaciones.
### Concatenación
Sea w,z cadenas de E
La concatenacion es una cadena obtenida tras añadir a w la cadena z y se representa con wz o w\*z, la longitud de dicha cadena sera la suma de las longitudes de las otras dos.
w = abra
z = cadabra
wz = abracadabra
**ε** es la identidad de la concatenación **ε**\*w = w\***ε** = w

### Repeticiones
Consiste en concatenar una cadena consigo misma n veces
![[Pasted image 20240918102556.png]]

### Igualdad
Se da cuando dos cadenas son de la misma longitud con los mismo símbolos en el mismo orden.

### Prefijos y sufijos.
w,x perteecientes **Σ**\*
x es prefijo de de w si 
![[Pasted image 20240918120401.png]]
+ Toda cadena puede considerarse prefijo de si misma y **ε** es prefijo de cualquier cadena.
+ Los prefijos propios son aquellos que no son iguales a la cadena.

### Subcadenas
Sean x, y, z, w cadenas pertenecientes a **Σ**\*
w sera subcadena de z si existen x e y tan que z = xwy
![[Pasted image 20240918121113.png]]

### Subsecuencias
Sean x, y cadenas pertenecientes a **Σ**\*
Se dice que x es subsecuencia de y si contiene símbolos de y, respetando su orden aunque no sea contiguos (se puede saltar símbolos)

Sea w = 123456789
una subsecuencia sería y = 257 ó y = 19 ó 3489

+ Toda subcadena es subsecuencia, su recíproco es falso
+ **ε** es subsecuencia de toda cadena
### Inversa
Siendo w una cadena que pertenece a **Σ**\*.
Su inversa se define como:
![[Pasted image 20240918121932.png]]
Ejemplo
![[Pasted image 20240918121957.png]]
## Operaciones con lenguajes
#### Concatenación
Produce como resultado un conjunto con todas las posibles concatenaciones de ambos lenguajes, no es conmutativo
![[Pasted image 20240920164049.png]]
Ejemplo:
![[Pasted image 20240920164115.png]]
+ Si los lenguajes a concatenar son sobre diferentes alfabetos la concatenación será sobre la union de dichos alfabetos.
+ Concatenar un lenguaje cualquiera con un lenguaje que solo contenga la cadena vacía resulta en el lenguaje original.
#### Potencia
Sea L⊆Σ*
Se define su potencia como:
![[Pasted image 20240920164519.png]]
Ejemplo:
![[Pasted image 20240920164558.png]]
+ La potencia 0 del lenguaje vacío resulta en el lenguaje que contiene únicamente la cadena vacía.
+ La enésima potencia del lenguaje vacío para cualquier n mayor que 1 es igual al lenguaje vacío.
![[Pasted image 20240920164824.png]]
#### Unión e Intersección.
Sean L$_1$ ⊆ Σ* , L$_2$ ⊆ Σ*
![[Pasted image 20240920165408.png]]
La Unión cumple la propiedad distributiva de la siguiente manera.
![[Pasted image 20240920165514.png]]
#### Sublenguajes e igualdad
Un lenguaje es sublenguaje de otro si todas sus cadenas están en este otro lenguaje, se dice que todo lenguaje sobre el alfabeto Σ son sublenguajes de Σ*.

Se dice que son iguales si contienen las misma cadenas y, por tanto, están contenidos el uno en el otro.
#### Diferencia
Sean L$_1$ y L$_2$ lenguajes de un alfabeto Σ la diferencia será
![[Pasted image 20240920173117.png]]
Ejemplo:
![[Pasted image 20240920173213.png]]
#### Complementario
Se L un lenguaje sobre un alfabeto Σ su complementario será.
![[Pasted image 20240920173404.png]]
Un ejemplo de esto.
![[Pasted image 20240920173523.png]]
#### Inversa
Se L un lenguaje sobre un alfabeto Σ su inverso será.
![[Pasted image 20240920173645.png]]
Ejemplo:
![[Pasted image 20240920173832.png]]
## Cierre de Kleene y Cierre positivo
Sea L ⊆ Σ\*
![[Pasted image 20240920170416.png]]
Sea L ⊆ Σ\*
![[Pasted image 20240920170554.png]]
Ejemplo:
![[Pasted image 20240920170719.png]]
#### Propiedades
![[Pasted image 20240920170818.png]]
#### Teoremas
![[Pasted image 20240920170918.png]]
#### Demostración
![[Pasted image 20240920172142.png]]
La demostración es la siguiente.
![[Pasted image 20240920172340.png]]![[Pasted image 20240920172644.png]]
