#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include "state.h"
#include <map>
#include <string.h>
#include "../model/player.h"

#include "attacking.h"
#include "defending.h"
#include "moving.h"
#include "occupying.h"
#include "populating.h"
#include "simplepopulatng.h"
#include ".h"
#include ".h"

/**
 *
 * 
 */
class StateMachine {
	
	public:
		
		StateMachine();
	
		~StateMachine();
	
		void setNextState(const std::string & statename);
		
		void setNextPlayer(const std::string &playername);
		
		void setNextPlayer(const Player * player);

	private:
		
		std::map <std::string, State*> states;
		State * current_state;
		Player * current_player;
		Player * current_defender;
		
	
	
	//ReferenceCountPtr<State> state;
    //std::map<std::string,ReferenceCountPtr<State> > currentState;
};
#endif /** __STATEMACHINE_H__ */
