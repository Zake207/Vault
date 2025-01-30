Crear usuarios y grupos.
+ Usuarios y grupos de Active directory
+ Dentro de las unidades organizativas se pueden crear.

Se deben crear grupos globales en los servidores, esos grupos son incluidos dentro de grupos locales en el dominio donde se encuentre el recurso en cuestión. A estos grupos se les otorgan los permisos.

Los recursos deben ser compartidos con los grupos locales y dando todos los permisos pues en el apartado de seguridad se declararán los permisos más restrictivos.

Una vez compartidos, editando la política/usuario/Preferencias se pueden asignar las unidades, colocando el nombre del \\\\equipo\\recurso
donde recurso es el nombre que se dio una vez se compartió. Se debe seleccionar una unidad donde se encontrará el recurso.

Las políticas de las contraseñas se puede editar en la parte de *Equipos/Configuración_Windows/Configuración_seguridad/Directivas_cuenta*

Las GPO's se aplican sobre unidades dominios, sites u OU's.

Si se quiere que a un solo individuo de una OU no se le aplique una directiva se debe ir a la directiva, delegación, añadir a dicho usuario y seleccionar en denegar aplicar directiva.

Por otro lado si se quiere que un usuario tenga capacidad para aplicar directiva o controlarla en general, dentro de la misma delegación de control se le debe permitir configurar/editar/eliminar

El DFS se debe agregar como rol y característica. Se accede desde Herramientas/Administración_DFS. Al crearlo se debe declarar un espacio de nombre que servirá como raiz, la ruta de este ya no será a una máquina sino al dominio en el que se encuentre, se podrá asignar a una unidad pudiendo ampliar el potencial de este.

Al añadir carpetas a esta raiz se puede activar la replicación, lo que permite que lo que se edite desde una máquina se vea reflejado en las demás.