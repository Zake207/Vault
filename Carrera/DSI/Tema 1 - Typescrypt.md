# 1. Anotaciones básicas sobre proyectos

**Recursos**
[[PDF1.pdf|PDF]]
___
## Depuración de proyectos
Para depurar se debe generar un fichero en la parte de configuración launch.json, luego en dicho fichero cambiar el target al .js

Se puede activar una opción de mapeo para que depurando el .js, te muestre la equivalencia en el .ts

**ANOTACIÓN -> USAR === SOBRE == EN COMPROBACIONES, ES MEJOR EN TS Y JS**

# 2. Tipos de variables

**Recursos**
[[PDF2.pdf|PDF]]
___
## Conceptos
Usa tipado dinámico, por lo que cambia según lo que se le asigne.
``` ts
let myVar;
console.log(`${myVar} = ${typeof myVar}`);
myVar = 12;
console.log(`${myVar} = ${typeof myVar}`);
myVar = "Hello";
console.log(`${myVar} = ${typeof myVar}`);
myVar = true;
console.log(`${myVar} = ${typeof myVar}`);
```

Existen los siguientes tipos:
+ number: representa valores numéricos.
- string: representa cadenas de caracteres.
- boolean: toma los valores lógicos `true` y `false`.
- symbol: representa valores constantes únicos.
- null: solo puede tomar el valor `null` e indica una referencia que no existe o no válida.
- undefined: este tipo (y valor) es el que toma una variable que se ha definido pero a la que no se ha asignado valor alguno.
- object: representa valores complejos, formados por pares propiedad–valor.
## Anotaciones e inferencia de tipo
Si se desea declarar una variable con tipo estático se debe usar las etiquetas de tipo:

``` ts title:example.ts
function add(firstNum: number, secondNum: number): number {
  return firstNum + secondNum;
}

const myConst: number = 7;
let myResult: number = add(1, myConst);
console.log(`myResult = ${myResult}`);
```

Cabe destacar que el compilador de Typescrypt infiere algunos tipos de variables, si quitásemos la etiqueta de la declaración de myConst y myResult, por ejemplo.

En caso de no coincidir los valores pasados con los anotados mostrará un error.

**Buena práctica:** Usar las anotaciones todo lo posible.

En el compilador del código existe una opción para mostrar los tipos de datos que se están usando en un fichero de tipo file.d.js
``` json
{
  "compilerOptions": {
    "target": "es2024",
    "module": "commonjs",
    "rootDir": "./src",
    "declaration": true,
    "outDir": "./dist"
  }
}
```
## Tipo de dato any
Indica que una variable es de cualquier tipo.

Por lo general suele llevar a errores el permitir que el compilador infiera el tipo any de manera implicita

**PREFERENTEMENTE EVITAR USARLO**

Puesto que su uso es básicamente programar en javascrypt y typescrypt nos provee de herramientas necesarias para evitar usar este tipo.

En el compilador hay una opción `noImplicitAny` que se recomienda tener activada.

Se puede asignar a todo.
## Uniones de tipos
También conocido como *type-narrowing*

En las uniones no se puede acceder a las propiedades que son exclusivas de dichos tipos, es decir, que si los tipos no comparten dicha propiedad, la unión no permite usarla.

Ejemplo de Unión
``` ts
function add(firstNum: number, secondNum: number,
    isNumber: boolean): number | string {
  return isNumber ? firstNum + secondNum : (firstNum + secondNum).toFixed(2);
}

let myResult = add(1, 7, true);
console.log(`myResult = ${myResult}`);
myResult = add(1, 7, false);
console.log(`myResult = ${myResult}`);
```
## Tipos literales
Permiten definir los valores que se deben pasar especificamente, por ejemplo:
``` ts
function add(firstNum: number, secondNum: number,
    conversionMode: "asNumber" | "asString"): number | string {
  if (conversionMode === "asNumber") {
    return firstNum + secondNum;
  }
  return (firstNum + secondNum).toFixed(2);
}

let myResult = add(1, 7, "asNumber");
console.log(`myResult = ${myResult}`);
myResult = add(1, 7, "asString");
console.log(`myResult = ${myResult}`);
myResult = add(1, 7, "asWhatever");
console.log(`myResult = ${myResult}`);
```

