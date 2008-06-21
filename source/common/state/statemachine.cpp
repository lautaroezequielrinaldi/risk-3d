#include "statemachine.h"
// #include "todos los estados"

StateMachine::StateMachine(ReferenceCountPtr<GameManager> & gameManager){
	states.insert(std::make_pair("attacking",new Attacking(gameManager)));
        states.insert(std::make_pair("defending",new Defending(gameManager)));
        states.insert(std::make_pair("moving",new Moving(gameManager)));
        states.insert(std::make_pair("occupying",new Occupying(gameManager)));
        states.insert(std::make_pair("simplePopulating",new SimplePopulating(gameManager)));
        states.insert(std::make_pair("populating",new Populating(gameManager)));
        states.insert(std::make_pair("waitingPlayer",new WaitingPlayer(gameManager)));
        states.insert(std::make_pair("waitingFirstPlayer",new WaitingFirstPlayer(gameManager)));
        states.insert(std::make_pair("waitingMapSelection",new WaitingMapSelection(gameManager)));



}

StateMachine::~StateMachine(){

}

ReferenceCountPtr<State> StateMachine::getCurrentState() {
	return currentState;

}

ReferenceCountPtr<State> StateMachine::getState(std::string statename) {
	return states[statename];

}

void StateMachine::setState(std::string statename){
	currentState= getState(statename);
}
