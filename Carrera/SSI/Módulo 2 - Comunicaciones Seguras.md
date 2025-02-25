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

## Cifrado en bloque
Divide el mensaje en bloques sobre los que se aplica el algoritmo
Usa cifrados tipo Feistel, que divide en dos mitades un bloque de N bits y opera con la clave solo en una mitad. Es bastante usado en el cifrado Kasumi que usa 40 claves de 16 bits, el cual es usado en 3G

El cifrado AES o Rijndael, usa:
+ BLoques de 128 bits
+ La clave de 128, 192 y 256 bits
+ Iteraciones 10, 12, 14
+ Las operaciones son a nivel de byte.

El estado se representa como una matriz de 4x4 de 8 bits al igual que la clave
+ ? Cae en examen
### Iteración 0
XOR entre el bloque y la clave

### Bucle
1. ByteSub : sustitución no lineal, usa una S-box
2. ShiftRow : Usa desplazamientos circulares
3. MixColumn : Realiza multiplicaciones entre cada columna y una matriz.
4. Sum : hace una xor entre la matriz y la clave

Usa una expansión de claves que consiste en dividir una clave de 128 bits en bloques de 32 y sobre el último se realiza una rotación cíclica izquierda y una sustitución. También se usan constantes

Para el descifrado se deben realizar operaciones diferentes

Hay diferentes modos de cifrado en bloque
+ ECB : mantiene la estructura, no se usa por obvias razones
+ CFB : Cada bloque de texto esta cifrado con realimentación, usa un vector de inicialización. En caso de que el mensaje a cifrar(N) sea mayor que el vector de inicialización(Q) se realizaran las operaciones de realimentación N/Q veces.
+ OFB : Igual que el anterior pero la realimentación se realiza antes del xor en lugar de después
+ CBC : Se realiza la xor antes de entrar en el algoritmo de encriptado
