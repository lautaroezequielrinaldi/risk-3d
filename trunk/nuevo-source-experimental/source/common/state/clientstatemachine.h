#ifndef __CLIENTSTATEMACHINE_H__
#define __CLIENTSTATEMACHINE_H__

class GameManager;

#include "statemachine.h"

#include "attacking.h"
#include "defending.h"
#include "moving.h"
#include "occupying.h"
#include "populating.h"
#include "waiting.h"
/**
 *
 * 
 */
class ClientStateMachine:public StateMachine {
	
	public:
		
		/**
		 * Constructor de la clase
		 */
		ClientStateMachine(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Destructor de la clase
		 */
		virtual ~ClientStateMachine();

	
};
#endif /** __CLIENTSTATEMACHINE_H__ */
