# Servicios
+ Direccionamiento: Cada paquete debe ir etiquetado con una dirección de origen y destino.
+ Reenvío: Se encarga de colocar los mensajes en las salidas adecuadas. Usa una tabla.
+ Enrutamiento: Determina cual es la ruta más adecuada entre el origen y el destino.

Los routers negocian los parámetros de transmisión para reservar los recursos necesarios. 
Los routers fragmentan los paquetes para más adelante reensamblarlos

- **Control de flujo**: Sincroniza las velocidades del emisor y receptor por ambas partes.
- **Control de congestión**: Detecta y corrige errores.

La capa se encarga de garantizar la entrega, de manera ordenada y segura.

# Conmutación
El circuito virtual consta de varias partes las cuales permiten dos particiones de enlace:
+ Multiplexación por división en tiempo. Se asignan ranuras de tiempo fijas.
+ Multiplexación por división en frecuencia. Se asignan bandas de frecuencias a cada circuito.

1. Primero el emisor se comunica con la capa de red indicándole el destino, la capa determina la ruta y configura el circuito virtual.
2. Se transmiten los datos.
3. En caso de querer cortar comunicación se informa a la capa de red. Los routers mediante protocolos de señalización se envían mensajes de este tipo entre ellos para informar que el circuito ya no existe.

Los routers no guardan información de estado. Usan la dirección de destino para dirigir la salida: Si hubiera una coincidencia se manda por la interfaz asociada, si hay coincidencias se manda por el más largo, si no hay ninguna se manda por una interfaz estándar. 

Para compartir el medio se usa la multiplexación estadística en los paquetes.
# Plano de control
Plano de datos: se encarga de la función de reenvío
Plano de control: Toma decisiones sobre el reenvío.
Ambas existen en cada dispositivo.

En las redes definidas por software se separan ambos planos para delegar a un controlador de software el plano de control.
# Estrategias
**Inundación**: El nodo envía a todos sus vecinos, estos la reenvían igual menos al nodo origen, un paquete cuenta con identificador para detectar repeticiones.

**Encaminado estático**: Configura una ruta permanente entre cada par de nodos.

**Vector de distancia**: Cada nodo guarda su coste y la distancia al resto de nodos y a sus vecinos, si recibe un vector de distancia usa bellman-ford para actualizar el suyo. Los envíos tratan de minimizar el coste. Converge lentamente y tiene riesgos de bucles y errores.

**Estado de enlace**: Cada router debe conocer a sus vecinos, medir el coste de la línea para cada uno, construir y enviar el paquete calculando la ruta más corta usando Djijkstra. Para solucionar la repetición de paquetes y las caídas de router los paquetes deben llevar un identificador y su edad. Finalmente cada router guarda una tabla con la información.

**Enrutamiento jerárquico**: Para otorgar autonomía administrativa y escalabilidad se organizan los routers en sistemas autónomos. Esto crea protocolos de encaminado interior y exterior.

**Broadcasting**: Manda un paquete a los demás nodos de la red
**Multicasting**: Un nodo puede mandar una copia de un paquete de un subconjunto de nodos.
# IP
![[Pasted image 20240504182757.png]]
+ Versión: IPv4 o IPv6
+ Protocolo: La siguiente cabecera que hay en el datagrama.

NAT resuelve la escacez de direcciones, aboga para que cada organización tenga una ip de cara al exterior, dentro de ella cada uno tiene su propia IP que no tiene porque ser exclusiva, cada vez que se envíen datos al exterior se hará con la IP de la organización.
Se trabaja con una tabla
![[Pasted image 20240504183649.png]]

IP debe implementar ICMP, este proporciona retroalimentación en el proceso de comunicación, pese a que este funcione en la capa de enlace, pertenece a la capa de red. Tiene una cabecera con los siguientes campos:
+ Tipo(8 bits)
+ Código(8 bits)
+ Checksum(16 bits)
+ Parámetros(32 bits)

# IPv4
Consta de 4 enteros de 8 bits
La máscara sirve para poder diferenciar la parte de red de la parte de host
+ Direcciones de red: Una dirección cuyo componente host está todo a 0, sirve para identificar a la red.
+ Dirección broadcast: El componente host está todo a "1", no se puede asignar y mandar algo ahí se traduce en mandarlo a todos los host de la red.

Al principio se diferenciaban 5 clases de direcciones.
![[Pasted image 20240504183031.png]]
La D y la E son reservadas.

Las subredes se codifican en la parte de red
![[Pasted image 20240504174519.png]]

+ VLSM: El host de cada subred se ajusta al tamaño de esta
+ CIDR: Los bloques de las organizaciones pueden ser de diferentes clases (A, B, C). Solo toma en cuenta la parte del host y de red.

