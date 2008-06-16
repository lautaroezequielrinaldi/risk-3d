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

State::State() {
    // No realiza ninguna acciòn.
}

State::~State() {
    // No realiza ninguna acciòn,
}

std::string State::getName(){
	return name;

}


bool attack(Attack & command){
	return false;
}

bool defend(Defend & comman){
	return false;
}

//virtual void occupy(Occupy & command);

bool joinGame(JoinGame & command){
	return false;
}
//virtual bool kill(Kill & move);
bool move(Move & command){
	return false;
}
bool selectMap(SelectMap & command){

}

//bool virtual setOwner(SetOwner & command);
bool populate(Populate & command){

}

bool readyToPlay(ReadyToPlay & command){
	return false;
}

bool noMore(NoMore & command){
	return false;
}

bool surrender(Surrender & command){
	return false;
}



