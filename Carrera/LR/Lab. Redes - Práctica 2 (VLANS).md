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
**Crear VLAN**
>vlan \[id\]
+ Debe hacerse en modo configuración