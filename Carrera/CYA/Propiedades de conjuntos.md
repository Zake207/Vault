A continuación te enlisto las principales **propiedades de los conjuntos**, que también aplican en el contexto de lenguajes formales. Estas propiedades describen cómo interactúan las operaciones de unión, intersección, complemento y diferencia entre conjuntos.

### 1. **Propiedades Idempotentes**
- **Unión**: \( A ∪ B = A \)
- **Intersección**: \( A ∩ A = A \)

### 2. **Propiedades con el conjunto vacío y el conjunto universal**
- **Unión con el conjunto vacío**: \( A \cup ∅ = A \)
- **Intersección con el conjunto vacío**: \( A \cap \emptyset = \emptyset \)
- **Unión con el conjunto universal**: \( A \cup U = U \) (donde \( U \) es el conjunto universal)
- **Intersección con el conjunto universal**: \( A \cap U = A \)
- **Complemento del conjunto vacío**: \( \overline{\emptyset} = U \)
- **Complemento del conjunto universal**: \( \overline{U} = \emptyset \)

### 3. **Propiedad conmutativa**
- **Unión**: \( A \cup B = B \cup A \)
- **Intersección**: \( A \cap B = B \cap A \)

### 4. **Propiedad asociativa**
- **Unión**: \( (A \cup B) \cup C = A \cup (B \cup C) \)
- **Intersección**: \( (A \cap B) \cap C = A \cap (B \cap C) \)

### 5. **Propiedad distributiva**
- **Distributividad de la unión sobre la intersección**: \( A \cup (B \cap C) = (A \cup B) \cap (A \cup C) \)
- **Distributividad de la intersección sobre la unión**: \( A \cap (B \cup C) = (A \cap B) \cup (A \cap C) \)

### 6. **Propiedades de absorción**
- **Unión**: \( A \cup (A \cap B) = A \)
- **Intersección**: \( A \cap (A \cup B) = A \)

### 7. **Leyes de De Morgan**
- **Primera ley de De Morgan**: \( \overline{A \cup B} = \overline{A} \cap \overline{B} \)
- **Segunda ley de De Morgan**: \( \overline{A \cap B} = \overline{A} \cup \overline{B} \)

### 8. **Propiedades del complemento**
- **Doble complemento**: \( \overline{(\overline{A})} = A \)
- **Complemento del vacío**: \( \overline{\emptyset} = U \)
- **Complemento del conjunto universal**: \( \overline{U} = \emptyset \)

### 9. **Propiedad de la diferencia**
- **Definición**: La diferencia entre dos conjuntos \( A \) y \( B \) (también llamada resta de conjuntos) es \( A - B = \{x \mid x \in A \text{ y } x \notin B \} \).
  - **Relación con la intersección**: \( A - B = A \cap \overline{B} \)

### 10. **Propiedad del complemento relativo**
- **Complemento relativo** (diferencia de conjuntos): \( A - B = A \cap \overline{B} \)

### 11. **Propiedad de la intersección de complementos**
- Si \( A \subseteq B \), entonces \( A \cap \overline{B} = \emptyset \).

### 12. **Propiedades de la inclusión**
- **Inclusión reflexiva**: \( A \subseteq A \)
- **Inclusión anti-simétrica**: Si \( A \subseteq B \) y \( B \subseteq A \), entonces \( A = B \)
- **Inclusión transitiva**: Si \( A \subseteq B \) y \( B \subseteq C \), entonces \( A \subseteq C \)

### 13. **Propiedad de la diferencia simétrica**
- **Definición**: La diferencia simétrica entre \( A \) y \( B \), denotada \( A \triangle B \), es el conjunto de los elementos que están en \( A \) o en \( B \), pero no en ambos:
  \[
  A \triangle B = (A \cup B) - (A \cap B) = (A - B) \cup (B - A)
  \]

### 14. **Principio de inclusión-exclusión**
- La cardinalidad de la unión de dos conjuntos es:
  \[
  |A \cup B| = |A| + |B| - |A \cap B|
  \]
  Para tres conjuntos:
  \[
  |A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|
  \]

### Resumen:
Estas son las propiedades principales que gobiernan cómo interactúan los conjuntos bajo las operaciones de unión, intersección, complemento, y diferencia. Son fundamentales en teoría de conjuntos y se utilizan en diversos contextos, como lenguajes formales y lógica.