---
banner: "![[Pasted image 20241006174625.png]]"
banner_y: 0.706
---

---

```contributionGraph
title: Contributions
graphType: default
dateRangeValue: 7
dateRangeType: LATEST_MONTH
startOfWeek: "1"
showCellRuleIndicators: true
titleStyle:
  textAlign: center
  fontSize: 25px
  fontWeight: normal
dataSource:
  type: PAGE
  value: ""
  dateField:
    type: FILE_CTIME
  filters: []
fillTheScreen: true
enableMainContainerShadow: false
cellStyleRules:
  - id: default_b
    color: "#a76fd9ff"
    min: 1
    max: 2
  - id: default_c
    color: "#7c44adff"
    min: 2
    max: 5
  - id: default_d
    color: "#5a238aff"
    min: 5
    max: 10
  - id: default_e
    color: "#3c0d65ff"
    min: 10
    max: 999
mainContainerStyle:
  backgroundColor: "#6b059600"
cellStyle:
  minWidth: 15px
  minHeight: 15px
  borderRadius: 0%

```
---
# Carrera

## 2 año
``` dataview
list from "Carrera" and #índice and #carrera_año2 
```
## 3 año
[[1º cuatri_tercero.pdf|1º cuatrimestre]]
``` dataview
list from "Carrera" and #índice and #carrera_año3 and #cuatri_1 
```

[[2º cuatri_tercero.pdf|2º cuatrimestre]]
``` dataview
list from "Carrera" and #índice and #carrera_año3 and #cuatri_2 
```
## 4 año
``` dataview
list from "Carrera" and #índice and #carrera_año4 
```

# Ocio

``` dataview
list from "Ocio/Pasatiempos" and #índice
```

# Proyectos
## Proyectos
``` dataview
list from "Proyectos/Registros" and #project
```
## Recursos adicionales
```dataview
list from "Proyectos/Documentación" and #índice 
```

## Ideas
[[Migración a Arch (portátil)]]
[[Aniversario]]


