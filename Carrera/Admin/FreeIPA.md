Gestiona los usuarios y máquinas de una entidad, también establece políticas para operar con los servicios e información.

Para que funcione debe utilizar diferentes servicios como el DNS, Kerberos o PKI.
# DNS
Un sistema de nombres de la organización distribuido y jerárquico.
Un servidor DNS se encarga de los nombre de su zona.
+ Dominio: Parte del espacio de nombres
+ Zona: Estructura en la que se almacena la información de gestión

Las direcciones se pueden ser resueltas de manera directa o indirecta:

Los servidores DNS almacenan registros con información sobre el dominio y otros recursos, son los responsables de la resolución del dominio.
+ Servidor Primario: Contiene la copia original del fichero de zona, es donde se realizan las modificaciones, actualiza a los servidores secundarios mediante transferencias de zona.

+ Servidor Secundario: Contiene una copia del fichero de zona, es actualizado por el Primario y aporta balanceo de carga.

+ Servidor Caché: Únicamente almacenan resoluciones anteriores.

Los Forwarders son atajos usados para reducir el tiempo de resolución de un nombre, se suelen usar en nombres altamente recurrentes.

El DNS dinámico permite que los clientes se registren en el DNS y que los servidores puedan registrar los servicios que proporcionan todo de manera automática.

El DNSSEC está basado en una cadena de confianza, cada nodo puede autenticar al nodo jerárquicamente inferior.
Cada dominio envía a su superior su clave pública firmada por la clave privada.

## Registros.
+ SOA: Proporciona información sobre el dominio en cuestión, como quien tiene el fichero de zona.
+ A: Dado el nombre de un servidor se resuelve su dirección ip.
+ AAAA: Igual que el registro A pero con direcciones ipv6.
+ MX: Apunta al servidor de correo electrónico.
+ PTR: Resuelve el nombre de un servidor dada su ip.
+ NS: Determina cuales son los nombres de dominio.
+ SRV: Usado para la búsqueda de servidores en base a los servicios que ofrecen.
# Kerberos
Es un servicio que permite el inicio de sesión único, usa tickets que prueban la identidad de un usuario en un servidor. Los usuarios solo necesitan iniciar. Este servicio usa un servidor de autenticación centralizado en el que todos confían (centro de distribución de claves).

Cabe destacar que el servicio dns no puede ser kerberizado pues si se desea obtener un TGT se debe hacer una busqueda del servidor proveedor de tickets, esto lo hace mediante los registros srv de dns. Si estuvieran kerberizados no se podría realizar esta búsqueda.

El procedimiento es:
1. Encontrar al servidor que provee el servicio de kerberos. 
2. Envío de la solicitud pre-autenticación
3. Al comprobar la información se envía el TGT

Los servicios se pueden kerberizar para que solo usuarios con tickets accedan a estos.
Cuando un usuario con un TGT desea acceder a un servicio kerberizado, se hace una petición al servidor de kerberos, este provee un ticket TGS que permite a ese usuario en concreto el acceso a ese servicio en concreto, mediante el ticket se pueden autenticar tanto el usuario como la máquina.

# LDAP
Base de datos de estructura jerárquica, permite centralizar toda la información de una organización, este organiza dicha información y la protege.

La información se distribuye por entradas, cada una tiene un atributo que un tipo y uno o más valores.

Un servidor LDAP sigue un esquema (Schema) que contiene clases de objeto y atributos. Las clases especifican el tipo de objeto que esta almacenado en la entrada, estos tienen atributos que pueden ser requeridos o permitidos.
Los objetos pueden ser de clases que heredan de otras clases. Todas las clases heredan de top.
![[Pasted image 20240424184135.png]]
![[Pasted image 20240424184415.png]]
El LDAP se compone de un modelo funcional que consta de de 3 categorías de operaciones: Autenticación, Interrogación (query) y Actualización.

