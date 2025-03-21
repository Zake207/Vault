# Preguntas de examen
Saber relacionar información.
Como funcionan y para que sirven.
___
+ Diferencias entre router y switch.
+ resumen de asignatura.
+ Gráfico de asignatura.
+ Tecnologías de la capa 1 y 2

+ Puede ocurrir que al enviar paquetes fragmentados todos cojan el mismo camino? **Si**
+ El precio de circuito permanente y conmutado en conmutacion puede ser le mismo? **Si**
+ Te lo pueden regalar el circuito virtual? **Si**
+ Que son las tecnicas de acceso al medio **Tecnologías usadas para acceder al medio de manera ordenada y evitando colisiones**
+ Porque existen diferentes técnicas de conmutación **Para adaptarse a las diferentes situaciones**
+ Definir las técnicas de conmutación

+ Para que sirve una protocolo orientado a conexión
+ Diferencias entre TCP y UDP
+ Para que sirve el nivel de transporte(nivel 4) **Para multiplexar procesos**
+ Me das un servicio no orientado a conexión, se puede desarrollar orientado a conexión
+ Una red tipo bus(recto) se puede hacer que funcione como anillo? **Sí se le asigna un número a cada componente, entonces el 1 solo manda al 2 ... y el 5 solo manda al 1 además es más ligero**
+ Puedes tener una centralita combinada en la nube con otra fisica? **Sí** 
+ ¿Cual es la mejor topología? **Depende**
+ ¿Cual es la más extendida? **No se puede decir con exactitud pero la estella es muy usada**
+ Una centralita puede conectar conexiones analógicas con modernas? **Sí**
+ En el mcdonald hay concurrencia? **Si**
+ Pueden existir tecnologías de comunicacion por el aire? **Si, con láseres (FSO)**
+ Diferencia entre Baudios y Bits por segundos?**Cuantos bits salen por segundos, los baudios limite de cambios de transmisión soportada por línea**

+ 
# 31/01/2025

Eficaz: Realiza las acciones correctas
Eficiente: Realiza las acciones correctas correctamentes

Hay dos tipos de redes
+ Red de telecomunicación: 
+ Red de ordenador:

Al montar puentes entre redes se puede requerir de un operador.
Existen dispositivos que no trabajan en todos los niveles OSI

ETHERNET es una tecnología de base, es la más extendida a nivel de usuario. Existió ATM que es similar pero ya no se usa, es más difícil configurar dispositivos con este.

La tecnoogía ETHERNET se ubicaría en las capas 1 y 2. El protocolo ETHERNET se ubica en la capa 2.

Las redes de comunicación tienen protocolos y las de **completar**

La fibra óptica es un medio de transmisión, como la comuncicación inalámbrica, no una tecnología.
Los switches son dispositivos

Tecnologías: FTTH, Ethernet, wifi, 5g, radio frecuencia, BlueTooth, Redes satelitales, Redes submarinas, ATM, ADSL.

Las redes de transporte están conectadas, los operadores de redes llegan a un acuerdo para conectarse entre ellos, pese a esto se puede crear una red de transporte privada. Detrás de las redes de transporte están los operadores.

Las redes de acceso son aquellas redes donde permiten acceder a la nube, la tecnología usada es FTTH o 5g.

Sin embargo aún se usan otras tecnologías menos generalizadas como ATM o ADSL, esto es porque se diseñaron para un determinado ámbito, funcionan bien y tienen buen desempeño.

**Diferencia entre "tecnología" y "protocolo"**

**Diferencia entre "red de accesp" y una "red de transporte"**

# 06/02/2025

Redes segun alcance: LAN, MAN, WAN
Redes según Tecnología: Broadcast, punto a punto.

**Anotar tabla de las diapos**

**router**: trabaja en capa 3
**switch**: trabaja en capa 2

Dos tipos de direcciones:
Física: MAC, más fácil de usar en entorno acotado, es más rápido, no tiene jerarquía.

Lógica: IP, más potente, mejor en entornos más grandes, tiene una organización jerárquica.

Para moverme de un punto a otro podría bastar con una, pero hay que tener lo anterior.

Cuando dos puntos usan diferentes tecnologías se podrían conectarse pero:

En la capa 3 hay un acuerdo de homogeneidad.
Se puede cambiar la dirección física pero sería un problema en el sentido de que el resto de equipos tienen la anterior

Ethernet funciona de manera probabilistica: uno obseva si el canal esta vacío, manda el mensaje y si antes de que llegue otro se trata de conectar se produce una colisión.

Un método determinista pregunta uno por uno a todas las conexiones si va a transmitir, esto otorga un tiempo seguro a todas las conexiones.

tren de bits == tecnología digital síncrono.

**Bridge** limita los entornos de conexión, mientras no haya un mensaje para la otra parte no se abre el puente.
Por ende se puede conectar servidores e interfaces directamente a un bridge, lo cual es un birdge multipuerto, es decir, un switch.

