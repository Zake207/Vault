Para que sirven las cookies
http/https vs ftp

# Examen 25
6 tipo test
4 de desarrollo

Enrutamiento estático: configurar un router o pc
Enrutamiento Dinámico: configurar con RIP

Que comando se usa para:

Pregunta de "Averigua..." del guion.
# Apuntes
## PC
Para asignar la dirección IP a un PC de manera estática:
+ ifconfig eth0 A.B.C.D/E
+ ip addr add A.B.C.D/E dev eth0 (sustituir add por del para borrar)
Para mostrar la tabla de enrutamiento se ejecuta route -n
Para añadir entradas a la tabla se ejecuta lo siguiente: 
+ route add default gw A.B.C.D
El problema es que al reiniciar la máquina esto se habrá borrado.

También se puede editar el fichero /etc/network/interface y dar los datos para la ip y el gateway, una vez editado se debe ejecutar ifup eth0 para activar la interfaz, en este caso eth0
+ vi /etc/network/interface
+ ifup eth0

## Router
Para poder editar el enrutamiento se debe ejecutar vtysh. Tras esto se debe ejecutar `configure terminal` para poder editar, siempre que se hagan cambios, fuera del modo edición se de debe ejecutar `write`

Asignar dirección ip: 
+ interface eth0
+ ip address A.B.C.D/E
+ no shutdown
+ link-detect
+ exit
+ write

Para configurar la tabla de enrutamiento:
+ ip route (IP+MASC DESTINO) (IP GATEWAY)
Para eliminar esta entrada se debe ejecutar igual pero precedido de "no".

Para configurar un router para usar RIP primero hay que activar RIP:
+ configure terminal
+ router rip
+ version 2
Luego hay que declarar las redes en las que va a operar el router:
+ network A.B.C.D/E

Se asignan las entradas a la tabla de enrutamiento de la misma manera que la anterior.

Luegos hay que declarar las interfaces que esten en contacto con PC como pasivas:
+ configure terminal
+ router rip
+ passive-interface eth0

Si alguna interfaz pasiva se conecta con un router hay que decirle a quien debe mandar los mensajes RIP
+ router rip
+ neighbor (IP DE LA INTERFAZ VECINA)

Activar el mecanismo de autenticación de paquetes RIP
+ key chain kal
+ key 1
+ key-string clavepararip
Activarla en cada interfaz:
+ interface eth0
+ ip rip authentication mode text
+ ip rip authentication key-chain kal

Para que la red sepa como salir al exterior (internet):
+ default-information originate

## ¿Cómo añadir una ruta por defecto en la interfaz de comandos Cisco en un router?

seleccionar el router que tendrá acceso a la red en cuestión y ejecutamos los siguientes comandos:
+ vtysh
+ configure terminal
+ ip route 0.0.0.0 (próximo salto)
Si además se desea que esta ruta sea la que esté conectada a internet por defecto se debe añadir:
+ router rip
+ default-information originate