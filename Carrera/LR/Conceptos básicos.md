## Definiciones
### Switch
Interconecta dispositivos de la misma red LAN, opera en la capa de enlace (capa 2) del modelo TCP/IP. El switch tiene las direcciones MAC a las que puede llegar, por que puerto se llega a estas y un TTL en una tabla de 3 entradas. Usa esta tabla para operar:
+ Al iniciar empieza vacía
+ Si busca una dirección y no la encuentra, inunda los puertos, los que no coinciden con dicha dirección desechan la trama.
+ Cuando entra por un puerto anota en la tabla el destino, el puerto y un ttl. Así se rellena la tabla.

*Nota:*
*Una trama ETHERNET con cabecera DESTINO, ORIGEN y TIPO*

*Pregunta: Tienes una organización, ¿porque se prefiere dividir la red de la organización en varias en lugar de tener una única red para toda la organización?*


