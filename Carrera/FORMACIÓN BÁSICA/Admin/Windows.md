# Dominios.
Agrupación lógica de ordenadores, usuarios y otros recursos, es manejado por un administrador e incluye como mínimo un controlador de dominio (DC)

Un bosque es una agrupación jerárquica de árboles, y un árbol es una distribución jerárquica de varios servidores. Los árboles comparten un schema y un catálogo global, además de administradores y configuración de confianza compartida.

El catálogo global es un almacén de información, guarda aquellos atributos relacionados con el bosque. Es la info que más frecuentemente se usa en consultas.

Existen unidades organizativas que son contenedores que permiten agrupar objetos de un dominio, permiten delegar el control administrativo de forma controlada.

# Usuarios.
Se les asigna dos números de identificación:
+ Número de identificador global GUID
+ Número de identificador de seguridad SID
+ User Principal Name UPN

Tipos de cuenta de usuario:
+ Cuenta de usuario local: El usuario entra a un ordenador específico y esta reside en SAM
+ Cuenta del usuario del dominio: Permite acceder a cualquier ordenador de la red del dominio al que pertenece.
+ Cuenta de usuario predefinido: Permite hacer tareas administrativas (admin o invitado) y se crean automáticamente.

Se debe tener una política de contraseñas
La situación de los directorios puede ser:
+ Descentralizada
+ Centralizada

## Perfiles
Estructura predeterminada de carpetas y datos de registro.
Cada usuario requiere de uno, define la configuración delentorno de trabajo del usuario.

+ Perfil por defecto: la base para el resto.
+ Perfil Local: Se crea la primera vez que el usuario entra en el ordenador.
+ Perfil Flotante: Se crea por el administrador y se almacena en un servidor, estando disponible desde cualquier ordenador de la red.
+ Perfil Obligatorio: Creado para especificar una configuración particular de los usuarios, pudiendo ser local o flotante.
# Grupos.
Colección de cuentas de usuario y permiten simplificar el acceso a los recursos. Son anidables.
### Tipos:
**Grupos de seguridad:** Usados para cualquier asunto relacionado con el tópico.
**Grupo de distribución:** Usados para el resto de asuntos.
### Ámbitos:
Determinan dónde se puede utilizar dicho grupo.
+ Global del dominio: Son visibles para el resto de dominios del bosque pero sólo puede contener miembros y grupos anidados del mismo dominio que el grupo.
+ Local del dominio: Solo es visible en el dominio donde se define, pero puede contener usuarios y grupos globales anidados de cualquier otro dominio.
+ Universales: Se le pueden asignar miembros de cualquier dominio y se le puede asignar permisos en todos los dominios del árbol, no están asociados a ningún dominio sino que residen en el catálogo global.
###### Recomendaciones:
![[Captura desde 2024-04-02 17-31-48.png]]
+ No usar universales
+ Meter un usuario en un grupo global, al recurso darle permisos en un grupo local y luego metemos el grupo global en el grupo local.
#### Distribución de información
Distribuido
Centralizado

La info se guarda en diferentes formatos FAT, FAT32, extFAT, NFTS.

Se puede acceder a la información de manera local o de manera remota
## Control de accesos
### **Permisos NTFS**
A nivel del sistema de archivos.
Almacena una ACL para cada fichero, cuando a un recurso intenta entrar un usuario que no tiene entrada en esta lista se le deniega el permiso. 

El permiso denegar prevalece sobre el resto. 

Los permisos son acumulativos y en caso de que haya varias coincidencias los permisos son la suma de estos.

Los permisos son heredados y propagados, se puede evitar esta herencia y la primera carpeta después de esta herencia se convierte en padre de las descendientes de esta.

### **Permisos compartidos**
Solo se aplican cuando se accede por la red. Utiliza una ruta universal para acceder a la carpeta compartida: \\\\desktop.elderring.com\\dinerito
El recurso compartido tiene un nombre que se le asigna para ser compartido, en este caso es *dinerito*.

Los permisos compartidos se establecen a nivel de carpeta y se aplica a todo su contenido, suele ser el menos restrictivo para que los NTFS controlen los permisos de mejor manera.

### Permisos especiales
Son permisos individuales para los archivos. Es mejor no asignarlos. La idea es tratar de "no permitir" antes que "denegar".

# Diseño Lógico.
+ Cada DC gestiona un único dominio. No se pueden borrar.
+ Tratar de tener un único dominio con varias Unidades Organizativas siempre que sea posible.
+ Saber la estructura de la organización. Establecer un criterio de nombres para la red.
+ Organizar la info interna y hacer las GPOs.

**NO ES NECESARIO AÑADIR DC A SITES DE DOMINIOS A LOS CUALES SUS USUARIOS NO VAN A ACCEDER**
Ejemplo: Si los usuarios de mojopicon.com están en la palma no es necesario añadir un controlador de dominio de mojopicon.com en la gomera, pues no van a acceder de una manera tan recurrente.

