[Repositorio de GitHub](https://github.com/ull-cs/aeda/tree/main/c%2B%2B/theory)

# Fases de compilación
El compilador es un programa que convierte el código fuente en un código de salida
## Preprocesador
Gestiona las directivas (\#include, \#define...).
## Compilador
Convierte el código fuente de C++ en código ensamblador
## Ensamblador
Convierte el código ensamblador en código objeto.
## Enlazador
Une los archivos objeto (.o) en un archivo ejecutable.

# c++
## Variables y constantes
Toda variable tiene un tipo, las variables no pueden cambiar de tipo.
El tipo auto permite que el compilador fije el tipo según le convenga, pero no hace que el tipo cambie constantemente.

Las constantes se pueden declarar de dos formas
`const float kPI = 3.1415` o `#define PI 3.1415`
La colocación de const afecta al resultado

**const char* a**           puntero a un char constante
**char* const a**           puntero constante a un char
**const char* const a**     puntero constante a un char constante

Funcionamiento de new y delete.
![[Pasted image 20240501183929.png]]

Declarar una variable como `static` cambia su duración, destruyéndose esta al final de la ejecución.
## Funciones
Existen varios tipos de paso de parámetro.
![[Pasted image 20240501182258.png]]


Una macro es un fragmento de código al que se le ha dado un identificador, al usarlo se le reemplaza por el código de este. Se pueden parecer a los objetos de datos o a las llamadas a funciones.
![[Pasted image 20240501181353.png]]

assert() detiene el programa si la sentencia booleana que se le coloque dentro es falsa.
```
#define NDEBUG           // Esto provoca que los asserts sean nulos, debe ir  
#include <assert.h>      // encima del include

int main() {
int x{1};
assert(x < 0);
std::cout << "x no es menor que 0\n";
return 0;
}
```

Si una función devuelve una referencia se puede operar de la siguiente manera.
![[Pasted image 20240501182816.png]]

A la hora de sobrecargar funciones se deben diferenciar estas por los parámetros pasados pues si no lo hicieran a la hora de ejecutar no se puede determinar cual se debe ejecutar.

Se pueden declarar valores por defecto en las funciones
`void function(const int var = 0) {...}
Con esto se puede producir el mismo problema de antes
![[Pasted image 20240501183248.png]]

Al declarar una funcion como inline, el compilador sustituye su llamada por su código, mejorando el rendimiento. Suelen ser funciones cortas. Son preferibles a las macros.

## Clases
Un `struct` permite crear objetos y almacenar datos de estos, por defecto todo es público.
![[Pasted image 20240501184106.png]]
 
 Una `union` permite conglomerar varias variables bajo un mismo nombre, de tal manera se puede acceder a estos de la siguiente manera.
 ![[Pasted image 20240501184323.png]]

En una clase existen 3 niveles de protección.
+ public: todo el mundo accede
+ private: solo miembros de la clase pueden acceder
+ protected: solo miembros de la clase y clases derivadas pueden acceder.
Dentro de los métodos se usa `this` para acceder a los atributos y métodos del objeto invocante de la función.

La interfaz de una clase va en un fichero .h mientras que la implementación en un fichero .cc

Para evitar que se redefina la clase se usa el siguiente bloque.
![[Pasted image 20240501184845.png]]

Existen varios tipos de métodos y si alguno de estos está definido en la interfaz de la clase se asume como inline.

Los atributos estáticos de una clase son compartidos por todos los objetos y existen aunque no se hayan creado objetos. Se deben inicializar en el ámbito global.
![[Pasted image 20240501185357.png]]

Las funciones estáticas no se asocian a ningún objeto, pudiéndose invocar si se usa el nombre de la clase::Método();

Un constructor crea objetos, no devuelve nada, puede ser sobrecargado y debe instanciarse uno por defecto para crear vectores de esos objetos.
Un destructor no devuelve nada, no puede ser sobrecargado y no se le pasan parámetros.

Una función friend se declara como tal en cualquier parte de la clase. Si se define fuera no se debe colocar el calificativo de friend.

## Plantillas
Permiten programar sin determinar el tipo concreto con el que se va a trabajar. se pueden aplicar sobre funciones y sobre clases.
![[Pasted image 20240501193631.png]]
![[Pasted image 20240501193758.png]]
Se pueden especificar en las plantillas cantidad.
![[Pasted image 20240501193858.png]]
Y además se le pueden colocar a los parámetros de la plantilla unos valores por defecto.

Si se desea, se puede definir una especialización para las plantillas, pasándole un tipo específico a la plantilla.
![[Pasted image 20240501194341.png]]
También se pueden hacer plantillas de métodos.
## Sobrecarga de operadores.
La sobre carga tiene la siguiente sintáxis:
`<RETURN_TYPE> operator<NAME>(<PARAMS>)`
### Funciones friend
Si se tiene que acceder a los atributos privados de la clase.
```C++
class Clase {
friend Class operator+(const Cent& a, cosnt Cent& b);
int cents_{0};
};

```
De esta manera se deben sobrecargar los operadores de entrada y salida
![[Pasted image 20240501195558.png]]
### Funciones convencionales
Si no se requiere acceder a los atributos
`Cents operator+(const Cents& c1, const Cents& c2)`

### Función miembro
Se define dentro de la clase y uno de los operadores es el objeto implícito \*this

```C++
Complex operator+(Complex const &obj) {
  Complex res;
  res.real = real + obj.real;
  res.imag = imag + obj.imag;
  return res;
}
```
De esta manera deben ser sobrecargados los operadores () \[] = ->

El operando izquierdo es al que se le aplica la función.

## Herencia
Las clases hijas heredan atributos y métodos de sus antecesores. Permite redefinir características heredadas.

Las clases hijas no pueden acceder a la parte privada de su padre pero si a la protegida.

La herencia puede ser de tres tipos:
+ Pública: los miembros públicos y protegidos conservan ese nivel.
+ Protegida: los miembros públicos y protegidos pasan a ser protegidos en la hija
+ Privada: Los miembros públicos y protegidos pasan a ser privados en la hija.

Los constructores no se heredan pero se llaman en orden desde la Base hasta la clase a crear cuando se crea un objeto de dicha clase. En las listas de inicialización se puede especificar el constructor que se empleará para crear la base.
## Polimorfismo
Consiste en redefinir un método de la clase base ocultándolo y solo siendo accesible usando el operador de ámbito.
La sobrecarga se resuelve en tiempo de compilación.
El polimorfismo se decide en ejecución.

Un método virtual se escribe en la clase base y sobrescribe en la calase heredada. Se puede usar la versión redefinida si se llama desde un puntero o referencia de la clase base. Aseguran que el método correcto es invocado.

Si un método virtual se redefine debe llevar override en la redefinición tras los parámetros. Es opcional.

Si se destruye a un objeto desde un puntero a la base se debe hacer con un destructor virtual.

Las clases bases pueden ser abstractas, esto se logra igualando un método virtual a 0. Esto es un método virtual puro y toda clase que herede de esta debe dar una definición para estos métodos, o se seguirá tomando como abstracta.

Si en vez de override se escribe *final* impide que clases derivadas reescriban la función. También se puede colocar al lado del nombre de la clase para evitar la herencia.

Ocurre igual si el constructor se coloca en la parte privada y se pone en público un método static para crear objetos.

## Gestión de errores
+ tiempo de compilación
Errores de sintaxis y semántica, el compilador los identifica
+ tiempo de ejecución
Se producen en la ejecución y el resultado es impredecible.

Los errores debería ser manejados en tiempo de ejecución, sin embargo se pueden gestionar saliendo.

abort() finaliza soltando un mensaje
exit() acaba de forma silenciosa

Una función puede devolver una excepción para indicar al invocador que ha fallado

try define un bloque de código que será analizado en busca de errores en tiempo de ejecución

throw lanza una excepción al detectar un problema

catch define un bloque de código a ejecutar si se detecta un error detectado en un bloque try
![[Pasted image 20240501222639.png]]

Si el bloque try genera varios tipos de excepciones se deben agregar más clausulas catch una tras otra debajo.

Si se declara un catch(...) captura cualquier tipo de excepciones.
![[Pasted image 20240501223109.png]]

Una función no puede lanzar una excepción si se marca con la palabra noexcept.

Los objetos excepcion que se lanzarán están definidos en la stl 
Ejemplos:
![[Pasted image 20240501223355.png]]
![[Pasted image 20240501223440.png]]
![[Pasted image 20240501223455.png]]
Se puede definir excepciones personalizadas
![[Pasted image 20240501223533.png]]

Un destructor no debería hacer algo que pueda provocar excepciones pues puede provocar comportamientos inesperados.

Los constructores no devuelven nada por lo que los fallos deben ser gestionados por excepciones. Una opción es invalidar el objeto colocandolo en estado zombie.

## Conversión de tipos
*(type)expression* logra fuerza a un tipo de dato a ser convertido en otro

const_cast\<type> (expr). Se emplea para explícitamente sobreescribir const y/o volatile en un cast. El tipo de destino debe ser el mismo que el origen excepto por la modificación de los atributos const o volatile.

dynamic_cast\<type> (expr). Realiza una conversión en tiempo de ejecución que verifica la validez del cast. Si el casting no puede ser realizado, la expresión se evalúa como null. 

reinterpret_cast\<type> (expr). Cambia un puntero a cualquier otro tipo de puntero. También realiza el cambio de puntero a tipo entero, y viceversa.

static_cast\<type> (expr). Realiza un cambio no polimórfico. Por ejemplo, cambiar un puntero de clase base a puntero de clase derivada.

La conversión dinámica se usa para convertir hacia abajo en una jerarquía de clases, convierte un puntero de la clase base a uno de la clase derivada
`newType* newPointer = dynamic_cast<newType*>(pointer);`

typeid(expression) comprueba la info sobre un tipo o para comprobar si dos objetos son del mismo tipo.

