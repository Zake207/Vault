# Codificación

CODEC: Recibe una señal que codifica y envía como señal digital a un decodificar para obtener la señal recuperada.

MODEM: Al recibir una señal la pasa por un modulador, este produce una señal analógica que luego le pasa a un demodulador, produciendo una señal recuperada.

La codificación se ve afectada por:
- Velocidad de transmisión
- Relación señal-ruido
- Ancho de banda
- Esquema de codificación

Una secuencia digital es una secuencia de pulsos que codifican datos binarios. Usan esquemas de codificación:  
![[Pasted image 20240502181000.png]]

La velocidad de modulación es la cantidad de elementos de señal por unidad de tiempo.

# Medios físicos

Existe entre cada par transmisor-receptor.  
Pueden o no ser guiados.

Cables de par trenzado:

- UTP: Baratos, limitados en distancia y producen errores.
- STP: Cables de cobre aislados en una cubierta protectora.
- FTP: Par trenzado con pantalla global.

Los pares trenzados tienen categorías (1, 3, 4, 5 y 5e), cada una con más ancho de banda que el anterior.

El cable coaxial tienen dos conductores concéntricos, el central es el vivo y el externo es la malla, referencia a tierra.
![[Pasted image 20240502182600.png]]

La fibra óptica es inmune a las interferencias electromagnéticas.

Los enlaces de radio son un medio no guiado y puede ser interceptado por cualquiera al alcance.

# Transmisión

- Señal analógica: La intensidad varía suavemente
- Señal digital: La intensidad cambia de una constante a otra tras un tiempo.
- Señal periódica: Consiste en un patrón que se repite con el tiempo.

Las señales se pueden expresar en dominio de frecuencia o temporal.
![[Pasted image 20240502183545.png]]![[Pasted image 20240502183613.png]]

**La formula para describir la onda es la siguiente**
![[Pasted image 20240507211905.png]]
siendo:

- A: amplitud
- f: frecuencia
- t: tiempo
- θ: la fase, que si es inicial será 0,

Una señal se puede definir como el sumatorio de las ondas senoidales, el espectro es el conjunto de frecuencias que componen una señal y el ancho de banda es la anchura de este.  
Cuantos más componentes de secuencia se añadan al sumatorio más se acerca el resultado a la realidad.  
No hacen faltas todos los componentes pero si una cierta cantidad.

Hay varios problemas principales de transmisión:

- Atenuación: La potencia de la señal decae con la distancia.
- Distorsión el retardo de transmisión varía con la frecuencia.
- Ruido: a la señal se le añaden otras no deseadas, dificultando su transmisión.

La capacidad de transmisión es la capacidad máxima a la que se puede transmitir los datos. A esto afectan la velocidad de transmisión, el ancho de banda, el ruido y la tasa de errores.

La velocidad de transmisión esta limitado por el ancho de banda.  
La capacidad viene dada por:  
![[Pasted image 20240507212331.png]]
  
donde B son las frecuencias y M la cantidad de niveles.

La fórmula de Shannon establece la relación entre la velocidad el ruido y los errores  
![[Pasted image 20240502190247.png]]

Esta relación condiciona la capacidad de señales digitales.  
![[Pasted image 20240502190325.png]]