Esto dará una salida tal que:
``` ts
src/index.ts:13:22 - error TS2345: Argument of type '"asWhatever"' is not assignable to parameter of type '"asNumber" | "asString"'.

13 myResult = add(1, 7, "asWhatever");
                        ~~~~~~~~~~~~


Found 1 error in src/index.ts:13
```

Facilita en el sentido de que no será necesario recordar que tipo de parámetros pasar, en caso de las string, que es lo que se puede o no puede pasar como parámetros.
## Alias de tipo
Permiten dar alias a tipos de datos uniones de estos.
```ts
type ConversionType = "asNumber" | "asString"; 
type ResultType = number | string; 

function add(firstNum: number, secondNum: number, 
  conversionMode: ConversionType): ResultType { 
	if (conversionMode === "asNumber") { 
		return firstNum + secondNum; 
	} 
	return (firstNum + secondNum).toFixed(2); 
} 

let myResult = add(1, 7, "asNumber"); 
console.log(`myResult = ${myResult}`); 
myResult = add(1, 7, "asString"); 
console.log(`myResult = ${myResult}`);
```


## Afirmaciones de tipo
Tamvién conocido como *type assertion*
Se usan cuando se tiene claro que va a devolver determinada función, permite afinar el código.

``` ts
function add(firstNum: number, secondNum: number,
    isNumber: boolean): number | string {
  return isNumber ? firstNum + secondNum : (firstNum + secondNum).toFixed(2);
}

let myNumResult = add(1, 7, true) as number;
console.log(`myNumResult = ${myNumResult}`);
console.log(myNumResult.toFixed(2));
let myStrResult = add(1, 7, false) as string;
console.log(`myStrResult = ${myStrResult}`);
console.log(myStrResult.charAt(0))
```

Si deseara tratar con un tipo que no esta definido, añadiendo las siguientes lineas:
``` ts
let myBoolResult = add(1, 7, false) as boolean;
console.log(`myBoolResult = ${myBoolResult}`);
```

Se obtiene un error, que se puede evitar ampliando la unión de tipos o sustituyendo del ejemplo anterior la primera linea por la siguiente:
``` ts
let myBoolResult = add(1, 7, false) as unknown as boolean;
```
## Guardianes de tipo
Implica el uso de `typeof` para averiguar el tipo de dato de las variables, sirve como alternativa a las afirmaciones de tipo.
``` ts
function add(firstNum: number, secondNum: number,
    isNumber: boolean): number | string {
  return isNumber ? firstNum + secondNum : (firstNum + secondNum).toFixed(2);
}

let myResult = add(1, 7, true);

if (typeof myResult === "number") {
  console.log(`myResult = ${myResult}`);
  console.log(myResult.toFixed(2));
} else if (typeof myResult === "string") {
  console.log(`myResult = ${myResult}`);
  console.log(myResult.charAt(0));
}
```

También se puede usar la sentencia switch en lugar de if-else:
``` ts
function add(firstNum: number, secondNum: number,
    isNumber: boolean): number | string {
  return isNumber ? firstNum + secondNum : (firstNum + secondNum).toFixed(2);
}

let myResult = add(1, 7, true);

switch (typeof myResult) {
  case "number":
    console.log(`myResult = ${myResult}`);
    console.log(myResult.toFixed(2));
    break;
  case "string":
    console.log(`myResult = ${myResult}`);
    console.log(myResult.charAt(0));
    break;
}
```
## Tipo never
Si el guardián de tipo ya a comprobado todas las opciones posibles sin coincidir con ninguna de un valor.

```ts
function add(firstNum: number, secondNum: number,
    isNumber: boolean): number | string {
  return isNumber ? firstNum + secondNum : (firstNum + secondNum).toFixed(2);
}

let myResult = add(1, 7, true);

switch (typeof myResult) {
  case "number":
    console.log(`myResult = ${myResult}`);
    console.log(myResult.toFixed(2));
    break;
  case "string":
    console.log(`myResult = ${myResult}`);
    console.log(myResult.charAt(0));
    break;
  default:
    let result = myResult;
    console.log(`Type was not expected: ${result}`);
}
```

En el default se trata al tipo never, si en lugar de eso se escribiera que haga algo si el tipo es un `bool` sería válido, permitiendo más opciones a añadir.