Redes de Conmutación. puede usar conmutadores (no todos son de ethernet) para cerrar interrumptores que no vayan al destino, creando el canal de comunicación.
Los canales puedes tenerlos abiertos de manera ininterrumpida pero suele tener un costo. Existe otro método que trocea el mensaje en paquetes con la información necesaria para llegar a su destinp y lo esparce por la red (Conmutación de circuitos), este método es más beneficioso.

Redes de Difusión.

**Tecnologías simétricas y asimétricas**: Se baja mas info de la que se sube, la tecnología asimétrica permite aumentar el tamaño del camino de bajada, en la subida se usa simétrica.

# 07/02/2025

**Gráfico**: Hacer tipico gráfico A <--> B con la nuve en medio, poner las capas de OSI con sus niveles, los direccionamientos que usa cada una.
En el diagrama indicar cuales son redes de acceso y de transporte y que dispositivos se usa en cada una y los metodos usados (conmutación conmutación). Indicando la dimensión de las redes (LAN MAN WAN).

Puede haber varias tecnologías para un mismo nivel.

Por la via de conmutación van paquetes troceados en diferentes tamaños:
**Datagrama**: se lanza con una cabecera de origen y destino con su correspondiente info, en orden, cuando llegan al destino se reordena la información en el destino. Al fragmentarla se consigue mejor equilibrio en la red. En el caso de que haya un error en la red y no lleguen los paquetes B le dice a A que reenvie todo de nuevo o solo lo que le falta.

**Circuito virtual**: Es una especie de via privada de un punto a otro, reservas una vía "privada" para enviar tus paquetes. Esto es, darte prioridad sobre una vía de comunicación al adquirirla, al enviar algo se te prioriza a ti y cuando liberas esa vía para otros usuarios. Ya no se requieren la fragmentación ni las cabeceras pues al conectarte a esta vía ya se sabe a donde se va.
+ Conmutado SVC: se te reserva una via, si está ocupada te aseguran otra, tiene una via asegurada pero no necesariamente es la misma
+ Permanente PVC:: Se te asegura la misma vía fija siempre (más cara).

# 13/02/2025

Las tecnologías de conmutación de paquetes son ATM, Frame Relay o X-25
+ **Protocolo orientado a conexión**
+ **Protocolo no orientado a conexión**

Topologías físicas : Por donde van los cables
Topologías lógicas : Como fluye la información

Un Token es un testigo usado en un anillo

Un bus funciona de manera probabilistica
Un bus circular funciona de manera determinista (igual que el anillo), también conocido como 8024 Token

Es más sólido el circular, el más usado actualmente es una topología de estrella, pero para comunicaciones telefónicas se usa una estrella distribuida.

Puedes pagar un servicio que permita tener centralitas en la nube, aunque siguen existiendo las físicas

**VLANS** ==> 

En dos LAN conectadas privadas, si fueran centralitas, se debe pagar por enlace hacia el exterior, 

Las centralitas tienen un límite, cuando muchas estaciones acceden a esta a la vez sufre congestión, para evitar esto se debe estudiar la dimensión de la red

Tipos de enlace:
+ Simplex
+ Semi-duplex
+ Duplex

En los dos segundos los enlaces pueden ser simétricos o asimétricos según el perfil de los usuarios.
Se suelen usar duplex simétricos.

Primero se elige la tecnología y en base a esta se escoge la topología, siempre hay que ir holgados en términos de recursos otorgados

# 14/02/2025

*A Felix le gusta que a la hora de asumir cosas se asuman de manera absoluta, un A implica B quiere que pienses que A siempre en cualquier situación va a implicar B, hay que pensar exagerado en este tipo de preguntas*

*Se pueden hacer asteriscos para tu aclarar en el examen lo que entiendes del enunciado, ayuda a facilitar la pregunta: Considero que un nodo activo es un nodo encendido y que tenga tráfico*

*Por poder se puede, la pregunta es seria si pregunta si lo harías o no y el porqué*

**Preguntas A**
1. ATM es un protocolo exclusivo de nivel 3 **Falso**
2. Es posible multiplexar la comunicación a nivel de transporte **Verdad**
3. El nivel de transporte no controla errores **Falso**
4. Los niveles 2 y 3 han de estar siempre presentes en una comunicación **Falso**
5. Una MAN no puede ser parte de una WAN **Falso**
**Preguntas B**
1. La carga de una red no depende de la topología de la misma **Verdad, será más rápido o mas lento, pero la carga es la misma**
2. La carga de una red depende del número de nodos activos **Falso**
3. La carga de una red depende del método de acceso empleado **Verdad**
4. La carga de una red siempre se mejora con un cambio de tecnología de red **Falso**
5. El empleo de los diferentes protocolos de comunicaciones está limitado por el valor MTU *La MTU es unidad máxima de transmisión* **Falso**
**Preguntas C**
1. No es posible realizar broadcast en redes de anillo **Falso**
2. Para una red ATM los tiempos de espera medios son altos en condiciones de baja carga **Falso**
3. No es posible obtener concurrencia en tipo de red Fast Ethernet **Falso**
4. Es posible obtener concurrencia en una red de tipo 802.3 (Ethernet) **Verdad**
5. Todas las redes disponen de nivel de distribución **No lo hemos dado**
**Preguntas D*
1. Las redes troncales que dan servicios de cable usan combinaciones de fibra y coaxial **Falso**
2. La dimensión de una red que usa CSMA/CD (método de acceso) es independiente del tiempo de propagación **Falso**
3. Un dispositivo "hotswap" significa que soporta altas temperaturas **Falso**
4. Un acceso básico de RDSI incluye un canal E2 **No lo hemos dado pero Falso**
5. Un router trabaja más rápido que un bridge **Falso**

