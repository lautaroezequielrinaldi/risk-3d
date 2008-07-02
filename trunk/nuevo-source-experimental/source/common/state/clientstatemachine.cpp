#include "clientstatemachine.h"
// #include "todos los estados"


// esto se va a la clase derivada....
ClientStateMachine::ClientStateMachine(ReferenceCountPtr<GameManager> & gameManager):StateMachine(gameManager){
	states.insert(std::make_pair("attacking",new Attacking(gameManager,"attacking")));
        states.insert(std::make_pair("defending",new Defending(gameManager,"defending")));
        states.insert(std::make_pair("moving",new Moving(gameManager,"moving")));
        states.insert(std::make_pair("occupying",new Occupying(gameManager,"occupying")));
        states.insert(std::make_pair("populating",new Populating(gameManager,"populating")));
	states.insert(std::make_pair("waiting",new Waiting(gameManager,"waiting")));

}

ClientStateMachine::~ClientStateMachine(){

}
