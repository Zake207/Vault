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