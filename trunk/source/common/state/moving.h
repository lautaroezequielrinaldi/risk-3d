#ifndef MOVING_H_
#define MOVING_H_

#include "state.h"



class Moving : public State
{
	public:
	
		/**
		 * Constructor de la clase
		 */
		Moving(ReferenceCountPtr<GameManager>&gameManager, std::string name);
		
		/**
		 * Destructor de la clase
		 */	
		virtual ~Moving();
		
		/**
		 * Metodo cuyo proposito es ejecutar la accion correspondiente al estado del juego y notificar 
		 * los cambios en el mismo.
		 */
		virtual bool move(Move & command);

		virtual void accept(StateObserver* observer);	 
};

#endif /*MOVING_H_*/
