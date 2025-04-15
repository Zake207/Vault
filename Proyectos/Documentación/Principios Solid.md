## Single responsibility principle

Una clase debe ser responsable de una única tarea, manteniéndola lo más simple posible, sin llegar a simplificarla demasiado para no aumentar el número de estas.

Por lo que si se empieza a complicar demasiado la clase se deben delegar las funcionalidades que se quieran añadir en otra clase.

## Open-closed principle

Toda clase debe estar abierta a la extensión y cerrada a la modificación. Las funcionalidades a añadir se deben implementar a una clase que extiende la clase original, añadiendo la funcionalidad en esta.

-  Es importante seguir esta.

## Liskov substitution principle

Dada una clase, al tener subclases de esta, sustituir en cualquier parte del código la clase principal por cualquiera de las subclases, el código cliente debe seguir funcionando igual.

## Interface segregation principle

Tener una interfaz para cada funcionalidad, en cierto modo sigue el primer principio pero aplicado a interfaces.

## Dependency inversion principle

Una clase que por ejemplo implemente un algoritmo, solo debe depender de clases superiores en la jerarquía, es decir una clase abstracta por ejemplo.

-  Podría decirse que es la más importante

A continuación un ejemplo:
```ts title:example.ts
abstract class Individual {
  constructor(protected decisionVariables: unknown[]) {

  }
  abstract getDecisionVariables(): unknown[];
}

class NumericIndividual extends Individual {
  constructor(decisionVariables: number[]) {
    super(decisionVariables)
  }
  getDecisionVariables(): number[] {
    return this.decisionVariables as number[];
  }
}

class BooleanIndividual extends Individual {
  constructor(decisionVariables: boolean[]) {
    super(decisionVariables)
  }
  getDecisionVariables(): boolean[] {
    return this.decisionVariables as boolean[];
  }
}

class EvolutionaryAlgorithm {
  constructor(private population: Individual[]) {
  }
  runGeneration() {
    this.population.forEach((individual)=> {
      individual.getDecisionVariables();
    });
  }
}
```