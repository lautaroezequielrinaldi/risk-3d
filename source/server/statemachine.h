#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include "state.h"
#include <map>
#include <string.h>

/**
 *
 * 
 */
class StateMachine {
	public:
	StateMachine();
	~StateMachine();
	void setNext(const std::string & statename);

	private:
	//std::map <std::string, State*> states;
	State * current;
};
#endif /** __STATEMACHINE_H__ */
