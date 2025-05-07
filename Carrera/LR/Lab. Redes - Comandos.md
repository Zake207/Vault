[[Presentación práctica 1.pdf]]
[[Presentación práctica 2.pdf]]
[[Presentación práctica 3.pdf]]
[[Presentación práctica 4.pdf]]
[[Presentación práctica 5.pdf]]
[[Presentación práctica 6.pdf]]
[[Presentación práctica 7.pdf]]
[[Presentación práctica 8.pdf]]

---

## Primera práctica
**Acceso por telnet**
screen /dev/ttyUSB0 115200 (router)
screen /dev/ttyUSB0 38400 (switch)

**Formatear router**
system reset-configuration no-defaults=yes keep-users=no (router)
reset (switch)

**Cambiar identidad**
system identity set name=R1 (router)
hostname S1 (switch)

**Asignar direcciones ip**
ip address add address=192.168.88.x/24 interface=ether1

**Rutas Estáticas**
ip route add dst-address=10.2.0.0/24 gateway=10.0.0.1
ip route add gateway=10.0.0.1 (default route)

## Segunda práctica
**Crear VLAN**
vlan 99

**Puertos de acceso**
S1(config)# interface range gi 1/0/6-7 (seleccionar) 
S1(config-if)# switchport mode access (modo) 
S1(config-if)# switchport access vlan 10 
S1(config-if)# no shutdown 
S1(config-if)# end

S1(config-if)# switchport general allowed vlan 10 untagged 
S1(config-if)# switchport pvid 10

**Puerto troncal**
S1(config-if)# switchport mode trunk 
S1(config-if)# switchport trunk allowed vlan 10,20,99 
S1(config-if)# switchport pvid 99 (VLAN nativa)

S1(config-if)# switchport general allowed vlan 10,20 tagged S1(config-if)# switchport general allowed vlan 99 untagged 
S1(config-if)# switchport pvid 99 (VLAN nativa) 
S1(config-if)# no switchport general allowed vlan 1 (quitar)

**VLAN de gestión**
S2(config)# ip management-vlan 99
*Siempre hay que poner una dirección IP para el acceso* S1(config)# interface vlan 99 
S1(config-if)# ip address 10.10.10.3 255.255.255.0

**Crear interfaz virtual**
R1> interface vlan add interface=ether1 name=ether1.10 vlan-id=10

**Asignar direcciones** 
R1> ip address add address=192.168.0.1/24 interface=ether1.10

## Tercera práctica

**Activar STP en el switch** 
S(config)# spanning-tree 
S(config)# spanning-tree mode stp 

**Activar STP en puertos troncales** 
S(config)# interface range gi 1/0/1-4 
S(config-if-range)# spanning-tree 

**Ver estado STP** 
S(config)# show spanning-tree active 
S(config)# show spanning-tree interface 

**Forzar raíz en STP** 
S(config)# spanning-tree priority 0

**Activar RSTP** 
S(config)#spanning-tree mode rstp 
S(config)#spanning-tree

**Activar MSTP** 
S(config)# spanning-tree mode mstp 
S(config)#spanning-tree mst configuration 
S(config-mst)#name 1 (nombre de región) 
S(config-mst)#revision 100 (nombre de revisión) 
S(config-mst)#instance 1 vlan 99 
S(config-mst)#instance 2 vlan 10,20 

**Forzar raíz en MSTP** 
S(config)#spanning-tree mst instance 2 priority 0 

**Ver estado de MSTP** 
S(config)#show spanning-tree mst instance 2

## Cuarta práctica
**Crear interfaces de loopback** 
R> interface bridge add name=lo0 

**Activar OSPF (la instancia default y el área 0 ya existen)** 
R> routing ospf instance add name=default 
R> routing ospf area add name=area1 area-id=0.0.0.1 
R> routing ospf network add network=10.0.g.0/24 area=backbone 

**Ver estado OSPF** 
R> routing ospf route print (ver rutas) 
R> routing ospf neighbor print (ver vecinos ospf) 

**Sumarización de rutas** 
R> routing ospf area range add area=area1 range=10.1.0.0/16

## Quinta práctica
Activar RIP en FRR 
R(config)# router rip 
R(config-router)# network 192.168.1.0/26 
R(config-router)# network 192.168.1.128/30 

Redistribuir rutas aprendidas por OSPF en zona RIP 
R(config)# router rip 
R(config-router)# redistribute ospf metric 1 

Ver información RIP 
R# show ip rip R# show ip rip status

Activar OSPF 
R(config)# router ospf 
R(config-router)# network 10.0.0.4/30 area 0 
R(config-router)# network 10.0.0.0/30 area 0 

Convertir área en stub (en todos) y nssa stub (sólo ABR) R1(config)# router ospf R1(config-router)# area 1 stub 
… 
R2(config)# router ospf 
R2(config-router)# area 2 nssa no-summary 

Sumarizar redes (sólo ABR) 
R(config-router)# area 2 range 10.2.0.0/23 
R(config-router)# area 1 range 10.1.0.0/23

Activar OSPF (la instancia default y el área 0 ya existen) 
R> routing ospf instance add name=default 
R> routing ospf area add name=area1 area-id=0.0.0.1 
R> routing ospf network add network=10.0.g.0/24 area=backbone 

Ver estado OSPF 
R> routing ospf route print (ver rutas) 
R> routing ospf neighbor print (ver vecinos ospf)

Activar VRRP, creando interfaz virtual (asignar IP) 
interface vrrp add interface=ether1 vrid=51 

Ver estado VRRP 
interface vrrp print detail 

Incrementar prioridad (mayor valor es más prioritario) de un router físico en VRRP para convertirlo en maestro 
interface vrrp set vrrp1 priority=150
## Sexta práctica
Activar sesiones BGP entre peers (en los 2) 
router bgp ID
neighbor remote-as 

Poner NEXT-HOP a IP de un router 
neighbor next-hop-self 

Anunciar un prefijo de red 
router bgp ID
network 
aggregate-address 20.0.1.0/24 summary-only 

Comprobar vecinos y prefijos de red conocidos show bgp neighbors show bgp ipv4 unicast Forzar sync de políticas (soft) # clear ip bgp * soft

Distribuir salida redundante por RIP router rip default-information originate … ip route 0.0.0.0/0 20.0.0.1 Túneles GRE ip tunnel add gre1 mode gre remote 20.0.1.6 local 20.0.1.1 ttl 255 ip link set gre1 up ip addr add 10.10.10.1/24 dev gre1 Reajustar vecindad con túneles router bgp 100 no neigbor 20.0.1.6 neighbor 10.10.10.2 remote-as 100 neighbor 10.10.10.2 next-hop-self

Ingeniería de tráfico (políticas de routing) (config)# route-map AS300-entrada permit 10 (config-route-map)# set local-preference 200 (config)# router bgp 100 (config-router)# neighbor 20.0.0.1 route-map AS300-entrada in (config)# ip as-path access-list 1 permit ^$ (config)# route-map AS300-salida permit 10 (config-route-map)# match as-path 1 (config)# router bgp 100 (config-router)# neighbor 20.0.0.1 route-map AS300-salida out
## Séptima práctica
EDITAR FICHEROS
## Octava práctica

