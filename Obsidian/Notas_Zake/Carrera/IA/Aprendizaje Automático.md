+ [[Introducción_sistemas_aprendizaje.pdf]]
+ [[Introducción_IA_generativa.pdf]]
+ [[Redes_neuronales_parte1.pdf]]
+ [[Redes_neuronales_parte2.pdf]]
---
# Conceptos Básicos
## Definición
También llamado machine learning, trata de desarrollar computadoras que aprendan tras ciertas experiencias.

El aprendizaje se lleva a cabo mediante una serie de ejemplos que se les da para que una vez llegue un nuevo caso, en base a lo aprendido, sabrá responder de la mejor manera posible.
![[Pasted image 20241113104712.png]]

A lo largo de la historia desde 1943 se han hecho avances en el campo como la creación de *The Shark*, el primer neurocomputador, *Perceptrons* por Frank Rosenblatt en 1957, *Cybertron* en 1960s.
[Visualizador de algortimos](https://phiresky.github.io/kogsys-demos/neural-network-demo/?preset=Rosenblatt%20Perceptron)

Este campo de la inteligencia artificial toca áreas como la estadística, la IA generativa, DeepLearning, BigData, Minería de Datos y otros como redes neuronales.
## Paradigmas del aprendizaje
### Supervisado
+ Se le presentan entradas y salidas deseadas
+ Aprende reglas que mapean las entradas a las salidas
+ Se usa en problemas de clasificación y aproximación
### No supervisado
+ Se presentan solo entradas
+ Trata de encontrar las estructuras de las entradas
+ Se usa para extracción de características y agrupamiento
### Por refuerzo
+ Se presentan entradas y una recompensa o castigo
+ Trata de maximizar la recompensa
+ Se usa en problemas de control
## Modelos
+ Redes neuronales artificiales
+ Árboles de decisión
+ Algoritmos de agrupamiento
+ Procesos Gauss
+ Redes Bayesianas
## Fases de desarrollo
![[Pasted image 20241113112407.png]]
## Limitaciones
+ Sobreajustes
+ Costo de entrenamientos
+ Explicabilidad
+ Falta de datos
## Requerimientos
En términos de **Hardware** se requieren tarjetas gráficas, infraestructuras de aprendizaje en la nube y chips específicos.
En lo que conscierne al **Software** los lenguajes de programación predilectos son Python, R y Matlab con las librerías PyTorch, TensorFlow o Keras.

# IA Generativa
## Características
Tipo de ia que genera texto, imágenes y otros medios.
+ Generan un salida como respuesta a un prompt.
+ La respuesta se basa en sus patrones de entrenamiento, de los cuales aprenden.
+ Usan paradigmas de no supervisado o auto-supervisado.

Existen varios modelos:
+ **Autocodificador variacional**: Contiene un cuello de botella en su entrada que la comprime y decodifica.
+ **GAN**: contiene dos redes neuronales que compiten en un juego de suma 0, compiten entre ellos para mejorar.
+ **LSTM**: Red neuronal recurrente que aborda el problema de desvanecimiento de gradiente, aprende dependencias a largo plazo en secuencias de datos, permite que entradas hechas hace tiempo sean recordadas.
+ **Trasformer**: Da un peso diferente a cada parte de la entrada.
+ **LLM**: Variante del anterior con un corpus textual de gran tamaño.

Las modalidades de entrenamiento pueden ser unimodales o multimodales según los tipos de entrada que acepten, los principales tipos son:
+ Texto
+ Código
+ Imágenes
+ Música
+ Moléculas
+ Vídeo
+ Acciones
+ Modelos 3D

## LLM
Un ML (Modelo de lenguaje) trata de predecir la siguiente palabra de un documento. Un LLM es un ML con muchos parámetros y entrenado con grandes cantidades de texto sin etiquetar.

Puede capturar gran parte de sintáxis y semántica humana, tiene capacidad de memorización. A medida que crece posibilita la aparición de habilidades emergentes.

Cuenta con varias fases:
+ **Tokenización**: La palabra de entrada se transforma en tokens(números). La salida es una distribución de probabilidad sobre el vocabulario de tokens.
+ **Entenamiento**: Se da un conjunto de entrenamiento con billones de tokens de texto para que prediga el conjunto de datos.
+ **Tareas posteriores** Se hace un entreno supervisado para una acción en específica. Después se proporcionan ejemplos de resolución.

**Ejemplos**:
![[Pasted image 20241120110624.png]]

## Prompting
Texto en lenguaje natural que describe la tarea a realizar. El proceso para etructurarlo se llama *Prompt Engineering*.
El Aprendizaje en contexto permite al modelo aprender temporalmente en base a indicaciones.

+ Consulta directa
+ Orden específica
+ Declaración larga que incluya contexto

Las **cadenas de pensamiento** instruye al LLM para que explique paso a paso el proceso de resolución de un problema, antes de dar la respuesta.

La **solicitud de conocimiento generado** pide al LLM que cree información relacionada con la consulta para usar sus propia respuesta.

**Indicación de menor a mayor** resuelve el problema paso a paso desde lo más simple hasta lo más complejo.

**Texto a imagen** recoge entradas descriptivas con estilo, iluminación, color, etc...

Los principales problemas de estas inteligencias artificiales son: la pérdida de empleo, Deepfakes,
Cibercrímenes, coste de los entrenamientos, calidad del contenido, la regulación y el daño a la propiedad intelectual.
# Red neuronal
Es un procesador distribuido que tiende a almacenar conocimiento en base a su experiencia para usarlo posteriormente.
+ Usa un proceso de aprendizaje.
+ La fuerza de conexión entre neuronas (peso sináptico) se usa para almacenar.

Una red neuronal artificial tiene ciertos puntos en común con las redes neuronales biológicas:
+ El procesamiento ocurre en elementos simples llamados neuronas.
+ Las señales se transmiten entre estas por enlaces.
+ Cada uno tiene un peso que multiplica la señal.
+ Cada neurona aplica una función de activación a su entrada de red para determinar su salida.

Cuentan con un algoritmo de aprendizaje que modifica los pesos de un modo ordenado para alcanzar el objetivo deseado.

A diferencia que su inspiración biológicas las redes neuronales artificiales no cuentan con muerte neuronal y están optimizadas para distintos problemas.

![[Pasted image 20241127110005.png]]

Las RNA poseen las siguientes capacidades
![[Pasted image 20241127111440.png]]

+ Arquitectura: Sigue una estructura de capas y patrón generalizado.
+ Modelo de neurona: Función de suma y activación.
+ Algoritmo de aprendizaje: Métodos de definición de los pesos.

## Neurona
Una neurona tiene un grupo de entradas, pesos, función de suma, función de activación, una salida y una función de aprendizaje.

![[Pasted image 20241206201424.png]]

![[Pasted image 20241206201449.png]]

## Arquitecturas de red
+ **Según e/o/s**: Posee número y tipo de entradas, elementos ocultos, elementos de salida.
+ **Según la conectividad entre capas**: Puede ser *feedforward*,*Redes Recurrentes*, *Lattice*.
+ **Según conexión entre capas**: Pueden ser *Totalmente conectados*, *Parcialmente conectados*, *Conectados 1 a 1*.
+ **Sincronía**: Existen varios tipos como *Simultánea*, *Aleatoria* o *Según orden topológico*.

![[Pasted image 20241206202532.png]]

![[Pasted image 20241206202602.png]]

![[Pasted image 20241206202616.png]]

## Aprendizaje
### Eventos
+ Estimulación de la red por el entorno
+ Cambios en la red por la estimulación
+ Nueva forma de responder debido a los cambios de la estructura interna, lo que repite el ciclo

### Taxonomía
#### Paradigmas de aprendizaje:
+ Aprendizaje supervisado
+ Aprendizaje por Reforzamiento
+ Aprendizaje Auto-organizado
+ Precalculado o prefijado
#### Algoritmos de aprendizaje
+ Corrección del error
+ Optimización de la energía
+ Hebbiano
+ Competitivo
#### Otros
+ local vs global
+ por dato vs por época (batch)
+ valores iniciales vs pesos
### Aprendizaje supervisado
Se presentan pares de patrones de entrada y de salida.
• Fijar pesos aleatorios las conexiones 
• Seleccionar par de entrenamiento 
• Presentar patrón de entrada y calcular salida 
• Calcular error o discrepancia con la salida deseada 
• Aplicar regla de aprendizaje

Este método requiere propagar información hacia atrás y requiere de un instructor.
### Aprendizaje no supervisado
Se presentan solo patrones de entrada y se basa en la redundancia de las entradas
El aprendizaje extrae los siguientes patrones:
• Familiaridad con patrones típicos o promedios del pasado 
• Análisis de las Componentes Principales 
• Clustering 
• Prototipos, correspondientes a las categorias existentes 
• Codificación 
• Mapa de Características

## Problemas
• Aproximación 
• Asociación 
• Clasificación de Patrones 
• Predicción 
• Control


Se debe disponer de una gran cantidad de datos.
Es difícil describir el conocimiento y la forma de resolver los problemas.
## Codificación entrada salida
#### Tipo de señal
– Global vs. local 
– Discretas vs. continuas
#### Relación
– Leer salida para cada entrada 
– Evolución de la salida ante la entrada
#### Preparación de los datos
– Diseño de conjuntos de entrenamiento y testeo 
– Longitud de la distribución (Grandes conjuntos) 
– Eliminación de información redundante e irrelevante 
	• Manualmente 
	• Preproceso de reducción de datos (extracción de características) 
– PCA, Momentos de Zernike, ... 
– Centrado, escalado o normalización 
– Eliminación de no-linealidades conocidas
## Software
![[Pasted image 20241208221814.png]]

# Modelos
## Perceptrón simple
Es una RN de una capa de cómputo, con entradas reales y salidas bipolares o binarias.
Posee el siguiente modelo:
![[Pasted image 20241209110000.png]]

Utiliza el aprendizaje supervisado mediante corrección de error, su ajuste de pesos es el siguiente: $$\Delta w_{ij} = \alpha\ ·\ e_{j}\ ·\ x_{i}$$
Siendo:
+ $\alpha$: Radio de aprendizaje
+ $e_{j}$: Error ajustado a \[-1, 0, 1\]

### Algoritmo de aprendizaje
1. Se inicializan los pesos y bias ∈ {-1,0,1}, 0 < α ≤ 1,0
2. Repetir para cada patrón hasta que no se modifiquen los pesos.
	+ Calcular salida de cada neurona.
	![[Pasted image 20241209111125.png]]
	+ Modificar los pesos de cada conexión ij.
	![[Pasted image 20241209111144.png]]

#### Ejemplo
![[Pasted image 20241209111244.png]]

![[Pasted image 20241209111304.png]]
![[Pasted image 20241209111317.png]]

### Separabilidad lineal
![[Pasted image 20241209111423.png]]

### Teorema de convergencia
*Si existe un vector de pesos w\* tal que para todo patron p, perteneciente a un conjunto de patrones de entrenamiento P, tenemos que f_act(x(p)·w\*) = d(p).
*Para cualquier vector de pesos inicial, el aprendizaje del preceptrón convergerá en un número finito de pasos a un vector de pesos que da la respuesta correcta a todos los patrones de entrenamiento.*

### Limitaciones
+ Separabilidad lineal
+ Concavidad y convexidad
+ Problemas clásicos como xor y paridad
+ Incapacidad de generalización global en base a ejemplos localmente aprendidos

## Perceptrón multicapa
Soporta una o más capas ocultas, tiene entradas binarias o reales y salidas binarias aproximadas por una función continua no lineal.

El modelo de la neurona es la siguiente:
![[Pasted image 20241209120225.png]]

También sigue un aprendizaje supervisado mediante corrección de error.
Además usa un ajuste de pesos por retropropagación del error.$$\Delta w_{ij} = \alpha\ ·\ \delta_{j}\ ·\ x_{i}$$
Donde $\delta_{j}$ es un coeficiente de error calculado para cada capa y $\alpha$ el radio de aprendizaje.

### Algoritmo de aprendizaje
1. Inicializar pesos y bias
2. Repetir para cada patrón, hasta dar con un error pequeño o se alcance nmi
	+ Para cada capa, calcular la salida de cada neurona j
	![[Pasted image 20241209121919.png]]
	+ Para cada conexión ij da la capa de salida
	![[Pasted image 20241209121934.png]]
	+ Para cada conexión ij de las capas anteriores
	![[Pasted image 20241209121954.png]]


### Obtención de la regla
![[Pasted image 20241209122204.png]]
![[Pasted image 20241209122222.png]]
![[Pasted image 20241209122259.png]]

### Elecciones
#### Número de capas ocultas
Una suele bastar pero más capas facilitan el trabajo
#### Número de neuronas ocultas
Cuanto menos menor, puesto que mejora el aprendizaje, la capacidad de generalización y disminuye la probabilidad de parálisis. Además se usan técnicas de creación y eliminación de neuronas.
#### Funciones de activación
En capas ocultas son no lineales mientras que en capas de salida depende de los valores deseados.
#### Número de pares de entrenamiento
Habiendo P numero de patrones, W numeros de pasos y $\epsilon$ fracción del error se tiene P > W/$\epsilon$.
También se usan Shuffled de patrones.
#### Inicialización de pesos y bias
+ Influyen en alcanzar el error global o local y la velocidad con la que se alcanza.
+ Si se dan valores grandes se satura
+ Si se dan valores pequeños ralentiza el sistema
#### Radios de aprendizaje
– Grande == parálisis o inestabilidad 
– Pequeños == lentitud en aprendizaje 
– Ratios adaptivos (RMSProp, Hinton (2012))
#### Función de pérdida a minimizar
– Error cuadrático medio (MSE de Mean Squared Error) 
– Cross-entropy loss
#### Tiempo de aprendizaje
– Hasta que el error sea menor que cota definida a priori 
– Hasta que pendiente de error sea menor que cota definida a priori 
– Hasta que pendiente de pesos sea menor que cota definida a priori 
– Jugar con 2 conjuntos, mientras no empeore el error de testeo (Early stopping)

### Variantes
![[Pasted image 20241209125542.png]]
### Desventajas
+ Convergencia no demostrada
+ Lento proceso de aprendizaje
+ Incertidumbre en la convergencia debido a la parálisis de red y a mínimos locales.