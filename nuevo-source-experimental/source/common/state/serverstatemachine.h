#ifndef __SERVERSTATEMACHINE_H__
#define __SERVERSTATEMACHINE_H__

class GameManager;

#include "statemachine.h"


#include "attacking.h"
#include "defending.h"
#include "moving.h"
#include "occupying.h"
#include "populating.h"
#include "simplepopulating.h"
#include "waitingfirstplayer.h"
#include "waitingmapselection.h"
#include "waitingplayer.h"
#include "waiting.h"
/**
 *
 * 
 */
class ServerStateMachine:public StateMachine {
	
	public:
		
		/**
		 * Constructor de la clase
		 */
		ServerStateMachine(ReferenceCountPtr<GameManager>& gameManager);
		
		/**
		 * Destructor de la clase
		 */
		virtual ~ServerStateMachine();


	
};
#endif /** __SERVERSTATEMACHINE_H__ */