## Tipo unknown
Tiene preferencia sobre el tipo any, ya que es más seguro que el tipo de datos any.
``` ts
function add(firstNum: number, secondNum: number,
  isNumber: boolean): unknown {
return isNumber ? firstNum + secondNum : (firstNum + secondNum).toFixed(2);
}

let myResult: number = add(1, 7, true);

console.log(myResult);
```

Dado que unknown solo se puede asignar a unknown, el código anterior da un error pues se le esta asignando un valor unknown a un number. Se soluciona haciendo una afirmación de tipo como number en la llamada de la función add en la línea 6.
## Tipo null y undefined
+ null : Representa algo que no existe.
+ undefined : tipo de una variable a la que no se le ha asignado valor en su declaración.

También se pueden asignar a todos los tipos.
```ts
function div(
  numerator: number,
  denominator: number,
  isNumber: boolean,
): number | string {
  if (denominator === 0) {
    return null;
  }
  return isNumber
    ? numerator / denominator
    : (numerator / denominator).toFixed(2);
}

let myResult: number | string = div(1, 0, true);

switch (typeof myResult) {
  case "number":
    console.log(`myResult = ${myResult}`);
    console.log(myResult.toFixed(2));
    break;
  case "string":
    console.log(`myResult = ${myResult}`);
    console.log(myResult.charAt(0));
    break;
  default:
    let result = myResult;
    console.log(`Type was not expected: ${result}`);
}
```

Para evitar esto haciendo uso de una función del compilador llamada `strictNullChecks` en el fichero tsconfig.json. Esto hace que no se puedan asignar estos dos tipos a otro tipo de variable. Activar esta variable prohíbe el uso de una variable antes de inicializarla 
```ts
function div(
  numerator: number,
  denominator: number,
  isNumber: boolean,
): number | string | null {
  if (denominator === 0) {
    return null;
  }
  return isNumber
    ? numerator / denominator
    : (numerator / denominator).toFixed(2);
}

let myResult: number | string | null;
eval("myResult = div(1, 2, true)");

if (myResult !== null) {
  let myNonNullResult = myResult;
  switch (typeof myNonNullResult) {
    case "number":
      console.log(`myNonNullResult = ${myNonNullResult}`);
      console.log(myNonNullResult.toFixed(2));
      break;
    case "string":
      console.log(`myNonNullResult = ${myNonNullResult}`);
      console.log(myNonNullResult.charAt(0));
      break;
  }
} else {
  console.log(`myResult = ${myResult}`);
}
```
Si se desea evitar la emisión de estos errores, pues pueden salir aún estando inicializada, esto debido a el compilador no lo puede ver, se debe usar `!` de la siguiente manera:
``` ts
let myResult!: number | string | null;
```

En el guardián de tipos se debe contemplar la opción de obtener null, la única forma de manejar este tipo es añadir las siguientes lineas en el default del switch:
```ts
default:
    if (myResult === null) {
      console.log(`myResult = ${myResult}`);
    } else {
      let result = myResult;
      console.log(`Type was not expected: ${result}`);
    }
```

Esto es porque al hacer un typeof de null devuelve object, el tipo de un objeto null. Esto no ocurre con los tipos undefined.

Estos dos tipos no cuentan con propiedades ni atributos por lo que incluirlos en una unión de tipos conlleva no usar ninguna de las funcionalidades de los otros tipos unidos. Esto se puede evitar haciendo la siguiente afirmación de tipo no nula:
```ts
let myResult: number | string = div(1, 2, true)!;
```

La cual consiste en añadir `!` al final de la linea donde se desea hacer la afirmación de tipo.
# 3. Funciones

#### Recursos
[[PDF3.pdf|PDF]]
___
Para empezar se asume que se parte de un fichero tsconfig.json con las siguientes características.
```json title:tsconfig.json
{
  "compilerOptions": {
    "target": "ES2024",
    "module": "commonjs",
    "rootDir": "./src" ,
    "declaration": true,
    "outDir": "./dist"
  }
}
```

Ádemas del siguiente fichero en src 
```ts title:index.ts
function add(firstNum, secondNum) {
  return firstNum + secondNum;
}

const mySum = add(1, 7);
console.log(`mySum = ${mySum}`);
```

