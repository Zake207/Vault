#### Recursos
[[pr_intro.pdf|PDF]]

## Máquinas
4 arriba switches
3 abajo routers

En cada puerto del switch se conectan dispositivos a una misma LAN
En cada puerto del router son subredes, al conectar algo se indica que por este puerto se accede a dicha red

2.0
3.0

La puerta de enlace es necesaria para salir de la red local


## Comandos
**Conectarse por cable**
> screen /dev/ttyUSB0 115200 (*user* "admin", *pass* "" o "class")
+ En caso de error de conexión cerrar terminal y desconectar y conectar por el ordenador

**Valores de fábrica**
> system reset-configuration no-default=yes keep-users=no
+ No usa los parámetros por defecto
+ No mantiene credenciales de configuración de usuarios

**Acceso por telnet**
> ip address add address=192.168.88.x/24 interface=ether10
+ Se le asigna dicha dirección a la interfaz 10

**Ver rutas e interfaces**
> ip route print
+ Imprime la tabla de enrutamiento

> ip interface print
+ Imprime la tabla de interfaces

___
**Cambiar el nombre del router**
> system identity set name=R1

**Añadir rutas estáticas**
> ip route add dst-address=10.2.0.0/24 gateway=10.0.0.1

___
**Conectarme al switch**
> screen \/dev\/ttyUSB0 38400

**Modo privilegiado**
> enable

**Modo Configuración**
>configure

**Reseteo del switch**
> reset
+ Debe realizarse en modo privilegiado
**Mostrar configuración**
> show running-config
+ Debe realizarse en modo privilegiado
**Guardar configuración**
> copy runnnig-config startup-config
+ Debe realizarse en modo privilegiado
**Fijar el nombre del dispositivo**
> hostname S1
+ Debe realizarse en modo configuración