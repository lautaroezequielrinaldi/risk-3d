#include "serverbattleresult.h"



ServerBattleResult::ServerBattleResult()
{
}

ServerBattleResult::~ServerBattleResult()
{
}

bool ServerBattleResult::validate(ReferenceCountPtr<GameManager>& gameMAnager){
	return true;
}
		
void ServerBattleResult::execute(ReferenceCountPtr<State>& state){

	state->battleResult(*this);
}


