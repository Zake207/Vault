# 📌 Directivas de Documentación en reStructuredText para Python

Este documento resume las directivas más comunes utilizadas en **reStructuredText (reST)** para documentar código Python con **Sphinx**.

---

## 🔹 1. Directivas Básicas

### `:param <nombre>: <descripción>`
Documenta un parámetro de una función.

```python
:param a: Primer número.
:param b: Segundo número.
```

### `:type <nombre>: <tipo>`
Especifica el tipo de un parámetro.

```python
:type a: int
:type b: int
```

### `:return: <descripción>`
Describe el valor de retorno.

```python
:return: La suma de `a` y `b`.
```

### `:rtype: <tipo>`
Define el tipo del valor de retorno.

```python
:rtype: int
```

### `:raises <excepción>: <descripción>`
Indica qué excepciones puede lanzar la función.

```python
:raises ZeroDivisionError: Si `b` es cero.
```

---

## 🔹 2. Directivas Avanzadas

### `:var <nombre>: <descripción>`
Documenta una variable dentro de un módulo o clase.

```python
:var PI: Valor de pi (aproximado).
:var VERSION: Versión del software.
```

### `:note:`
Agrega una nota informativa.

```python
:note: Esta función usa el operador `**`.
```

### `:warning:`
Resalta una advertencia importante.

```python
:warning: No usar exponentes negativos con enteros grandes.
```

### `:seealso:`
Referencia a funciones o documentación relacionada.

```python
:seealso: `math.pow` para una alternativa con `float`.
```

---

## 🔹 3. Ejemplo Completo

```python
def dividir(a, b):
    """
    Realiza una división entre dos números.

    :param a: Numerador.
    :type a: float
    :param b: Denominador.
    :type b: float
    :return: Resultado de la división.
    :rtype: float
    :raises ZeroDivisionError: Si `b` es cero.
    """
    if b == 0:
        raise ZeroDivisionError("No se puede dividir por cero")
    return a / b
```

---

## 🔹 4. Tabla Resumen

| Directiva                            | Descripción                                         |
| ------------------------------------ | --------------------------------------------------- |
| `:param <nombre>: <descripción>`     | Describe un parámetro.                              |
| `:type <nombre>: <tipo>`             | Especifica el tipo de un parámetro.                 |
| `:return: <descripción>`             | Explica el valor de retorno.                        |
| `:rtype: <tipo>`                     | Indica el tipo de dato del retorno.                 |
| `:raises <excepción>: <descripción>` | Documenta excepciones lanzadas por la función.      |
| `:var <nombre>: <descripción>`       | Documenta variables en módulos o clases.            |
| `:note:`                             | Agrega una nota informativa.                        |
| `:warning:`                          | Resalta una advertencia importante.                 |
| `:seealso:`                          | Referencia a funciones o documentación relacionada. |

