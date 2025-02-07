La encargada de la comunicación lógica entre procesos. Se implementan en los sistemas terminales implicados. Los mensajes se dividen en segmentos.

Sus protocolos son TCP y UDP. Estos marcan los segmentos para que puedan ser ordenados en el destino (multiplexación), en el destino la capa de red entrega los paquete se entregan a la capa de transporte para que los recomponga (Demultiplexación)

# Técnicas de transferencia fiable
Las siguientes técnicas están basadas en el envío de paquetes de confirmación para poder controlar el envío de paquetes.

Se implementan unos temporizadores para detectar la pérdida de estos paquetes y poder actuar de manera consecuente.

Cada paquete tiene un número de confirmación y de secuencia que permite ordenar los paquetes de datos en el destinatario.

La eficiencia de los siguientes métodos se mide con:
E = Te/(Te + RTT)
## Parada y espera.
Se basa en mandar un paquete y esperar a recibir la confirmación para mandar el siguiente.
Si recibe paquetes corruptos el receptor manda un ack con el número de secuencia que espera, el emisor lo detecta y reenvía el paquete
## Vuelta atrás N
Mandas un número de paquetes seguidos si tener que esperar la respuesta del destinatario para aumentar la eficiencia.
Usa un temporizador en el que se mandan los paquetes, si uno de ellos se pierde el receptor continúa enviando el ack del último que recibió. En el siguiente ciclo reenvía los paquetes que estaban pendientes de confirmación.
## Repetición selectiva
Cada paquete tiene un temporizador propio para detectar su pérdida, así solo se hace reenvío de ese paquete
# TCP
Protocolo orientado a conexión que consta de 3 fases:
+ Inicio de conexión (1)
+ Envío/Recepción
+ Cierre de conexión (2)
Utiliza un número de secuencia en su cabecera para ordenar los ficheros y asegurar las entregas.

(1)![[Pasted image 20240505115307.png]]

(2)![[Pasted image 20240505115320.png]]


El número de confirmaciones en TCP es el siguiente byte que espera recibir el receptor. El numero de secuencia es el numero del byte que se envía, es decir, si hacen envíos de 4 bytes los numeros de secuencia serán 0, 4, 8, ... Y los ACK serán 4, 8, 12

Puede seguir el principio de confirmación acumulativa, esto es, una confirmación con un numero de aceptación X, confirma todos los anteriores.

Se utilizan temporizadores para detectar un paquete perdido y poder reenviarlo. El tiempo de espera varía dependiendo de a qué se está conectando. Este se establece midiendo el tiempo del envío del primer paquete y se va estimando a lo largo de la conexión. Es necesario que el receptor sea capaz de detectar duplicados para no ocasionar problemas cuando se pierdan paquetes.

También se puede duplicar el temporizador cuando, tras perder un paquete, se hace el reenvío para darle tiempo de recibir la confirmación. Esto proporciona un control de congestión limitado.

La retransmisión rápida consiste en hacer varios envíos sin llegar a esperar el ACK, si se detecta una perdida pues se lleva un control de los ACK recibidos se hace inmediatamente el reenvío del paquete, incluso antes de que acabe el temporizador.
# UDP
Ofrece los servicios de multiplexación/demultiplexación y detección de errores. No garantiza la entrega.
Sin embargo da poca sobrecarga, no requiere de conexión y ofrece un mejor control de los datos.
![[Pasted image 20240505115038.png]]
# Control de Flujo
El control de flujo consiste en adaptar la velocidad de emisión de paquetes del emisor a la velocidad de procesamiento del receptor. Se da entre cualquier par de entidades conectadas.

Mediante una serie de variables se controla que el buffer del emisor no se desborde.

Utiliza una ventana de recepción para calcular los bytes que se enviarán.
![[Pasted image 20240505123645.png]]
Si la ventana es de 0, cuando esto pasa se comienzan a enviar mensajes de 1 byte para forzar las confirmaciones y actualizar la ventana de recepción. Se utiliza el algoritmo de Nagle:
1. El emisor envía la primera pieza
2. Se espera a que se acumulen suficientes bytes para hacer un envío mayor


Para evitar el síndrome de la ventana tonta se debe esperar hasta que haya suficiente espacio en el buffer, este problema se debe a que el receptor lee muy lento.
# Control de congestión
Cada emisor debe controlar su velocidad de transmisión en función de la congestión de la red.
==Pregunta de examen: Diferencias entre control de flujo y control de congestión==

Se crea la ventana de congestión para limitar la velocidad del emisor, esta varia en función de las transmisiones, en caso de pérdidas se baja la velocidad general, si todo va bien se aumenta.

Una pérdida se detecta si se produce el fin de un temporizador o se reciben 3 ACK duplicados del receptor.
Esto indica congestión.

El control de congestión tiene tres algoritmos principales que derivan en diferentes tipos de TCP: Arranque lento (crece la ventana exponencialmente), evitación de congestión(crece la ventana de unidad en unidad) y la recuperación rápida (al detectar 3 ACK's duplicados reduce el umbral y la ventana a la mitad).

Hay dos tipos de TCP:
+ Tahoe
![[Pasted image 20240505124358.png]]
+ Reno
![[Pasted image 20240505124419.png]]