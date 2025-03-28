#### Recursos
[Repositorio](https://ull-esit-inf-dsi-2425.github.io/typescript-theory/docs/)
# 1. Anotaciones básicas sobre proyectos

___
## Depuración de proyectos

**Formatear Código**
npx prettier --write .

Para depurar se debe generar un fichero en la parte de configuración launch.json, luego en dicho fichero cambiar el target al .js

Se puede activar una opción de mapeo para que depurando el .js, te muestre la equivalencia en el .ts

**ANOTACIÓN -> USAR === SOBRE == EN COMPROBACIONES, ES MEJOR EN TS Y JS**

+ ? Mirar vitest run --coverage --converage.includes .src/ Este genera un directorio que no es necesario someterlo a control de versiones, la primera vez se debe instalar una dependencia

# 2. Tipos de variables


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

___
## Intro
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

# 4. Contenedores

## Array
Pueden contener elementos de cualquier tipo y de tamaño variable.
Si se hace una anotación de tipo a un array, este solo podrá contener elementos de dicho tipo, el compilador de TypeScrypt muestra un error en caso de intentarlo.
```ts title:example.ts
let MyArray: number[] | string[] = ["hola", 23, 5, "11", 012]
console.log(MyArray)
```

**Buena práctica** Para recorrer las listas es preferente usar el método de los arrays forEach

Si no se es suficientemente explícito a la hora de definir un array que no tiene anotaciones de tipo el compilador puede inferir el tipo de dato any, lo cual no es deseable pues se pierde control sobre lo que se está desarrollando, habilitar `StrictNullChecks` en las opciones del compilador ayuda a eliminar la posibilidad de generar estos vectores mal definidos.
## Tuplas
Son un tipo de dato proporcionado por TypeScrypt que se trata como array en JavaScrypt pero que funciona como un vector de tamaño fijo
```ts title:example.ts
let bankActivities: [string, number][] =
  [["Trail Shop", 23.45], ["Coffee Shop", 15.43]];

bankActivities.forEach((activity) => {
  console.log(`I spent ${activity[1]} euros at ${activity[0]}`);
});

bankActivities[0] = ["Supermarket"];
bankActivities[1][1] = "15.43";
bankActivities.push(["Pub", "Tons of beers", 15, 16]);
```
Ante el ejemplo anterior, el compilador de TypeScript informará de los siguientes errores:

```ts title:compilator_error
src/index.ts:8:1 - error TS2322: Type '[string]' is not assignable to type '[string, number]'.
  Source has 1 element(s) but target requires 2.

8 bankActivities[0] = ["Supermarket"];
  ~~~~~~~~~~~~~~~~~

src/index.ts:9:1 - error TS2322: Type 'string' is not assignable to type 'number'.

9 bankActivities[1][1] = "15.43";
  ~~~~~~~~~~~~~~~~~~~~

src/index.ts:10:29 - error TS2322: Type 'string' is not assignable to type 'number'.

10 bankActivities.push(["Pub", "Tons of beers", 15, 16]);
                               ~~~~~~~~~~~~~~~


Found 3 errors in the same file, starting at: src/index.ts:8
```
Se pueden deserializar igual que los arrays
```ts title:example.ts
type BankActivity = [string, number];

let bankActivities: BankActivity[] =
  [["Trail Shop", 23.45], ["Coffee Shop", 15.43]];

bankActivities.forEach((activity) => {
  const [activityName, activityPrice] = activity;
  console.log(`I spent ${activityPrice} euros at ${activityName}`);
});
```
Tambien pueden contener elementos opcionales como se muestra en el siguiente ejemplo:
```ts title:example.ts
type BankActivity = [string, number, string?];
```
Por lo que se puede deducir que tambien permiten almacenar elementos de tipo rest

## Enumerados
Permite definir etiquetas con una constante numérica asociada
**Buena practica** tener las etiquetas en mayúsculas

Las eitquetas numéricas por defector empiezan por 0 y las etiquetas posteriores toman valores consecutivos, aunque se les pueden asignar valores por defecto.

Si se le dan valores numéricos duplicados pueden ocurrir errores.

Cabe destacar que las claves también pueden ser cadenas de caracteres

# 5. OPP

## Declaración de objetos
El nombre y tipo de las propiedades de un objeto se denomina **forma**, esta es usada por el compilador para determinar el tipo del dato.
```ts title:example.ts
let rectangle = {
  name: "Rectangle",
  sides: 4,
};

let pentagon = {
  name: "Pentagon",
};
```

Si se hiciera un array con estos dos objetos, el compilador hace una unión de tipo diciendo que el array contiene strings, al ser una unión no se podrá acceder a la propiedad sides pues no pertenece a la union de tipos

Para solucionar esto se debe usar un guardián de tipos:
```ts title:example.ts
const figures = [rectangle, triangle, hexagon, pentagon];

figures.forEach((figure) => {
	if ('sides' in figures)
	  console.log(`I am a ${figure.name} and I have ${figure.sides} sides`);
});
```

O también se puede anotar el tipo del array de la siguiente manera
```ts title:exmaple.ts
const figures: { name: string; sides: number }[] = []
```

El el caso de que un objeto tenga propiedades adicionales a las especificadas en la anotación de tipos del array, estos podrán ser almacenados. 

Otra opción es añadir una propiedad aleatoria a la anotación de tipo del array de la siguiente manera:
```ts title:example.ts
const figures: { name: string; sides: number; color?: string }[] = [
  rectangle,
  triangle,
  hexagon,
  pentagon,
];
```

Si activamos la opción del compilador StrictNullChecks el compilador avisa de que los valores podrían ser NULL o undefined
## Métodos de objetos
Se pueden declarar de las siguiente manera:
```ts title:example.ts
let rectangle = {
  name: "Rectangle",
  sides: 4,
  area: (base: number, height: number) => base * height,
};

let triangle = {
  name: "Triangle",
  sides: 3,
  area: (base: number, height: number) => (base * height) / 2,
};

let circle = {
  name: "Circle",
  area: (radius: number) => Math.PI * Math.pow(radius, 2),
};

const figures: {
  name: string;
  sides?: number;
  area(...params: number[]): number;
}[] = [rectangle, triangle, circle];

figures.forEach((figure) => {
  console.log(
    `I am a ${figure.name}, I have ${figure.sides} sides and my area is ${figure.area(3, 5)}`,
  );
});
```

Si pusiéramos en el array el método como opcional y añadiésemos hexagon, el compilador no da fallos pero da un error en tiempo de ejecución debido a que intenta ejecutar un método que no existe para hexagon. Evitar esto es conseguido activando a strictNullChecks
## Alias de tipos
Usualmente se usan Alias de tipos para específicar el tipo de los objetos a definir.
```ts title:example.ts
type Figure = {
  name: string;
  sides?: number;
  area(...params: number[]): number;
};

let rectangle: Figure = {
  name: "Rectangle",
  sides: 4,
  area: (base, height) => base * height,
};
```
Cabe destacar que al haber anotado en la definición del tipo figura que los operandos son de tipo number, no es necesario anotar el tipo en la instancia en rectangle. 

Como triangle y cicle tienen la misma forma que Figure pues permite introducir estos al array de figures.

Sin embargo si añadimos una propiedad adicional como 'color' a triangle, por ejemplo, estos ya no tienen la misma forma que un figure, dando un error de compilación.

**Buena práctica:** Usar la opción del compilador strictNullCheck.

## Uniones de tipos
```ts title:example.ts
type TwoDimensionalFigure = {
  name: string;
  sides?: number;
  area(...params: number[]): number;
};

type ThreeDimensionalFigure = {
  name: string;
  volume(...params: number[]): number;
};

let rectangle: TwoDimensionalFigure = {
  name: "Rectangle",
  sides: 4,
  area: (base, height) => base * height,
};

let cube: ThreeDimensionalFigure = {
  name: "Cube",
  volume: (base, height, depth) => base * height * depth,
};

const figures: (TwoDimensionalFigure | ThreeDimensionalFigure)[] = [
  rectangle,
  cube,
];

figures.forEach((figure) => {
  console.log(`I am a ${figure.name}`);
});
```

Conservan solo las propiedades que comparten ambos tipos por lo que el compilador peta cuando intenta invocar el método área, la solucion: Un guardián de tipos.
```ts title:example.ts
figures.forEach((figure) => {
  if ("area" in figure) {
    console.log(
      `I am a ${figure.name} and my area is ${figure.area(5, 4).toFixed(2)}`,
    );
  } else if ("volume" in figure) {
    console.log(
      `I am a ${figure.name} and my volume is ${figure.volume(5, 4, 7).toFixed(2)}`,
    );
  }
});
```

O usar funciones que comprueben el tipo de las funciones:
```ts title:example.ts

function isTwoDimensionalFigure(myObj: any): myObj is TwoDimensionalFigure {
  return myObj.area !== undefined;
}

function isThreeDimensionalFigure(myObj: any): myObj is ThreeDimensionalFigure {
  return myObj.volume !== undefined;
}

figures.forEach((figure) => {
  if (isTwoDimensionalFigure(figure)) {
    console.log(
      `I am a ${figure.name} and my area is ${figure.area(5, 4).toFixed(2)}`,
    );
  } else if (isThreeDimensionalFigure(figure)) {
    console.log(
      `I am a ${figure.name} and my volume is ${figure.volume(5, 4, 7).toFixed(2)}`,
    );
  }
});
```

## Intersecciones de tipos
Permite unir las propiedades de los objetos:
```ts title:example.ts
type TwoDimensionalFigure = {
  name: string;
  area(...params: number[]): number;
};

type TwoDimensionalFigureWithSides = {
  name: string;
  sides: number;
};

const rectangle = {
  name: "Rectangle",
  sides: 4,
  area: (base: number, height: number) => base * height,
};

const triangle = {
  name: "Triangle",
  sides: 3,
  area: (base: number, height: number) => (base * height) / 2,
};

const figures: (TwoDimensionalFigure & TwoDimensionalFigureWithSides)[] = [
  rectangle,
  triangle,
];

figures.forEach((figure) => {
  console.log(
    `I am a ${figure.name}, I have ${figure.sides} sides and my area is ${figure.area(5, 4).toFixed(2)}`,
  );
});
```

En cada ciclo del bucle puedo acceder a cualquier propiedad, si algun objeto del array tuviera una propiedad que no sigue la forma de ninguno de los dos, hay un error porque el compilador no detecta que triangle tiene la misma forma que el resto.

Si se hace la intersección de dos tipos con propiedades:
+ Mismo nombre y tipo: no pasa nada
+ Mismo nombre y tipo diferente: dara la intersección de tipos en aquellas propiedades con el mismo nombre, resultando en un tipo imposible (da error).
+ Métodos con el mismo nombre: Locura (en palabras del profe), pues se hace una intersección entre las signaturas y no se sabe lo que puede pasar.

## Clases
Hay que modificar el compilador para que sea
```json title:package.json
{
  "compilerOptions": {
    "target": "ES2024",
    "module": "commonjs",
    "rootDir": "./src",
    "declaration": true,
    "outDir": "./dist",
  }
}
```

Hay una manera de crear una función que funciones como constructor:
```ts title:example.ts
let TwoDimensionalFigure = function(name: string, sides: number,
    area: (...params: number[]) => number) {
  this.name = name;
  this.sides = sides;
  this.area = area;
};

let rectangle =
  new TwoDimensionalFigure("Rectangle", 4, (base, height) => base * height);

let triangle =
  new TwoDimensionalFigure("Triangle", 3, (base, height) => base * height / 2);

let figures = [rectangle, triangle];

figures.forEach((figure) => {
  console.log(`I am a ${figure.name}, I have ${figure.sides} sides and my area is ${figure.area(5, 4).toFixed(2)}`);
});
```

Esto dará un error de compilación debido a que el compilador con la opción noImplicitAny detecta que el compilador esta infiriendo el tipo any para estas declaraciones.

Lo mejor es el uso de clases:
```ts title:example.ts
class TwoDimensionalFigure {
  name: string;
  sides: number;
  area: (...params: number[]) => number;

  constructor(name: string, sides: number,
      area: (...params: number[]) => number) {
    this.name = name;
    this.sides = sides;
    this.area = area;
  }
}

let rectangle =
  new TwoDimensionalFigure("Rectangle", 4, (base, height) => base * height);

let triangle =
  new TwoDimensionalFigure("Triangle", 3, (base, height) => base * height / 2);

let figures = [rectangle, triangle];

figures.forEach((figure) => {
  console.log(`I am a ${figure.name}, I have ${figure.sides} sides and my area is ${figure.area(5, 4).toFixed(2)}`);
});
```

Las propiedades de una clase pueden tener niveles de acceso:
+ public: Acceso libre y por defecto
+ private: suelen ir precedidos de '\_' y solo puede ser accedido desde dentro de la clase
+ protected: pueden acceder las clases hijas de la misma

Además se pueden definir getters y setters
```ts title:example.ts
class TwoDimensionalFigure {
  public name: string;
  private _sides: number;
  public area: (...params: number[]) => number;

  constructor(name: string, sides: number,
      area: (...params: number[]) => number) {
    this.name = name;
    this._sides = sides;
    this.area = area;
  }

  get sides() {
    return this._sides;
  }

  set sides(sides) {
    this._sides = sides;
  }
}
```


Si se intenta acceder a una propiedad privada se da un error de compilación, si en el set no se anota el tipo se infiere por el tipo de retorno del get
Al usar los getters y setters no es necesario añadir el paréntesis pues simulan el acceso a la propiedad

Si no se declara solo el getter la propiedad será de solo lectura. El setter debe ser igual de accesible que el getter

+ ? Realmente un private es un soft private, por lo que se puede acceder a través de las comillas, si se quiere hacer uso de un privado estricto se debe declarar `#atribute`, al intentar acceder, acceder a este atributo da un error de compilación.
**Buena práctica** Activar `strictPropertyInitialization` y `strictNullCheck` 

+ ? public readonly name: string Establece esta variable como readonly

## Constructor simplificado
```ts title:example.ts
class TwoDimensionalFigure {
  constructor(public readonly name: string, private _sides: number,
      public area: (...params: number[]) => number) {
  }

  get sides() {
    return this._sides;
  }

  set sides(sides) {
    this._sides = sides;
  }
}
```

Permite congregar el constructor y la declaración de atributos en un solo código.

## Herencia
```ts title:example.ts
class TwoDimensionalFigure {
  constructor(public readonly name: string, public readonly sides: number,
    public color: string) {
  }
}

class Rectangle extends TwoDimensionalFigure {
  constructor(public readonly name: string, public readonly sides: number,
    public color: string) {
    super(name, sides, color);
  }

  getArea(base: number, height: number) {
    return base * height;
  }
}

class Triangle extends TwoDimensionalFigure {
  constructor(public readonly name: string, public readonly sides: number,
    public color: string) {
    super(name, sides, color);
  }

  getArea(base: number, height: number) {
    return base * height / 2;
  }
}

let rectangle =
  new Rectangle("RedRectangle", 4, "red");

let triangle =
  new Triangle("BlueTriangle", 3, "blue");

let figures = [rectangle, triangle];

figures.forEach((figure) => {
  console.log(`I am a ${figure.name}, I have ${figure.sides} sides ` +
              `and my area is ${figure.getArea(5, 4).toFixed(2)}`);
});
```

En el caso del array este sería del tipo triangle | rectangle
pero es mejor anotarlo con la clase más abstracta posible

## Clase abstracta
Declara métodos abstractos que obliga a que sus hijos lo implementen, estas clases no permiten la creación de objetos

```ts title:example.ts
abstract class TwoDimensionalFigure {
  constructor(public readonly name: string, public readonly sides: number,
    public color: string) {
  }

  abstract getArea(...params: number[]): number;
}
```

Si no se implementan los métodos abstractos en las clases herederas da dos error de compilación.
## Interfaces
Permite declarar la forma de un objeto:
```ts title:example.ts
interface TwoDimensionalFigure {
  name: string;
  sides: number;
  color: string;
  getArea(): number;
}

class Rectangle implements TwoDimensionalFigure {
  constructor(public readonly name: string, public readonly sides: number,
    public color: string, public base: number, public height: number) {
  }

  getArea() {
    return this.base * this.height;
  }
}
```

Ademas se pueden implementar varias interfaces, no hay ventajas o desventajas sobre usar herencia.

Si no se implementa todo lo que dicta en las interfaces, da un error de compilador

Además se puede hacer una herencia de interfaces, permitiendo heredar la menos abstracta para implementar el resto de funcionalidades de la interfaz abstracta.

```ts title:example.ts
interface TwoDimensionalFigure {
  name: string;
  sides: number;
  color: string;
  getArea(): number;
}

interface PrintableTwoDimensionalFigure extends TwoDimensionalFigure {
  print(): void;
}
```

Además de interfaces abstractas
```ts title:example.ts
abstract class PrintableRedTwoDimensionalFigure implements TwoDimensionalFigure {
  abstract name: string;
  abstract sides: number;
  abstract getArea(): number;
  abstract print(): void;
  color = "red";
}
```

Pese a no tener mucho sentido, se pueden declarar propiedades opcionales 
Además se dice que una interfaz es abstracta si es implementada en una clase abstracta

También se puede hacer uso de guardianes de tipo para filtrar las interfaces.
```ts title:example.ts
figures.forEach((figure) => {
  if ('getArea' in figure) {
    console.log(`Figure: ${figure.name}; Area: ${figure.getArea()}`);
  } else if ('getVolume' in figure) {
    console.log(`Figure: ${figure.name}; Volume: ${figure.getVolume()}`);
  }
});
```


Haciendo uso de una asignación indexada se puede asignar dinámicamente objetos a un tipo, por ejemplo, observese el siguiente ejemplo:
```ts title:example.ts
class TwoDimensionalFiguresSet {
  constructor(...twoDimensionalFigures: [string, TwoDimensionalFigure][]) {
    twoDimensionalFigures.forEach((figure) => {
      this[figure[0]] = figure[1];
    });
  }

  [propertyName: string]: TwoDimensionalFigure;
}

let figures = new TwoDimensionalFiguresSet(
    ['rectangle', new Rectangle('rectangle', 4, 'red', 5, 4)],
    ['triangle', new Triangle('triangle', 3, 'yellow', 10, 15)],
);

// It dinamically assigns to the object figures a property named
// "circle" whose value is a new Circle
figures.circle = new Circle('circle', 'green', 6);
```

Si se intentase acceder a una propiedad inexistente por este método se da un error en tiempo de ejecución, para evitar este error se deben habilitar las siguientes opciones del compilador: `strictNullChecks` y `noUncheckedIndexedAccess`

Y finalmente para solucionar este problema se puede comprobar si la instancia hexagon existe:
``` ts title:example.ts
if ('hexagon' in figures) {
  figures.hexagon.print();
}
```
# 6. Clases e interfaces genéricas.

## Clase genérica
Son usados para aumentar la escalabilidad del código, son basicamente, templates del lenguaje C++: 
```ts title:example.ts
class FigureCollection<T> {
  constructor(private figures: T[]) {
  }

  addFigure(newFigure: T) {
    this.figures.push(newFigure);
  }

  getNumberOfFigures() {
    return this.figures.length;
  }

  getFigure(index: number) {
    return this.figures[index];
  }

  /* print() {
    this.figures.forEach((figure) => {
      figure.print();
    });
  } */
}
```
Print está comentado debido a que el compilador no puede garantizar que el objeto de tipo T tenga este método.

Si usamos extends dentro de las flechas seguido de los tipos que deseo que tenga, estamos retringiendo para que el tipo genérico asignado sea del que le indicas después del extends
```ts title:example.ts
class FigureCollection<T extends (TwoDimensionalFigure | ThreeDimensionalFigure)>
```

En el caso de que se le asigne un tipo que no esta permitido por el extends dara un error de compilación.

Se le puede asignar condiciones al extends, es decir, que cumpla lo que se le indica, como que tenga un método print: 
```ts title:example.ts
class FigureCollection<T extends { print: () => void }>
```


También se le puede asignar varios tipos genericos y a estos se les puede aplicar el extends, véase el siguiente ejemplo:
```ts title:example.ts
class FigureCollection<T extends TwoDimensionalFigure, U extends ThreeDimensionalFigure>
```

+ ? Tener en cuenta que al restringir, se retringe a la forma del objeto, si hubiera un objeto que no fuera el especificado con la misma forma podría pasar.

Las clases genéricas pueden presentar herencia, en estos casos el tipo genérico puede ser manejado de las siguientes maneras:
+ Añadir funcionalidad adicional a la clase original.
+ Fijar los parámetros genéricos
+ Restringir los parámetros de tipo genéricos
## Interfaces genéricas
``` ts example.ts
interface CollectionInterface<T> {
  addItem(newItem: T): void;
  getItem(index: number): T;
  getNumberOfItems(): number;
}
```


# 7. Módulos

Todo fichero que contiene las sentencias import o export. En este ámbito es importante recalcar la importacia de la sintáxis, La resolución de módulos y la carga y ejecución de los mismos.

Cada uno de estos 3 campos principales tienen sus características expuestas en los apuntes.

La sintáxis usada en typescrpyt no es la misma que la del código que se va a generar en javascrypt, la manera en la que se va a generar se puede definir en el compilador con la opción "type": "commonjs" o "type": "module", para esta ultima el campo node se debe cambiar al estandar a es2016 o es2018, **RECOMENDABLE ESTO ULTIMO**, además hay que añadir ciertos paquetes.

**Buenas Prácticas** Clases/interfaces similares en ficheros separados

Esto liga muy bien con los espacios de nombres, los cuales definen tipos y suelen almacenarse en otros ficheros