Una query se lleva a cabo mediante los siguientes parámetros: Base, Ámbito, Filtro.

La actualización modifican el contenido del directorio

La autenticación tiene 3 niveles: anónimo, sin autenticación y autenticado.

El concepto de replicación permite tener varias copias del directorio distribuidas lo que provoca una mayor tolerancia a fallos y un aumento de eficiencia.

A la hora de llevar a cabo el diseño se debe tener en cuenta los siguientes aspectos.
+ Detectar la necesidad del directorio.
+ Identificar las fuentes de datos.
+ Crear el Schema.
+ Crear el esquema de nombres.
+ Determinar la ubicación de los servidores.
+ Determinar como se dividen los datos.
+ Seguridad.
# PKI
Autoridad certificadora, permite comunicaciones cifradas, controla certificados
# SSSD
Permite almacenamiento en caché, Demonio en los clientes FreeIPA
# NFS
**En los ejercicios también se pueden compaginar con los permisos de Linux**
## Servidor
Permite compartir información por la red, accediendo a info remota desde accesos locales, mejorando las prestaciones de seguridad y escalabilidad.

Para montarlo se debe editar el fichero /etc/exports de la siguiente manera
*directorio_a_compartir     ip_cliente1(permisos) ip_cliente2 (permisos)*

### Permisos del servidor
Permisos/opciones del tipo r o rw lo que hacen es establecer la cota superior de los permisos. Es decir, a la hora de calcular los permisos efectivos sobre un fichero o directorio estos no podrán ser superiores a los que estén declarados en el servidor o cliente.

**El usuario anónimo referido posteriormente es identificado como el usuario nobody, y en los archivos se aplicarán los permisos que tenga dicho usuario**

+ root_squash: los accesos como root se convierten en accesos anónimos
+ no_root_squash: La opción anterior está activada por defecto, esta la desactiva.
+ all_squash: cualquier acceso desde cualquier cuenta se convierte en accesos anónimos.
+ anonuid/anongid: Estos se establecen en la forma *anonuid=pepe* para el primero, el segundo es con grupos y al establecer esto los accesos anónimos, en vez de usar el usuario nobody usan las credenciales del usuario o grupo establecido.
+ sec=\[mode\] : permite usar tipos de seguridad a la hora de montar datos. 
	+ sec=sys -> Por defecto, usa UIDs y GIDs para autenticar las operaciones
	+ sec=krb -> Usa kerberos para autenticar
	+ sec=krb5i -> Como el anterior y utiliza checksums seguros
	+ sec=krb5p -> Como el anterior y además cifra el tráfico de datos


## Cliente
Por parte del cliente, este tiene que montar el recurso compartido, teniendo dos opciones:
mount: 
	*\#mount -t nfs4 nombre.servidor:recurso/compartido /ruta/destino*

editando el fichero /etc/fstab
	*nombre.servidor:/recurso/compartirdo /ruta/destino nfs (opciones) 0*

Este tipo de montaje estático presenta errores pues ralentiza el arranque y consume recursos. Para solucionar esto se recurre al automontaje evitando los problemas anteriores.
Su funcionamiento se basa en colocar puntos de escucha, al ser estos atravesados se invoca el automount. Estos puntos de escucha se declaran en /etc/auto.master:
*punto/escucha  fichero_mapa  opciones*

Los ficheros mapa deben tener la siguiente forma: /etc/auto.nombre

Estos deben tener la siguiente forma:
*clave opciones nombre.servidor:/ruta/absoluta*

siendo la clave el siguiente directorio tras el punto de escucha.
EJEMPLO DE MONTAJE DE HOME:
* \* nfs_server:/export/datos/&

### Permisos de cliente
También se pueden establecer los permisos máximos. Además de esto:
+ soft: Si el servidor no responde se devuelve un código de error
+ hard: Si el servidor no responde el proceso que inicio la petición se queda estático. Está activado por defecto
+ intr: Permite un montaje ininterrumpible.