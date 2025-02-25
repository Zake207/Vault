#### Recursos
[[pr_vlans.pdf|PDF]]

## VLAN 
+ Una forma de agrupar puertos en grupos
+ Todos los puertos están por defecto en la misma VLAN
+ Las tramas solo deben mandarse y recibirse entre la misma VLAN
+ Para posibilitar esto se debe hacer uso de la capa 3.
+ Las tramas se etiquetan para diferenciar el tráfico entre VLANs

**Puerto troncal** Usado para conectar switches, se etiquetan solo si no son de la VLAN nativas. Aglutina las tramas de todas las VLANes

**Puerto de acceso** Conecta directamente con dispositivos

La VLAN de administración suele usar el identificador 99

Para acceder por telnet a la terminal del switch se le asigna a este una ip virtual.

Los switches rellenan su tabla de conmutación de la siguiente forma:
+ Aprendizaje
+ Inundación
+ Reenvío
+ Filtrado
+ Aging

Tres versiones de switches

## PVID
Identificador de la VLAN que lo tiene
+ En un puerto de acceso se le da este código como etiqueta automática
+ En un puerto troncal, se le asocia por defecto la VLAN con este configuración
## Comandos
**Ver interfaces**
> show interface status

**Configurar interfaz**
> interface gi 1/0/1
> interface range gi 1/0/1
+ Debe estar en modo configuración.

**Ver VLANs**
> show vlan

**Crear VLAN**
>vlan \[id\]
+ Debe hacerse en modo configuración
+ name \[nombre\] cambia el nombre de la interfaz

**Ver info del sistema**
> show system-info
+ Existen 3 versiones

**Añadir puertos de acceso**
> interface gi 1/0/1
> switchport mode access
> switchport access vlan 10
> no shutdown
> end

**Añadir puertos troncales**
> interface gi 1/0/1
> switchport mode trunk
> switchport trunk allowed vlan 10,20,99
> no shutdown
> end

**Añadir puertos generales**
> switchport mode general

**Añadir puertos en v2, v3**
> switchport general allowed vlan 20, 99 tagged
> switchport general allowed vlan 10 untagged

**Ver puertos**
> show interface switchport gi 1/0/1

**VLAN de gestión**
> ip management-vlan 99
> ip address 10.10.10.3 255.255.255.0

**Añadir PVID**
> switchport pvid 10
+ Se debe estar en modo personalización de la interfaz

**Enrutamiento de VLANs**
> interface vlan add interface=ether1 name=ether1.10 vlan-id=10

> ip address add address=192.168.0.1/24 interface=ether1.10