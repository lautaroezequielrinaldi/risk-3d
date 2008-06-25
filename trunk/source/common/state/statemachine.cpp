#include "statemachine.h"
// #include "todos los estados"


// esto se va a la clase derivada....
StateMachine::StateMachine(ReferenceCountPtr<GameManager> & gameManager){

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
