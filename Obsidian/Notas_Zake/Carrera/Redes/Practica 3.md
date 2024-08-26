Protocolos de la capa de aplicación:
+ Estándar: Se les asocia a un puerto bien conocido y se basan en una especificación.
+ Propietarios: Están diseñadas para una aplicación particular.

Se usan sockets que combinan una dirección ip y un puerto, pueden ser de tipo TCP o UDP.

Los servicios de la capa de transporte pueden ser accedidos desde ciertas librerías en múltiples API's y lenguajes.

---
En la practica se usará la versión UDP, y trabajaremos con AF_INET

Desde el cliente se manda un byte al servidor, este lo recibe y devuelve la hora del sistema.

Crear una función para crear sockets que inicialice sus datos
La dirección asignada al socket debe ser marcada como ANY para que las diferentes arquitecturas puedan operar con ella sin generar problemas.

En el cliente se conecta al servidor sabiendo el nombre de host y su ip.

Con el TCP por otro lado, hay que tener en cuenta que se debe ordenar los paquetes que se envia. Para ello hay que cambiar el tipo de socket.