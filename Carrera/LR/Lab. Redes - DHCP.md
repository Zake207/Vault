[[Carrera/LR/Transparencias-20250428/DHCP.pdf|PDF]]

## Teoría
Protocolo que permite asignar dinámicamente direcciones IP a los dispositivos que se conectan a una red.

Funciona de la siguiente manera
1. **Discover** El dispositivo nuevo lanza un mensaje al broadcast para encontrar un servidor DHCP
2. **Offer** El servidor responde con una oferta de configuración disponible
3. **Request** Responde aceptando las ofertas y pidiendo formalmente la dirección
4. **ACK** El servidor confirma la asignación para que el cliente use esta configuración

El *DHCP relay* es un protocolo que permite que el cliente pueda acceder al servidor DHCP incluso si este se encuentra en otra red. Los routers configurados con el relay se encargan de hacer llegar el discover al servidor
## Comandos
### DHCP
**Crear pool de direcciones:**
/ip pool add name=pool1 ranges=172.16.0.10-172.16.0.255

**Indicar la configuración de la red:**
/ip dhcp-server network add address=172.16.0.0/16 gateway=172.16.0.1

**Asociar el pool a una interfaz:**
/ip dhcp-server add interface=ether2 address-pool=pool1 name=dhcp1

**Activar el servicio:**
ip dhcp-server enable dhcp1

### DHCP Relay
**Agente de reenvío**
ip dhcp-relay add name=relay16 dhcp-server=10.0.0.2 interface=ether1 local-address=172.17.0.1 disabled=no

**Servidor**
/ip dhcp-server set dhcp2 relay=172.17.0.1




