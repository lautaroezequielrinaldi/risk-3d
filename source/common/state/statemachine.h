#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

class GameManager;

#include "state.h"
#include <map>
#include <string.h>
#include "../model/player.h"
#include "../smartpointer/referencecountptr.h"

/**
 *
 * 
 */
class StateMachine {
	
	public:
		
		/**
		 * Constructor de la clase
		 */
		StateMachine(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Destructor de la clase
		 */
		virtual ~StateMachine();

		/**
		* Metodo cuyo proposito es obtener un estado a partir de su nombre.
		*/
		ReferenceCountPtr<State> getState(std::string statename);
		
		/**
		 * Metodo cuyo proposito es obtener el estado actual del juego.
		 */ 
		ReferenceCountPtr<State> getCurrentState();
		
		/**
		 * Metodo cuyo proposito es establecer el estado actual del juego.
		 */
		void setState(std::string statename);
	
		
	
	protected:	
		
		std::map <std::string, ReferenceCountPtr<State> > states;
	private:
		ReferenceCountPtr<State> currentState;
	
};
#endif /** __STATEMACHINE_H__ */
