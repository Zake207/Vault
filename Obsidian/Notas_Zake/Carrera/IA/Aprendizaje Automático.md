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

## IA Generativa
### Características
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

### LLM
Un ML (Modelo de lenguaje) trata de predecir la siguiente palabra de un documento. Un LLM es un ML con muchos parámetros y entrenado con grandes cantidades de texto sin etiquetar.

Puede capturar gran parte de sintáxis y semántica humana, tiene capacidad de memorización. A medida que crece posibilita la aparición de habilidades emergentes.

Cuenta con varias fases:
+ **Tokenización**: La palabra de entrada se transforma en tokens(números). La salida es una distribución de probabilidad sobre el vocabulario de tokens.
+ **Entenamiento**: Se da un conjunto de entrenamiento con billones de tokens de texto para que prediga el conjunto de datos.
+ **Tareas posteriores** Se hace un entreno supervisado para una acción en específica. Después se proporcionan ejemplos de resolución.

**Ejemplos**:
![[Pasted image 20241120110624.png]]

### Prompting
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

