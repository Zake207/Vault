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

**Bridge** limita los entornos de conexión
mientras no haya un mensaje para la otra parte no se abre el puente.
Por ende se puede conectar servidores e interfaces directamente a un bridge, lo cual es un birdge multipuerto, es decir, un switch.

Redes de Conmutación. puede usar conmutadores (no todos son de ethernet) para cerrar interrumptores que no vayan al destino, creando el canal de comunicación.
Los canales puedes tenerlos abiertos de manera ininterrumpida pero suele tener un costo. Existe otro método que trocea el mensaje en paquetes con la información necesaria para llegar a su destinp y lo esparce por la red (Conmutación de circuitos), este método es más beneficioso.

Redes de Difusión.

**Tecnologías simétricas y asimétricas**: Se baja mas info de la que se sube, la tecnología asimétrica permite aumentar el tamaño del camino de bajada, en la subida se usa simétrica.