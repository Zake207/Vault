[[Carrera/LR/2SSICifradoenFlujosinRC4niE0.pdf|PDF]]

Permiten agrupar redes y host contiguos formando un Área. Cada una de estas hace una copia del algoritmo básico de enrutamiento de estado de enlace. Por lo que cada área tiene su propia base de datos de estado de enlace.

Se crean varios tipos de routers:
+ Interno de área: Conectado a redes de un único área.
+ Fronterizo de área (ABR): Conectado a redes de más de un área.
+ Troncal: Conectado al menos a una red del área troncal.
+ Fronterizo del sistema autónomo(ASBR): Ejecuta y comunica más de un protocolo de enrutamiento.

Mensajes de estado de enlace:
+ Tipo 1: Info de enlaces directos
+ Tipo 2: Info de los routers de la red multiacceso
+ Tipo 3: Resúmenes de redes externas al área
+ Tipo 4: Info sobre cómo alcanzar el ASBR dentro de un área
+ Tipo 5: Información sobre rutas externas de redes ajenas a OSPF
+ Tipo 7: Como el anterior pero se propagan en un área NSSA que contiene un ASBR

**Área Troncal**
Interconecta otras áreas, permitiendo mensajes de tipo 1 y 2 internos y 3, 4 y 5 externos.
Debe existir en toda topología de OSPF y se denomina como área 0

**Área Standard**
Área por defecto, dejan pasar mensajes de tipo 3, 4 y 5 externos, por lo que los routers internos tienen info necesaria del exterior.

**Área Stub**
Permiten el mensajes de tipo 3 externos, bloqueando los de tipo 4 y 5, en su lugar inyectan una ruta por defecto hacia el ABR. Por tanto, los routers internos tiene info de otras áreas y de los demás routers internos, pero carecen de prefijos externos pues los sustituyen con la ruta por defecto.

**Área totally stub**
Los routers internos solo tienen información de los routers internos, el resto de info sobre el exterior se sustituye con la ruta por defecto, pues no aceptan ni siquiera el mensaje de tipo 3.

**No So Stubby Area (NSSA)**
Es un área de tipo stub en cuanto a los mensajes que dejan entrar.
La diferencia es que estos permite que haya un ASBR el cual propaga un mensaje de tipo 7 que al llegar al ABR se sustituyen por mensajes de tipo 5 que inundan toda la red.
