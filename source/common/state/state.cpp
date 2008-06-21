#include "state.h"

#include "../commands/attack.h"
#include "../commands/defend.h"
#include "../commands/joingame.h"
#include "../commands/move.h"
#include "../commands/selectmap.h"
#include "../commands/populate.h"
#include "../commands/readytoplay.h"
#include "../commands/nomore.h"
#include "../commands/surrender.h"
#include "../commands/quit.h"


State::State(ReferenceCountPtr<GameManager>& gameManager):gameManager(gameManager) {
    // No realiza ninguna acciòn.
}

State::State(GameManager & gameManager):gameManager(gameManager) {
    // No realiza ninguna acciòn.
}


State::~State() {
    // No realiza ninguna acciòn,
}

std::string State::getName(){
	return name;

}


bool State::attack(Attack & command){
	return false;
}

bool State::defend(Defend & command){
	return false;
}

//virtual void State::occupy(Occupy & command);

bool State::joinGame(JoinGame & command){
	return false;
}
//virtual bool State::kill(Kill & move);
bool State::move(Move & command){
	return false;
}
bool State::selectMap(SelectMap & command){
        return false;
}

//bool virtual setOwner(SetOwner & command);
bool State::populate(Populate & command){
     return false;
}

bool State::readyToPlay(ReadyToPlay & command){
	return false;
}

bool State::noMore(NoMore & command){
	return false;
}

bool State::surrender(Surrender & command){
	return false;
}

bool State::quit(Quit & command){
        return false;
}


