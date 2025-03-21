## Comandos
### Crear interfaces con loopback
> interface bridge add name=lo0

### Activar OSPF
> routing ospf instance add name=default
> routing ospf area add name=area1 area-id=0.0.0.1
> routing ospf network 