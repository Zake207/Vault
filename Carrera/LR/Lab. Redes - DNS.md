[[DNS.pdf|PDF]]

Sistema de nombres de dominio:
+ Base de datos distribuida
+ Protocolo de la capa de aplicación que consulta la base de datos
+ Se implementa en una jerarquía de servidores DNS

Los servidores pueden ser:
+ **Raíz**: Existen 13 instancias que operan a lo largo del mundo
+ **TLD**: Responsables de los dominios de nivel superior (com, org)
+ **Autoritativos**: Servidores usados por organizaciones para proveer servicios
+ **Local**: No forman parte de la jerarquía, aceleran las consultas.

