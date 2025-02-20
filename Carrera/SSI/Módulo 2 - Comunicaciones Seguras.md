**Recursos**
[[2SSICifradoenFlujosinRC4niE0.pdf|PDF]]
___
# Tema 3
## Criptografía
+ Clave Secreta: Ambas partes comparte una misma clave con la que operan.
+ Clave Pública: Se usan dos claves diferentes para cifrar y descifrar.

El cifrado en flujo realiza una operación de cifrado Vernam, pero la key usada es pseudoaleatoria, cada una de las partes debe tener una misma semilla.

### ChaCha20
El cifrado ChaCha20 usa generador pseudoaleatorio ARX (Add Rotate Xor) y usa:
+ Una constante de 128 bits, actualmente son 256
+ Una clave secreta de 256 bits
+ Un nonce pseudoaleatorio de 96 bits (evita ataques por repetición)
+ Un contador de 32 bits

Produce 16 palabras de 32 bits (512 bits).

La secuencias cifrantes tienen un periodo de $2^{73}$ bits.

Se usa una hash Poly1305 que genera una MAC la cual sirve para acreditar que el contenido no se ha modificado.

Su funcionamiento es el siguiente:
+ Se trabaja en una matriz 4x4.
+ Se empiezan con 4 parámetros hexadecimales de 128 bits, 8 palabras clave de 256 bits, una palabra contador, 3 palabras de nounce y 4 palabras constantes.
+ Usa la operación QR(a,b,c,d) que opera de la siguiente manera:
![[Pasted image 20250210130738.png]]
Durante 20 iteraciones hace: 
+ impares se aplica sobre las 4 columnas.
+ pares se aplica sobre las 4 diagonales.

![[Pasted image 20250218101346.png]]

### Desplazamiento con realimentación lineal
+ ~ Consiste en un generador de secuencias pseudo-aleatorias binarias

+ ~ Este método es usado por GPS, Bluetooth, telefonía móvil y cifrados militares

Se usa un polinómio de realimentación el cual calcula cual de los bits van a ser usados para generar, mediante un XOR el nuevo bit que se añadira a la posición más significativa, desplazando a la derecha.
![[Pasted image 20250218103540.png]]

+ ~ Uno de los ejemplo de uso son los GNSS (Global Navigation Satellite System) donde el 87% de señales son generadas usando este método

Uno de los más famosos son los GPS C/A que usan dos LFSRs para operar de la siguiente manera
![[Pasted image 20250218103852.png]]

Dado un determinado ID, se determinan los taps que se van a emplear en el segundo LFSR

+ ~ Múltiples satélites de GNSS hacen uso de variaciones de estos métodos, variando la cantidad y longitudes de los LFSRs

### Cifrados en Telefonía Móvil
+ ~ Se suelen usar Snow3G y Aes principalmente, pero también se usan ZUC y kasumi

Por lo general se usa el siguiente diseño:
![[Pasted image 20250218104659.png]]

En 5G el cifrado es el siguiente:
+ se usa una clave de 128 bits, un contador de 32 bits, Identidad del portador de 5 bits, dirección de la transmisión de 1 bit y la longitud de la secuencia a cifrar necesaria.

![[Pasted image 20250218110232.png]]

El método SNOW3G consta de un LFSR y una máquina de estados finitos FSM.
+ El LFSR tiene longitud 16 y cada elemento contiene 4 bytes
+ La realimentación se define como un polinomio primitivo sobre GF($2^{32}$) el cual es el siguiente:

![[Pasted image 20250218110558.png]]

+ La FSM es la parte no lineal del generador y se alimenta de las posiciones 5 y 15
+ Está formada por tres registros de 32 bits y dos cajas de sustitución o S-boxes
+ Las S-boxes toman 32 bits y producen 32 bits tras una serie de operaciones
+ La primera S-Box se basa en el cifrado AES mientras que la segunda está pensada para SNOW3G
+ Las operaciones de mezcla consisten en una XOR bit a bit y una suma de enteros módulo $2^{32}$
+ El LFSR tiene modo inicialización y modo generación
+ El SNOW3G se inicializa con la clave de 128 bits, un vector de inicialización de 128 bits, una palabra 0xffffffff y los registros a 0.

![[Pasted image 20250218110632.png]]

Las dos multiplicaciones son en módulo x⁸ + x⁷ + x⁵ + x³ + 1
o lo que es lo mismo, desplazamientos de bytes y XORs con 10101001
![[Pasted image 20250218112523.png]]
