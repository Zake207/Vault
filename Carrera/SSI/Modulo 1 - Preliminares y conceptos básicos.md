[[1SSIConceptosHistoria (1).pdf|PDF]]
___
## Conceptos
Área que se enfoca en la seguridad de la infraestructura computacional.

Te puedes centrar en proteger tanto Software (cortafuegos, SO robustos), Hardware (vigilar de quien la maneja) o Datos (Criptografía).

Existen amenazas internas y externas.

Las principales amenazas en la transmisión de información son:
+ Intercepción
+ Modificación
+ Interrupción
+ Generación

Se debe preservar
+ Confidencialidad
+ Integridad
+ Autenticidad
+ Accesibilidad : Controlar el acceso a personas autorizadas
+ Anonimato : Proteger la identidad del emisor y receptor.
+ No repudio : Dejar constancia de cambios y acciones realizadas.

## Cifrado
Un **cifrado** es un algoritmo que transforma la información mediante una **clave** con la cual se encripta el mensaje. No es lo mismo que un **código**, el cual no requiere de claves.
### Reglas de Kerckhoffs
1. No debe existir ninguna forma de recuperar el mensaje original desde el cifrado.
2. Todo sistema criptográfico debe estar compuesto por información pública y privada.
3. La clave debe de ser fácil de recordar y modificar
4. El mensaje debe poder enviarse por los medios habituales de comunicación.
5. La complejidad del proceso de recuperación debe ser proporcional a la importancia de la información.

### Tipos de secretos
**Secretos prácticos** : Seguros frente a recursos acotados.
**Secretos perfectos** : Seguros frente a recursos ilimitados.

### Cifrado Vernam
Cifrado de Vernam tiene seguro perfecto dada la aleatoriedad de la clave a la hora de ser generada. Realiza la suma bit a bit sin acarreo entre el mensaje y la clave para generar el mensaje cifrado.

*Instituto Nacional de Ciberseguridad: Retos*

### Cifrados adicionales
+ Escítala griega
+ Cifrado César
+ Telegrama Zimmermann
+ Máquina Enigma
+ Clave Pública (RSA)
+ Cifrado Atbash

### Cifrado Vigenere
Cifrado de Vigenere generaliza el cifrado por desplazamiento. Usando una tabla y la clave para cifrar el mensaje.

**Aritmética modular** : Usa un conjunto finito de enteros para realizar calculos complejos y permite calcular la inversa de varias operaciones.

Gracias a este concepto se pueden simplificar algunos algoritmos de cifrado:
![[Pasted image 20250128184201.png]]
#### Ejemplo de cifrado Vigenere
![[Pasted image 20250128184333.png]]