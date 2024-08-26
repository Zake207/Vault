# Super-usuario.
Tiene acceso a todos los ficheros y directorios además de poder ejecutar todos los comandos del sistema operativo. Suelen realizar las tareas de administración.

Se puede acceder como root ya sea iniciando sesión con ese perfil, con el comando `su -o` que guarda registro de quien lo ha ejecutado.
Con el comando `sudo` precediendo cualquier otro comando otorga la identidad de super-usuario al ejecutor de dicho comando, pero para poder usar este prefijo se debe estar en la lista de /etc/sudoers, este fichero debe editarse teniendo en cuenta una serie de criterios.

# Usuarios
Los datos de los usuarios del sistema se almacenan en el fichero /etc/passwd y tiene el siguiente formato:

*username:x:UID:GID:user-information:home-directory:login-shell*

Este fichero es modificable y por ende inseguro para almacenar la contraseña de los usuarios, esta se almacena en el fichero /etc/shadow, que solo es accesible para root y usuarios que puedan hacerse pasar por este usuario.
Cada registro de contraseña de grupo o usuario esta almacenada con el siguiente formato:

username:encoded-password:changed:minlife:maxlife:warn:inactive:expires:unused

# Grupos
Los grupos se utilizan para conglomerar un grupo de usuarios para simplificar la asignación de permisos, todo usuario tiene un grupo primario y varios grupos secundarios, por lo general el grupo primario de cada usuario es un grupo privado del que solo este es miembro.

La información de los grupos se almacena en el fichero /etc/groups, cuyo formato es el siguiente:

group-name:x:GID:additional-users

De la misma manera la contraseña de los grupos se guarda en /etc/gshadow

group-name:encoded-password:group-admins:additional-users

# Procesos
Los procesos de iniciados conservan un atributo que identifica al usuario que los ejecutó, a la hora de actuar, el proceso en cuestión lo hará con los permisos del usuario y del grupo de este.

# Permisos
Los ficheros y directorios tienen asignados una serie de permisos para leer, escribir y acceder/ejecutar para el propietario, el grupo propietario y el resto de usuario (rwx). El usuario propietario solo puede ser cambiado por root, sin embargo los permisos y grupo puede ser cambiado por el propietario, para el caso de los grupos el usuario debe estar en el grupo al cual desea cambiar la propiedad.

A la hora de modificar estos archivos se revisa la identidad de la entidad que desea operar con estos y se le aplican los permisos pertinentes.

![[Pasted image 20240413195325.png]]

Existen diferentes tipos de permisos especiales que se les añade a los permisos básicos, setUID, setGID y sticky-bit. La función de estos depende del tipo de archivo sobre el que se ejecuta

|            | ficheros ejecutables                                                                                      | directorios                                                                                              |
| ---------- | --------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------- |
| SetUID     | El fichero se ejecuta con los permisos del propietario sin tener en cuenta el que lo ejecutó.             | -                                                                                                        |
| SetGID     | El fichero se ejecuta con los permisos del grupo propietario sin tener en cuenta el grupo que lo ejecutó. | Los ficheros creados dentro del directorio tendrán como propietario el grupo propietario del directorio. |
| Sticky-bit | -                                                                                                         | Los archivos dentro del directorio solo podrán ser borrados por el propietario                           |
# Máscaras
Un usuario tiene una máscara que determina los permisos por defecto que tendrán los ficheros y directorios que cree. Está puede ser cambiada por el propio usuario con el comando umask, o por el root en el fichero /etc/profile

La máscara esta compuesta por 4 numeros. La máscara de los usuarios es el negado de los permisos totales, es decir, un usuario con máscara 0006 tendrá los permisos atribuidos a:
+ En caso de directorio
7777 - 0006 = 7771
+ En caso de fichero
6666 - 0006 = 6660

Para saber que permisos son esos se puede consultar la siguiente tabla:
![[Pasted image 20240413210445.png]]

# Listas de control de acceso (ACL's)
Una ACL se crea para dar a los ficheros y directorios permisos para casos específicos de usuarios o grupos.
Estos permisos conviven con los permisos tradicionales de Linux.

Si una ACL esta marcada como `default` esos permisos solo se aplicarán sobre los ficheros y carpetas que estén contenidos en el directorio, si fueran una lista de control de acceso por defecto en un fichero, esta no tendría ningún efecto, pues default solo afecta a ACL de directorios.

El orden en el que se comprueban los permisos normales y los de las listas de control de acceso es el siguiente:
+ Comprobar que es el propietario
+ Si no lo es, comprueba que ese ususario tenga una entrada en la lista de control de acceso.
+ Si no la tiene comprueba que el usuario está en el grupo propietario o en alguno de sus grupos coincide con los establecidos en la ACL.
+ Si no a encotrado ninguna coincidencia le aplica los permisos de "*others*"