El tamaño del bloque debe ser potencia de dos, el bloque debe comenzar por una dirección múltiplo de su tamaño y no debe solaparse.
# IPv6
Mayor cantidad de direcciones, si se especifica esta versión las opciones miradas son las del campo de opciones y las demás son ignoradas. Permite la asignación dinámica.

No permite fragmentación y requiere un ICMPv6. Permite asignar varias direcciones a una interfaz.
![[Pasted image 20240504191324.png]]
+ Clase de tráfico = tipo de servicio de IPv4
+ Etiqueta de flujo: marca paquetes para un uso especial


Existen 3 tipos de dirección:
+ Unidifusión: Interfaz individual
+ Monodifusión: Multiples interfaces
+ Multidifusión: Identifica un grupo de interfaces, si se le envía un paquete les llega a todas.

La direcciones se pueden asignar de manera estática, combina su dirección a nivel de enlace con el prefijo anunciado por los demás o puede ser manipulado a mano.
# Protocolos de enrutamiento
## Pasarela interior.

### RIP.
Trabaja con vectores de distancia, se basa en Bellman-Ford.
El coste de la ruta y el nº de saltos están limitados a 15.

PAQUETE RIP:
\[IP | UDP | MENSAJE RIP\]
udp funciona aquí en el puerto 520.

Existen 3 tipos:
+ v1: Enrutamiento con clases
+ v2: Enrutamiento sin clases
+ ng: Sirve para IPv6

Usa una tabla y la actualiza cada 30 segundos, si tras 180 no recibe nada el vecino es inalcanzable y se borra de la lista.

### OSPF.
Protocolo de estado de enlace, se basa en Dijkstra para hallar el camino mínimo entre routers. Más avanzado y permite al administrador establecer los costes.

PAQUETE OSPF
\[IP | MENSAJE OSPF\]
IP utiliza el protocolo 89


También utiliza el método de inundación, sin embargo, es más escalable.
## Pasarela exterior.
### BGP.
Permite obtener información sobre el alcance de las subredes, la función principal es conectar diferentes subredes con diferentes protocolos de enrutamiento para que puedan comunicarse sin problema.

PAQUETE BGP
\[IP | TCP | MENSAJE TCP\]

El grafo utilizado para calcular caminos tiene por nodos los sistemas autónomos conectados.

Para poder funcionar correctamente debe tener:
* Operación de adquisición de vecinos
* Actualización de vecinos alcanzables
* Detección de redes alcanzables.

Este protocolo no permite la actualización de los caminos mínimos en función del estado de la red, pues hay que establecer políticas de enrutamiento, pues no todo el mundo permitirá que se atraviese su red de forma gratuita (Ingeniería de trafico).
# Control de congestión
La congestión se da cuando se el número de paquetes se aproxima a la capacidad de gestión de la red, produciendo colas y provocando la pérdida de paquetes.

En toda red a medida que se aumenta la carga se aumenta el rendimiento hasta cierto punto en que ya empieza a congestionarse![[Pasted image 20240404115115.png]]

A la hora de hacer los rechazos existen varios criterios.
+ Equidad: trata de descartarse el mismo número de paquetes de todas las conexiones.
+ Calidad de servicios: Los flujos se tratan de cierta manera para optimizar el rendimiento de las aplicaciones.
+ Reservas: Ser pre-establecen ciertos parámetros de calidad de servicios antes de conectarse, si la red no puede asegurar estos parámetros no permite la conexión
### Métodos de control.
##### Señalización implícita.
Se detecta al ver que hay una pérdida de paquetes en las comunicaciones, o cuando aumenta el retardo considerablemente.

Es responsabilidad de los sistemas terminales(nodos emisores) gestionar la congestión, se basa en TCP.
##### Señalización explicita.
Se envían paquetes para notificar el estado de la red
Utiliza la técnica de choque.

Se puede hacer hacia delante o hacia detrás
![[Pasted image 20240408111705.png]]
La señalización de la congestión puede ser:
+ Binaria (activa un bit en un paquete)
+ Basada en crédito (Hasta que no vuelva a recibir un crédito nuevo, siendo este un límite en el envío de paquetes a enviar)
+ Basada en velocidad (Da un límite sobre la velocidad)
##### Paquetes de choque
Es un paquete enviado al nodo transmisor por uno congestionado para que reduzca el flujo.

## Criterios
Imparcialidad: Trata de compartir la congestión entre los host del nodo.

Calidad de servicio: Da un trato específico a las aplicaciones para mejorar el rendimiento.

Reservas: Se reservan recursos para las peticiones, si no hay suficientes para cumplir la petición de deniega la reserva.