Al pedir diseñar una organización hay que responder las siguientes cuestiones:
## nº de bosques 
Un bosque por lo general, hay excepciones: 
+ Unidades de la organización independientes 
+ Razones políticas 
+ La más común es por la necesidad de tener esquemas(clases o atributos) diferentes.
## nº de dominios
Un solo dominio salvo que: 
+ Se quiera dividir las tareas de administración.
+ Diferentes duración de los tickets de kerberos
+ Diferentes desvíos en la hora del sistema.
+ Para optimizar el sistema o comunicaciones teniendo diferentes DC's(controladores de dominio) para minizar el tráfico de baja replicación.

El cómo organizarlos depende de los nombres otorgados a los dominios, siempre tratar de tener el menor número posible de dominios.

El dominio raiz del bosque puede ser uno vacío en el que se aísle a los administradores de la empresa o ser un dominio que perdure y tenga una función.
## Unidades organizativas
Debe tener un diseño independiente en cada dominio.
Se crean para tener una mejor delegación de control y poder organizar las GPO's. Son anidables aunque no se recomienda pasar de los 3 niveles de anidación.

La delegación de control permite asignar ciertas tareas de administrador a un usuario sobre una unidad organizativa.
#### Estructuras.
![[Pasted image 20240409175224.png]]

# Diseño Físico.
Permite configurar el tráfico de red. Involucra los sites y la replicación.
## Sites.
Proporcionan una conexión entre la infraestructura física y la lógica.
Son un área de red donde los equipos se conectan de manera rápida fiable y barata.
+ Un site puede tener varios dominios
+ Un dominio puede distribuirse entre varios sites.
A los sites se les pueden asignar GPOs y estos mejoran la eficiencia.

Es recomendable tener DC redundantes para así tener mayor tolerancia a fallos, mejor balanceo de carga y proximidad de la información, siempre que se pueda.

La replicación permite tener la información de un dominio actualizada y disponible desde otro dominio desde el cual acceder. Sigue el modelo multimaster, es decir, se puede replicar a través de cualquier DC.

Las replicaciones se aplican sobre particiones de Active Directory.
![[Pasted image 20240430112429.png]]

### Intrasite
Los CD se sincronizan en el menor tiempo posible. 
Usa una topología de anillo, cuando un DC modifica la base de datos avisa al resto para que inicien el proceso de replicación.

### Intersite
Reduce el ancho de banda usado. 
Atiende a una planificación, los datos a replicar se comprimen. 
La replicación se realiza a través de los servidores cabeza de puente.
La planificación de esta dicta las horas en las que se llevará a cabo.

Los sites están unidos por enlaces que tienen asociado un número que representa el costo de atravesarlo, la replicación se lleva a cabo a través del enlace con menor coste. 
# Directivas de grupo
Se aplican sobre sitios, dominios o Unidades organizativas y afectan a los usuarios y ordenadores.
Pueden estar:
+ Habilitado
+ Deshabilitado
+ No configurado

Se pueden aplicar varias GPO's a un contenedor, o un GPO a varios contenedores.

En una directiva sobre ordenadores y usuarios tienen preferencia la primera.

Se aplican:
1. Site
2. Dominio
3. Unidades organizativas

Las GPO's se heredan, se aplican primero las del padre y después las del hijo, en caso de colisión prevalece la del hijo.
## Gestión de GPO's
+ **Bloqueo de herencia:** El contenedor hijo no hereda las GPO's del padre que no estén forzadas.
+ **Forzar herencia:** Fuerza la aplicación de las GPO's, sobrescribiendo las GPO's de arriba si estas no están forzadas.
+ **Filtrar configuración de GPO:** Permite filtrar la directiva a determinados elementos del contenedor.
+ **Cambio de orden de procesamiento:** En el caso de que las múltples GPO's que están asociadas a un contenedor se contradigan, prevalecerá la que esté más bajo en el listado de GPO's, a no ser que estas esten forzadas, lo cual cambia y hace que la que prevalezca es la que más arriba esté.
## Administración
#### Modificar las directivas existentes
Tener permisos de lectura y escritura sobre la GPO.
#### Creación de nuevas GPO's
Solo pueden Propietarios Creadores de Directivas de grupo, Sistema, Administradores de Dominio y Administradores de Empresa.

Se debe añadir a los usuarios a Propietarios Creadores de Directivas de Grupo.
#### Vinculación/Desvinculación de GPO a contenedor
Se puede usar "Delegar control" para permitir a los usuarios el "Administrar la directiva de grupo"
## Ejemplo.
![[Pasted image 20240430153521.png]]
# DFS
Mejora el uso de carpetas compartidas, permite su organización y reparto.
Tiene un espacio de nombres y permite replicación.

Su espacio de nombres puede ser 
+ Autónomo pues la configuración se guarda en el servidor DFS 
+ Basado en dominio, lo que permite redundancia en los enlaces, así no se limita el acceso al recurso a una sola máquina (no depende de un servidor)

Para acceder al recurso se usa un *referral* la cual es una lista ordenada de servidores a los cuales entra para acceder al recurso, siempre siguiendo el orden de la lista.

La replicación DFS permite replicar carpeta entre servidores, usa la red de forma eficiente pues permite planificarla y solo propaga los cambios. Sin embargo cuenta con limitaciones de espacio.
