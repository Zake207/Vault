## Definiciones
### Switch
Interconecta dispositivos de la misma red LAN, opera en la capa de enlace (capa 2) del modelo TCP/IP. El switch tiene las direcciones MAC a las que puede llegar, por que puerto se llega a estas y un TTL en una tabla de 3 entradas. Usa esta tabla para operar:
+ Al iniciar empieza vacía
+ Si busca una dirección y no la encuentra, inunda los puertos, los que no coinciden con dicha dirección desechan la trama.
+ Cuando entra por un puerto anota en la tabla el destino, el puerto y un ttl. Así se rellena la tabla.

*Nota:*
*Una trama ETHERNET con cabecera DESTINO, ORIGEN y TIPO*

*Pregunta: Tienes una organización, ¿porque se prefiere dividir la red de la organización en varias en lugar de tener una única red para toda la organización?*
## OSPF
+ ! Volver a resumir temario

Área Stub: Solo deja pasar los mensajes de tipo 1, 2, 3, el resto se tratan con ruta por defecto 0.0.0.0

Area totally stub: No reciben ningun tipo de mensaje, todos son tratados con una dirección por defecto

NSSA: Usado cuando se tiene un ASBR dentro del area, este devuelve tramas de tipo 7 que se transforma en un mensaje de 5 fuera del area

## Redistribución de rutas
**Sistema autónomo** grupo conectado de uno o más prefijos donde se usan el mismo protocolo de enrutamiento de pasarela interior (OSPF o RIP)

La redistribución de rutas obtiene una información entre las todas las rutas aunque tengan diferentes protocolos, sirve para: 
+ Fusión de empresas
+ Migraciones de protocolo
+ Interconexión de redes
+ Razones de diseño

+ ? Tener cuidado con la adaptación de costes que se lía, puede haber problemas con los caminos generando comportamientos inesperados (bucles)

Te puedes aprender todos los caminos posibles y usar la distancia administrativa, tiene prioridad la que tenga menor distancia administrativa.
## Redundancia de primer salto
Permite gestionar fallo en el primer salto teniendo varios routers.
El protocolo de enrutamiento permite tener alta disponibilidad en capa 3. Si embargo el enrutamiento de los ordenadores es estáticos, por lo que si la puerta de enlace falla, aún habiendo dos routers, esta no va a cambiar.

Para solucionar esto se usa VRRP (Virtual Router Redundancy Protocol) o HSRP. Esto Crea un router virtual que compila los dos router con una ip que sea la puerta de enlace a la red local, uno de los router de este router virtual es el master, si este falla, los paquetes son redirigidos a los router backups

El master dentro del router virtual esta activo indicando que es el master constantemente, cuando falle, este deja de emitir, el siguiente en la jerarquía se convierte en master y la red local no se ha enterado de nada. La jerarquía se establece con un nivel de prioridad, siempre es master el de mayor prioridad.

Sistema autónomo, se comunican dentro de este con protocolos de pasarela interior(RIP, OSPF) y entre otros sistemas autónomos con protocolos de pasarela exterior, tiene los siguientes tipos:
+ Strub
+ Tránsito
+ Multihomed
+ Internet Exchange Point

BGP usa tcp como protocolo de transprote en el puerto 179, a la hora de conectarse dos router BGP se realizan diferentes pasos:
+ OPEN
+ UPDATE
+ KEEPALIVE
+ NOTIFICATION

Tiene una serie de atributos: AS-PATH es una lista, NEXT-HOP es la ip del proximo salto...
Usa vectores de caminos, que no es otra cosa que el AS-PATH, que se rellena a medida que se reciben mensajes de updates, esto en cierto modo mapea los sitemas autónomos pues los mensajes de UPDATE no siempre recorren la misma ruta






