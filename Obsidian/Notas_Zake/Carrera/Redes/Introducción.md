# Introducción
Internet es una red que conecta millones de dispositivos en el mundo. Infraestructura que provee servicios a aplicaciones distribuidas, estas se ejecutan sobre ISP y requieren una API que especifica cómo un programa debe pedir a otro programa que se ejecuta en otro sistema terminal.

+ Host: Dispositivos conectados a la red ejecutando aplicaciones distribuidas.
+ Enlaces de comunicaciones: Cables, satélites, fibra.
+ Dispositivos de reenvío de paquetes: Routers y switches.

Los componentes esenciales:
+ ISP: Proporcionan acceso a internet.
+ Protocolos: Conjunto de reglas que controlan el envío y recepción
+ Estándares: Desarrollados por la IEFT.

Las aplicaciones distribuidas pueden ser del tipo:
+ Cliente-Servidor: Una serie de clientes solicitan servicios al servidor.
+ Peer-to-peer: Los sistemas hacen funciones de cliente y de servidor.
**Clasificación de redes**
+ LAN
+ WLAN
+ MAN
+ WAN
+ Internet
# Protocolos
Definen el formato y orden de los mensaje intercambiados, además de las acciones tomadas en la transmisión/recepción del mensaje y otro suceso.

Se organizan en capas que ofrecen diferentes servicios a la capa superior, estos forman una pila de protocolo.
![[Pasted image 20240503224950.png]]
## OSI 
### Capa física
Lleva a cabo la transmisión de bits binarios puros a través del canal de comunicaciones
### Capa enlace
Convierte un medio de transmisión puro en una línea de transmisión libre de errores

Controla el flujo de datos y el acceso al medio de transmisión.
### Capa red
Controla el enrutamiento desde el origen al destino y el direccionamiento de los host de la red.
### Capa transporte
Se encarga de dividir los datos de capas superiores en unidades más pequeñas y pasarlas a la capa de red.
Ofrece servicios orientados y no orientados a conexión.
### Capa Sesión
Permite conocer el estado de la transmisión en todo momento. No es necesario pero algunas aplicaciones las ofrecen. Permite controlar el diálogo, administrar los token y sincronizar.
### Capa presentación
Permite interpretar los datos en cuestiones de semántica y sintáxis, para lograr esto se usan codificaciones.
### Capa aplicación
Comprende las aplicaciones de red y sus protocolos, estas están distribuidas entre varios sistemas terminales
## TCP/IP
### Capa física
Mueve bits de un nodo al siguiente. Depende de la superior y del medio físico.
### Capa enlace
Traslada un nodo de un paquete de un nodo al siguiente en red. Este paquete puede ser manipulado durante el traspaso.
### Capa red
Traslada los paquetes de red de un host a otro. Se suele usar IP, que funciona al estilo de un servicio postal.
### Capa transporte
Transporta los mensajes de la aplicación entre los diferentes puntos terminales.
+ TCP: Conexión fiable, control de errores y de flujo.
+ UDP: Más rápido pero no proporciona control de errores ni conexión fiable.
### Capa aplicación
Aglutina las funciones de la capa de sesión y presentación del modelo OSI.

### Procedimiento
1. En la capa de aplicación se crea el mensaje que desea enviar.
2. La capa de transporte añade una cabecera que será usada por la capa de transporte del receptor. Ahora se habla de segmento.
3. La capa de red añade una cabecera con información de direccionamiento a lo que ahora se denomina datagrama.
4. La capa de enlace añade su propia información a lo que ahora trata como trama.
5. La capa física transmite los bits.
6. Los dispositivos intermedios van deshaciendo el encapsulamiento en orden inverso hasta que el payload/mensaje llega al destino.