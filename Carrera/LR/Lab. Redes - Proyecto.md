### Crear docker DHCP
+ Crear directorio dhcp
+ Crear los ficheros de configuración de dhcp (dhcpd.conf, isc-dhcp-server)
+ Pasar las lineas del guión al fichero docker_file
+ docker  build . -t dhcp-server2
+ Para localizarlo se hace docker image ls

Se pueden establecer redes entre contenedores
+ Tipo bridge (por defecto)
+ Tipo none (no se le permite interacción de red al contenedor)
+ Tipo host 
+ Tipo Overlay (Redes superpuestas, permite comunicación entre contenedores en diferentes dispositivos)
+ Tipo ipvlan (permite mapear interfaces de red del contendor sobre la capa física)
+ Tipo macvlan

docker compose gestiona la ejecución simultánea de imágenes
+ Crear un fichero docker-compose.yml y copiar el contenido
+ Crear arriba una etiqueta services e indentar todo
+ Crear la red virtual
+ docker compose build
+ docker compose up

docker exec -it dhcp-server bash (inicia un proceso bash en el docker)

---

Copiar directorio DHCP llamarlo Asterisk y copiar dockerfile de la foto.

FROM debian:11-slim
..
..
apt-get install -y asterisk && \
..
CMD\["asterisk", "-c"\]


Añadir al docker-compose.yml
Copia del DHCP server: (cambiar nombre)
+ build asterisk
+ name asterisk-server
+ volumes - ./asterisk/data:/data
+ ipv4 192.168.0.4