JavaScrypt no permite la sobrecarga de funciones, si se declaran varias que compartan nombre se queda con la última que se defina. TypeScrypt te indica que estás cometiendo ese error por lo que se debe asignar nombres diferentes.
## Parámetros
El compilador de typescrypt espera que se le pasen el mismo número de argumentos que de parámetros, caso contrario mostrará un error.

## Parámetros opcionales
Los parámetros pueden ser opcionales, de esta manera permite juego a la hora de pasar los parámetros, estos siempre se deben especificar después de los parámetros obligatorios:
```ts title:example.ts
function add(firstNum, secondNum, thirdNum?) { // Esto es un parámetro opcional.
  return firstNum + secondNum + (thirdNum || 0); 
}

let mySum = add(1, 7);
console.log(`mySum = ${mySum}`);

mySum = add(1, 7, 8);
console.log(`mySum = ${mySum}`);
```

Si alteramos el código para hacer opcional el segundo el código fallará pues el compilador no diferencia si se le esta pasando el opcional o el tercero, por lo que al haber dos, interpreta este como el segundo y exige un tercer argumento.

## Parámetros por defecto
También se puede hacer que una función tenga un valor por defecto como se muestra en el siguiente ejemplo:
```ts title:example.ts
function add(firstNum, secondNum, thirdNum = 0) {
  return firstNum + secondNum + thirdNum;
}

let mySum = add(1, 7);
console.log(`mySum = ${mySum}`);

mySum = add(1, 7, 8);
console.log(`mySum = ${mySum}`);
```

Estos parámetros **cuentan como opcionales** por lo que deben ponerse al final de la lista de parámetros, después de los obligatorios.

## Parámetros rest
Una función solo puede tener un parámetro de tipo rest, estos son agrupaciones de 0 o más variables pasadas como parámetros.
Por ejemplo:
```ts title:example.ts
function add(firstNum, secondNum = 0, ...remainingNums) { // Parámetro rest, siempre son del tipo ...var
  return firstNum + secondNum +
         remainingNums.reduce((total, value) => total + value, 0);
}

let mySum = add(1);
console.log(`mySum = ${mySum}`);

mySum = add(1, 7);
console.log(`mySum = ${mySum}`);

mySum = add(1, 7, 8);
console.log(`mySum = ${mySum}`);

mySum = add(1, 7, 8, 10, 23);
console.log(`mySum = ${mySum}`);
```

## Anotaciones
Para evitar que el compilador de TypeScrypt asuma tipo any en los parámetros se pueden hacer anotaciones de tipo en las cabeceras de las funciones, como muestra el ejemplo siguiente:
```ts title:example.ts
function add(firstNum: number, secondNum: number = 0,
    ...remainingNums: number[]) {
  return firstNum + secondNum +
         remainingNums.reduce((total, value) => total + value, 0);
}

let mySum = add(1);
console.log(`mySum = ${mySum}`);

mySum = add(1, 7);
console.log(`mySum = ${mySum}`);

mySum = add(1, 7, 8);
console.log(`mySum = ${mySum}`);

mySum = add(1, 7, 8, 10, 23);
console.log(`mySum = ${mySum}`);
```

## Parámetros nulos
Se puede hacer una llamada a una función pasándole `null` como argumento:
```ts title:example.ts
function add(firstNum: number, secondNum: number = 0,
    ...remainingNums: number[]) {
  return firstNum + secondNum +
         remainingNums.reduce((total, value) => total + value, 0);
}

let mySum = add(1);
console.log(`mySum = ${mySum}`);

mySum = add(null, 7, 8, 10, 23);
console.log(`mySum = ${mySum}`);
```

En esa llamada lo que ocurrirá es que el compilador recibió null en el único parámetro obligatorio, el primero, por lo que dentro de la función se le asignó el valor 0, por lo que la suma resulta en 48.

Si se activa la opción `strictNullChecks` en el fichero `tsconfig.ts`

En caso de querer pasar argumentos nulos pese a esto se deberá usar una unión de tipos como se muestra en el ejemplo.

```ts title:example.ts
function add(firstNum: number | null, secondNum: number = 0,
    ...remainingNums: number[]) {
  if (firstNum !== null) {
    return firstNum + secondNum +
           remainingNums.reduce((total, value) => total + value, 0);
  }
}

let mySum = add(1);
console.log(`mySum = ${mySum}`);

mySum = add(null);
console.log(`mySum = ${mySum}`);
```

