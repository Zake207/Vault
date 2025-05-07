[[FIREWALL-NAT.pdf|PDF]]

## Firewall
Dispositivo hardware o software que se encarga del filtrado de paquetes.
Opera mediante reglas que establecen patrones y opera con el tráfico que coincide con este patrón.

Hay 3 cadenas por defecto:
+ **Input** Paquetes entrantes destinados a alguna dirección del router
+ **Forward** Ni originados ni destinados al router
+ **Output** Paquetes originados del router

Las acciones a realizar en una regla son
+ Accept
+ Drop
+ Log
+ Jump
+ Reject

Para evitar el **IP Spoofing** se usan las siguientes direcciones internas:
+ Las direcciones privadas especificadas en RFC 1918: 10.0.0.0/8 172.16.0.0/12 192.168.0.0/16 
+ Direcciones multicast (direcciones de multidifusión) 224.0.0.0/4 
+ Direcciones de loopback 127.0.0.0/8
+ Direcciones de la clase E (Están reservadas). 240.0.0.0/4

Si las direcciones de la red interna no coinciden con alguno de los bloques de direcciones para redes privadas, también es recomendable restringir el acceso a aquellos paquetes con direcciones de origen correspondientes a la red interna.

## NAT (Network Address Translation)
Al usarse ciertas direcciones en las redes privadas, estas no se usarán en redes externas, por lo que hace falta transformarlas. En los routers que tienen acceso al exterior se configura NAT para ello. 

Si se quiere acceder a un host externo que no tiene una dirección global única o trabajar con otras redes que tienen sus direcciones privadas en necesario el NAT

+ **Source** Cambia la dirección de origen
+ **Destination** Cambia la dirección de destino
+ **Bidireccional** Source y Destination juntos

