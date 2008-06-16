#include "statemachine.h"
// #include "todos los estados"

StateMachine::StateMachine(){
	std::string key("attaking");

	states.insert(std::make_pair(key,new Attacking()));
}

StateMachine::~StateMachine(){

}

void StateMachine::setNextState(const std::string & statename){

}

void StateMachine::setNextPlayer(const std::string &playername){

}

void StateMachine::setNextPlayer(const Player * player){

}
