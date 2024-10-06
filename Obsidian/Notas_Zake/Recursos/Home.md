---
banner: "![[Pasted image 20241006174625.png]]"
banner_y: 0
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
[[Fechas importantes]]

___
# Proyectos
## Ideas
```dataview
TASK
from "Recursos/task_proyectos" WHERE !completed
```
[[ADD TASK (PROYECTOS)]]

[[Ideas a largo plazo|Ideas a largo plazo]]
## Proyectos
``` dataview
list from "Proyectos/Registros"
```
## Recursos adicionales
```dataview
list from "Proyectos/Documentación"
```


