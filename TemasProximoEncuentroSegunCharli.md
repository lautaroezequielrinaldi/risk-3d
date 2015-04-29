## Para que "Pais::contienePaisAdyacente(string/coord)"? ##
Si vamos a utilizar una interfaz grafica, el usuario no manipula los nombres ni las coordenadas.

Ademas solo nos interesa si es adyacente, con bool Pais::esAdyacente(Pais) nos alcanza

Solo si metemos un bot puede servirnos explorar los adyacentes.

## Para que "Pais::contiene/obtiene"? ##
```

if (pais->contiene(otro)) {
  otro = pais->obtener(....)
  otro->accion
}

```

es equivalente a

```
otro=pais->obtener(...)
if (otro) {
  otro->accion()
}


```

la segunda forma permite utilizar ademas null object

```

otro=pais->obtener(...)
otro->accion()

```

En general me parece que hay metodos de mas

## Nombres de metodos ##

Agregar/RemoverUnidad no necesita Infanteria/Artilleria/Caballeria, lo obtiene de la firma

## Composicion mapa-continente-pais ##

El continente es solo una agrupacion lógica que tiene sentido a la hora de los objetivos y la repoblacion.

```

  mapa ---- continente
   |           |
 pais----------+

```

Cuando hagamos click sobre la esfera, obtendremos un Pais, no un continente.

## Undo/redo ##

Estoy de acuerdo en incorporarlo como desafio, me parece un estorbo en la usabilidad

## Lectura de Sockets ##

Si va a ser un preambulo de tamaño fijo que determina el tamaño del resto o leeremos hasta consumir todo. Me inclino por lo primero.

## Organizacion de fuentes y paquetes logicos de codigo ##
Vamos a usar namespaces para denotar los diferentes modulos de nuestra aplicacion? Si es asi o en caso de no serlo tambien vamos a separar en "paquetes" a nuestros fuentes, es decir toda la funcionalidad de sockets y de networking dentro de source/common/net, toda la de threading a source/common/threading o dejaremos todos los fuenets en un mismo directorio?
Yo me inclinaria por tener todo separado por paquetes, me parece mas organizado y es mas facil de entender las clases que componen a un modulo en particular con simplemente ver las clases que estan en su paquete...

## YAGNI ##

quien sabe puede llegar a ser necesario mostrrar algun label o algun "link

## Varios ##

El atacado participa de la defensa?

Qué pasa si alguien abandona o se cae la conexión? republicas independientes?

Interfaz "reducida" para Editor y Player

Ultra alta reutilizacion Editor/Player

Mismas clases en Server/Client con mensajes de sincronizacion de estado o clases adaptadas a cada contexto?

El cliente posee logica? Aunque sea logica minima de validacion, por ejemplo no nos deberia permitir atacar a una ciudad o pais que es nuestro.

En caso de errores en las oepraciones, como vamos a noticiar a cada cliente? Por ejemplo supongamos que estamos atacando a un jugador y este se desconecta en el medio del ataque, como se le notifica al cliente que el contrincante se desconecto? Lo mismo apsa para cuando hay problemas de conexion o no recibimos nunca una respuesta del servidor.