### Teoría
[Tema 4](https://ull-esit-inf-dsi-2425.github.io/nodejs-theory/docs/)
# Definición
# Creación de procesos
## Introducción
## EventEmitter
Se puede redirigir la salida de los procesos hijos a traves de objetos Stream y sus métodos pipe. Estos Stream cada vez que tienen datos legibles emiten un evento data, enviando dichos datos. Todos los objetos EventEmitter tienen un método `on` que registra un manejador que se registra cada vez que se lanza el evento.

Se ve el siguiente ejemplo:
```ts title:example.ts
import {watchFile} from 'fs';
import {spawn} from 'child_process';

watchFile('helloworld.txt', (curr, prev) => {
  console.log(`File was ${prev.size} bytes before it was modified.`);
  console.log(`Now file is ${curr.size} bytes.`);

  const wc = spawn('wc', ['helloworld.txt']);

  let wcOutput = '';
  wc.stdout.on('data', (piece) => wcOutput += piece);

  wc.on('close', () => {
    const wcOutputAsArray = wcOutput.split(/\s+/);
    console.log(`File helloworld.txt has ${wcOutputAsArray[1]} lines`);
    console.log(`File helloworld.txt has ${wcOutputAsArray[2]} words`);
    console.log(`File helloworld.txt has ${wcOutputAsArray[3]} characters`);
  });
});
```

La variable wcOutput va registrando la salida del comando.

También se pueden crear streams para la lectura y escritura
Obsérvese como en el siguiente código implementa diferentes manejadores.
```ts title:example.ts
import {createReadStream} from 'fs';

const inputStream = createReadStream('helloworld.txt');

inputStream.on('data', (piece) => {
  process.stdout.write(piece);
});

inputStream.on('error', (err) => {
  process.stderr.write(err.message);
});
```


# Sockets
los sockets vienen dados por el módulo 'net'
```ts 
import net from 'net';

const server = net.createServer((connection) => {
  // The connection object is emitted when a new connection is made
  // It is the socket object
  console.log(connection);
});

server.listen(60300);
```

