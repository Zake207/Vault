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