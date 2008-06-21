#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

class GameManager;

#include "state.h"
#include <map>
#include <string.h>
#include "../model/player.h"
#include "../smartpointer/referencecountptr.h"

#include "attacking.h"
#include "defending.h"
#include "moving.h"
#include "occupying.h"
#include "populating.h"
#include "simplepopulating.h"
#include "waitingfirstplayer.h"
#include "waitingmapselection.h"
#include "waitingplayer.h"

/**
 *
 * 
 */
class StateMachine {
	
	public:
		
		StateMachine(GameManager& gameManager);
	
		~StateMachine();
                ReferenceCountPtr<State> getState(std::string statename);
		void setState(std::string statename);
	
		
	private:
		
		std::map <std::string, ReferenceCountPtr<State> > states;
		ReferenceCountPtr<State> currentState;
	
};
#endif /** __STATEMACHINE_H__ */
