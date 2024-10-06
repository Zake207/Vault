---
banner: "![[Pasted image 20241006174625.png]]"
banner_y: 0.5
---
# Carrera
```dataview
TASK 
from "Recursos/task_clases" WHERE !completed
```
[[ADD TASK (CLASES)]]
```contributionGraph
title: Contributions
graphType: default
dateRangeValue: 12
dateRangeType: LATEST_MONTH
startOfWeek: 0
showCellRuleIndicators: true
titleStyle:
  textAlign: center
  fontSize: 15px
  fontWeight: normal
dataSource:
  type: PAGE
  value: '"Carrera"'
  dateField: {}
  filters: []
fillTheScreen: false
enableMainContainerShadow: false
cellStyleRules:
  - id: default_b
    color: "#9be9a8"
    min: 1
    max: 2
  - id: default_c
    color: "#40c463"
    min: 2
    max: 5
  - id: default_d
    color: "#30a14e"
    min: 5
    max: 10
  - id: default_e
    color: "#216e39"
    min: 10
    max: 999
mainContainerStyle:
  backgroundColor: "#6b059600"

```
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
```contributionGraph
title: Contributions
graphType: default
dateRangeValue: 12
dateRangeType: LATEST_MONTH
startOfWeek: 0
showCellRuleIndicators: true
titleStyle:
  textAlign: center
  fontSize: 15px
  fontWeight: normal
dataSource:
  type: PAGE
  value: '"Ocio"'
  dateField: {}
  filters: []
fillTheScreen: false
enableMainContainerShadow: false
cellStyleRules:
  - id: default_b
    color: "#9be9a8"
    min: 1
    max: 2
  - id: default_c
    color: "#40c463"
    min: 2
    max: 5
  - id: default_d
    color: "#30a14e"
    min: 5
    max: 10
  - id: default_e
    color: "#216e39"
    min: 10
    max: 999
mainContainerStyle:
  backgroundColor: "#6b059600"

```
## Juegos
``` dataview
list from "Ocio/Juegos" and #índice
```
## Libros
``` dataview
list from "Ocio/Libros"
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
[[Ideas a largo plazo|Ideas a largo plazo]]
```contributionGraph
title: Contributions
graphType: default
dateRangeValue: 12
dateRangeType: LATEST_MONTH
startOfWeek: 0
showCellRuleIndicators: true
titleStyle:
  textAlign: center
  fontSize: 15px
  fontWeight: normal
dataSource:
  type: PAGE
  value: '"Proyectos"'
  dateField:
    type: FILE_CTIME
  filters: []
  countField:
    type: DEFAULT
fillTheScreen: false
enableMainContainerShadow: false
cellStyleRules:
  - id: default_b
    color: "#9be9a8"
    min: 1
    max: 2
  - id: default_c
    color: "#40c463"
    min: 2
    max: 5
  - id: default_d
    color: "#30a14e"
    min: 5
    max: 10
  - id: default_e
    color: "#216e39"
    min: 10
    max: 999
mainContainerStyle:
  backgroundColor: "#6b059600"

```
## Proyectos
``` dataview
list from "Proyectos/Registros"
```
## Recursos adicionales
```dataview
list from "Proyectos/Documentación"
```


