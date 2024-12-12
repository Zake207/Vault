# Sesión 1.
# Sesión 2.
Direccionamiento: Estático, Dinámico. (Asignación de direcciones)
Enrutamiento: Estático y Dinámico. (Como se buscan los caminos)

`ip route` permite ver las tablas de enrutamiento de un router

En algunos casos la dirección debe ser estática, como los router y los servidores.

En el enrutamiento dinámico los routers comparten información para calcular las rutas.

###### Configurar enrutamiento
-> vtysh
-> configure terminal
-> router rip
-> network <ip de la red a hacer visible para los demás routers>

Hay que hacer network para cada red conectada a cada router.
Este proceso se repite para todos los router.
IMPORTANTE: No se debe hacer network con la red conectada a internet.

La salida a internet se resuelve con una ruta estática en el router de salida de la siguiente manera:

-> ip route 0.0.0.0/0 (ip de la interfaz de red que da al exterior).

Tras esto hay que conseguir que los router conectados al router de salida deben saber como llegar a internet. Estos routers deben encontrar el camino mínimo para llegar a este. Hay que declarar al router de salida como fuente de información por defecto.

-> configure terminal
-> router rip
-> default-information originate

Tras esto con un traceroute se deberia ver la ruta.
El enrutamiento dinámico propaga la información entre los router para poder funcionar, esto provoca que información no deseada llegue a los ordenadores. Para solucionar esto hay que declarar pasivas las interfaces que conectan con ordenadores
-> router rip
-> passive-interface eth2

En los casos en los que se hagan pasivas dos interfaces de router que se comunican entre ellas hay que definirlas como vecinas:
-> router rip
-> neighbor < ip del vecino >

Hay que repetir esto en ambas interfaces para que logren comunicarse.



