por cada nuevo jugador se abre un thread
en este thread se escuchan mensajes bloqueado
cuando llega el mensaje, 
   se obtiene un lock sobre el estado.
   dependiendo del estado, al cual todos los jugadores acceden
   se toma alguna accion, que puede involucrar escribir en todos los demas jugadores
   devuelve el lock 
   y vuelve a bloquearse en lectura
   
