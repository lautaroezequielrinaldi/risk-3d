#ifndef MOVEING_H_
#define MOVEING_H_

#include "state.h"


class Moveing : public State
{
	public:
	
		/**
		 * Constructor de la clase
		 */
		Moveing();
		
		/**
		 * Destructor de la clase
		 */	
		~Moveing();
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion correspondiente al estado del juego y notificar 
		 * los cambios en el mismo.
		 */
		bool move(Move & command);
};

#endif /*MOVEING_H_*/
