#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

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
		
		StateMachine();
	
		~StateMachine();
	
		void setNextState(const std::string & statename);
		
	private:
		
		std::map <std::string, ReferenceCountPtr<State> > states;
		ReferenceCountPtr<State> current_state;
                std::string current_state_name;
		
	
	
};
#endif /** __STATEMACHINE_H__ */
