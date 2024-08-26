# Enlazado
Se encarga de mover tramas de un nodo al siguiente.
Las tramas se encapsulan en un datagrama de la capa de red.
Lleva a cabo funciones como el entramado, control de flujo, corrección de errores...

+ La capa de enlace es implementada en el adaptador de red.

Para llevar a cabo la detección de errores se ejecuta la comprobación de paridad. En la sucesión de números binarios que es el paquete se le añade un bit de paridad.
+ Paridad par: el bit se activa si el número de "1" en la secuencia es impar. 
+ Paridad impar: el bit se activa si en número de "1" en la secuencia es par.

Las comprobaciones de paridad multi-dimensionales dividen la secuencia en filas y columnas para comprobar por filas y columnas la paridad y así encontrar antes el error.

Las sumas de comprobación tratan los bits como unas secuencias de enteros de k bits, que suma, el resultado es usado para detectar errores.

En la redundancia cíclica el emisor y receptor están de acuerdo en un patrón de r+1 bits (G) el más significativo de este debe ser "1". Para una secuencia de datos, el emisor añade r bits adicionales para que los bits resultantes sean divisibles por G.
==REVISAR EJEMPLO DE CLASE==

+ Enlace punto a punto.
+ Enlace de difusión.

Los protocolos de control de acceso al medio controlan la transmisión en un medio. Cuando dos estaciones transmiten se produce una colisión. Estos protocolos controlan las colisiones.

### Particionamiento de canal
Son métodos que particionan la vía para que las estaciones transmitan lo hagan de manera ordenada.
### Protocolos de acceso aleatorio.
Cada nodo transmite a velocidad máxima, cuando ocurre una colisión cada nodo espera una cantidad de tiempo aleatoria.

(ALOHA con particiones)
El tiempo se divide en particiones, todos los nodos operan al principio de una partición pues están sincronizados. Cada nodo espera al principio de una partición para enviar
(ALOHA puro)
Transmite una trama y si se produce una colisión se transmite de forma inmediata con una probabilidad p. Si no se envía se espera el tiempo equivalente a si lo hubiera hecho para volver a intentarlo.
### Protocolos de acceso por turnos.
Uno de los nodos ejerce de maestro, el cual sondea a cada uno de los demás nodos a la manera de turno aleatorio.

En el paso de testigo se va turnando una trama especial de tamaño pequeño. Al recibirlo se mantiene, si tiene datos que transmitir lo transmite y luego lo pasa al siguiente.
# Ethernet
Tecnología dominante en las redes de área local actualmente. Puede tener una topología en bus o en estrella. 
Este protocolo encapsula los datagramas del nivel de red en el payload de la trama de Ethernet.
Si un adaptador recibe una trama con una dirección de destino coincidente con la suya lo desempaqueta, si no lo descarta.
También indica el protocolo de la capa superior.
El payload mínimo son 46 bytes y el máximo son 1500.

## CSMA/CD
1. El adaptador de red obtiene un datagrama que prepara y coloca en el buffer.
2. Si el canal está inactivo comienza a transmitir, si no espera a que no haya señal para transmitir.
3. Mientras transmite el adaptador monitoriza otras señales 
4. Si detecta una señal de otro adaptador deja de transmitir y pasa a transmitir una señal de interferecnia.
5. Cuando se aborta la transmisión de la trama se entra en fase de espera exponencial.
Se limita la distancia máxima entre nodos y se establece un tamaño mínimo.
## Eficiencia
Depende de la velocidad que tarda la señal en propagarse y el tiempo necesario para transmitir una trama (d_pro y d_trans).
![[Pasted image 20240503173432.png]]
## Switches
Las LAN modernas usan topología de estrella, en la que los nodos están conectados a un conmutador central que recibe tramas a nivel de enlace y las reenvia.
Los switches son invisibles para los nodos.
+ Determinan si una trama se descarta o reenvia
+ Determinan las interfaces a las que debe dirigirse la trama.
Para poder filtrar usa una tabla de conmutación con:
+ La dirección MAC destino
+ El gateway
+ El instante en el que se incluyó la entrada.
Revisa la tabla, inundando las salidas si no tiene entrada. Si tiene entrada pero el gateway es el mismo que de donde vino descarta la trama. Si no se cumple ningún caso se reenvía la trama.

La tabla comienza vacía, se va actualizando añadiendo entradas que no tenga y borrando las que llevan un tiempo sin usarse.
## Dispositivos
**Router**
Reenvío y enrutamiento a nivel de red.
**Switch**
Filtra y reenvía a nivel de enlace.
**Hub**
Repetidor que reproduce la señal por todas las salidas menos por la que se envió.
## VLAN
Permite definir múltiples redes LAN virtuales sobre una misma infraestructura. Etiqueta los puertos de manera que solo interactúan aquellos de la misma VLAN. En estas existen conmutadores lo cuales se conectan a uno que pertenece a todas las VLAN. Este método es el trunking.
# Wifi
IEEE 802.11
Posee un conjunto de servicios básicos. Existe una estación básica que funciona a modo de acceso. Cada una tiene su MAC.
Si tiene AP es una red LAN inalámbrica de infraestructura y si no será una red ad-hoc.

A cada conjunto de servicio se le asigna un SSID de manera manual. Al poder estar asociados a diferentes redes nodos deben asociarce mediante mecanismos:
+ Exploración pasiva
+ Exploración activa

Usa el CSMA/CA como protocolo de acceso al medio.
Debido al problema de la estación oculta no se pueden detectar colisiones, por ello se aboga por evitarlas:

Cuando una estación recibe una trama espera un tiempo SIFS y envía una confirmación.
Si el emisor detecta inactividad en el canal esperá un tiempo DIFS y transmite. Si está activo el contador no iniciará hasta que lo esté. Si recibe el ACK continua enviando, si no entra en fase de espera otra vez.