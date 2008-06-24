#include "statemachine.h"
// #include "todos los estados"

StateMachine::StateMachine(ReferenceCountPtr<GameManager> & gameManager){
	states.insert(std::make_pair("attacking",new Attacking(gameManager,"attacking")));
        states.insert(std::make_pair("defending",new Defending(gameManager,"defending")));
        states.insert(std::make_pair("moving",new Moving(gameManager,"moving")));
        states.insert(std::make_pair("occupying",new Occupying(gameManager,"occupying")));
        states.insert(std::make_pair("simplePopulating",new SimplePopulating(gameManager,"simplePopulating")));
        states.insert(std::make_pair("populating",new Populating(gameManager,"populating")));
        states.insert(std::make_pair("waitingPlayer",new WaitingPlayer(gameManager,"waitingPlayer")));
        states.insert(std::make_pair("waitingFirstPlayer",new WaitingFirstPlayer(gameManager,"waitingFirstPlayer")));
        states.insert(std::make_pair("waitingMapSelection",new WaitingMapSelection(gameManager,"waitingMapSelection")));
	states.insert(std::make_pair("waiting",new Waiting(gameManager,"waiting")));


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