# 20/02/2025
Hay diferentes espectros de frecuencias
+ ? Repasar diapos del dia de hoy

Teorema de Fourier, sirve para descomponer cualquier onda en un sumatorio de ondas
# 21/02/2025
Teorema de Nyquist: 

Relacion señal ruido: SR = 36 dB, por lo que la señal es de $10^{3,6}$ = 3981 veces mayor que el ruido

Existen diferentes capacidades de transferencia a cada cual más complejo electrónicamente que el anterior.

Teorema de muestreo, coger el doble del rango capturado puntos de la onda.
+ ! REVISAR

**PDH** (tecnología): Sistema que describe la desincronía en las comunicaciones internacionales

**RDSI** (tecnología): Te preparas un bucle digital en local y la compañía te oferta dos canales de 64Kib para su uso, además tiene de un canal de control D de 16Kib

Tecnología que no para (sincrono), es jerarquica y acumulativa, además de digital, es compleja cuando se añaden muchas ramas al árbol jerárquico, con trenes de bits

**ATM** (tecnología): Usa por debajo la jerarquía digital síncrona dividiendo la información en "vagones" de 52

**ADSL** (tecnología): funciona muchisimo mejor que el RDSI pues daban un canal de 4Mib y no hace cambiar el cable, se trato de exprimir al máximo mejorando su rendimiento pero siempre limitado por el cable de cobre

**FTTH** (tecnología): fibra hasta la casa, mejor incluso que el ADSL, pero esta vez se cambia el cobre (categoría 3) por el cable de fibra (categoría 6)

**Modulación** Manda una señal analógica super acelerada para quedarse con la envolvente de la señal, permitiendo tener la señal digital
# 28/02/2025
digitalización, tiene varios pasos:
+ Muestreo
+ Cuantificación
+ Códificación

Las tecnologías además de sacar la señal las codifica para facilitar las cosas al receptor

Existen patrones determinados que dependiendo de su forma binaria el receptor entiende que debe ejecutar diferentes ordenes

**OSI**
**Nivel 1**: cables y demás (cobre, fibra, etc...) usa un bucle de abonado y funciona en sistemas de red local suelen usar hilos trenzados de los caules hay diferentes tipos, cabe destacar que no es lo mismo los bits que salen del cable que la frecuencia con la que salen, el coste de instalación y de reemplazo es exorbitante, por lo que se trata de mantener todo lo posible la tecnología instalada Se usan cables coaxiales, también hay diferentes tipos de fibra óptica: por led y por láser(+caro +preciso) también varian en función del cable (multimodo o monomodo) en la fibra la luz se dispersa
+ ? revisar diapos

longitud de onda = distancia de cresta a cresta, al haber diferentes tipos de luces se sobrentiende que debido a esto también varían los tipo de fibras, en concreto se usan rangos:
+ 1º ventana
+ 2º ventana
+ 3º ventana

existen gráficos que decubren cuales son las luces que más les gustan a determinada fibra óptica, de la que sacamos que es mejor tener una baja atenuación y que las que tienen un rango de longitud de onda más estable son las segunda y tercera ventana

# 13/03/2025

Tecnologías de voz (SONET/SDH) tienen diferentes topologías y demás
+ ? Mirar diapos debido a que faltaste la semana pasada.

**Cableado estructurado** como mucho se pueden tener enlaces de 100 metros, pero recomendable no pasar de 90, del ordenador va a una roseta con un latiguillo, de aqui usa el enlace para conectarse a un patch panel, el cual se encarga de gestionar sus conexiones.

Lo *lógico* es tener menos bocas gigabit que puertos en el patch panel 
(*no entiendo esto*) 

En el replanteo se revisa en persona con los planos el edificio para comprobar si se debe hacer modificaciones

Se pueden usar bytes inteligentes, estos usan un mapeado que permiten habilitar y deshabilitar las redes a distancia

El salto vertical suele ser en fibra, pero puede hacerse en fibra, usando un LIU

La electrónica de acceso es las que se pude colocar en cada planta, la de distribución une todas estas dentro de una edificio, y la electrónica de core une estas últimas, el backbone (zona más sensible al daño, la columna vertebral) suelen ser los cores con las uniones entre estos

La parte troncal de una red dentro del edificio sería la parte de distribución

Los cores se conectan a los firewalls, estos por tener todas las reglas no quiere decir que sean mejores, esto pasa más en redes grandes. El internet que pasa al router, debe pasar por el filtro del firewall para poder acceder a la red