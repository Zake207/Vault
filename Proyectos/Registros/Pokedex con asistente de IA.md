#project 
# Introducción
## Ideas
Crear una aplicación de escritorio en python que realice las siguientes tareas:
+ Realizar consultas con una API que de información sobre pokemons a partir de información oficial.
+ Tratar de crear un sistema de logeo para implementar una api propia y asentar bases teóricas sobre bases de datos
+ Integrar inteligencia artificial para crear un asistente que permita dar sugerencias sobre este pokemon, estrategias, ataques, compañeros, debilidades, etc...

## Objetivos
+ Profundizar en mis conocimientos sobre python y las aplicaciones de escritorio
+ Aprender las interacciones básicas de una API
+ Aprender a integrar IA en aplicaciones de escritorio
+ Profundizar en herramientas, tecnologías y conceptos genéricos

## Tecnologías a usar
+ **Python**
+ **Frameworks de aplicaciones de escritorio**
+ **APIs**
+ **IA** 
+ **Linter**
+ **Manejador de paquetes (Conda o Node)**
+ **Coverall**
+ **Principios solid**
+ **Tests unitarios**
+ **Documentación**
# Desarrollo
## Elección de herramientas y tecnologías
### Lenguaje y frameworks
Se usará **Python** para desarrollar el proyecto, este usará librerías de uso común como *numpy, collections, etc...* además para desarrollar la aplicación de escritorio usará la librería *PyQT* debido a que es una de las más populares, aunque *PySide* es una opción viable debido a problemas de licencias que se pueda tener a futuro.

Para comunicarme con una API, y aprender como funcionan estas debo desarrollar una API sencilla que se comunique con las otras APIs por esto descargaré *FastAPI* y *uvicorn*

Después toca comunicarme con la inteligencia artificial se debe instalar la librería *openai* o realizar consultas a deepseek, sin embargo esta requiere de una suscripcion por lo que tengo en cuenta opciones como *ollama* o *llm studio* sin embargo la primera no es eficiente en terminos de uso, tengo que investigar otras opciones.
Finalmente la opción que utilice fue usar una de las APIs proporcionadas por *openrouter* en concreto 

### Funcionalidades
1. Dar dato de pokemon aleatorio
2. Buscar pokemon con opciones de filtrado
3. Sugerir estrategias al asistente de IA
4. Guardar un historial de búsquedas que se pueda mostrar
5. Guardar fichas con anotaciones hechas por el usuario y por la IA, destacando una de otra.

## Observaciones
Los json devueltos por la PokeAPI tienen los siguientes campos principales:
+ abilities
+ cries
+ forms
+ game_indices
+ held_items
+ height
+ weight
+ base_experience
+ moves
+ name
+ sprites
+ stats

Para trabajar con esta info es recomendable usar la variable en lugar de guardarlo en fichero, y cuando lo vaya a guardar en fichero tratar de formatear el json.

La inteligencia artificial no opera correctamente con los nombres de pokemon mal esccritos por lo que puedo usar la pokeapi para filtar o asegurarme de que use solo los nombres de pokemon bien escritos, además funciona en markdown, por lo que me va a permitir guardar los ficheros en ese formato legible.

Ahora para profundizar en el funcionamiento de una API debo barajar la posibilidad de desarrollar una API, ya sea para comunicarme con una base de datos o para comunicarme con las 2 API ya desarrolladas, **Destacar que es es contraproducente en un proyecto real**
