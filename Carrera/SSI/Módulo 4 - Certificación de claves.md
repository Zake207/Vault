## Certificados
Las claves públicas son seguras siempre que estén certificadas, estos certificados deben tener información básica como:
+ la identidad que se certifica
+ la clave que se certifica
+ entidad que expide el certificado
+ fecha de validez

Existen modelos desentralizados de certificación como GPG, donde cada persona firma las claves de las personas en las que confía

El modelo centralizado se basa en el modelo X.509, aquí determinadas autoridades pueden emitir certificados.

Los certificados se revocan si se acaba el periodo de validez o si esta se ve comprometida y siempre se debe mirar la lista de revocados antes de acertar un certificado

## Firma digital

Sus ventajas son:
+ Verifica el emisor
+ Autentica la integridad del mensaje
+ Permite comprobarse por terceros

Depende del mensaje a firmar y el emisor, es fácil de reconocer y de producir, permite guardar los documentos firmados y es imposible de falsificar.

Se suele usar en correo electrónico y la certificación de clave pública
Se puede combinar el cifrado y la firma digital

La Firma RSA es un tipo de firma que emplea este algoritmo de cifrado:
*Insertar foto del mecanismo de firma*
Ejemplo:
P_a = 3  -- Pb = 5
q_a = 13 -- qb = 17
d_a = 7  -- db = 11
M = 2

Firma A-B = $M^{d_{a}}\ \%\ n_{a}$ siendo $n_a = p_{a} * q_{a}$ 
El resultado de esta operación es 128 mod 39 = 11
Cifrar y firmar basicamente aplicas RSA 2 veces

Normalmente se aplica una función hash al mensaje, sobre este se aplica el esquema de cifrado y firma, la más conocida es MD5 y la familia de funciones SHA

El sistema de firma digital estándar es el DSS y también ECDSA

Se suele usar un criptosistema que combina varios de los métodos vistos para asegurar la seguridad

