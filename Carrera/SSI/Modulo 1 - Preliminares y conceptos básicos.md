# Tema 1
## Conceptos
Área que se enfoca en la seguridad de la infraestructura computacional.

Te puedes centrar en proteger tanto Software (cortafuegos, SO robustos), Hardware (vigilar de quien la maneja) o Datos (Criptografía).

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

### Tipos de secretos
**Secretos prácticos** : Seguros frente a recursos acotados.
**Secretos perfectos** : Seguros frente a recursos ilimitados.

Cifrado de Vernam tiene seguro perfecto dada la aleatoriedad de la clave a la hora de ser generada. Realiza la suma bit a bit sin acarreo entre el mensaje y la clave para generar el mensaje cifrado.

*Instituto Nacional de Ciberseguridad: Retos*

### Cifrados adicionales
+ Escítala griega
+ Cifrado César
+ Telegrama Zimmermann
+ Máquina Enigma
+ Clave Pública (RSA)
+ Cifrado Atbash

Cifrado de Vignere generaliza el cifrado por desplazamiento. Usando una tabla y la clave para cifrar el mensaje.

## Aritmética modular
Usa un conjunto finito de enteros para realizar calculos complejos y permite calcular la inversa de varias operaciones.
# Tema 2