Para evitar un aviso del compilador se deberá usar un guardián de tipos.

## Resultados de una función
Analizando `dist/index.d.ts` TypeScrypt infiere el tipo de retorno de la función `add` como la unión de tipos `number | undefined`, dado que al que no hay una sentencia return si se pasa como primer parámetro null, la función devuelve por defecto `undefined`.

Para evitar estos problemas se usa la opción `noImplicitReturn`, de esta manera sale un error si la función no tiene  un return por defecto.

## Anotaciones en el resultado
Se pueden hacer anotaciones de tipo para el resultado del retorno de la función.

```ts title:example.ts
function add(firstNum: number | null, secondNum: number = 0,
    ...remainingNums: number[]): number;
```

Si devuelve algo que no coincide con lo que estipula en la anotación de tipo el compilador devolverá un error.

**Buena práctica** Anotar el tipo de retorno de la función.

## Anotación void
Si una función no va devolver nada se pude usar en la anotación de tipo de retorno `void` para indicar esto y que el compilador no de nada.

```ts title:example.ts
function printNumber(myNum: number): void {
  console.log(`Number = ${myNum}`);
}
```

De esta manera se evita tener que añadir una sentencia return, de añadirse se produciría un error, a no ser que el tipo devuelto sea de tipo `undefined` 

## Sobrecarga de tipos de funciones
La sobrecarga de tipos de función permite especificar los tipos que debe devolver una función si se reciben ciertos tipos de parámetros.
```ts title:example.ts
function add (x: number, y: number): number;
function add (x: null, y: null): null;
function add(firstNum: number | null, secondNum: number | null): number | null {
	if (firstNum !== null && secondNum !== null) { 
		return firstNum + secondNum; 
	} 
	return null; 
}
```

De esta manera se puede controlar que si recibe dos number, deba devolver dos number, por ejemplo. Esto facilita trabajo al compilador pues gracias a la sobrecarga este sabe que se debe retornar un number.

Ahora gracias a esto la función no podrá ser llamada con argumentos de tipos diferentes.

## Funciones asertivas
Sirven como guardianes de tipos en JavaScrypt, estos evalúan expresiones y si son falsas lanzan una excepción.
```ts title:example.ts
function checkNumber(expr: boolean) {
	if (!expr) {
		throw new Error('Expr is false')
	}
}
```

Esto puede ser usado por una función para determinar por ejemplo si la variable pasada no es del tipo correcto.
Sin embargo el compilador de TypeScrypt, por su funcionamiento, no permite valores no numericos en los assert, soltando un error.

La solución está en anotar el tipo de la función assert como `assert expr` 

## Funciones como tipos
En JavaScrypt una variable puede apuntar a un función. Véase:
```ts title:example.ts
function add(x: number, y: number): number {
	return x + y;
}

let myFunc;
myFunc = add;
console.log(myFunc(1,2));
```

El tipo de esta variable será de tipo any.

Para evitar errores en TypeScrypt se anota el tipo de dato `Function` para determinar que una variable solo puede apuntar a funciones.

Para evitar errores en el uso de una variable de este tipo se puede especificar que forma tiene la función a la que va a apuntar:
```ts title:example.ts
let myFunction : (a: number, b: number) => number;
```
De esta manera, si se trata de asignar a una función que no tenga esta forma se muestra un error.

## Callbacks
Gracias a lo anterior TypeScrypt puede hacer comprobaciones a la hora de definir callbacks.
```ts title:example.ts
function addAndDoSomething(firstNumber: number, secondNumber: number, myFunction: (a: number) => void) { 
	const addition = firstNumber + secondNumber; 
	myFunction(addition); 
} 

addAndDoSomething(1, 7, (num) => { 
	console.log(`Number: ${num}`); 
});
```

Las funciones anónimas pasadas por parámetro deben tener una forma en concreta, si se llaman a estas con más parámetros de los que indica la declaración, o con variables de tipo diferente al especificado en la misma, se produce un error.

Un detalle importante es que la función anónima que tiene como anotación de resultado void, omitirá todo return que se le añada.