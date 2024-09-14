---
banner: "![[depositphotos_323952574-stock-illustration-synthwave-sunset-background-80s-sun.webp]]"
banner_y: 0.526
---
# Carrera
```dataview
TASK 
from "Recursos/task_clases" WHERE !completed
```
[[ADD TASK (CLASES)]]
### 2 año
``` dataview
list from "Carrera" and #índice and #carrera_año2 
```

### 3 año
``` dataview
list from "Carrera" and #índice and #carrera_año3 
```
### 4 año
``` dataview
list from "Carrera" and #índice and #carrera_año4 
```
# Ocio
``` dataview
TASK
from "Recursos/task_ocio" WHERE !completed
```
[[ADD TASK (OCIO)]]
## Libros
``` dataview
list from "Libros"
```
## Ideas
``` dataview
list from "Ocio" and #índice
```

___
# Proyectos
## Tareas
```dataview
TASK
from "Recursos/task_proyectos" WHERE !completed
```
[[ADD TASK (PROYECTOS)]]
## Documentos
``` dataview
list from "Proyectos"
```
## Recursos adicionales
[[Python]]
