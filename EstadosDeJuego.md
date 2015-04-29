Esta pagina es mas que nada para resaltar los distintos estados de juego sobre los que pasa el cliente y como transita entre ellos.

  1. Estado desconectado: Se produce cuando el cliente todavia no se conectó a ningún servidor.
  1. Estado conectando: Se produce durante el handshake de conexión entre el cliente y el servidor.
  1. Estado conectado: Se produce cuando el handshake de conexión terminó y el cliente fue aceptado al servidor como participante.
  1. Estado comienzo de juego: Se produce cuando el usuario esta conectado y el juego esta a punto de comenzar.
  1. Estado posiconamiento tropas iniciales: Se produce luego que el servidor hace un broadcast a cada cliente solicitandole que posicionen sus tropas iniciales a punto de empezar la partida.
  1. Estado turno activo: Se produce cuando el cliente es notificado que posee el turno actual y todavia no ha realizado ninguna acción en su turno.
  1. Estado ataque: Se produce cuando el usuario ha entrado en un estado de turno activo y decide atacar a algun jugador.
  1. Estado reposicion tropas: Se produce cuando el usuario ha entrado en un estado de turno activo y luego del ataque debe reposicionar tropas.
  1. EStado turno pasivo: Se produce cuando el cliente no posee el turno actual y de hecho debe esperar a que otro cliente en turno activo realice sus jugadas y movimientos.
  1. Estado final de juego: Se produce cuando el juego ha acabado o el jugador ha sido eliminado.

Gente estos son algunos estados ques e me ocurrieron, la idea es armar una lista formal con todos los estados del juego porque luego con eso deberemos armar una maqunina de estados para transitar entre los diversos estados del juego y tambien para hacer validaciones...

Por ejemplo si el usuario esta en un estado de turno pasivo, es decir no tiene ningun turno actual, no tiene ningun sentido de que seleccione una unidad y pueda atacar a otro contrincante, lo mismo pasa para un estado de reposicion de tropas, no tiene sentido que en un estado de reposicion de tropas el cliente seleccione una unidad y la mueva a un pais contrincante ocupado como si fuera a atacar.

Estas son mis opiniones, me gustaria ver si se les viene a la mente alguna idea mas, o algun estado, o alguna sugerencia sobre el tema.