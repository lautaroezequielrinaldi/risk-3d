#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include "state.h"
#include <map>
#include <string.h>
#include "../common/model/player.h"
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
	//std::map <std::string, State*> states;
	State * current_state;
	Player * current_player;
	Player * current_defender;
};
#endif /** __STATEMACHINE_H__ */
