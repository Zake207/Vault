Pueden ser del tipo cliente-servidor o Peer-to-peer
+ Cliente-servidor: Existe un host activo que provee servicios a los clientes. Requiere arquitectura intensiva
+ Peer to peer: Servicios no centralizados, arquitectura auto-escalable, se explota la comunicación entre los hosts
## Comunicación de mensajes.
Para direccionar procesos se debe conocer la dirección del host y del proceso (IP y puerto).
La organización IANA se encarga de gestionar los nombres de dominios, recursos y asignaciones de protocolos

Se utiliza una caché web para ahorrar tiempo de conexión, para ello se usan los servidores proxy como almacenamiento intermedio.
HTTP no cuenta con memoria de conexión, para que puedan tener esto se usan las cookies.

Al hacer una petición se abre una conexión con el puerto 80 del servidor, 
1. el cliente envía un mensaje GET 
2. el servidor envía un HTTP response con el recurso 
3. este cierra conexión, el cliente recibe la respuesta y la conexión termina. 

Se suelen enviar GET condicionales para comprobar si el recurso está actualizado.

DNS Es una base de datos distribuida que traduce las direcciones IP en nombres legibles. Un host puede tener diferentes alias y un alias puede pertenecer a diferentes hosts. Hay 3 tipos de servidores:
+ Servidor raiz
+ Servidor de dominio de nivel superior (responsables de los dominios a nivel superior)
+ Servidor autoritativo

Además existe el Servidor DNS local empleado para acelerar consultas a nivel local

El servidor local recibe una petición dns, si no la tuviera en el caché debe acudir al Servidor DNS raíz, tras esto, dicho servidor consulta al Servidor DNS TLD, al obtener la dirección consultada se hace una consulta al servidor autoritativo de la dirección consultada para reenvíar en sentido contrario una respuesta.

Si se hiciera de forma iterativa el servidor local sería el encargado de hacer todas las consultas.

Los servidores DNS guardan diferentes tipos de registros (A, NS, CNAME, MX)

DHCP
El cliente envía un DHCP discover a la dirección broadcast, este llega al servidor que tiene un pool de direcciones a asignar, le manda  un DHCP offer al broadcast de nuevo ofreciéndole una ip al cliente nuevo, tras comprobar esta el cliente le solicita esta dirección con un DHCP request al servidor, la dirección se retira del pool del servidor DHCP y le envía un DHCP ACK al cliente.

El servidor DHCP se puede colocar en el router que da al exterior y mediante DHCP relay se le hace la consulta al servidor DHCP centralizado fuera de la red.

NAT
Un protocolo de traducción de direcciones de red.
Hay tres bloques de direcciones privadas:
+ 10.0.0.0/8
+ 172.16.0.0/12
+ 192.168.0.0/16

Estas son de libre disposición, pero al estar repetidas en redes locales de múltiples sitios, se llega a que ningún host de internet debe mandar paquetes a estas direcciones. El protocolo NAT se encuentra en el router fronterizo entre el área privada y pública.
Si un ordenador de la red privada envía un paquete a un host de internet, el envío se hace correctamente pero al querer reenviar una respuesta no podrá enviarla a la ip privada de la maquina.

Por ello al hacer el envío se apunta en la tabla NAT la ip y puerto desde donde se envió el paquete y un puerto libre del router.
Se sustituye la ip y puerto del origen por el puerto libre y la ip del router. Al recibir la respuesta comprueba el puerto destino, revisa en la tabla NAT las entradas encontrando una con este puerto y haciendo la traducción inversa.

Se puede modificar la tabla NAT para que si desde fuera se solicita un servicio alojado dentro de la red, se acceda a un puerto del router que tenga una entrada en la tabla que nosotros añadimos para que se redirija a donde nosotros le especifiquemos en la tabla.

La VPN encapsula paquetes de capas bajas en las de capas más altas para encriptarlas y mandarlas, pareciendo que los dos intermediarios están directamente conectados.

Middleware, esto es el software que permite a otro software operar (JMS, RPC, ...).

CORBA Es un estándar que establece como se crean los objetos distribuidos. Tiene varios elementos que se encargan de permitir este servicio. Genera plantillas de código tanto para el cliente como para el servidor.