
#### Autenticación
Sin -> ERROR, pues no tiene credenciales de kerberos.
con -x -> Da resultados generales.
con SASL -> pide las credenciales del usuario especificado con -xD

a. muestra info pública.
b. muestra cierta cantidad de información adicional según el usuario
c. muestra más info 
## windows.
#### dia 2.
En usuarios y equipos de active directory (en el padre).
los dos muchachos encandilados se añade grupo. Escogemos seguridad  en el panel de la derecha:
local -> puede contener usuarios de otros dominios y es visible desde solo desde el padre.
global -> se puede ver desde todo el bosque, solo se pueden meter usuarios de su dominio.
universal-> Recomendado no usar (super-grupo global)

Lo creamos local
GL_rw_prueba
SL_rw_prueba

Para añadir miembros seleccionamos miembros/agregar tras doble-clicar el grupo. Seleccionamos como ubicacion el dominio hijo. Luego en opciones avanzadas, buscar ahora y seleccionamos a Usuarios del dominio y a pepe.
#### dia 3
auto compartir se hace por directivas, a nivel de dominio y está en preferencias, a nivel de usuario.

net use para compartir

para los home se crea la carpeta y se le asigna al usuario en sus propedades/perfil

#### Dudas
Como acceder con Escritorio remoto al hijo (directivas)
Como montar las unidades de las carpetas
Como hacer el escritorio remoto