Dado que vamos a usar un solo socket por cliente y que va a ser bloqueante, podemos definir un protocolo que consiste de un encabezado de tamaño fijo y un cuerpo.

Hacemos entonces socket\_read(buffer\_header, 100) y obtenemos esa linea, el proximo socket\_read(buffer\_body, n) trae la carga. No se si vale la pena meter en el encabezado el tipo de mensaje, me parece que no.

```
<header>
  <version>
    1.0.0
  </version>
  <content-length>
     0x0000fa  // longitud del body
  </content-length>
</header>

<body type="chat">
  <chat version="1.0">
    me ganaste, come @#$#%#$% y morite $%#$%#%
  </chat>
</body>
```

usamos la version para, por ejemplo introducir el tipo pero fuera del body.


```
<header>
  <version>
    1.1.0
  </version>
  <content-length>
     0x0000fa   // longitud del proximo bloque
  </content-length>
</header>

<message-type>
  <type>
    chat
  </type>
  <content-length>
     0x0000fa   // longitud del body
  </content-length>
<message-type>

<body>
  <chat version="1.0">
    me ganaste, come @#$#%#$% y morite $%#$%#%
  </chat>
</body>
```

La ventaja de tener el tipo separado del mensaje (aunque el tipo de todos modos este en el mensaje) es que nos permite elegir la estrategia de carga "desde afuera", no tenemos que parsear una parte con el mensaje ya abierto, no tenemos que tratar de modo especial el end tag.

De este modo podemos ir encapsulando de modo "encadenado"