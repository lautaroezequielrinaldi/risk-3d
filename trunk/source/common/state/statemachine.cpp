#include "statemachine.h"
// #include "todos los estados"

StateMachine::StateMachine(){
	states.insert(std::make_pair("attacking",new Attacking()));
        states.insert(std::make_pair("defending",new Defending()));
        states.insert(std::make_pair("moving",new Moving()));
        states.insert(std::make_pair("occupying",new Occupying()));
        states.insert(std::make_pair("simplePopulating",new SimplePopulating()));
        states.insert(std::make_pair("populating",new Populating()));
        states.insert(std::make_pair("waitingPlayer",new WaitingPlayer()));
        states.insert(std::make_pair("waitingFirstPlayer",new WaitingFirstPlayer()));
        states.insert(std::make_pair("waitingMapSelection",new WaitingMapSelection()));



}

StateMachine::~StateMachine(){

}

ReferenceCountPtr<State> StateMachine::getState(std::string statename) {
	return states[statename];

}
