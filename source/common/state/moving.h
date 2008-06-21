#ifndef MOVING_H_
#define MOVING_H_

#include "state.h"

class Move;

class Moving : public State
{
	public:
	
		/**
		 * Constructor de la clase
		 */
		Moving(ReferenceCountPtr<GameManager> & gameManager);
		
		/**
		 * Destructor de la clase
		 */	
		virtual ~Moving();
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion correspondiente al estado del juego y notificar 
		 * los cambios en el mismo.
		 */
		virtual bool move(Move & command);

	 
};

#endif /*MOVING_H_*/
