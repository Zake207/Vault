[[BGP.pdf|PDF]]

BGP es un protocolo de pasarela exterior encargándose de enrutamiento entre sistema autónomos.

BGP nace para no tener aplicar el protocolo a lo largo de toda la red, de esta manera se pueden organizar las redes en sistemas con protocolos diferentes (RIP, OSPF, ...) y conectarlos con BGP.
Las redes se organizan en un grafo donde cada nodo se identifica, actualmente los id son 32 bits.

Existen varios tipos de sistemas autónomos:

+ **Stub** Un sistema autónomo que esta conectado solamente a otro sistema autónomo
+ **Tránsito** Interconecta otros sistemas autónomos a través de este
+ **Multihomed** Son los que tienen conexiones con otros sistemas autónomos pero no sirven de tránsito
+ **Internet Exchange Point** Infraestructura física a través de la cual los proveedores de servicio intercambian tráfico entre sistemas


BGP usa TCP como protocolo de transporte en el puerto 179, cuando 2 routers se conectan entre ellos se llaman peers, los cuales intercambian diferentes tipos de mensajes.
+ **OPEN** Usado para establecer conexion BGP, se suelen negociar ciertos parámetros.
+ **UPDATE** Contiene anuncios de nuevos prefijos cuando se determina una nueva ruta óptima
+ **KEEPALIVE** Mantiene viva la conexión con su envío periódico
+ **NOTIFICATION** Se envía al cerrar una conexión BGP

Las sesiones BGP pueden ser
- iBGP cuando es dentro del mismo sistema
- eBGP cuando es fuera del mismo sistema

Los mensajes de BGP tienen diferentes atributos:
- **ORIGIN**: Indica cómo se anunció inicialmente el prefijo IP (IGP = 0, EGP = 1, INCOMPLETE = 2).
    
- **AS-PATH**: Guarda la secuencia de números de AS por los que ha pasado el anuncio; se añade un número de AS al salir de un sistema autónomo.
    
- **NEXT-HOP**: Especifica la IP del siguiente salto hacia el destino; se actualiza al anunciar rutas fuera del AS o redirigir tráfico.
    
- **LOCAL-PREF**: Define la preferencia interna por una ruta en el AS; un valor mayor indica mayor preferencia (por defecto 100).