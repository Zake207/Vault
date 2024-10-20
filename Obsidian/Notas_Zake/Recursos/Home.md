---
banner: "![[Pasted image 20241006174625.png]]"
banner_x: 0.40875
---

```contributionGraph
title: Contributions
graphType: default
dateRangeValue: 12
dateRangeType: LATEST_MONTH
startOfWeek: 0
showCellRuleIndicators: true
titleStyle:
  textAlign: center
  fontSize: 25px
  fontWeight: normal
dataSource:
  type: PAGE
  value: ""
  dateField: {}
  filters: []
fillTheScreen: true
enableMainContainerShadow: false
cellStyleRules:
  - id: Ocean_a
    color: "#8dd1e2"
    min: 1
    max: 2
  - id: Ocean_b
    color: "#63a1be"
    min: 2
    max: 3
  - id: Ocean_c
    color: "#376d93"
    min: 3
    max: 5
  - id: Ocean_d
    color: "#012f60"
    min: 5
    max: 9999
mainContainerStyle:
  backgroundColor: "#6b059600"
cellStyle:
  minWidth: 9px
  minHeight: 9px

```
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


___

# Ocio
``` dataview
TASK
from "Recursos/task_ocio" WHERE !completed
```
[[ADD TASK (OCIO)]]
## Pasatiempos
``` dataview
list from "Ocio/Pasatiempos" and #índice
```
## Social
``` dataview
list from "Ocio/Social"
```


___

# Proyectos
## Ideas
```dataview
TASK
from "Recursos/task_proyectos" WHERE !completed
```
[[ADD TASK (PROYECTOS)]]
## Proyectos
``` dataview
list from "Proyectos/Registros" and #project
```
## Recursos adicionales
```dataview
list from "Proyectos/Documentación" and #índice 
```

## [[Trabajo]]

