[[VLANs.pdf|PDF]]
## VLAN
Permite crear diferentes redes de forma lógica dentro de una misma red.

![[Pasted image 20250429152210.png]]

Para ello se abstrae un switch central para especificar cuales de sus puertos pertenecen a según qué vlan.

Los *enlaces troncales* permiten distinguir dos tipos de tramas:
+ Etiquetadas: VID usa IEEE802.1Q.
+ Vlan nativa: Las tramas se envían de forma nativa (sin VID), sólo existe una por enlace troncal.

Se usa un *PVID* como identificador de VLAN asignado por defecto a un puerto.

Existen diferentes tipos de puertos:
+ **Puerto de Acceso** Se conectan a los host finales y trabajan con tramas clásicas de Ethernet.
+ **Puerto Troncal** Conectan switches entre sí y con los routers
+ **Puerto General** Mezcla de los anteriores

## Spanning Tree
Para aumentar la disponibilidad se crean enlaces redundantes.
Sin embargo estos pueden provocar tormentas de broadcast debido a los bucles creados.

El protocolo Spanning Tree conecta todos los dispositivos sin ciclos, bloqueando los caminos redundantes mientras el principal este operativo.
Se usan diferentes versiones:
+ **STP** Versión original que usa un algoritmo de árbol de exapnsión.
+ **RSTP** Mejora que permite una mejor convergencia, minimiza el tiempo de inactividad.
+ **MSTP** Extensión de RSTP permite crear multiples instancias de árboles de expansión para diferentes Vlans

La raíz viene definida por el BID (Bridge indentifier), aquel que tenga el menor será la raíz.
