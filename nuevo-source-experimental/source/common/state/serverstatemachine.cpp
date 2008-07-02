#include "serverstatemachine.h"
// #include "todos los estados"


// esto se va a la clase derivada....
ServerStateMachine::ServerStateMachine(ReferenceCountPtr<GameManager> & gameManager):StateMachine(gameManager){
	states.insert(std::make_pair("attacking",new Attacking(gameManager,"attacking")));
        states.insert(std::make_pair("defending",new Defending(gameManager,"defending")));
        states.insert(std::make_pair("moving",new Moving(gameManager,"moving")));
        states.insert(std::make_pair("occupying",new Occupying(gameManager,"occupying")));
        states.insert(std::make_pair("simplePopulating",new SimplePopulating(gameManager,"simplePopulating")));
        states.insert(std::make_pair("populating",new Populating(gameManager,"populating")));
        states.insert(std::make_pair("waitingPlayer",new WaitingPlayer(gameManager,"waitingPlayer")));
        states.insert(std::make_pair("waitingFirstPlayer",new WaitingFirstPlayer(gameManager,"waitingFirstPlayer")));
        states.insert(std::make_pair("waitingMapSelection",new WaitingMapSelection(gameManager,"waitingMapSelection")));


}

ServerStateMachine::~ServerStateMachine(){

}

